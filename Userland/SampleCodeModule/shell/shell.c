//
// Created by Santiago Devesa on 21/05/2024.
//

#include <shell.h>
#include <iolib.h>
#include <stringutils.h>
#include <stddef.h>
#include <commands.h>
#include <color.h>
#include <stdint.h>
#include <time.h>

#define CURSOR_COLOR CYAN
#define SCREEN_COLOR BLACK
#define USER_COLOR 0x0000AFFF
#define USER_SEPARATOR_COLOR 0x005FD700

static void printUser();
static void getInputAndPrint(char * input);
static void clearInput(char * input);
static void printCursor(uint32_t hexColor, size_t offsetX);

static char * username;

void shell() {
    char input[MAX_COMMAND_SIZE];
    char copy[MAX_COMMAND_SIZE];
    int returned;

    if(username == NULL) {
        // Default username
        setUsername("user");
    }

    // Main loop
    while(returned != EXIT) {
        printUser();
        getInputAndPrint(input);
        putchar('\n');
        strcpy(copy, input);
        returned = parseCommand(copy);
        if(returned == INPUT_ERROR) {
            puts("Invalid command. Type 'help' to see the available commands.");
            printf("Input: %s\n", input);
        }
        clearInput(input);
    }
}

static void getInputAndPrint(char * input) {
    char c;
    int i=0;
    printCursor(CURSOR_COLOR, 0);
    while((c = getchar()) != '\n') {
        if(c != '\b') {
            // Replace tabs with spaces
            if(c == '\t') {
                c = ' ';
            }
            printCursor(CURSOR_COLOR, getFontWidth());
            if(i < (MAX_COMMAND_SIZE-1))
                input[i++] = c;
            putchar(c);
        }
        else {
            if(i > 0) {
                i--;
                uint32_t lastX = getCursorX();
                uint32_t lastY = getCursorY();
                putchar(c);
                // we need to erase the cursor
                printCursor(SCREEN_COLOR, getFontWidth());
                printCursor(CURSOR_COLOR, 0);
            }
        }
    }
    printCursor(SCREEN_COLOR, 0);
    input[i] = 0;
}

void setUsername(char * user) {
    username = user;
}

static void printUser() {
    printStringColor(username, USER_COLOR);
    printStringColor("@os:", USER_COLOR);
    printStringColor("$ ", USER_SEPARATOR_COLOR);
}

static void clearInput(char * input) {
    for(int i=0; i<MAX_COMMAND_SIZE; i++) {
        input[i] = 0;
    }
}

static void printCursor(uint32_t hexColor, size_t offsetX) {
    uint32_t x = getCursorX() + offsetX;
    uint32_t y = getCursorY();
    if(x + getFontWidth() > getScreenWidth()) {
        x = 0;
        y += getFontHeight();
    }
    drawRectangle(hexColor, x, y, getFontWidth(), getFontHeight());
}