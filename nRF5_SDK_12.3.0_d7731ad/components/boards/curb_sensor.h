/**
 * Copyright (c) 2016 - 2017, Nordic Semiconductor ASA
 * 
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 * 
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 * 
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 * 
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 * 
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 * 
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */
#ifndef CURB_SENSOR_H
#define CURB_SENSOR_H

#ifdef __cplusplus
extern "C" {
#endif

// LEDs definitions
#define LEDS_NUMBER    2

#define LED_0          18
#define LED_1          17

/* Flips the active state being logic high or logic low */
#define LEDS_ACTIVE_STATE 0

#define LEDS_LIST {LED_0, LED_1}

#define BSP_LED_0      LED_0
#define BSP_LED_1      LED_1
#define BSP_LED_2      LED_1


#define LEDS_INV_MASK  0

#define BUTTONS_NUMBER 2

#define BUTTON_0       10
#define BUTTON_1       11 
#define BUTTON_START   BUTTON_0
#define BUTTON_STOP    BUTTON_0
#define BUTTON_PULL    NRF_GPIO_PIN_NOPULL

#define BUTTONS_ACTIVE_STATE 0

#define BUTTONS_LIST { BUTTON_0, BUTTON_1 }

#define BSP_BUTTON_0   BUTTON_0

#define USART0_RX_PIN_NUMBER  21
#define USART0_TX_PIN_NUMBER  22
#define USART0_CTS_PIN_NUMBER 0     // not initialized
#define USART0_RTS_PIN_NUMBER 0     // not initialized
#define USART0_HWFC           APP_UART_FLOW_CONTROL_DISABLED

// #define USART1_RX_PIN_NUMBER  5
// #define USART1_TX_PIN_NUMBER  6
// #define USART1_CTS_PIN_NUMBER 7
// #define USART1_RTS_PIN_NUMBER 12
// #define USART1_HWFC           true

// //SPI pin
// #define SPI0_MISO              23
// #define SPI0_MOSI              24
// #define SPI0_SCL               25
// #define SPI0_SS                30

//I2C pin
#define I2C0_SCK               23
#define I2C0_SDA               24

// Sensor output pins
#define SENSOR_CLK_1            12
#define SENSOR_CLK_2            13
#define SENSOR_CLK_3            14

#define SENSOR_DAT1_1           3
#define SENSOR_DAT1_2           4
#define SENSOR_DAT2_1           5
#define SENSOR_DAT2_2           6
#define SENSOR_DAT3_1           7
#define SENSOR_DAT3_2           8

// Low frequency clock source to be used by the SoftDevice
#define NRF_CLOCK_LFCLKSRC      {.source        = NRF_CLOCK_LF_SRC_XTAL,            \
                                 .rc_ctiv       = 0,                                \
                                 .rc_temp_ctiv  = 0,                                \
                                 .xtal_accuracy = NRF_CLOCK_LF_XTAL_ACCURACY_20_PPM}


#ifdef __cplusplus
}
#endif

#endif // CURB_SENSOR_H
