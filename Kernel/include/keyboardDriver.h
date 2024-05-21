
#ifndef TPE_ARQ_KEYBOARDDRIVER_H
#define TPE_ARQ_KEYBOARDDRIVER_H

#include <stdint.h>

#define ESC 0x01
#define BACKSPACE 0x0E
#define ENTER 0x1C
#define LSHIFT 0x2A
#define RSHIFT 0x36
#define CAPSLOCK 0x3A
#define RELEASE_OFFSET 0x80
#define KEYS_AMOUNT 59

/**
 * @brief Hardware interrupt handler for the keyboard.
 *
 */
void keyboard_handler();

/**
 * @brief Returns a character from the keyboard buffer
 * or 0 if the buffer is empty.
 */
char kb_getchar();

#endif
