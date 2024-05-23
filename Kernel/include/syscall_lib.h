#ifndef TPE_ARQ_SYSCALL_LIB_H
#define TPE_ARQ_SYSCALL_LIB_H

#include <stdint.h>

/**
 * @brief Reads a string from the standard input.
 * @param buffer: the buffer to store the string.
 * @param count: the number of chars to read.
 * @return the number of chars read.
 */
uint64_t sys_read(int fd, char * buffer, int count);

/**
 * @brief Writes a string to the standard output.
 * @param buffer: the string to write.
 * @param count: the number of chars to write.
 * @param color: the color of the string in hexadecimal. Usage: 0x00RRGGBB.
 * @return the number of chars written.
 */
uint64_t sys_write(int fd, const char * buffer, int count, uint32_t color);

/**
 * @brief Draws a rectangle in the screen on the given coordinates.
 * @param hexColor: the color of the rectangle in hexadecimal. Usage: 0x00RRGGBB.
 * @param x: the x coordinate of the rectangle.
 * @param y: the y coordinate of the rectangle.
 * @param width: the width of the rectangle.
 * @param height: the height of the rectangle.
 * @return 0 if the rectangle was drawn successfully, 1 if the rectangle was out of bounds.
 */
uint64_t sys_drawRectangle(uint32_t hexColor, uint64_t x, uint64_t y, uint64_t width, uint64_t height);

/**
 * @brief Clears the screen.
 */
uint64_t sys_clearScreen();

/**
 * @brief Returns the current cursor position.
 * @return the current cursor y position in the higher 32 bits and the x position in the lower 32 bits.
 */
uint64_t sys_getCoords();

/**
 * @brief Returns the screen width in the high 32 bits and the screen height in the low 32 bits.
 */
uint64_t sys_getScreenInfo();

/**
 * @brief Returns the font width in the high 32 bits and the font height in the low 32 bits.
 */
uint64_t sys_getFontInfo();

/**
 * @brief Returns the time data of the current time read from the RTC.
 */
uint64_t sys_getTime(uint64_t rdi);

#endif
