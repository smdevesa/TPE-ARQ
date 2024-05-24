#include <syscall_lib.h>
#include <videoDriver.h>
#include <keyboardDriver.h>
#include <font.h>
#include <rtc.h>

#define STDIN 0
#define STDOUT 1

#define TAB_SIZE 4

#define WHITE 0x00FFFFFF
#define BLACK 0x00000000

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
            if ((print_x + getFontWidth() * getScale()) > getScreenWidth()) {
                print_x = 0;
                print_y += getFontHeight() * getScale();
            }

            if((print_y + getFontHeight() * getScale()) > getScreenHeight()) {
                // No more space in the screen, return the number of characters written
                return count;
            }

            // Check if the character is a special case
            if(!printSpecialCases(buffer[i])) {
                drawChar(buffer[i], color, BLACK, print_x, print_y);
                print_x += getFontWidth() * getScale();
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
            print_y += getFontHeight() * getScale();
            return 1;
        case '\t':
            print_x += getFontWidth() * getScale() * TAB_SIZE;
            return 1;
        case '\b':
            if(print_x > 0) {
                print_x -= getFontWidth() * getScale();
            }
            else if(print_y > 0) {
                print_y -= getFontHeight() * getScale();
                print_x = getScreenWidth() - getFontWidth() * getScale();
                // Align the cursor to the previous line
                print_x -= print_x % (getFontWidth() * getScale());
            }
            drawChar(' ', BLACK, BLACK, print_x, print_y);
            return 1;
        default:
            return 0;
    }
}

uint64_t sys_drawRectangle(uint32_t hexColor, uint64_t x, uint64_t y, uint64_t width, uint64_t height) {
    return drawRectangle(hexColor, x, y, width, height);
}

uint64_t sys_getCoords() {
    // Return the y in the high 32 bits and the x in the low 32 bits
    return ((uint64_t) print_y << 32) | print_x;
}

uint64_t sys_clearScreen() {
    clearScreen();
    print_x = 0;
    print_y = 0;
    return 0;
}

uint64_t sys_getScreenInfo() {
    // return the width in the high 32 bits and the height in the low 32 bits
    return ((uint64_t) getScreenWidth() << 32) | getScreenHeight();
}

uint64_t sys_getFontInfo() {
    // return the width in the high 32 bits and the height in the low 32 bits
    return ((uint64_t) (getFontWidth() * getScale()) << 32) | (getFontHeight() * getScale());
}

uint64_t sys_getTime(uint64_t arg) {
    return getTime(arg);
}

uint64_t sys_setFontScale(uint64_t scale) {
    return setScale(scale);
}
