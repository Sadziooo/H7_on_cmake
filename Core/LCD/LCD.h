/*
 * LCD.h
 *
 *  Created on: Jun 06, 2025
 *      Author: Sadziooo
 */

#ifndef LCD_H_
#define LCD_H_

#pragma once

#include "main.h"
#include "ST7789.h"
#include "spi.h"
#include "cmsis_os2.h"

void ST7789_HAL_set_cs(bool state);
void ST7789_HAL_set_dc(bool state);
void ST7789_HAL_set_bl(bool state);
uint8_t ST7789_HAL_spi_transmit(const uint8_t* data, size_t size);
uint8_t ST7789_HAL_spi_transmit_dma(const uint8_t* data, size_t size);
uint8_t ST7789_HAL_spi_transmit_receive(const uint8_t* tx, uint8_t* rx, size_t size);
void ST7789_HAL_delay_ms(uint32_t ms);

#endif /* LCD_H_ */