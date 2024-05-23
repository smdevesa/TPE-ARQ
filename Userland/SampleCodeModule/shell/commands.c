//
// Created by Santiago Devesa on 22/05/2024.
//

#include <commands.h>
#include <iolib.h>
#include <string.h>
#include <time.h>

#define HELP_IDX 0
#define CLEAR_IDX 1
#define EXIT_IDX 2

#define COMMAND_SECONDARY_COLOR 0x00F5ED51

static char * commands[][2] = {
        {"help", "Shows the available commands."},
        {"clear", "Clears the screen."},
        {"exit", "Exits the shell."},
        {"time", "Shows the current time."}
};

#define COMMANDS_COUNT (sizeof(commands) / sizeof(commands[0]))

static int helpCommand(int argc, char * argv[]);
static int clearCommand(int argc, char * argv[]);
static int exitCommand(int argc, char * argv[]);
static int timeCommand(int argc, char * argv[]);
static int fillCommandAndArgs(char ** command, char * args[], char * input);
static char * readToBlank(char * input);

static int (*commandFunctions[])(int argc, char * argv[]) = {
        helpCommand,
        clearCommand,
        exitCommand,
        timeCommand
};

static int helpCommand(int argc, char * argv[]) {
    for(int i=0; i<COMMANDS_COUNT; i++) {
        printStringColor(commands[i][0], COMMAND_SECONDARY_COLOR);
        printf(": %s\n", commands[i][1]);
    }
    return OK;
}

static int clearCommand(int argc, char * argv[]) {
    clearScreen();
    return OK;
}

static int exitCommand(int argc, char * argv[]) {
    return EXIT;
}

static int timeCommand(int argc, char * argv[]) {
    printStringColor("Current time: ", COMMAND_SECONDARY_COLOR);
    printf("%d/%d/%d %d:%d:%d\n", getDay(), getMonth(), getYear(), getHours(), getMinutes(), getSeconds());
    return OK;
}

int parseCommand(char * input) {
    if(input == NULL) {
        return INPUT_ERROR;
    }

    char * args[MAX_ARGS] = {0};
    char * command;

    int argsCount = fillCommandAndArgs(&command, args, input);
    if(argsCount == INPUT_ERROR) {
        return INPUT_ERROR;
    }

    for(int i=0; i<COMMANDS_COUNT; i++) {
        if(strcmp(command, commands[i][0]) == 0) {
            return commandFunctions[i](argsCount, args);
        }
    }
    return INPUT_ERROR;
}

static int fillCommandAndArgs(char ** command, char * args[], char * input) {
    int argsCount = 0;
    char *current = input;

    *command = current;

    while (*current != 0 && argsCount < MAX_ARGS) {
        // Remove blanks
        if (*current == ' ') {
            *current = 0;
            args[argsCount++] = current + 1;
        }
        current++;
    }
    printf("Command: %s\n", *command);
    for(int i=0; i<argsCount; i++) {
        printf("Arg %d: %s\n", i, args[i]);
    }
    return argsCount;
}

