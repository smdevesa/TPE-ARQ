//
// Created by Santiago Devesa on 24/05/2024.
//

#include <eliminator.h>
#include <iolib.h>
#include <color.h>

static int numOfPlayers;

static void startScreen();
static int getNumOfPlayers();

int eliminator() {
    startScreen();

    //clearScreen();
    return 1;
}

static void startScreen() {
    clearScreen();
    puts("Welcome to the Eliminator Game!");
    numOfPlayers = getNumOfPlayers();
    
}

int getNumOfPlayers() {
    char c;
    while(c != '1' || c != '2') {
        puts("Choose number of players: 1 or 2");
        c = getchar();
        if(c == '1') {
            return 1;
        }
        else if(c == '2') {
            return 2;
        }
        puts("Number of players must be between 1 and 2");
    }
}