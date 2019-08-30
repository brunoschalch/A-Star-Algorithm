//
// Created by bruno on 8/29/2019.
//

#include <iostream>
#include "Agent.h"

const int WIDTH = 50;
const int HEIGHT = 50;

list<Cell *> openList;
list<Cell *> closedList;
Cell **boardref[WIDTH][HEIGHT];
char id;

Agent::Agent(char name) {
    id = name;
}

// A* magic.
list<Cell *> Agent::calculateShortestPath(Cell *startingPosition) {
    std::cout << "Starting position: x:" << startingPosition->getX()
              << ", y:" << startingPosition->getY() << std::endl;
    return list<Cell *>();
}

void addToOpenList() {

}

void addToClosedList() {

}
