//
// Created by bruno on 8/29/2019.
//

#include "Cell.h"

Cell::Cell() {}

Cell::Cell(int x, int y) : x(x), y(y) {}

Cell::Cell(int x, int y, bool isWall) : x(x), y(y), isWall(isWall) {}

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

bool Cell::isWallCell() const {
    return isWall;
}

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

void Cell::setIsWall(bool isWall) {
    Cell::isWall = isWall;
}

bool Cell::isGoalCell() const {
    return isGoal;
}

void Cell::setIsGoal(bool isGoal) {
    Cell::isGoal = isGoal;
}

Cell *Cell::getParent() const {
    return parent;
}

void Cell::setParent(Cell *parent) {
    Cell::parent = parent;
}

Cell::~Cell() {}