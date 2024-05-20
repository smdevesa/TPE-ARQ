#ifndef TPE_ARQ_SYSCALL_LIB_H
#define TPE_ARQ_SYSCALL_LIB_H

#include <stdint.h>

/*
 * Writes a string to the standard output.
 * @param buffer: the string to write.
 * @param count: the number of chars to write.
 * @param color: the color of the string in hexadecimal. Usage: 0x00RRGGBB.
 * @return the number of chars written.
 */
uint64_t sys_write(int fd, const char * buffer, int count, uint32_t color);

#endif
