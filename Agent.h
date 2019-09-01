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
    Agent();
    Agent(char name);
    ~Agent();

    list<Cell*> calculateShortestPath(Cell* startingPosition);

private:
    static const int WIDTH = 50;
    static const int HEIGHT = 50;
    list<Cell*> openList;
    list<Cell*> closedList;
    // TODO: Review type here.
    Cell* boardCopy[HEIGHT][WIDTH];
    char id;
};
#endif //ASTAR_AGENT_H
