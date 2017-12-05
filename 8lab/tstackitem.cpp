#include "tstackitem.h"

template <class T>
TStackItem<T>::TStackItem(const std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->next = nullptr;
}

template <class T>
std::shared_ptr< TStackItem<T> > TStackItem<T>::SetNext(std::shared_ptr< TStackItem<T> > next) {
    std::shared_ptr< TStackItem<T> > current = this->next;
    this->next = next;
    return current;
}

template <class T>
std::shared_ptr< TStackItem<T> > TStackItem<T>::GetNext() {
    return this->next;
}

template <class T>
std::shared_ptr<T> TStackItem<T>::GetFigure() const {
    return this->figure;
}

template <class T>
std::ostream & operator <<(std::ostream &os, const TStackItem<T> &rhs) {
    os << *rhs.figure;
    return os;
}

template <class T>
TStackItem<T>::~TStackItem() {
}

template class TStackItem<Figure>;
template std::ostream & operator <<(std::ostream &os, const TStackItem<Figure> &rhs);
