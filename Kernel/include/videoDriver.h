//
// Created by Santiago Devesa on 19/05/2024.
//

#ifndef TPE_ARQ_VIDEODRIVER_H
#define TPE_ARQ_VIDEODRIVER_H

#include <stdint.h>

/*
 * Draws a pixel in the screen on the given coordinates.
 * @param hexColor: the color of the pixel in hexadecimal. Usage: 0x00RRGGBB.
 * @param x: the x coordinate of the pixel.
 * @param y: the y coordinate of the pixel.
 */
void drawPixel(uint32_t hexColor, uint64_t x, uint64_t y);

/*
 * Draws a character in the screen on the given coordinates using the 8x16 font in font.c
 * @param c: the character to draw.
 * @param hexColor: the color of the character in hexadecimal. Usage: 0x00RRGGBB.
 * @param x: the x coordinate of the character.
 * @param y: the y coordinate of the character.
 */
void drawChar(char c, uint32_t charColor, uint32_t bgColor, uint64_t x, uint64_t y);

/*
 * Returns the width of the screen in pixels.
 */
uint16_t getScreenWidth();

/*
 * Returns the height of the screen in pixels.
 */
uint16_t getScreenHeight();

#endif //TPE_ARQ_VIDEODRIVER_H
