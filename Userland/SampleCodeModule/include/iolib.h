//
// Created by Santiago Devesa on 20/05/2024.
//

#ifndef TPE_ARQ_STDIO_H
#define TPE_ARQ_STDIO_H

#include <stddef.h>

#define STDIN 0
#define STDOUT 1

/**
 * Reads a character from the standard input.
 * @return The character read.
 */
char getchar();

/**
 * Writes a character to the standard output.
 * @param c The character to write.
 */
void putchar(char c);

/**
 * Reads from STDIN until the user enters a newline or the buffer is full.
 * @param buffer The buffer to store the line.
 * @param size The size of the buffer.
 * @return A null-terminated string with the line read.
 */
char * fgets(char *buffer, size_t size);

/**
 * @brief Prints a formatted string to the standard output.
 * @param fmt The format string.
 * @param ... The arguments to replace the format specifiers.
 * @return The number of characters printed.
 */
int printf(const char * fmt, ...);

/**
 * @brief Reads formatted input from the standard input.
 * @param fmt The format string.
 * @param ... The variables pointers to store the input.
 * @return The number of variables read.
 */
int scanf(const char * fmt, ...);

/**
 * Writes a string to the standard output with a line break.
 * @param str The string to write.
 */
void puts(const char * str);

/**
 * Converts a integer to a string.
 * @param num The integer to convert.
 * @param str The buffer to store the string.
 */
char * itoa(int num, char * str);

/**
 * Converts a string to an integer.
 * @param str The string to convert.
 * @return The integer value.
 */
int atoi(const char * str);

/**
 * @return The current cursor x position.
 */
unsigned int getCursorX();

/**
 * @return The current cursor y position.
 */
unsigned int getCursorY();

/**
 * @brief Clears the screen and resets the cursor to the origin of coordinates.
 */
void clearScreen();

/**
 * @brief Draws a rectangle in the screen on the given coordinates.
 * @param x top left corner x coordinate of the rectangle.
 * @param y top left corner y coordinate of the rectangle.
 * @param width width of the rectangle in pixels.
 * @param height height of the rectangle in pixels.
 * @param color the color of the rectangle in hexadecimal. Usage: 0x00RRGGBB.
 */
void printRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height, unsigned int color);

/**
 * @brief Returns the screen width in pixels.
 */
unsigned int getScreenWidth();

/**
 * @brief Returns the screen height in pixels.
 */
unsigned int getScreenHeight();

/**
 * @brief Returns the font width in pixels.
 */
unsigned int getFontWidth();

/**
 * @brief Returns the font height in pixels.
 */
unsigned int getFontHeight();

#endif
