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
 * Reads until the user enters a newline or the buffer is full.
 * @param buffer The buffer to store the line.
 * @param size The size of the buffer.
 * @return A null-terminated string with the line read.
 */
char * fgets(char *buffer, size_t size);

/**
 * Writes a null-terminated string to the standard output.
 * @param str The string to write.
 */
void printf(const char * str);

#endif
