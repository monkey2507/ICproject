#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int board[100];
int snakes[5][2];
int ladders[5][2];

int rollDice(){
    return rand()%6 + 1;
}

int rollDice90(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 5;
    }
    if(a>40 && a<=45){
        return 6;
    }
    if(a>45 && a<=60){
        return 2;
    }
    if(a>60 && a<=70){
        return 3;
    }
    if(a>70 && a<=80){
        return 1;
    }
    if(a>80 && a<=90){
        return 4;
    }
}


int rollDice94(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 5;
    }
    if(a>40 && a<=45){
        return 6;
    }
    if(a>45 && a<=60){
        return 2;
    }
    if(a>60 && a<=70){
        return 3;
    }
    if(a>70 && a<=80){
        return 1;
    }
    if(a>80 && a<=90){
        return 4;
    }
}

int rollDice95(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 4;
    }
    if(a>40 && a<=45){
        return 5;
    }
    if(a>45 && a<=60){
        return 2;
    }
    if(a>60 && a<=70){
        return 3;
    }
    if(a>70 && a<=80){
        return 1;
    }
    if(a>80 && a<=90){
        return 6;
    }
}

int rollDice96(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 3;
    }
    if(a>40 && a<=45){
        return 4;
    }
    if(a>45 && a<=60){
        return 2;
    }
    if(a>60 && a<=70){
        return 6;
    }
    if(a>70 && a<=80){
        return 1;
    }
    if(a>80 && a<=90){
        return 5;
    }
}

int rollDice97(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 2;
    }
    if(a>40 && a<=45){
        return 3;
    }
    if(a>45 && a<=60){
        return 6;
    }
    if(a>60 && a<=70){
        return 5;
    }
    if(a>70 && a<=80){
        return 1;
    }
    if(a>80 && a<=90){
        return 4;
    }
}

int rollDice98(){
    int a = rand()%90 + 1;
    if(a>0 && a<=40){
        return 1;
    }
    if(a>40 && a<=45){
        return 2;
    }
    if(a>45 && a<=60){
        return 5;
    }
    if(a>60 && a<=70){
        return 3;
    }
    if(a>70 && a<=80){
        return 6;
    }
    if(a>80 && a<=90){
        return 4;
    }
}


void displayBoard(int player1,int player2){
    printf("\n");
    for (int row = 10; row >= 1; row--) {
        for (int col = 1; col <= 10; col++) {
            int cell = (row % 2 == 0) ? (row - 1) * 10 + col : (row - 1) * 10 + 10 - col + 1;

            
            char symbol[2];
            symbol[0] = ' ';
            for (int i = 0; i < 5; i++) {
                if (snakes[i][0] == cell) {
                    symbol[0] = 'S';
                    symbol[1] = i+1;
                } 
                else if (ladders[i][0] == cell) {
                    symbol[0] = 'L';
                    symbol[1] = i+1;
                }
                else if(snakes[i][1] == cell){
                    symbol[0] = 's';
                    symbol[1] = i+1;
                }
                else if(ladders[i][1] == cell){
                    symbol[0] = 'l';
                    symbol[1] = i+1;   
                }
            }

            if (player1 == cell) {
                printf(" P1 ");
            } else if (player2 == cell) {
                printf(" P2 ");
            } else if (symbol[0] != ' ') {
                printf(" %c%c ", symbol[0], symbol[1]);
            } else {
                printf(" %2d ", board[cell]);
            }

            if (col < 10) {
                printf("|");
            }
        }
        printf("\n");

        if (row > 1) {
            for (int col = 1; col <= 10; col++) {
                printf("----");
                if (col < 10) {
                    printf("+");
                }
            }
            printf("\n");
        }
    }
    printf("\n");
}

void initialiseBoard(){
    int x=0,y=0; 
    displayBoard(x,y);
} 

int main(){
    srand(time(0));
    char name1[50], name2[50];
    printf("Enter the name of player 1: ");
    scanf("%s", name1);
    printf("Enter the name of player 2: ");
    scanf("%s", name2);
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
    initialiseBoard();
    getchar();
    printf("%s's turn, press enter to roll the die.\n",name1);
    while(player1 < 100 && player2 < 100){
        getchar();

        int dice = rollDice();
        int check =0;
        if(check == 0 && currentplayer%2 == 1 && player1 == 0){
            if(dice == 6){
                player1 += 1;
                printf("%s rolled a %d\n", name1, dice);
                printf("Yay!!\n");
                displayBoard(player1, player2);
            }
            else{
                printf("%s rolled a %d\n", name1, dice);
                printf("Roll 6 to enter the game\n");
            }  
            currentplayer++;
            check = 1;
        }
        if(player1 != 0){
            if(currentplayer%2 == 1){
                if(player1 + dice <= 100){
                    player1 += dice;
                }
                printf("%s rolled a %d\n",name1, dice);
                currentplayer++;

                if (board[player1] > 0){
                player1 = board[player1];
                }

                displayBoard(player1, player2);
                printf("%s press enter to roll the die\n", name2);
            }
        }
        if(check == 0 && currentplayer%2 == 0 && player2 == 0){
            if(dice == 6){
                player2 += 1;
                printf("%s rolled a %d\n", name2, dice);
                printf("Yay!!\n");
                displayBoard(player1, player2);
            }
            else{
                printf("%s rolled a %d\n", name2, dice);
                printf("Roll 6 to enter the game\n");
            }   
            currentplayer++;
            check = 1;
        }
        if(player2 != 0){
            if(currentplayer%2 == 0){
                if(player2 + dice <= 100){
                    player2 += dice;
                }
                printf("%s rolled a %d\n", name2, dice);
                currentplayer++;

                if (board[player2] > 0) {
                player2 = board[player2];
                }

                displayBoard(player1, player2);
                printf("%s press enter to roll the die\n", name1);
            }
        }
    }

    if(player1 == 100){
        printf("%s Wins!!\n", name1);
    }
    if(player2 == 100){
        printf("%s Wins!!\n", name2);
    }
    return 0;
}
