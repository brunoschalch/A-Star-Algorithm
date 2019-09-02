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
    
    void addToOpenList(Cell* cell);
    void addToClosedList(Cell* cell);
    void discoverCell(Cell* parent, int x, int y);
    Cell* getBestCellFromOpenList();
    list<Cell*> aStar();
};
#endif //ASTAR_AGENT_H
