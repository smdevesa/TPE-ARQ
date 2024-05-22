//
// Created by Santiago Devesa on 21/05/2024.
//

#include <shell.h>
#include <iolib.h>
#include <string.h>
#include <stddef.h>

#define MAX_COMMAND_SIZE 30
#define MAX_ARGS 3

// Commands
char * commands[] = {
    "help",
    "exit"
};

// Help messages
char * help[] = {
    "help - Shows this message.",
    "exit - Exits the shell."
};

static void printUser();
static void parseCommand(char * command, char * args[]);
static void fillCommandAndArgs(char * args[], char * input);

static char * username;

void shell() {
    if(username == NULL) {
        // Default username
        setUsername("user");
    }

    // Main loop
    while(1) {
        printUser();
        fgets(input, MAX_COMMAND_SIZE);
        parseCommand(input, args);
    }
}

void setUsername(char * user) {
    username = user;
}

static void fillCommandAndArgs(char * args[], char * command, char * input) {
    int inputIndex = 0;
    for(int i = 0; i < MAX_ARGS; i++) {

    }
}

static void printUser() {
    printf("%s@os:>$ ", username);
}