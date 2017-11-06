#ifndef TITERATOR_H
#define TITERATOR_H
#include "tstack.h"

template <class T>
class TIterator {
private:
    std::shared_ptr< TStackItem<T> > elem;
public:
    TIterator(std::shared_ptr< TStackItem<T> > ptr) {
        elem = ptr;
    }

    std::shared_ptr<T> operator *() {
        return elem->GetValue();
    }

    std::shared_ptr<T> operator ->() {
        return elem->GetValue();
    }

    void operator ++() {
        elem = elem->GetNext();
    }

    TIterator operator ++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator ==(TIterator const &iter) {
        return elem == iter.elem;
    }

    bool operator !=(TIterator const &iter) {
        return !(*this == iter);
    }
};

#endif // TITERATOR_H
