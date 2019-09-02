// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#ifndef ASTAR_AGENT_H
#define ASTAR_AGENT_H

#include "Cell.h"

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
    list<Cell*> openList;
    list<Cell*> closedList;
    Cell* boardCopy[HEIGHT][WIDTH];
    char id;
    Cell* startingCell;

    void addToOpenList(Cell* cell);
    void addToClosedList(Cell* cell);
    void discoverCell(Cell* parent, int x, int y);
    Cell* getBestCellFromOpenList();
    list<Cell*> aStar();

    void discoverNeighbours(Cell *cell);

    bool isInOpenList();

    bool isInOpenList(Cell *cell);

    bool isInClosedList(Cell *cell);

    bool isWall(Cell *cell);

    void discoverCell(Cell *parent, Cell *cell);

    bool coordsWithinBounds(int x, int y);

    void tryToImproveCellNumbers(Cell *pCell);

    void tryToDiscoverOrImprove();

    void tryToDiscoverOrImprove(int x, int y);

    void tryToDiscoverOrImprove(int x, int y, Cell *parentCell);

    void tryToImproveCellNumbers(Cell *cell, Cell *parentCell);

    bool areHorizontalOrVertical(Cell *a, Cell *b);

    bool areDiagonal(Cell *a, Cell *b);

    static void showList(list<Cell *> g);

    void plotProgress();

    void moveFromOpenToClosedList(Cell *cell);

    void removeFromOpenList(Cell *cell);

    float calculateH();

    float calculateH(Cell *cell);

    Cell *getGoalCell();

    bool isStartingPosCell(Cell *cell);

    list<Cell *> constructPath(Cell *finalNode);
};
#endif //ASTAR_AGENT_H
