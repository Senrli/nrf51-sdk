/**
 * @file hx710.c
 * @author your name (you@domain.com)
 * @brief Driver source file for HX710B driver, adopted from the source datasheet. Compatible with HX710A.
 * @version 0.1
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "hx710.h"
#include "nrf_gpio.h"
#include "nrf_delay.h"
#include "app_timer.h"

/* Logging module definition */
#define NRF_LOG_MODULE_NAME "HX710"

/* Set both debug and log color as Green */
#define NRF_LOG_DEBUG_COLOR 7
#define NRF_LOG_INFO_COLOR 7

#include "nrf_log.h"

// TODO: remove the hard-coded prescaler
#define HX710_READ_TIMEOUT_DURATION      APP_TIMER_TICKS(TIMEOUT_MS, 0)  /**< Battery level measurement interval (ticks). */

APP_TIMER_DEF(hx710_timeout_timer);
static volatile uint8_t hx710_read_timeout = 0;                     /* set the field volatile since handled by interrupt */


/**@brief Function for handling the HX710 timer read timeout.
 *
 * @details This function will be called each time the HX710 read timer expires.
 *
 * @param[in] p_context  Pointer used for passing some arbitrary information (context) from the
 *                       app_start_timer() call to the timeout handler.
 */
static void hx710_read_timeout_handler(void * p_context)
{
    UNUSED_PARAMETER(p_context);
    hx710_read_timeout = 1;
}

void hx710_init(hx710_t* sensor) {
    uint32_t err_code;

    nrf_gpio_cfg_output(sensor->sck);
    nrf_gpio_cfg_input(sensor->dat, NRF_GPIO_PIN_PULLUP);

    err_code = app_timer_create(&hx710_timeout_timer,
                                APP_TIMER_MODE_SINGLE_SHOT,
                                hx710_read_timeout_handler);
    APP_ERROR_CHECK(err_code);
}


void get_weight_gross(hx710_t* sensor);

unsigned int get_weight(hx710_t* sensor);

long hx710_read(hx710_t* sensor) {
    uint32_t err_code;

    long count = 0;
    // nrf_gpio_pin_write(sensor->sck, 1);
    // nrf_delay_us(1);
    nrf_gpio_pin_write(sensor->sck, 0);
    nrf_delay_us(1);

    err_code = app_timer_start(hx710_timeout_timer, HX710_READ_TIMEOUT_DURATION, NULL);
    APP_ERROR_CHECK(err_code);

    // Loop while the data pin is high
    // NRF_LOG_DEBUG("reading sensor now\r\n");
    uint32_t pin_val = 1;
    do {
        if (hx710_read_timeout) {
            NRF_LOG_ERROR("read timeout!\r\n");
            hx710_read_timeout = 0;
            return -1;
        } else {
            pin_val = nrf_gpio_pin_read(sensor->dat);
        }
    } while (pin_val);
    
    err_code = app_timer_stop(hx710_timeout_timer);
    APP_ERROR_CHECK(err_code);
    
    for (int i = 0; i < HX710_ACCU; i++) {
        // if(i >= HX710_BITS){
        //     nrf_gpio_pin_write(sensor->dat, 1);
        // }
        nrf_gpio_pin_write(sensor->sck, 1);
        nrf_delay_us(1);
        nrf_gpio_pin_write(sensor->sck, 0);
        nrf_delay_us(1);
        if (i < HX710_BITS) {
            count = count << 1;
            if (nrf_gpio_pin_read(sensor->dat)) {
                count++;
            }
        }
    }
    nrf_gpio_pin_write(sensor->sck, 1);
    nrf_delay_us(1);
    nrf_gpio_pin_write(sensor->sck, 0);
    count ^= 0x800000;

    return count;
}