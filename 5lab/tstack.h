#ifndef TSTACK_H
#define TSTACK_H
#include "tstackitem.h"
#include "hexagon.h"
#include "titerator.h"

template <class T>
class TStack {
private:
    std::shared_ptr< TStackItem<T> > head;
    unsigned int _size;
public:
    TStack();

    void push(std::shared_ptr<T> &&figure);
    std::shared_ptr<T> pop();
    unsigned int size();
    bool empty();

    TIterator<T> begin();
    TIterator<T> end();


    template <class X>
    friend std::ostream & operator << (std::ostream &os, const TStack<X> &stack);

    virtual ~TStack();
};

#endif // TSTACK_H
