#ifndef TSTACK_H
#define TSTACK_H
#include "tstackitem.h"
#include "hexagon.h"
#include "titerator.h"
#include "tarray.h"
#include "tremovecriteria.h"

template <class T, class Z>
class TStack {
private:
    std::shared_ptr< TStackItem< T > > head;
    unsigned int _size;
public:
    TStack();

    void insert(std::shared_ptr<Z> &&val);
    void remove(TRemoveCriteria<Z> *criteria);
    unsigned int size();
    bool empty();

    typedef TIterator<TStackItem<T>,T> TStackIterator;

    TStackIterator begin();
    TStackIterator end();

    template <class X, class Y>
    friend std::ostream & operator << (std::ostream &os, const TStack<X, Y> &stack);

    virtual ~TStack();
};

#endif // TSTACK_H
