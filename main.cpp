// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
// Environment
// Deterministic, sequential, static, discrete, known.
//
// Problem characterization
// IN(s) = board with walls randomly added.
// ACTIONS(s) = compute the shortest path based on the values (f,g,h and wall)
// of the 8 neighbouring cells.
// Transition Model: returns the board with the path currently computed
// Goal Test: a path between the initial cell and the goal is given
// Path Cost: take the minimum F value and move there. The final path must be
// the one that has the minimum F, or in the case that two possible paths have
// the same F, the minimum H.

#include "Agent.h"
#include "Cell.h"

#include <iostream>
#include <ctime>
#include <stdlib.h>

const int WIDTH = 50;
const int HEIGHT = 50;
Cell* board[HEIGHT][WIDTH];

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
        
        cout << "Step " << step++
        << " is: x:" << currentCell->getX()
        << ", y:" << currentCell->getY() << endl;
        
        cout << "g: " << currentCell->getG()
        << ", h: " << currentCell->getH()
        << ", f: " << currentCell->getF() << endl;
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

    // Keep adding a wall to a random position that is not a wall until we
    // reach zero.
    while (numberOfWalls > 0) {
        Cell *randomCell = board[randomInt(0, HEIGHT)][randomInt(0, WIDTH)];
        if (!randomCell->isWallCell()) {
            randomCell->setIsWall(true);
            numberOfWalls--;
        }
    }
}

void printTrajectories(char trajectories[WIDTH][HEIGHT]){
    std::cout << "TRAJECTORIES\n";
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (board[i][j]->isWallCell()) {
                std::cout << "X";
            } else {
                std::cout << trajectories[i][j];
            }
        }
        std::cout << std::endl;
    }
}

void initTrajectories(char trajectories[HEIGHT][WIDTH]){
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            trajectories[i][j] = '=';
        }
    }
}

void animateAgents(list<Cell*> agent1, list<Cell*> agent2, list<Cell*> agent3) {
    char trajectories[HEIGHT][WIDTH];
    initTrajectories(trajectories);

    list<Cell *>::iterator it1, it2, it3;
    it1 = agent1.begin();
    it2 = agent2.begin();
    it3 = agent3.begin();

    while (true) {
        Cell* agent1Pos = *it1;
        Cell* agent2Pos = *it2;
        Cell* agent3Pos = *it3;

        int x1, y1, x2, y2, x3, y3;

        if (it1 != agent1.end()) {
            x1 = agent1Pos->getX();
            y1 = agent1Pos->getY();
            trajectories[y1][x1] = 'A';
            it1++;
        } else {
            x1 = -1;
            y1 = -1;
        }

        if (it2 != agent2.end()) {
            x2 = agent2Pos->getX();
            y2 = agent2Pos->getY();
            
            // If x2, y2 equal x1, y1, do nothing and wait one turn.
            if (!(x2==x1 && y2 == y1)) {
                trajectories[y2][x2] = 'B';
                it2++;
            }
        } else {
            x2 = -1;
            y2 = -1;
        }

        if (it3 != agent3.end()) {
            x3 = agent3Pos->getX();
            y3 = agent3Pos->getY();
            if (!(x3==x1 && y3 == y1) && !(x3==x2 && y3 == y2)) {
                trajectories[y3][x3] = 'C';
                it3++;
            }
        } else {
            x3 = -1;
            y3 = -1;
        }

        if (it1 == agent1.end() && it2 == agent2.end() && it3 == agent3.end()) {
            break;
        }

        printTrajectories(trajectories);
    }
}


void Setup() {
    initializeBoard();
    addWalls();

    Cell* goalPosition = board[12][49];
    goalPosition->setIsWall(false);
    goalPosition->setIsGoal(true);

    Agent* agent1 = new Agent('a', board);
    Cell* startingPosition1 = board[5][0];
    startingPosition1->setG(0.0);
    startingPosition1->setH(0.0);
    startingPosition1->setF(0.0);

    Agent* agent2 = new Agent('b', board);
    Cell* startingPosition2 = board[24][0];
    startingPosition2->setG(0.0);
    startingPosition2->setH(0.0);
    startingPosition2->setF(0.0);

    Agent* agent3 = new Agent('c', board);
    Cell* startingPosition3 = board[35][0];
    startingPosition3->setG(0.0);
    startingPosition3->setH(0.0);
    startingPosition3->setF(0.0);


    list<Cell*> agent1solved = agent1->calculateShortestPath(startingPosition1);
    list<Cell*> agent2solved = agent2->calculateShortestPath(startingPosition2);
    list<Cell*> agent3solved = agent3->calculateShortestPath(startingPosition3);

    cout << "Agent 1 solved!: " << endl;
    showList(agent1solved);

    cout << "Agent 2 solved!: " << endl;
    showList(agent2solved);

    cout << "Agent 3 solved!: " << endl;
    showList(agent3solved);

    animateAgents(agent1solved, agent2solved, agent3solved);
}


int main() {
    srand((int) time(nullptr));
    Setup();
    return 0;
}
