#include <syscall_lib.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <font.h>

#define STDIN 0
#define STDOUT 1

// Positioning variables
static uint16_t print_x = 0;
static uint16_t print_y = 0;

static int printSpecialCases(char c);

uint64_t sys_read(int fd, char * buffer, int count) {
    // STDIN is the only file descriptor supported so far
    if(fd != STDIN) {
        return 0;
    }
    for(int i = 0; i < count; i++) {
        char c = kb_getchar();
        if(c == 0) {
            return i;
        }
        buffer[i] = c;
    }
    return count;
}

uint64_t sys_write(int fd, const char * buffer, int count, uint32_t color) {
    // STDOUT is the only file descriptor supported so far
    if (fd == STDOUT) {
        for(int i = 0; i < count; i++) {
            // Check if the character fits in the screen
            if ((print_x + getFontWidth()) > getScreenWidth()) {
                print_x = 0;
                print_y += getFontHeight();
            }

            if((print_y + getFontHeight()) > getScreenHeight()) {
                // No more space in the screen, return the number of characters written
                return count;
            }

            // Check if the character is a special case
            if(!printSpecialCases(buffer[i])) {
                drawChar(buffer[i], color, 0x00000000, print_x, print_y);
                print_x += getFontWidth();
            }
        }
        return count;
    }
    return 0;
}

static int printSpecialCases(char c) {
    switch (c) {
        case '\n':
            print_x = 0;
            print_y += getFontHeight();
            return 1;
        case '\t':
            print_x += getFontWidth() * 4;
            return 1;
        default:
            return 0;
    }
}