// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#ifndef ASTAR_CELL_H
#define ASTAR_CELL_H

class Cell {
public:
    Cell();
    
    // Constructor override with x and y.
    Cell(int x, int y);
    
    // Constructor override with x, y, and bool to see if it is a wall.
    Cell(int x, int y, bool isWall);
    
    virtual ~Cell();
    
    // Setters.
    void setX(int x);
    void setY(int y);
    void setG(float g);
    void setH(float h);
    void setF(float f);
    void setIsGoal(bool isGoal);
    void setIsWall(bool isWall);
    void setParent(Cell* parent);
    
    // Getters.
    int getX() const;
    int getY() const;
    float getG() const;
    float getH() const;
    float getF() const;
    Cell* getParent() const;
    
    // Returns true if the cell is the goal. False otherwise.
    bool isGoalCell() const;
    
    // Returns true if the cell is a wall. False otherwise.
    bool isWallCell() const;
    
private:
    int x;
    int y;
    float g;
    float h;
    float f;
    bool isWall;
    bool isGoal;
    Cell* parent;
};

#endif //ASTAR_CELL_H
