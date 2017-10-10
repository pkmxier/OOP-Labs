#ifndef TSTACK_H
#define TSTACK_H
#include "tstackitem.h"
#include "hexagon.h"

class TStack {
private:
    std::shared_ptr<TStackItem> head;
    unsigned int _size;
public:
    TStack();
    //TStack(const TStack &);
    void push(std::shared_ptr<Figure> &&figure);
    std::shared_ptr<Figure> pop();
    unsigned int size();
    bool empty();
    friend std::ostream & operator <<(std::ostream &os, const TStack &stack);

    virtual ~TStack();
};

#endif // TSTACK_H
