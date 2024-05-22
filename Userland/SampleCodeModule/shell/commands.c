//
// Created by Santiago Devesa on 22/05/2024.
//

#include <commands.h>
#include <iolib.h>
#include <string.h>

#define HELP_IDX 0
#define CLEAR_IDX 1
#define EXIT_IDX 2

static char * commands[][2] = {
        {"help", "Shows the available commands."},
        {"clear", "Clears the screen."},
        {"exit", "Exits the shell."}
};

#define COMMANDS_COUNT (sizeof(commands) / sizeof(commands[0]))

static int helpCommand(int argc, char * argv[]);
static int clearCommand(int argc, char * argv[]);
static int exitCommand(int argc, char * argv[]);
static int fillCommandAndArgs(char ** command, char * args[], char * input);
static char * readToBlank(char * input);

static int (*commandFunctions[])(int argc, char * argv[]) = {
        helpCommand,
        clearCommand,
        exitCommand
};

static int helpCommand(int argc, char * argv[]) {
    for(int i=0; i<COMMANDS_COUNT; i++) {
        printf("%s: %s\n", commands[i][0], commands[i][1]);
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

int parseCommand(char * input) {
    if(input == NULL) {
        return INPUT_ERROR;
    }

    char * args[MAX_ARGS];
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
    char * index;
    char * lastIndex = input;

    index = readToBlank(input);
    *index = 0;
    *command = lastIndex;
    printf("Command: %s\n", *command);
    index++;
    lastIndex = index;

    while(argsCount < MAX_ARGS && (index = readToBlank(index)) != lastIndex) {
        *index = 0;
        args[argsCount] = lastIndex;
        argsCount++;
        index++;
        lastIndex = index;
        printf("Argv [%d]: %s\n", argsCount, args[argsCount-1]);
    }

    return argsCount;
}

static char * readToBlank(char * input) {
    int i = 0;
    while(input[i] != 0 && input[i] != ' ' && input[i] != '\n') {
        input++;
    }
    return input;
}

