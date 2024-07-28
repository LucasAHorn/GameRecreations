// This will hold the entire game of life

// commands for running
    // cd C:/Users/Lucas/Documents/GitHub/GameRecreations
    // gcc GameOfLife.c -o GameOfLife
    // ./GameOfLife


#include <stdio.h>

// these store the width and height of the grid
int width;
int height;

// this prints the grid
void printGrid(int grid[width][height]) {
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf(" %d ", grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

void printCoords(int grid[width][height]) {
    printf("\n");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // printf(" %d ", grid[x][y]);
            printf("\t%d,%d,%d", x, y, grid[x][y]);
        }
        printf("\n");
    }
    printf("\n");
    printGrid(grid);
}

// this updates the grid
void updateGrid(int grid[width][height]){

    // calculating dead and alive cells
    int newGrid[width][height]; 
    int neighbors;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            neighbors = 0;

            // check left
            if (x > 0) {
                if (grid[x - 1][y] == 1) {neighbors++;}
                if ((y > 0) && (grid[x - 1][y - 1] == 1)) {neighbors++;}
                if ((y < height - 1) && (grid[x - 1][y + 1] == 1)) {neighbors++;}
            }
            // check right
            if (x < width - 1) {
                if (grid[x + 1][y] == 1) {neighbors++;}
                if ((y > 0) && (grid[x + 1][y - 1] == 1)) {neighbors++;}
                if ((y < height - 1) && (grid[x + 1][y + 1] == 1)) {neighbors++;}
            }
            // vertical
            if ((y > 0) && (grid[x][y - 1] == 1)) {neighbors++;}
            if ((y < height - 1) && (grid[x][y - 1] == 1)) {neighbors++;}


            // rules are found on playgameoflife.com/info
            if (grid[x][y] == 0) {
                if (neighbors <= 1) {
                    newGrid[x][y] = 0;
                } else if (neighbors <= 3) {
                    newGrid[x][y] = 1;
                } else {
                    newGrid[x][y] = 0;
                }
            } else {
                if (neighbors = 3) {
                    newGrid[x][y] = 1;
                } else {
                    newGrid[x][y] = 0;
                }
            }
        }
    }
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            grid[x][y] = newGrid[x][y];
        }
    }
}

// This checks if the grid is empty
int isEmptyGrid(int grid[width][height]) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (grid[x][y] == 1) {return 0;}
        }
    }
    return 1;
}



int main() {
    printf("\nSpecify number of columns and rows like 12x34, max values are 80x80\n\n");
    
    scanf("%dx%d", &width, &height);

    if ((height <= 0) || (height > 80) || (width <= 0) || (width > 80)) {
            printf("invalid dimensions: %d x %d", width, height);
            return -1;
        }

    printf("\ncreating a grid of dimensions: %d x %d\n", width, height);

    int grid[width][height];

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            grid[x][y] = 0;
        }
    }

    printGrid(grid);

    // user selects the sections 
    char selection;
    char endLoop;
    do {
        do {
            printf("\nYour options are:\n'a' - fill in a single grid square\n'b' - fill in a rectangle (multiple grid squares)\n'c' - fill in a column\n'd' - fill in a row\n");
            scanf(" %c", &selection);
        } while ((selection < 'a') || (selection > 'd'));

        printf("\n\nThe format of this grid is <x-coord>, <y-coord>, <is filled in>");
        printCoords(grid);


            // This portion is still unfinished
            // todo: finish filling in sections
        if (selection == 'a') {

        } else if (selection == 'b') {

        } else if (selection == 'c') {

        } else {

        }
        


        printf("respond 'y' if you would like to run the program: ");
        scanf(" %c", &endLoop);

    } while (endLoop != 'y');
    
    

    int tick = 0;
    do {
        updateGrid(grid);
        tick++;

        printf("tick %d", tick);
        printGrid(grid);
    } while (!isEmptyGrid(grid) || tick > 150);

    return 0;
}