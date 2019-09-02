// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#include "Agent.h"

#include <float.h>
#include <iostream>
#include <cmath>

//function for printing the elements in a list
void Agent::showList(list<Cell *> g) {
    list<Cell *>::iterator it;
    cout << "showing list:";
    for (it = g.begin(); it != g.end(); ++it) {
        Cell *cell = *it;
        cout << "\tx: " << cell->getX() << ", y: " << cell->getY();
    }
    cout << '\n';
}

void Agent::plotProgress() {
    std::cout << "PROGRESS\n";
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (boardCopy[i][j]->isGoalCell()) {
                std::cout << 'G';
            } else if (isInClosedList(boardCopy[i][j])) {
                std::cout << 'c';
            } else if (isInOpenList(boardCopy[i][j])) {
                std::cout << 'o';
            } else if (boardCopy[i][j]->isWallCell()) {
                std::cout << 'X';
            } else {
                std::cout << '=';
            }
        }
        std::cout << std::endl;
    }
}

Agent::Agent(char name, Cell *board[WIDTH][HEIGHT]) {
    id = name;
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            // TODO: if bugs arise with multiple agents, check this line.
            boardCopy[i][j] = board[i][j];
        }
    }
}

void Agent::addToOpenList(Cell *cell) {
    openList.push_back(cell);
}

void Agent::addToClosedList(Cell *cell) {
    closedList.push_back(cell);
}

void Agent::removeFromOpenList(Cell *cell) {
    list<Cell *>::iterator it;
    for (it = openList.begin(); it != openList.end(); ++it) {
        Cell *openListCell = *it;
        if (openListCell->getX() == cell->getX() && openListCell->getY() == cell->getY()) {
            openList.erase(it);
            break;
        }
    }
}

void Agent::moveFromOpenToClosedList(Cell *cell) {
    addToClosedList(cell);
    removeFromOpenList(cell);

  //  showList(openList);
}

Cell *Agent::getGoalCell() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (boardCopy[i][j]->isGoalCell()) {
                return boardCopy[i][j];
            }
        }
    }
    return NULL;
}

float Agent::calculateH(Cell *cell) {
    // Inefficient but working approach: iterate always trying to approach the goal until reached.

    // Simple and working solution, pythagorean:
    Cell *goal = getGoalCell();
    float x = cell->getX() - goal->getX();
    float y = cell->getY() - goal->getY();
    return sqrt(x * x + y * y);

}

// Adds the new node to the open list and populates g,h and f for that node.
void Agent::discoverCell(Cell *parent, Cell *cell) {

    cell->setParent(parent);
    addToOpenList(cell);

    // g is g of parent + cost to move from parent to current cell (1 for
    // vertical and horizontal, 1.4 for diagonal).
    float g;
    if (areHorizontalOrVertical(parent, cell)) {
        g = parent->getG() + 1;
    } else {
        g = parent->getG() + 1.4;
    }
    cell->setG(g);

    // h is the cost to the goal if no walls existed.
    float h = calculateH(cell);

    cell->setH(h);

    // f is g + h.
    cell->setF(g + h);
}

bool Agent::isInOpenList(Cell *cell) {
    list<Cell *>::iterator it;
    for (it = openList.begin(); it != openList.end(); ++it) {
        Cell *openListCell = *it;
        if (openListCell->getX() == cell->getX() && openListCell->getY() == cell->getY()) {
            return true;
        }
    }
    return false;
}

bool Agent::isInClosedList(Cell *cell) {
    list<Cell *>::iterator it;
    for (it = closedList.begin(); it != closedList.end(); ++it) {
        Cell *openListCell = *it;
        if (openListCell->getX() == cell->getX() && openListCell->getY() == cell->getY()) {
            return true;
        }
    }
    return false;
}

bool Agent::coordsWithinBounds(int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT;
}

bool Agent::areHorizontalOrVertical(Cell *a, Cell *b) {
    return (a->getX() == b->getX() || a->getY() == b->getY()) && !(a->getX() == b->getX() && a->getY() == b->getY());
}


// Check if g can be improved, if it can be, update g, f and parent.
void Agent::tryToImproveCellNumbers(Cell *cell, Cell *parentCell) {
    float candidateG;
    if (areHorizontalOrVertical(cell, parentCell)) {
        candidateG = parentCell->getG() + VERTICAL;
    } else {
        // diagonal neighbours
        candidateG = parentCell->getG() + DIAGONAL;
    }

    if (candidateG < cell->getG()) {
        cell->setG(candidateG);
        cell->setF(candidateG + cell->getH());
        cell->setParent(parentCell);
    }
}

// Calls discoverCell for all neighbouring cells that are not walls, and are not
// in the open or closed list. If a neighbour is in the open list already, but
// its g (and f) value can be improved, update parent and values.
void Agent::tryToDiscoverOrImprove(int x, int y, Cell *parentCell) {
    if (coordsWithinBounds(x, y)) {
        Cell *discovery = boardCopy[y][x];
        if (!discovery->isWallCell() && !isInOpenList(discovery) && !isInClosedList(discovery)) {
            discoverCell(parentCell, discovery);
        } else if (isInOpenList(discovery)) {
            tryToImproveCellNumbers(discovery, parentCell);
        }
    }
}

void Agent::discoverNeighbours(Cell *cell) {
    // Up.
    int x = cell->getX();
    int y = cell->getY() + 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Up, right.
    x = cell->getX() + 1;
    y = cell->getY() + 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Up, left.
    x = cell->getX() - 1;
    y = cell->getY() + 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Up, right.
    x = cell->getX() + 1;
    y = cell->getY() + 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Right.
    x = cell->getX() + 1;
    y = cell->getY();
    tryToDiscoverOrImprove(x, y, cell);
    // Left.
    x = cell->getX() - 1;
    y = cell->getY();
    tryToDiscoverOrImprove(x, y, cell);
    // Down.
    x = cell->getX();
    y = cell->getY() - 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Down, right.
    x = cell->getX() + 1;
    y = cell->getY() - 1;
    tryToDiscoverOrImprove(x, y, cell);
    // Down, left.
    x = cell->getX() - 1;
    y = cell->getY() - 1;
    tryToDiscoverOrImprove(x, y, cell);

   // showList(openList);
}

// Gets the best candidate to keep going.
Cell *Agent::getBestCellFromOpenList() {
    // First, we look for the lowest f value. In the case of a tie, the deciding
    // factor is the lowest h number.
    float minF = FLT_MAX;
    float minH = FLT_MAX;
    Cell *bestCell = nullptr;

    list<Cell *>::iterator it;

    for (it = openList.begin(); it != openList.end(); ++it) {
        Cell *cell = *it;
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

bool Agent::isStartingPosCell(Cell *cell) {
    return cell->getX() == startingCell->getX() && cell->getY() == startingCell->getY();
}

// Constructs a list with each node's parent until we reach the initial node.
list<Cell *> Agent::constructPath(Cell *finalNode) {
    list<Cell *> list;
    cout << "constructing final path:" << endl;

    Cell *currentCell = finalNode;

    while (!isStartingPosCell(currentCell)) {
        list.push_front(currentCell);
        //   cout << "next step is: x:"<< currentCell->getX() << ", y:" << currentCell->getY() << endl;
        //   cout << "g: "<< currentCell->getG() << ", h: " << currentCell->getH() << ", f: " << currentCell->getF() << endl;
        currentCell = currentCell->getParent();
    }

    list.push_front(currentCell);

    return list;
}

list<Cell *> Agent::aStar() {
    Cell *finalNode;

    while (true) {

        // VERY COOL, FOR DEBUGGING UNCOMMENT. VERY SLOW.
        //plotProgress();

        Cell *next = getBestCellFromOpenList();
        discoverNeighbours(next);

        moveFromOpenToClosedList(next);

      //  cout << "closed:" << endl;
      //  showList(closedList);

        // If the node we just closed is the goal, break the loop and walk back
        // following the parents until we reach the start.
        if (next->isGoalCell() == true) {
            cout << "GOAL REACHED at " << "x: " << next->getX() << ", y: " << next->getY() << endl;
            finalNode = next;
            break;
        }
    }
    return constructPath(finalNode);
}

// A* magic.
list<Cell *> Agent::calculateShortestPath(Cell *startingPosition) {
    // Printing the starting position.
    cout << "Starting position: x:" << startingPosition->getX()
         << ", y:" << startingPosition->getY() << endl;

    this->startingCell = startingPosition;

    // We add startingPosition to the open list and run the algorithm.
    addToOpenList(startingPosition);
  //  showList(openList);

    // discoverNeighbours(startingPosition);

    //return aStar();
    list<Cell *> list = aStar();
    return list;
}


