// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#ifndef ASTAR_OURLIST_H
#define ASTAR_OURLIST_H

#include "Cell.h"

#include <stdio.h>

struct Node {
    Cell* cell;
    Node* next;
};

class OurList {
public:
    Node* head;
    Node* tail;
    
    OurList();
    ~OurList();
    
    void push_back(Cell* cell);
    bool find(Cell* cell);
    Cell* find(int index);
    bool remove(Cell* cell);
    int size();
};

#endif //ASTAR_OURLIST_H
