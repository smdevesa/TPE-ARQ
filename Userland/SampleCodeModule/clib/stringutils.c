//
// Created by Santiago Devesa on 21/05/2024.
//

#include <stringutils.h>

size_t strlen(const char *str) {
    size_t len = 0;
    while(str[len] != '\0') {
        len++;
    }
    return len;
}

void strcpy(char *dest, const char *src) {
    size_t i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void strncpy(char *dest, const char *src, size_t n) {
    size_t i = 0;
    while(src[i] != 0 && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = 0;
}

void reverse(char *str) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}