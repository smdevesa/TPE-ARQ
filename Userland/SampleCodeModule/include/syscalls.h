//
// Created by Santiago Devesa on 19/05/2024.
//

#ifndef TPE_ARQ_SYSCALLS_H
#define TPE_ARQ_SYSCALLS_H

#include <stdint.h>

uint64_t _sys_read(int fd, char * buffer, int count);

uint64_t _sys_write(int fd, const char * buffer, int count, uint32_t color);

#endif
