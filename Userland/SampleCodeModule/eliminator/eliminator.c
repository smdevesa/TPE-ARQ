//
// Created by Santiago Devesa on 24/05/2024.
//

#include <eliminator.h>
#include <iolib.h>
#include <color.h>
#define SNAKE_COLOR_AMOUNT 4

static int numOfPlayers;
static uint32_t boardColor; 
static uint32_t snakeColor1; 
static uint32_t snakeColor2;   

static uint32_t setSnakeColor(uint32_t other);
static uint32_t snakeColors[SNAKE_COLOR_AMOUNT] = {RED, GREEN, BLUE, YELLOW};

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
    boardColor = getBoardColor();
    snakeColor1 = setSnakeColor(0);
    snakeColor2 = setSnakeColor(snakeColor1);
    
    
}



static uint32_t setSnakeColor(uint32_t other){
    char c; 
    printf("Choose snake color"); 
    if(other != 0){
        puts(" for Player 2:"); 
    }
    else{
        puts(" for Player 1:"); 
    }
    for(int i = 0; i < SNAKE_COLOR_AMOUNT; i++){
        printf("%d.", i+1);
    }
}


uint32_t getBoardColor(){
    char c; 
    puts("Choose board color:\n1. Black\n2. White");
    while(c != '1' || c != '2') {
        c = getchar();
        if(c == '1') {
            return BLACK;
        }
        else if(c == '2') {
            return WHITE;
        }
        
    }

}
static int getNumOfPlayers() {
    char c;
    puts("Choose number of players: 1 or 2");
    while(c != '1' || c != '2') {
        c = getchar();
        if(c == '1') {
            return 1;
        }
        else if(c == '2') {
            return 2;
        }
    }
}