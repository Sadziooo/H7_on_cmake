/*
 * ST7789.h
 *
 *  Created on: Jun 06, 2025
 *      Author: Sadziooo
 */

#ifndef INC_ST7789_H_
#define INC_ST7789_H_

#pragma once

//----------------------------------------------------------------------|
//------------------------- INCLUDES -----------------------------<
//----------------------------------------------------------------------|

#include "main.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#include "Fonts.h"

//----------------------------------------------------------------------|
//-------------------------- DEFINES -----------------------------<
//----------------------------------------------------------------------|

#define DISPLAY_H	240
#define DISPLAY_W	320

#define RGB565(r, g, b) (((r & 0xF8) << 8) | ((g & 0xFC) << 3) | ((b >> 3)))
#define WHITE       		0xFFFF
#define BLACK       		0x0000
#define BLUE       		 	0x001F
#define RED        		 	0xF800
#define MAGENTA     	    0xF81F
#define GREEN       		0x07E0
#define CYAN        		0x7FFF
#define YELLOW      	    0xFFE0
#define GRAY        		0X8430
#define BRED        		0XF81F
#define GRED        		0XFFE0
#define GBLUE       		0X07FF
#define BROWN       		0XBC40
#define BRRED       		0XFC07
#define DARKBLUE    	    0X01CF
#define LIGHTBLUE   	    0X7D7C
#define GRAYBLUE    	    0X5458
#define LIGHTGREEN  	    0X841F
#define LGRAY       		0XC618
#define LGRAYBLUE   	    0XA651
#define LBBLUE      		0X2B12

//----------------------------------------------------------------------|
//------------------------ VARIABLES ----------------------------<
//----------------------------------------------------------------------|

typedef struct {
    void (*set_cs)(bool state);
    void (*set_dc)(bool state);
    void (*set_bl)(bool state);
    uint8_t (*spi_transmit)(const uint8_t* data, size_t size);
    uint8_t (*spi_transmit_dma)(const uint8_t* data, size_t size);
    uint8_t (*spi_transmit_receive)(const uint8_t* tx, uint8_t* rx, size_t size);
    void (*delay_ms)(uint32_t ms);
} ST7789_IO_t;

//----------------------------------------------------------------------|
//---------------- FUNCTION PROROTYPES ------------------<
//----------------------------------------------------------------------|

uint8_t ST7789_init(ST7789_IO_t *io_interface);
void ST7789_SPI_TxCpltCallback(void);
void ST7789_fill_box(int x, int y, int width, int height, uint16_t color);
void ST7789_fill_box_fast(int x, int y, int width, int height, uint16_t color);
void ST7789_put_pixel(int x, int y, uint16_t color);
void ST7789_draw_image(int x, int y, int width, int height, const uint8_t* data);
void ST7789_draw_image_fast(int x, int y, int width, int height, const uint16_t* data);
void ST7789_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color);
void ST7789_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color);
void ST7789_draw_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color);
void ST7789_write_char(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor);
void ST7789_write_string(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor);

#endif /* INC_ST7789_H_ */
