// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#include "Cell.h"

Cell::Cell() { }

Cell::Cell(int x, int y) : x(x), y(y) { }

Cell::Cell(int x, int y, bool isWall) : x(x), y(y), isWall(isWall) { }

Cell::~Cell() { }

void Cell::setX(int x) {
    Cell::x = x;
}

void Cell::setY(int y) {
    Cell::y = y;
}

void Cell::setG(float g) {
    Cell::g = g;
}

void Cell::setH(float h) {
    Cell::h = h;
}

void Cell::setF(float f) {
    Cell::f = f;
}

void Cell::setIsGoal(bool isGoal) {
    Cell::isGoal = isGoal;
}

void Cell::setIsWall(bool isWall) {
    Cell::isWall = isWall;
}

void Cell::setParent(Cell* parent) {
    Cell::parent = parent;
}

int Cell::getX() const {
    return x;
}

int Cell::getY() const {
    return y;
}

float Cell::getG() const {
    return g;
}

float Cell::getH() const {
    return h;
}

float Cell::getF() const {
    return f;
}

Cell* Cell::getParent() const {
    return parent;
}

bool Cell::isGoalCell() const {
    return isGoal;
}

bool Cell::isWallCell() const {
    return isWall;
}
