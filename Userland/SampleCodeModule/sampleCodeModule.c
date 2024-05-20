/* sampleCodeModule.c */

#include <syscalls.h>

int main() {
    char * msg = "Hello, World!";
    while(1) {
        _sys_write(1, msg, 13, 0x00FFFFFF);
    }
    return 0;
}