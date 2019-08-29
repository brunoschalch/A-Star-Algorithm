#include <iostream>
#include <ctime>
#include "Cell.h"

const int WIDTH = 50;
const int HEIGHT = 50;
Cell board[WIDTH][HEIGHT];

void printBoard() {
    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            if (board[y][x].isWallCell()){
                std::cout << "X";
            } else {
                std::cout << "=";
           }
        }
        std::cout << '\n';
    }
}

// Inclusive max.
int randomInt(int min, int max) {
    return (rand() % (max-min)) + min;;
}

// Adds between 500 and 800 walls at random positions.
void addWalls() {
    int numberOfWalls = randomInt(500,800);
    std::cout << "Number of walls: " << numberOfWalls << std::endl;
    // Keep adding a wall to a random position that is not a wall until we reach zero.
    while(numberOfWalls>0){
        Cell* randomCell = &board[randomInt(0,HEIGHT-1)][randomInt(0,WIDTH-1)];
        if (!randomCell->isWallCell()) {
            randomCell->setIsWall(true);
            numberOfWalls--;
        }
    }
}

void

int main() {
    srand((int) time(0));

    addWalls();
    printBoard();

    return 0;
}