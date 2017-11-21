#ifndef TITERATOR_H
#define TITERATOR_H
#include <memory>

template <class A, class T>
class TIterator {
private:
    std::shared_ptr<A> elem;
public:
    TIterator(std::shared_ptr<A> ptr) {
        elem = ptr;
    }

    std::shared_ptr<T> operator *() {
        return elem->GetFigure();
    }

    std::shared_ptr<T> operator ->() {
        return elem->GetFigure();
    }

    void operator ++() {
        elem = elem->GetNext();
    }

    TIterator operator ++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator ==(const TIterator &iter) {
        return elem == iter.elem;
    }

    bool operator !=(const TIterator &iter) {
        return !(*this == iter);
    }
};

#endif // TITERATOR_H
