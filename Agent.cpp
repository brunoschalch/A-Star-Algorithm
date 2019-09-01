// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#include "Agent.h"

#include <iostream>

// TODO: create COPY of board!
Agent::Agent(char name) {
    id = name;
    //  boardref = board;
}

void addToOpenList(Cell *cell) {
    
}

void addToClosedList(Cell *cell) {
    
}

// Adds the new node to the open list and populates g,h and f for that node.
void discoverCell(Cell* parent, int x, int y) {
    Cell* cell = boardref[y][x];
    cell->setParent(parent);
    addToOpenList(cell);
    
    // g is g of parent + cost to move from parent to current cell (1 for vertical and horizontal, 1.4 for diagonal).
    // h is the cost to the goal if no walls existed.
    // f is g+h.
}


// Calls discoverCell for all neighbouring cells that are not walls, and are not in the open or closed list.
// If a neighbour is in the open list already, but its g (and f) value can be improved, update parent and values.
void discoverNeighbours(Cell* cell) {
    
}

// Gets the best candidate to keep going.
Cell* getBestCellFromOpenList() {
    // First we look for the lowest f value. In the case of a tie, the deciding factor is the lowest h number.
}

// Constructs a list with each node's parent until we reach the initial node.
list<Cell*> constructPath(Cell* finalNode) {
    
}

list<Cell*> aStar() {
    Cell* finalNode;
    
    while (true) {
        Cell* next = getBestCellFromOpenList();
        discoverNeighbours(next);
        addToClosedList(next);
        // if the node we just closed is the goal,
        // break the loop and walk back following the parents until we reach the start.
        if (next->isGoalCell()){
            finalNode = next;
            break;
        }
    }
    return constructPath(finalNode);
}

// A* magic.
list<Cell *> Agent::calculateShortestPath(Cell *startingPosition) {
    std::cout << "Starting position: x:" << startingPosition->getX()
    << ", y:" << startingPosition->getY() << std::endl;
    
    // We add startingPosition to the open list and run the algorithm.
    openList.push_back(startingPosition);
    
    return aStar();
}
