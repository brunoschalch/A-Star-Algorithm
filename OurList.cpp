// A* Algorithm
//
// Ana Sollano Kim A01651072
// Bruno Schalch A01651187
//

#include "OurList.h"

OurList::OurList() {
    head = nullptr;
    tail = nullptr;
}

OurList::~OurList() { }

void OurList::push_back(Cell* cell) {
    Node* temp = new Node();
    temp->cell = cell;
    temp->next = nullptr;
    
    if (head == nullptr) {
        head = temp;
    }
    else {
        tail->next = temp;
    }
    tail = temp;
    temp = nullptr;
}

bool OurList::find(Cell* cell) {
    Node* node = head;
    while (node != nullptr) {
        Cell* listCell = node->cell;
        if (listCell->getX() == cell->getX() &&
            listCell->getY() == cell->getY()) {
            return true;
        }
        node = node->next;
    }
    return false;
}

Cell* OurList::find(int index){
    int count = 0;
    Node* node = head;
    Cell* listCell = node->cell;
    
    while (count < index) {
        node = node->next;
        count++;
    }
    return listCell;
}

bool OurList::remove(Cell* cell) {
    if (head == nullptr) {
        return false;
    }
    
    // When we want to delete the head.
    Cell* listCell = head->cell;
    if (listCell->getX() == cell->getX() &&
        listCell->getY() == cell->getY()) {
        head->cell = head->next->cell;
        head->next = head->next->next;
        return true;
    }
    
    // When the node is not the head, we find the node that appears
    // just before the node we want to delete.
    Node* previous = head;
    while (previous != nullptr &&
           previous->next->cell->getX() != cell->getX() &&
           previous->next->cell->getY() != cell->getY()) {
        previous = previous->next;
    }
    
    // If it was never found, return false.
    if (previous == nullptr) {
        return false;
    }
    
    // It was found and now we update the references.
    previous->next = previous->next->next;
    return true;
}

int OurList::size() {
    int size = 0;
    Node* node = head;
    while (node != nullptr) {
        size++;
        node = node->next;
    }
    return size;
}
