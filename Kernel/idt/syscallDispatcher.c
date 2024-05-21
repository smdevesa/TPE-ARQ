#include <stdint.h>
#include <syscall_lib.h>

uint64_t syscallDispatcher(uint64_t rdi, uint64_t rsi, uint64_t rdx, uint64_t rcx, uint64_t r8, uint64_t rax) {
    // rax contains the syscall id
    switch (rax) {
        case 0: return sys_read(rdi, (char *) rsi, rdx);
        case 1: return sys_write(rdi, (char *) rsi, rdx, rcx);
        default: return 0;
    }
}