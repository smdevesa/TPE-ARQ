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



#endif
