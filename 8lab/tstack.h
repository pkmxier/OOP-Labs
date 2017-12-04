#ifndef TSTACK_H
#define TSTACK_H
#include <future>
#include "tstackitem.h"
#include "hexagon.h"
#include "titerator.h"

template <class T>
class TStack {
private:
    std::shared_ptr< TStackItem<T> > head;
    unsigned int _size;

    std::future<void> back_sort();
public:
    TStack();

    void push(std::shared_ptr<T> &&figure);
    std::shared_ptr<T> pop();
    std::shared_ptr<T> pop_last();
    unsigned int size();
    bool empty();

    typedef TIterator<TStackItem<T>,T> TStackIterator;

    TStackIterator begin();
    TStackIterator end();

    std::shared_ptr<T> operator [](int i);
    void sort();
    void thread_sort();

    template <class X>
    friend std::ostream & operator << (std::ostream &os, const TStack<X> &stack);

    virtual ~TStack();
};

#endif // TSTACK_H
