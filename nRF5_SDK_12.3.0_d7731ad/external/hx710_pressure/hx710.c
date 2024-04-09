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
#include "nrf_nvic.h"

/* Logging module definition */
#define NRF_LOG_MODULE_NAME "HX710"

/* Set both debug and log color as Green */
#define NRF_LOG_DEBUG_COLOR 7
#define NRF_LOG_INFO_COLOR 7

#include "nrf_log.h"


void hx710_init(hx710_t* sensor) {

    nrf_gpio_cfg_output(sensor->sck);
    nrf_gpio_cfg_input(sensor->dat, NRF_GPIO_PIN_NOPULL);

}


void get_weight_gross(hx710_t* sensor);

unsigned int get_weight(hx710_t* sensor);

long hx710_read(hx710_t* sensor) {
    
    uint32_t err_code;
    long count = 0;

    for (int i = 0; i < HX710_ACCU; i++) {
        // if(i >= HX710_BITS){
        //     nrf_gpio_pin_write(sensor->dat, 1);
        // }
        nrf_gpio_pin_write(sensor->sck, 1);
        nrf_delay_us(1);
        nrf_gpio_pin_write(sensor->sck, 0);
        // nrf_delay_us(1);
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