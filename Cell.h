//
// Created by bruno on 8/29/2019.
//

#ifndef ASTAR_CELL_H
#define ASTAR_CELL_H


class Cell {

public:
    Cell();

    Cell(int x, int y);

    Cell(int x, int y, bool isWall);

    void setX(int x);

    void setY(int y);

    void setG(float g);

    void setH(float h);

    void setF(float f);

    void setIsWall(bool isWall);

    int getX() const;

    int getY() const;

    float getG() const;

    float getH() const;

    float getF() const;

    bool isWallCell() const;

    virtual ~Cell();

private:
    int x;
    int y;
    float g;
    float h;
    float f;
    bool isWall;
};


#endif //ASTAR_CELL_H
