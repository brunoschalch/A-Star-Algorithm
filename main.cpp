// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
// Environment
//
// Problem characterization
//

#include "Agent.h"
#include "Cell.h"

#include <iostream>
#include <ctime>

const int WIDTH = 50;
const int HEIGHT = 50;
Cell *board[HEIGHT][WIDTH];

void printBoard() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (board[y][x]->isWallCell()) {
                // Walls are marked with an X.
                std::cout << "X";
            } else {
                std::cout << "=";
            }
        }
        std::cout << '\n';
    }
}

void showList(list<Cell *> g) {
    list<Cell *>::iterator it;
    int step = 0;
    for (it = g.begin(); it != g.end(); ++it) {
        Cell *currentCell = *it;
        cout << "Step " << step++ << " is: x:" << currentCell->getX() << ", y:" << currentCell->getY() << endl;
        cout << "g: " << currentCell->getG() << ", h: " << currentCell->getH() << ", f: " << currentCell->getF()
             << endl;
    }
    cout << '\n';
}

int randomInt(int min, int max) {
    return (rand() % (max - min)) + min;
}

void initializeBoard() {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = new Cell(j, i);
            board[i][j]->setIsGoal(false);
            board[i][j]->setIsWall(false);
        }
    }
}

// Adds between 500 and 800 walls at random positions.
void addWalls() {
    int numberOfWalls = randomInt(500, 800);
    std::cout << "Number of walls: " << numberOfWalls << std::endl;

    // Keep adding a wall to a random position that is not a wall until we reach zero.
    while (numberOfWalls > 0) {
        Cell *randomCell = board[randomInt(0, HEIGHT)][randomInt(0, WIDTH)];
        if (!randomCell->isWallCell()) {
            randomCell->setIsWall(true);
            numberOfWalls--;
        }
    }
}

void Setup() {
    initializeBoard();
    addWalls();

    Cell *goalPosition = board[5][10];
    goalPosition->setIsWall(false);
    goalPosition->setIsGoal(true);

    Agent *agent1 = new Agent('a', board);
    Cell *startingPosition = board[5][0];
    startingPosition->setG(0.0);
    startingPosition->setH(0.0);
    startingPosition->setF(0.0);
    list<Cell *> agent1solved = agent1->calculateShortestPath(startingPosition);

    Agent *agent2 = new Agent('b', board);
    Cell *startingPosition2 = board[17][0];
    startingPosition2->setG(0.0);
    startingPosition2->setH(0.0);
    startingPosition2->setF(0.0);
    list<Cell *> agent2solved = agent2->calculateShortestPath(startingPosition2);

    Agent *agent3 = new Agent('c', board);
    Cell *startingPosition3 = board[24][0];
    startingPosition3->setG(0.0);
    startingPosition3->setH(0.0);
    startingPosition3->setF(0.0);
    list<Cell *> agent3solved = agent3->calculateShortestPath(startingPosition3);

    cout << "Agent 1 solved!: " << endl;
    showList(agent1solved);

    cout << "Agent 2 solved!: " << endl;
    showList(agent2solved);

    cout << "Agent 3 solved!: " << endl;
    showList(agent3solved);
}

int main() {
    srand((int) time(nullptr));
    Setup();
    // printBoard();
    return 0;
}
