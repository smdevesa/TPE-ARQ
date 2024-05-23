#include <stdint.h>
#include <syscall_lib.h>

#define READ 0
#define WRITE 1
#define RECTANGLE 2
#define CLEAR 3
#define COORDS 4
#define SCREENINFO 5
#define FONTINFO 6
#define GETTIME 7


uint64_t syscallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t rax) {
    // rax contains the syscall id
    switch (rax) {
        case READ: return sys_read(rdi, (char *) rsi, rdx);
        case WRITE: return sys_write(rdi, (char *) rsi, rdx, rcx);
        case RECTANGLE: return sys_drawRectangle(rdi, rsi, rdx, rcx, r8);
        case CLEAR: return sys_clearScreen();
        case COORDS: return sys_getCoords();
        case SCREENINFO: return sys_getScreenInfo();
        case FONTINFO: return sys_getFontInfo();
        case GETTIME: return sys_getTime(rdi);
        default: return 0;
    }
}