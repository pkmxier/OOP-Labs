#include "tstack.h"

TStack::TStack() : head(NULL), _size(0) {
}

void TStack::push(Hexagon &hexagon) {
    TStackItem *temp = new TStackItem(hexagon);
    temp->SetNext(this->head);
    this->head = temp;
    this->_size++;
}

void TStack::pop() {
    if (this->head != NULL) {
        TStackItem *temp_head = this->head;
        this->head = head->GetNext();
        temp_head->SetNext(NULL);
        delete temp_head;
        this->_size--;
    }
}

Hexagon TStack::top() {
    Hexagon result;
    if (this->head != NULL) {
        result = this->head->GetHexagon();
    }
    return result;
}

unsigned int TStack::size() {
    return this->_size;
}

bool TStack::empty() {
    return this->_size == 0;
}

std::ostream & operator <<(std::ostream &os, const TStack &stack) {
    TStackItem *item = stack.head;
    while (item != NULL) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

TStack::~TStack() {
    delete this->head;
}
