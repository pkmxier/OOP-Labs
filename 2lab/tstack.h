#ifndef TSTACK_H
#define TSTACK_H
#include "TStackItem.h"

class TStack {
private:
    TStackItem *head;
    unsigned int _size;
public:
    TStack();

    void push(Hexagon &);
    void pop();
    Hexagon top();
    unsigned int size();
    bool empty();

    friend std::ostream & operator <<(std::ostream &os, const TStack &stack);

    ~TStack();
};

#endif // TSTACK_H
