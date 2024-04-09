/**
 * @file hx710.h
 * @author your name (you@domain.com)
 * @brief Header file for HX710B driver.
 * @version 0.1
 * @date 2024-02-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef _HX710_H_
#define _HX710_H_

#define HX710_10_HZ_TICKS 24
#define HX710_40_HZ_TICKS 26
#define HX710_BITS 24

#define HX710_ACCU HX710_40_HZ_TICKS

#define TIMEOUT_MS 2000                     /* HX710 read timeout in ms */

#include "nrf.h"
#include "nrf_drv_spi.h"

// volatile long hx710_buf = 0;
// volatile long weight_gross = 0;
// volatile long weight_actual = 0;

typedef struct {
    int sck; // sck pin for hx710 controller
    int dat; // data pin for hx710 controller
} hx710_t;

/// @brief Initialize the HX710 sensor
/// @param sensor sensor struct used
void hx710_init(hx710_t * sensor);

/// @brief Get gross weight 
void get_weight_gross(hx710_t * sensor);

/// @brief Get weight after calibration factor
/// @return weight in calibrated values 
unsigned int get_weight(hx710_t * sensor);

/// @brief Read data from HX710 sensor
/// @return Raw reading from HX710 sensor
long hx710_read(hx710_t * sensor);

#endif /* _HX710_H_ */