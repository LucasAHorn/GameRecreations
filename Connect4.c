// below are the commands to run the file:
    // cd C:/Users/Lucas/Documents/GitHub/GameRecreations
    // gcc Connect4.c -o Connect4.exe
    // ./Connect4.exe

#include <stdio.h>

    const int COLS = 7;

    const int ROWS = 6;

    char board[7][6];

    // this prints the current board
void printBoard() {
    char str[17];
    printf("\n\n\t\t 0 1 2 3 4 5 6 \n");
    for (int y = 5; y >= 0; y--) {
        for (int x = 0; x < 7; x++) {
            str[x * 2] = board[x][y];
            str[(x * 2) + 1] = '|';
        }
        printf("\t\t|%s\n", str);
    }
}


// this checks for a completed game, requiring the coordinates of the last piece
int unfinishedGame(int xCoord, int yCoord) {

    int runLength = 1;
    char c = board[xCoord][yCoord];
    int y;
    int x;

    // horizontal
    for (x = xCoord + 1; (x < COLS); x++) {
        if (board[x][yCoord] != c) {break;}
        runLength++;
    }
    for (x = xCoord - 1; (x >= 0); x--) {
        if (board[x][yCoord] != c) {break;}
        runLength++;
    }
    if (runLength >= 4) {return 0;}
    runLength = 1;

    // vertical
    for (y = yCoord + 1; (y < ROWS); y++) {
        if (board[xCoord][y] != c) {break;}
        runLength++;
    }
    for (y = yCoord - 1; (y >= 0); y--) {
        if (board[xCoord][y] != c) {break;}
        runLength++;
    }
    if (runLength >= 4) {return 0;}
    runLength = 1;

    // diagonal north east
    y = yCoord + 1;
    for (x = xCoord + 1; ((x < COLS) && (y < ROWS)); x++) {
        if (board[x][y] != c) {break;}
        runLength++;
        y++;
    }
    y = yCoord - 1;
    for (x = xCoord - 1; ((x >= 0) && (y >= 0)); x--) {
        if (board[x][y] != c) {break;}
        runLength++;
        y--;
    }
    if (runLength >= 4) {return 0;}
    runLength = 1;

    // diagonal south east
    y = yCoord - 1;
    for (x = xCoord + 1; ((x < COLS) && (y >= 0)); x++) {
        if (board[x][y] != c) {break;}
        runLength++;
        y--;
    }
    y = yCoord + 1;
    for (x = xCoord - 1; ((x >= 0) && (y < COLS)); x--) {
        if (board[x][y] != c) {break;}
        runLength++;
        y++;
    }
    if (runLength >= 4) {return 0;}

    // top row
    if ((board[0][5] != ' ') && (board[1][5] != ' ') && (board[2][5] != ' ') && (board[3][5] != ' ') && (board[4][5] != ' ') && (board[5][5] != ' ') && (board[6][5] != ' ')) {
        return 0;
    }
    return 1;
}

// this simulates a turn of a player
int takeTurn(char c) {

    printBoard();

    int columnSelected = -1;

    do {

    printf("\n\n\t\t%c selected column: ", c);
    scanf(" %d", &columnSelected);

    // checks for full column
    if (board[columnSelected][ROWS - 1] != ' ') {columnSelected = -1;}
    } while ((columnSelected < 0) || (columnSelected >= COLS));

    // this places the piece
    for (int i = 0; i < ROWS; i++) {
        if (board[columnSelected][i] == ' ') {
            board[columnSelected][i] = c;
            return unfinishedGame(columnSelected, i);
        }
    }
    return 0;
}


int main() {

    // board setup
    for (int y = 0; y < 6; y++) {
        for (int x = 0; x < 7; x++) {
            board[x][y] = ' ';
        }
    }

    // game running
    while (takeTurn('O') && takeTurn('X'));

    // game ended
    printBoard();
    if ((board[0][5] != ' ') && (board[1][5] != ' ') && (board[2][5] != ' ') && (board[3][5] != ' ') && (board[4][5] != ' ') && (board[5][5] != ' ') && (board[6][5] != ' ')) {
        printf("\n\n\t\tNo winners :/\n\n");
    } else {
        printf("\n\n\t\tWE HAVE A WINNER!!!!!!\n\n");
    }

    return 0;
}