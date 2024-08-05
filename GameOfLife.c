// This will hold the entire game of life

// commands for running
    // cd C:/Users/Lucas/Documents/GitHub/GameRecreations
    // gcc GameOfLife.c -o GameOfLife
    // ./GameOfLife


#include <stdio.h>
#include <string.h>

// these store the WIDTH and HEIGHT of the grid
int WIDTH;
int HEIGHT;

// this prints the grid
void printGrid(int grid[WIDTH][HEIGHT]) {
    char str[WIDTH * 3 + 1];
    memset(str, '-', WIDTH * 3);
    str[WIDTH * 3] = '\0';

    printf("\n|%s|\n|", str);
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[x][y]) {
                printf(" X ");
            } else {
                printf("   ");
            }
        }
        printf("|\n|");
    }
    printf("%s|\n", str);
}

// This returns the board printed with coords and if it is filled in
void printCoords(int grid[WIDTH][HEIGHT]) {
    printf("\n");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // printf(" %d ", grid[x][y]);
            printf("\t%d,%d,%d", x, y, grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

// makes grid[x][y] = 1 returns 1 if successful, 0 if failed
int makeLivingCell(int grid[WIDTH][HEIGHT], int x, int y) {
    if ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT)){
        grid[x][y] = 1;
        return 1;
    }
    return 0;
}

// this updates the grid
void updateGrid(int grid[WIDTH][HEIGHT]){

    // calculating dead and alive cells
    int newGrid[WIDTH][HEIGHT];
    int neighbors;

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            neighbors = 0;

            // check left
            if (x > 0) {
                if (grid[x - 1][y] == 1) {neighbors++;}
                if ((y > 0) && (grid[x - 1][y - 1] == 1)) {neighbors++;}
                if ((y < HEIGHT - 1) && (grid[x - 1][y + 1] == 1)) {neighbors++;}
            }
            // check right
            if (x < WIDTH - 1) {
                if (grid[x + 1][y] == 1) {neighbors++;}
                if ((y > 0) && (grid[x + 1][y - 1] == 1)) {neighbors++;}
                if ((y < HEIGHT - 1) && (grid[x + 1][y + 1] == 1)) {neighbors++;}
            }
            // vertical
            if ((y > 0) && (grid[x][y - 1] == 1)) {neighbors++;}
            if ((y < HEIGHT - 1) && (grid[x][y + 1] == 1)) {neighbors++;}


            // rules are found on playgameoflife.com/info
            if (grid[x][y] == 1) {
                if (neighbors <= 1) {
                    newGrid[x][y] = 0;
                } else if (neighbors <= 3) {
                    newGrid[x][y] = 1;
                } else {
                    newGrid[x][y] = 0;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[x][y] = 1;
                } else {
                    newGrid[x][y] = 0;
                }
            }
        }
    }
    
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            grid[x][y] = newGrid[x][y];
        }
    }
}

// This checks if the grid is empty
int isEmptyGrid(int grid[WIDTH][HEIGHT]) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (grid[x][y] == 1) {return 0;}
        }
    }
    return 1;
}


int main() {
    printf("\nSpecify number of columns and rows like 12x34, max values are 80x80\n\n");
    
    scanf("%dx%d", &WIDTH, &HEIGHT);

    if ((HEIGHT <= 0) || (HEIGHT > 80) || (WIDTH <= 0) || (WIDTH > 80)) {
            printf("invalid dimensions: %d x %d", WIDTH, HEIGHT);
            return -1;
        }

    printf("\ncreating a grid of dimensions: %d x %d\n", WIDTH, HEIGHT);

    int grid[WIDTH][HEIGHT];

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            grid[x][y] = 0;
        }
    }

    printGrid(grid);

    // user selects the sections 
    char selection;
    do {
        do {
            printf("\nYour options are:\n'a' - fill in a single grid square\n'b' - fill in a rectangle (multiple grid squares)\n'c' - fill in a column\n'd' - fill in a row\n'r' - run the program\nyour selection: ");
            scanf(" %c", &selection);
        } while (((selection < 'a') || (selection > 'd')) && (selection != 'r'));

        if (selection == 'r') {break;}

        printf("\n\nThe format of this grid is <x-coord>, <y-coord>, <is filled in>");
        printCoords(grid);

        // coords for the questions
        int x;
        int y;
            // This portion is still unfinished
            // todo: finish filling in sectionssea
        if (selection == 'a') {         // single square
            printf("\nWhat coordinate would you like to fill in? (Format: 12x13\nCoordinate: ");
            scanf(" %dx%d", &x, &y);
            
            if (makeLivingCell(grid, x, y)) {
                printf("\nSuccess at selecting cell\n");
            } else {
                printf("\nFailed to make living cell at: (%d, %d)", x, y);
            }



        } else if (selection == 'b') {  // rectangle (multiple)
            int x1;
            int y1;
            printf("\nWhat coordinates would you like to fill in? (format: 12x13)\nTop left corner: ");
            scanf(" %dx%d", &x, &y);

            printf("\nBottom right corner: ");
            scanf(" %dx%d", &x1, &y1);

            for (int i = x; i <= x1; i++){
                for (int j = y; j <= y1; j++) {
                    makeLivingCell(grid, i, j);
                }
            }

            
        } else if (selection == 'c') {  // column
            printf("\nWhat column would you like to fill in? x-coord: ");
            
            scanf(" %d", &x);
            for (y = 0; y < HEIGHT; y++) {
                makeLivingCell(grid, x, y);
            }

        } else {                        // row
            printf("\nWhat row would you like to fill in? y-coord: ");

            scanf(" %d", &y);
            for (x = 0; x < WIDTH; x++) {
                makeLivingCell(grid, x, y);
            }
        }

        printGrid(grid);
    } while (1);    // goes until the break statement
    
    int maxTicks;
    printf("Max ticks sumulated: ");
    scanf(" %d", &maxTicks);

    printGrid(grid);
    int tick = 0;
    do {
        updateGrid(grid);
        tick++;

        printf("tick %d", tick);
        printGrid(grid);

        for (long i = 0; i < 500000000; i++);
    } while ((!isEmptyGrid(grid)) && (tick < maxTicks));

    return 0;
}