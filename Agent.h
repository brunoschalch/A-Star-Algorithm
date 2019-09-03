// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#ifndef ASTAR_AGENT_H
#define ASTAR_AGENT_H

#include "Cell.h"
#include "OurList.h"

#include <list>

using namespace std;

class Agent {
public:
    static const int WIDTH = 50;
    static const int HEIGHT = 50;
    constexpr static const float VERTICAL = 1.0f;
    constexpr static const float DIAGONAL = 1.4f;
    
    Agent();
    Agent(char name, Cell* board[WIDTH][HEIGHT]);
    ~Agent();
    
    list<Cell*> calculateShortestPath(Cell* startingPosition);
    
private:
    OurList openList; // list<Cell*> openList;
    list<Cell*> closedList;
    Cell* boardCopy[HEIGHT][WIDTH];
    char id;
    Cell* startingCell;
    
    // Adding elements to the open or closed lists.
    void addToOpenList(Cell* cell);
    void addToClosedList(Cell* cell);
    
    // Iterating to know if the lists contain a particular cell.
    bool isInOpenList(Cell* cell);
    bool isInClosedList(Cell* cell);
    
    // Helper functions to remove elements from lists.
    void moveFromOpenToClosedList(Cell *cell);
    void removeFromOpenList(Cell *cell);
    
    // Debugging-purpose functions.
    static void showList(list<Cell *> g);
    void plotProgress();
    
    void discoverCell(Cell* parent, Cell* cell);
    void discoverNeighbours(Cell* cell);
    
    // Returns true if the coordinates are within the bounds. False otherwise.
    bool coordsWithinBounds(int x, int y);
    
    // Try to improve the values when possible.
    void tryToDiscoverOrImprove(int x, int y, Cell* parentCell);
    void tryToImproveCellNumbers(Cell* cell, Cell* parentCell);
    
    // Helper functions to compute values.
    float calculateH(Cell* cell);
    bool areHorizontalOrVertical(Cell* a, Cell* b);
    
    Cell* getGoalCell();
    Cell* getBestCellFromOpenList();
    bool isStartingPosCell(Cell* cell);
    
    list<Cell*> aStar();
    list<Cell*> constructPath(Cell*finalNode);
};
#endif //ASTAR_AGENT_H
