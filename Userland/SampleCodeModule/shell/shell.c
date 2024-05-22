//
// Created by Santiago Devesa on 21/05/2024.
//

#include <shell.h>
#include <iolib.h>
#include <stringutils.h>
#include <stddef.h>
#include <commands.h>

static void printUser();
static void getInputAndPrint(char * input);
static void clearInput(char * input);

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
    while((c = getchar()) != '\n') {
        if(c != '\b') {
            if(i < (MAX_COMMAND_SIZE-1))
                input[i++] = c;
            putchar(c);
        }
        else {
            if(i > 0) {
                i--;
                undrawChar();
            }
        }
    }
    input[i] = 0;
}

void setUsername(char * user) {
    username = user;
}

static void printUser() {
    printf("%s@os:>$ ", username);
}

static void clearInput(char * input) {
    for(int i=0; i<MAX_COMMAND_SIZE; i++) {
        input[i] = 0;
    }
}