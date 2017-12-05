#include "tstackitem.h"

template <class T>
TStackItem<T>::TStackItem(std::shared_ptr<T> &figure) {
    this->figure = figure;
    this->next = nullptr;
}

template <class T>
void TStackItem<T>::SetNext(std::shared_ptr< TStackItem<T> > next) {
    this->next = next;
}

template <class T>
std::shared_ptr< TStackItem<T> > TStackItem<T>::GetNext() {
    return this->next;
}

template <class T>
std::shared_ptr<T> & TStackItem<T>::GetFigure() {
    return this->figure;
}

template <class T>
std::ostream & operator <<(std::ostream &os, TStackItem<T> &rhs) {
    rhs.GetFigure()->Print();
    return os;
}

template <class T>
TStackItem<T>::~TStackItem() {
}

template class TStackItem< TArray<Figure> >;
template std::ostream & operator <<(std::ostream &os, TStackItem< TArray<Figure> > &rhs);
