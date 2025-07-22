/*
 * LCD.c
 *
 *  Created on: Jun 06, 2025
 *      Author: Sadziooo
 */

#include "LCD.h"

void ST7789_HAL_set_cs(bool state) {
    HAL_GPIO_WritePin(SPI1_CS_GPIO_Port, SPI1_CS_Pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void ST7789_HAL_set_dc(bool state) {
    HAL_GPIO_WritePin(LCD_DC_GPIO_Port, LCD_DC_Pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

void ST7789_HAL_set_bl(bool state) {
    HAL_GPIO_WritePin(LCD_BL_GPIO_Port, LCD_BL_Pin, state ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

uint8_t ST7789_HAL_spi_transmit(const uint8_t* data, size_t size) {
    uint8_t status = HAL_SPI_Transmit(&hspi1, (uint8_t*)data, size, HAL_MAX_DELAY);
    return status;
}

uint8_t ST7789_HAL_spi_transmit_dma(const uint8_t* data, size_t size) {
    uint8_t status = HAL_SPI_Transmit_DMA(&hspi1, (uint8_t*)data, size);
    return status;
}

uint8_t ST7789_HAL_spi_transmit_receive(const uint8_t* tx, uint8_t* rx, size_t size) {
    uint8_t status = HAL_SPI_TransmitReceive(&hspi1, (uint8_t*)tx, rx, size, HAL_MAX_DELAY);
    return status;
}

void ST7789_HAL_delay_ms(uint32_t ms) {
    osDelay(ms);
}
