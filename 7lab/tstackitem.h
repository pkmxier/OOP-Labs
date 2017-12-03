#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include <iostream>
#include "figure.h"
#include <cstdlib>
#include "tarray.h"

template <class T>
class TStackItem {
private:
    std::shared_ptr<T> figure;
    std::shared_ptr< TStackItem<T> > next;
public:
    TStackItem(std::shared_ptr<T> &);

    void SetNext(std::shared_ptr< TStackItem<T> >);
    std::shared_ptr< TStackItem<T> > GetNext();
    std::shared_ptr<T> & GetFigure();

    template <class X>
    friend std::ostream & operator <<(std::ostream &os, TStackItem<X> &rhs);

    virtual ~TStackItem();
};

#endif // TSTACKITEM_H
