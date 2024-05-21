#include <iolib.h>
#include <syscalls.h>
#include <stringutils.h>

char getchar() {
    char c;
    int readBytes = 0;
    while(readBytes != 1) {
        readBytes = _sys_read(STDIN, &c, 1);
    }
    return c;
}

void putchar(char c) {
    _sys_write(STDOUT, &c, 1, 0x00FFFFFF);
}

char * fgets(char *buffer, size_t size) {
    int readBytes = 0;
    while(readBytes < (size-1) && buffer[readBytes - 1] != '\n') {
        buffer[readBytes++] = getchar();
    }
    buffer[size-1] = 0;
    return buffer;
}

void printf(const char *str) {
    _sys_write(STDOUT, str, strlen(str), 0x00FFFFFF);
}