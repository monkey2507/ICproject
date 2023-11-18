#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[100];
int snakes[5][2];
int ladders[5][2];

int rollDice(){
    return rand()%6 + 1;
}

void displayBoard(){
    //isme vo graphic interface wala sabkuchh ayega
}

int main(){
    srand(time(0));
    int player1 = 0;
    int player2 = 0;
    int currentplayer = 1;
    snakes[0][0] = 99; snakes[0][1] = 77;
    snakes[1][0] = 24; snakes[1][1] = 8;
    snakes[2][0] = 62; snakes[2][1] = 18;
    snakes[3][0] = 69; snakes[4][1] = 33;
    snakes[4][0] = 93; snakes[4][1] = 73;
    ladders[0][0] = 71; ladders[0][1] = 91;
    ladders[1][0] = 28; ladders[1][1] = 65;
    ladders[2][0] = 21; ladders[2][1] = 42;
    ladders[3][0] = 9; ladders[3][1] = 31;
    ladders[4][0] = 78; ladders[4][1] = 84;

    for(int i=1; i<=100; i++){
        board[i] = i;
    }
    for(int i=0; i<5; i++){
        board[snakes[i][0]] = snakes[i][1];
    }
    for(int i=0; i<5; i++){
        board[ladders[i][0]] = ladders[i][1];
    }

    while(player1 < 100 && player2 < 100){
        int dice = rollDice();
        if(currentplayer%2 == 1){
            if(player1 + dice <= 100){
                player1 += dice;
            }
            currentplayer++;
        }
        else if(currentplayer%2 == 0){
            if(player2 + dice <= 100){
                player2 += dice;
            }
            currentplayer++;
        }
        if (board[player1] > 0) {
            player1 = board[player1];
        }
        if (board[player2] > 0) {
            player2 = board[player2];
        }
        displayBoard();
    }

    if(player1 == 100){
        printf("Player 1 Wins!!\n");
    }
    if(player2 == 100){
        printf("Player 2 Wins!!\n");
    }
    return 0;
}