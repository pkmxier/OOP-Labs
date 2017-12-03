#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include <iostream>
#include "figure.h"
#include "tallocationblock.h"
#include <cstdlib>

template <class T>
class TStackItem {
private:
    static TAllocationBlock allocator;

    std::shared_ptr<T> figure;
    std::shared_ptr< TStackItem<T> > next;
public:
    TStackItem(const std::shared_ptr<T> &);

    std::shared_ptr< TStackItem<T> > SetNext(std::shared_ptr< TStackItem<T> > &);
    std::shared_ptr< TStackItem<T> > GetNext();
    std::shared_ptr<T> GetFigure() const;

    void * operator new(size_t size);
    void operator delete(void *ptr);
    template <class X>
    friend std::ostream & operator <<(std::ostream &os, const TStackItem<X> &rhs);

    virtual ~TStackItem();
};

#endif // TSTACKITEM_H
