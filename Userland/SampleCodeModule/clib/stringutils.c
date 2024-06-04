#include <stringutils.h>

size_t strlen(const char *str) {
    size_t len = 0;
    while(str[len] != 0) {
        len++;
    }
    return len;
}

void strcpy(char *dest, const char *src) {
    size_t i = 0;
    while(src[i] != 0) {
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

int strcmp(const char *str1, const char *str2) {
    for(int i=0, j=0; str1[i] != 0 || str2[j] != 0; i++, j++) {
        if(str1[i] != str2[j]) {
            return str1[i] - str2[j];
        }
    }
    return 0;
}
