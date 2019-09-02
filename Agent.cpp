// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#include "Agent.h"

#include <float.h>
#include <iostream>

Agent::Agent(char name, Cell* board[WIDTH][HEIGHT]) {
    id = name;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
}

void Agent::addToOpenList(Cell* cell) {
    openList.push_back(cell);
}

void Agent::addToClosedList(Cell* cell) {
    closedList.push_back(cell);
}

// Adds the new node to the open list and populates g,h and f for that node.
void Agent::discoverCell(Cell* parent, int x, int y) {
    Cell* cell = boardCopy[y][x];
    cell->setParent(parent);
    addToOpenList(cell);
    
    // g is g of parent + cost to move from parent to current cell (1 for
    // vertical and horizontal, 1.4 for diagonal).
    float g = parent->getG();
    cell->setG(g);
    
    // h is the cost to the goal if no walls existed.
    float h = 0.0f;
    
    cell->setH(h);
    
    // f is g + h.
    cell->setF(g + h);
}


// Calls discoverCell for all neighbouring cells that are not walls, and are not
// in the open or closed list. If a neighbour is in the open list already, but
// its g (and f) value can be improved, update parent and values.
void discoverNeighbours(Cell* cell) {
    
}

// Gets the best candidate to keep going.
Cell* Agent::getBestCellFromOpenList() {
    // First, we look for the lowest f value. In the case of a tie, the deciding
    // factor is the lowest h number.
    float minF = FLT_MAX;
    float minH = FLT_MAX;
    Cell* bestCell = nullptr;
    
    list<Cell*>::iterator it;
    
    for (it = openList.begin(); it != openList.end(); ++it) {
        Cell* cell = *it;
        float f = cell->getF();
        float h = cell->getH();
        
        if ((f < minF) || (f == minF && h < minH)) {
            minF = f;
            minH = h;
            bestCell = cell;
        }
    }
    return bestCell;
}

// Constructs a list with each node's parent until we reach the initial node.
list<Cell*> constructPath(Cell* finalNode) {
    list<Cell*> list;
    return list;
}

list<Cell*> Agent::aStar() {
    Cell* finalNode;
    
    while (true) {
        Cell* next = getBestCellFromOpenList();
        discoverNeighbours(next);
        addToClosedList(next);
        
        // If the node we just closed is the goal, break the loop and walk back
        // following the parents until we reach the start.
        if (next->isGoalCell()){
            finalNode = next;
            break;
        }
    }
    return constructPath(finalNode);
}

// A* magic.
list<Cell*> Agent::calculateShortestPath(Cell* startingPosition) {
    // Printing the starting position.
    cout << "Starting position: x:" << startingPosition->getX()
    << ", y:" << startingPosition->getY() << endl;
    
    // We add startingPosition to the open list and run the algorithm.
    addToOpenList(startingPosition);
    
    discoverNeighbours(startingPosition);
    
    //return aStar();
    list<Cell*> list;
    return list;
}
