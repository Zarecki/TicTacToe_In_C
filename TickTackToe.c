#include <stdio.h>
#include <stdlib.h>

// #define P1 'X'
// #define P2 'O'

void runGame(void);
void markBoard(char board[9], char active);
void drawBoard(char board[9]);
int checkWin(char board[9], char active);
int checkDraw(char board[9]);
int checkColumn(char board[9], char active);
int checkRow(char board[9], char active);
int checkDiagonal(char board[9], char active);
int validate(int selection);
void setSelection(char board[9], char selection);
char changeActivePlayer(char player);

void drawBoard(char board[9]){
    printf("Player one is X, Player 2 is O\n");
    printf("Please type your selected number and hit return\n\n");
    printf("----------------\n");
    printf("| %c | %c | %c |\n", board[0], board[1], board[2]);
    printf("----------------\n");
    printf("| %c | %c | %c |\n", board[3], board[4], board[5]);
    printf("----------------\n");
    printf("| %c | %c | %c |\n", board[6], board[7], board[8]);
    printf("----------------\n\n");
}

void markBoard(char board[9], char active){
    char selection = '\0';
    int isValid = 0;
    printf("your choice: \n");
    scanf(" %1c", &selection);
    int selectionToInt = ((int)(selection) - 48);
    isValid = validate(selectionToInt);

    while (isValid != 1){
        printf("This selection was invalid. Try again: \n");
        scanf(" %1c", &selection);
        int selectionToInt = ((int)(selection) - 48);
        isValid = validate(selectionToInt);
    }

    board[(selectionToInt-1)] = active;
}

int validate(int selection){
    if (selection < 1 || selection > 9){
        return 0;
    }
    return 1;
}

int checkRow(char board[9], char active){
    if(board[0] == active && board[1] == active && board[2] == active){
        return 1;
    }
    else if (board[3] == active && board[4] == active && board[5] == active){
        return 1;
    }
    else if (board[6] == active && board[7] == active && board[8] == active){
        return 1;
    }

    return 0;
}

int checkColumn(char board[9], char active){
    if(board[0] == active && board[3] == active && board[6] == active){
        return 1;
    }
    else if (board[1] == active && board[4] == active && board[7] == active){
        return 1;
    }
    else if (board[2] == active && board[5] == active && board[8] == active){
        return 1;
    }

    return 0;
}

int checkDiagonal(char board[9], char active){
    if(board[0] == active && board[4] == active && board[8] == active){
        return 1;
    }
    else if (board[2] == active && board[4] == active && board[6] == active){
        return 1;
    }

    return 0;
}

int checkWin(char board[9], char active){
    int rowWin = checkRow(board, active);
    int columnWin = checkColumn(board, active);
    int diagonalWin = checkDiagonal(board, active);
    if (rowWin == 1 | columnWin == 1 | diagonalWin == 1){
        return 1;
    }
    return 0;
}

int checkDraw(char board[9]){
    int isDraw = 1;
    for(int i = 0; i < 9; i++){
        if (board[i] != 'X' || board[i] != 'O'){
            isDraw = 0;
        }
    }
    return isDraw;
}

char changeActivePlayer(char player){
    if (player == 'X'){
        return 'O';
    }
    return 'X';
}

void rungame(){
    char gameBoard[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char activePlayer = 'O';
    int win = 0;
    int draw = 0;

    while (win == 0 && draw == 0){
        activePlayer = changeActivePlayer(activePlayer);
        drawBoard(gameBoard);
        markBoard(gameBoard, activePlayer);
        win = checkWin(gameBoard, activePlayer);
        draw = checkDraw(gameBoard);
    };

    drawBoard(gameBoard);
    if (activePlayer == 'X'){
        printf("THE WINNER IS PLAYER 1!!\n");
    } else {
        printf("THE WINNER IS PLAYER 2!!\n");
    }
}

int main(int argc, char *argv[]){
    rungame();

    return 0;
}