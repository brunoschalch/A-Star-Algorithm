#include <iostream>
#include <ctime>
#include "Cell.h"
#include "Agent.h"

const int WIDTH = 50;
const int HEIGHT = 50;
Cell* board[WIDTH][HEIGHT];

void printBoard() {
    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            if (board[y][x]->isWallCell()){
                std::cout << "X";
            } else {
                std::cout << "=";
           }
        }
        std::cout << '\n';
    }
}

int randomInt(int min, int max) {
    return (rand() % (max-min)) + min;
}

void initializeBoard(){
    for (int i=0; i<HEIGHT; i++) {
        for (int j=0; j<WIDTH; j++) {
            board[i][j] = new Cell(j,i);
        }
    }
}

// Adds between 500 and 800 walls at random positions.
void addWalls() {
    int numberOfWalls = randomInt(500,800);
    std::cout << "Number of walls: " << numberOfWalls << std::endl;
    // Keep adding a wall to a random position that is not a wall until we reach zero.
    while(numberOfWalls>0){
        Cell* randomCell = board[randomInt(0,HEIGHT)][randomInt(0,WIDTH)];
        if (!randomCell->isWallCell()) {
            randomCell->setIsWall(true);
            numberOfWalls--;
        }
    }
}

void Setup() {
    initializeBoard();
    addWalls();
    Agent* testAgent = new Agent('a');
    testAgent->calculateShortestPath(board[5][0]);
}

int main() {
    srand((int) time(nullptr));
    Setup();
    printBoard();
    return 0;
}