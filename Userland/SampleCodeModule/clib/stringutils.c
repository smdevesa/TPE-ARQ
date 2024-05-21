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