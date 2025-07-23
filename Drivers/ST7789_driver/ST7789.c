/*
 * ST7789.h
 *
 *  Created on: Jun 06, 2025
 *      Author: Sadziooo
 */

//----------------------------------------------------------------------|
//------------------------- INCLUDES -----------------------------<
//----------------------------------------------------------------------|

#include "ST7789.h"
#include <string.h>

//----------------------------------------------------------------------|
//-------------------------- DEFINES -----------------------------<
//----------------------------------------------------------------------|

#define ST7789_NOP 							0x00 		// 	NOP
#define ST7789_SWRESET 					0x01		// 	Software Reset
#define ST7789_RDDID 						0x04		// 	Read Display ID
#define ST7789_RDDST 						0x09		// 	Read Display Status
#define ST7789_RDDPM 						0x0A		// 	Read Display Power Mode
#define ST7789_RDDMADCTL 				0x0B		// 	Read Display MADCTL
#define ST7789_RDDCOLMOD  			0x0C		// 	Read Display Pixel Format
#define ST7789_RDDIM  						0x0D		// 	Read Display Image Mode
#define ST7789_RDDSM  						0x0E		// 	Read Display Signal Mode
#define ST7789_RDDSDR  					0x0F		// 	Read Display Self-diagnostic Result
#define ST7789_SLPIN  						0x10		// 	Sleep In
#define ST7789_SLPOUT  						0x11		// 	Sleep Out
#define ST7789_PTLON  						0x12		// 	Partial Display Mode On
#define ST7789_NORON  						0x13		// 	Normal Display Mode On
#define ST7789_INVOFF  						0x20		// 	Display Inversion Off
#define ST7789_INVON  						0x21		// 	Display Inversion On
#define ST7789_GAMSET  					0x26		// 	Gamma Set
#define ST7789_DISPOFF  					0x28		// 	Display Off
#define ST7789_DISPON  						0x29		// 	Display On
#define ST7789_CASET  						0x2A		// 	Column Address Set
#define ST7789_RASET  						0x2B		//	Row Address Set
#define ST7789_RAMWR 						0x2C		//	Memory Write
#define ST7789_RAMRD  						0x2E		//	Memory Read
#define ST7789_PTLAR  						0x30		//	Partial Area
#define ST7789_VSCRDEF  					0x33		//	Vertical Scrolling Definition
#define ST7789_TEOFF  						0x34		//	Tearing Effect Line Off
#define ST7789_TEON  							0x35		//	Tearing Effect Line On
#define ST7789_MADCTL  					0x36		//	Memory Data Access Control
#define ST7789_VSCSAD 						0x37		//	Vertical Scroll Start Address of RAM
#define ST7789_IDMOFF  						0x38		//	Idle Mode Off
#define ST7789_IDMON  						0x39		//	Idle Mode On
#define ST7789_COLMOD  					0x3A		//	Interface Pixel Format
#define ST7789_WRMEMC  					0x3C		//	Write Memory Continue
#define ST7789_RDMEMC  					0x3E		//	Read Memory Continue
#define ST7789_STE  							0x44		//	Set Tear Scanline
#define ST7789_GSCAN  						0x45		//	Get Scanline
#define ST7789_WRDISBV 					0x51		//	Write Display Brightness
#define ST7789_RDDISBV  					0x52		//	Read Display Brightness
#define ST7789_WRCTRLD  					0x53		//	Write CTRL Display
#define ST7789_RDCTRLD  					0x54		//	Read CTRL Value Display
#define ST7789_WRCACE  					0x55		//	Write Content Adaptive Brightness Control and Color Enhancement
#define ST7789_RDCABC  					0x56		//	Read Content Adaptive Brightness Control
#define ST7789_WRCABCMB  				0x5E		//	Write CABC Minimum Brightness
#define ST7789_RDCABCMB  				0x5F		//	Read CABC Minimum Brightness
#define ST7789_RDABCSDR  				0x68		//	Read Automatic Brightness Control Self-Diagnostic Result
#define ST7789_RDID1  						0xDA		// 	Read ID1
#define ST7789_RDID2  						0xDB		// 	Read ID2
#define ST7789_RDID3							0xDC	// 	Read ID3
#define ST7789_RAMCTRL 					0xB0		//	RAM Control
#define ST7789_RGBCTRL  					0xB1		//	RGB Interface Control
#define ST7789_PORCTRL  					0xB2		//	Porch Setting
#define ST7789_FRCTRL1  					0xB3		//	Frame Rate Control 1 (In partial mode/ idle colors)
#define ST7789_PARCTRL  					0xB5		//	Partial Control
#define ST7789_GCTRL  						0xB7		// 	Gate Control
#define ST7789_GTADJ  						0xB8		//	Gate On Timing Adjustment
#define ST7789_DGMEN  						0xBA		//	Digital Gamma Enable
#define ST7789_VCOMS  						0xBB		//	VCOM Setting
#define ST7789_POWSAVE  					0xBC		//	Power Saving Mode
#define ST7789_DLPOFFSAVE  			0xBD		//	Display Off Power Save
#define ST7789_LCMCTRL  					0xC0		//	LCM Control
#define ST7789_IDSET  						0xC1		//	ID Code Setting
#define ST7789_VDVVRHEN  				0xC2		//	VDV and VRH Command Enable
#define ST7789_VRHS  						0xC3		//	VRH Set
#define ST7789_VDVS  						0xC4		//	VDV Set
#define ST7789_VCMOFSET  				0xC5		//	VCOM Offset Set
#define ST7789_FRCTRL2  					0xC6		//	Frame Rate Control in Normal Mode
#define ST7789_CABCCTRL  				0xC7		//	CABC Control
#define ST7789_REGSEL1  					0xC8		//	Register Value Selection 1
#define ST7789_REGSEL2  					0xCA		//	Register Value Selection 2
#define ST7789_PWMFRSEL  				0xCC	//	PWM Frequency Selection
#define ST7789_PWCTRL1  					0xD0		//	Power Control 1
#define ST7789_VAPVANEN  				0xD2		//	Enable VAP/VAN signal output
#define ST7789_CMD2EN  					0xDF		//	Command 2 Enable
#define ST7789_PVGAMCTRL  				0xE0		// 	Positive Voltage Gamma Control
#define ST7789_NVGAMCTRL  				0xE1		// 	Negative Voltage Gamma Control
#define ST7789_DGMLUTR  					0xE2		//	Digital Gamma Look-up Table for Red
#define ST7789_DGMLUTB  					0xE3		//	Digital Gamma Look-up Table for Blue
#define ST7789_GATECTRL  					0xE4		//	Gate Control
#define ST7789_SPI2EN  						0xE7		//	SPI2 Enable
#define ST7789_PWCTRL2  					0xE8		//	Power Control 2
#define ST7789_EQCTRL  					0xE9		//	Equalize Time Control
#define ST7789_PROMCTRL  				0xEC		//	Program Mode Control
#define ST7789_PROMEN  					0xFA		//	Program Mode Enable
#define ST7789_NVMSET  					0xFC		//	NVM Setting
#define ST7789_PROMACT  					0xFE		//	Program Action

/* Page Address Order ('0': Top to Bottom, '1': the opposite) */
#define ST7789_MADCTL_MY  0x80
/* Column Address Order ('0': Left to Right, '1': the opposite) */
#define ST7789_MADCTL_MX  0x40
/* Page/Column Order ('0' = Normal Mode, '1' = Reverse Mode) */
#define ST7789_MADCTL_MV  0x20
/* Line Address Order ('0' = LCD Refresh Top to Bottom, '1' = the opposite) */
#define ST7789_MADCTL_ML  0x10
/* RGB/BGR Order ('0' = RGB, '1' = BGR) */
#define ST7789_MADCTL_RGB 0x00
#define ST7789_MADCTL_BGR 0x01

#define ST7789_COLMOD_65K		0x50
#define ST7789_COLMOD_262K	0x60
#define ST7789_COLMOD_12bit	0x03
#define ST7789_COLMOD_16bit	0x05
#define ST7789_COLMOD_18bit	0x06
#define ST7789_COLMOD_16M		0x07

#define CMD(x)			((x) | 0x100)
#define ABS(x) ((x) > 0 ? (x) : -(x))

#define LCD_OFFSET_X	0
#define LCD_OFFSET_Y	0

#define MAX_CHUNK 32000 

//----------------------------------------------------------------------|
//------------------------ VARIABLES ----------------------------<
//----------------------------------------------------------------------|

static const uint16_t ST7789_init_table[] = {
	CMD(ST7789_COLMOD), (ST7789_COLMOD_262K | ST7789_COLMOD_16bit),
	CMD(ST7789_PORCTRL), 0x0C, 0x0C, 0x00, 0x33, 0x33,
	CMD(ST7789_GATECTRL), 0x35,
	CMD(ST7789_VCOMS), 0x20,
	CMD(ST7789_LCMCTRL), 0x2C,
	CMD(ST7789_VDVVRHEN), 0x01,
	CMD(ST7789_VRHS), 0x0B,
	CMD(ST7789_VDVS), 0x20,
	CMD(ST7789_FRCTRL2), 0x0F,
	CMD(ST7789_PWCTRL1), 0xA4, 0xA1,

	CMD(ST7789_PVGAMCTRL), 0xD0, 0x04, 0x0D, 0x11, 0x13, 0x2B, 0x3F, 0x54, 0x4C, 0x18, 0x0D, 0x0B, 0x1F, 0x23,
	CMD(ST7789_NVGAMCTRL), 0xD0, 0x04, 0x0C, 0x11, 0x13, 0x2C, 0x3F, 0x44, 0x51, 0x2F, 0x1F, 0x1F, 0x20, 0x23,
	CMD(ST7789_INVON),
	CMD(ST7789_NORON),

	CMD(ST7789_MADCTL), (ST7789_MADCTL_MV | ST7789_MADCTL_MX | ST7789_MADCTL_RGB)
};

uint8_t LCD_ID[3] = {0x00, 0x00, 0x00};

static ST7789_IO_t* st7789_io = NULL;

__attribute__((section(".framebuffer"))) uint16_t framebuffer[DISPLAY_W * DISPLAY_H];

//----------------------------------------------------------------------|
//---------------- FUNCTION PROROTYPES ------------------<
//----------------------------------------------------------------------|

static void ST7789_cmd(uint8_t cmd);
static void ST7789_data(uint8_t data);
static void ST7789_data16(uint16_t value);
static void ST7789_data_bulk(uint8_t* data, size_t size);
static void ST7789_send(uint16_t value);
static uint8_t ST7789_read_id(uint8_t *rx, uint8_t length);
static void ST7789_set_window(int x, int y, int width, int height);
static uint16_t swap_color(uint16_t color);

//----------------------------------------------------------------------|
//------------------------------- CODE ----------------------------<
//----------------------------------------------------------------------|

uint8_t ST7789_init(ST7789_IO_t *io_interface) {
	uint8_t status = 0;
	st7789_io = io_interface;

	st7789_io->set_dc(true);
	st7789_io->set_cs(true);

	st7789_io->delay_ms(50);
	ST7789_cmd(ST7789_SWRESET);
	st7789_io->delay_ms(150);

	status = ST7789_read_id(LCD_ID, 3);
	// if (status != 0 || LCD_ID[2] != 0xc0) {
	// 	return -1;
	// }

	st7789_io->delay_ms(50);

	for (size_t i = 0; i < sizeof(ST7789_init_table) / sizeof(uint16_t); i++) {
		ST7789_send(ST7789_init_table[i]);
	}

	st7789_io->delay_ms(200);
	ST7789_cmd(ST7789_SLPOUT);
	st7789_io->delay_ms(120);
	ST7789_cmd(ST7789_DISPON);
	ST7789_clear();
	st7789_io->set_bl(true);

	memset(framebuffer, 0, sizeof(framebuffer));

	return status;
}

static void ST7789_cmd(uint8_t cmd) {
	st7789_io->set_dc(false);
	st7789_io->set_cs(false);
	st7789_io->spi_transmit(&cmd, 1);
	st7789_io->set_cs(true);
}

static void ST7789_data(uint8_t data) {
	st7789_io->set_dc(true);
	st7789_io->set_cs(false);
	st7789_io->spi_transmit(&data, 1);
	st7789_io->set_cs(true);
}

static volatile bool spi_tx_done = true;

void ST7789_SPI_TxCpltCallback(void) {
    spi_tx_done = true;
}

static void ST7789_data_bulk(uint8_t* data, size_t size) {
    st7789_io->set_dc(true);
    st7789_io->set_cs(false);

    if (st7789_io->spi_transmit_dma) {
		spi_tx_done = false;
        st7789_io->spi_transmit_dma(data, size);
        while (!spi_tx_done) {
            __NOP();
        }
    } else {
		while (size > 0) {
			uint32_t to_send = (size > MAX_CHUNK) ? MAX_CHUNK : size;

			st7789_io->set_cs(false);
			st7789_io->spi_transmit(data, to_send);
			st7789_io->set_cs(true);

			data += to_send;
			size -= to_send;
		}
        
    }

    st7789_io->set_cs(true);
}


static void ST7789_send(uint16_t value) {
	if (value & 0x100) {
		ST7789_cmd(value);
	} else {
		ST7789_data(value);
	}
}

uint8_t ST7789_read_id(uint8_t *rx, uint8_t length) {
	uint8_t reg = ST7789_RDDID;
	uint8_t tx[length];
	memset(tx, ST7789_NOP, length);
	uint8_t status = 0;

	st7789_io->set_cs(false);
	st7789_io->set_dc(false);
	status = st7789_io->spi_transmit(&reg, 1);
	st7789_io->set_dc(true);
	status = st7789_io->spi_transmit_receive(tx, rx, length);
	st7789_io->set_cs(true);

	return status;
}

static void ST7789_data16(uint16_t value) {
	uint8_t data[2];
	data[0] = value >> 8;
	data[1] = value;
	ST7789_data_bulk(data, 2);
}

static void ST7789_set_window(int x, int y, int width, int height) {
	ST7789_cmd(ST7789_CASET);
	ST7789_data16(LCD_OFFSET_X + x);
	ST7789_data16(LCD_OFFSET_X + x + width - 1);

	ST7789_cmd(ST7789_RASET);
	ST7789_data16(LCD_OFFSET_Y + y);
	ST7789_data16(LCD_OFFSET_Y + y + height - 1);
}

static uint16_t swap_color(uint16_t color) {
    return (color >> 8) | (color << 8);
}

// ====================================================================================================

void ST7789_clear(void) {
	memset(framebuffer, 0x00, sizeof(framebuffer));
	ST7789_flush_to_display();
}    

void ST7789_flush_to_display(void) {
    ST7789_set_window(0, 0, DISPLAY_W, DISPLAY_H);
    ST7789_cmd(ST7789_RAMWR);
    ST7789_data_bulk((uint8_t*)framebuffer, sizeof(framebuffer));
}

void ST7789_put_pixel(uint32_t x, uint32_t y, uint16_t color, bool flush) {
	if (x < DISPLAY_W && y < DISPLAY_H) {
        framebuffer[y * DISPLAY_W + x] = swap_color(color);
		if (flush) ST7789_flush_to_display();
	}
}

void ST7789_fill_box(uint32_t x, uint32_t y, uint32_t width, uint32_t height, uint16_t color, bool flush) {
    if (x + width > DISPLAY_W || y + height > DISPLAY_H) {
        return;
    }

    uint16_t swapped_color = swap_color(color);

    for (uint16_t row = 0; row < height; row++) {
        uint16_t* dst = &framebuffer[(y + row) * DISPLAY_W + x];
        for (uint16_t col = 0; col < width; col++) {
            dst[col] = swapped_color;
        }
    }

	if (flush) ST7789_flush_to_display();
}

void ST7789_draw_line(uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1, uint16_t color, bool flush)  {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1) {
        ST7789_put_pixel(x0, y0, color, false);
        if (x0 == x1 && y0 == y1) break;
        e2 = 2 * err;
        if (e2 >= dy) { err += dy; x0 += sx; }
        if (e2 <= dx) { err += dx; y0 += sy; }
    }

	if (flush) ST7789_flush_to_display();
}

void ST7789_draw_rectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, bool flush) {
	ST7789_draw_line(x1, y1, x2, y1, color, false);
	ST7789_draw_line(x1, y1, x1, y2, color, false);
	ST7789_draw_line(x1, y2, x2, y2, color, false);
	ST7789_draw_line(x2, y1, x2, y2, color, false);

	if (flush) ST7789_flush_to_display();
}

void ST7789_draw_circle(uint16_t x0, uint16_t y0, uint8_t r, uint16_t color, bool flush) {
    int f = 1 - r;
    int dx = 1;
    int dy = -2 * r;
    int x = 0;
    int y = r;

    ST7789_put_pixel(x0, y0 + r, color, false);
    ST7789_put_pixel(x0, y0 - r, color, false);
    ST7789_put_pixel(x0 + r, y0, color, false);
    ST7789_put_pixel(x0 - r, y0, color, false);

    while (x < y) {
        if (f >= 0) {
            y--;
            dy += 2;
            f += dy;
        }
        x++;
        dx += 2;
        f += dx;

        ST7789_put_pixel(x0 + x, y0 + y, color, false);
        ST7789_put_pixel(x0 - x, y0 + y, color, false);
        ST7789_put_pixel(x0 + x, y0 - y, color, false);
        ST7789_put_pixel(x0 - x, y0 - y, color, false);

        ST7789_put_pixel(x0 + y, y0 + x, color, false);
        ST7789_put_pixel(x0 - y, y0 + x, color, false);
        ST7789_put_pixel(x0 + y, y0 - x, color, false);
        ST7789_put_pixel(x0 - y, y0 - x, color, false);
    }

	if (flush) ST7789_flush_to_display();
}

void ST7789_draw_image(uint16_t x, uint16_t y, uint16_t width, uint16_t height, const uint16_t* data) {
	const uint16_t chunk_size = MAX_CHUNK; // Number of pixels per chunk
	uint16_t pixels_remaining = width * height;
	uint16_t pixels_sent = 0;

	while (pixels_remaining > 0) {
		uint16_t chunk_pixels = (pixels_remaining < chunk_size) ? pixels_remaining : chunk_size;
		uint16_t chunk_rows = chunk_pixels / width;
		uint16_t chunk_cols = (chunk_pixels % width == 0) ? width : (chunk_pixels % width);

		ST7789_set_window(x + (pixels_sent % width), y + (pixels_sent / width), chunk_cols, chunk_rows);
		ST7789_cmd(ST7789_RAMWR);
		ST7789_data_bulk((uint8_t*)(data + pixels_sent), chunk_pixels * sizeof(uint16_t));

		pixels_remaining -= chunk_pixels;
		pixels_sent += chunk_pixels;
	}
}

void ST7789_write_char(uint16_t x, uint16_t y, char ch, FontDef font, uint16_t color, uint16_t bgcolor) {
    uint32_t i, b, j;
    uint16_t char_buffer_size = font.height * font.width * 2;
    uint8_t char_buffer[char_buffer_size];
    uint16_t buffer_index = 0;

    for (i = 0; i < font.height; i++) {
    		b = font.data[(ch - 32) * font.height + i];
    		for (j = 0; j < font.width; j++) {
    			if ((b << j) & 0x8000) {
    				uint8_t data[] = {color >> 8, color & 0xFF};
    				char_buffer[buffer_index++] = data[0];
    				char_buffer[buffer_index++] = data[1];
    			} else {
    				uint8_t data[] = {bgcolor >> 8, bgcolor & 0xFF};
    				char_buffer[buffer_index++] = data[0];
    				char_buffer[buffer_index++] = data[1];
    			}
    		}
    	}

    ST7789_set_window(x, y, font.width, font.height);
    ST7789_cmd(ST7789_RAMWR);
    ST7789_data_bulk(char_buffer, sizeof(char_buffer));
}

void ST7789_write_string(uint16_t x, uint16_t y, const char *str, FontDef font, uint16_t color, uint16_t bgcolor) {
	while (*str) {
		if (x + font.width >= DISPLAY_W) {
			x = 0;
			y += font.height;
			if (y + font.height >= DISPLAY_H) {
				break;
			}

			if (*str == ' ') {
				// skip spaces in the beginning of the new line
				str++;
				continue;
			}
		}
		ST7789_write_char(x, y, *str, font, color, bgcolor);
		x += font.width;
		str++;
	}
}
