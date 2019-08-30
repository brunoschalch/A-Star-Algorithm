//
// Created by bruno on 8/29/2019.
//

#ifndef ASTAR_AGENT_H
#define ASTAR_AGENT_H
#include <list>
#include "Cell.h"
using namespace std;



class Agent {
public:
    Agent();


    Agent(char name);

    list<Cell*> calculateShortestPath(Cell* startingPosition);

};


#endif //ASTAR_AGENT_H
