//
// Created by Santiago Devesa on 20/05/2024.
//

#ifndef TPE_ARQ_STDIO_H
#define TPE_ARQ_STDIO_H

#include <stddef.h>

#define STDIN 0
#define STDOUT 1

char getchar();
void putchar(char c);
char * fgets(char *buffer, size_t size);
void printf(const char * str);

#endif
