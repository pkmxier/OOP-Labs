#include "tstack.h"

template <class T>
TStack<T>::TStack() : head(nullptr), _size(0) {
}

template <class T>
void TStack<T>::push(std::shared_ptr<T> &&figure) {
    std::shared_ptr< TStackItem<T> > temp(new TStackItem<T>(figure));
    temp->SetNext(this->head);
    this->head = temp;
    this->_size++;
}

template <class T>
std::shared_ptr<T> TStack<T>::pop() {
    std::shared_ptr<T> result;
    if (this->head != nullptr) {
        result = head->GetFigure();
        this->head = this->head->GetNext();
        this->_size--;
    }
    return result;
}

template <class T>
unsigned int TStack<T>::size() {
    return this->_size;
}

template <class T>
bool TStack<T>::empty() {
    return this->head == nullptr;
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::begin() {
    return TIterator<TStackItem<T>, T>(head);
}

template <class T>
TIterator<TStackItem<T>, T> TStack<T>::end() {
    return TIterator<TStackItem<T>, T>(nullptr);
}

template <class T>
std::ostream & operator <<(std::ostream &os, const TStack<T> &stack) {
    std::shared_ptr< TStackItem<T> > item = stack.head;
    std::cout << "Stack:" << std::endl;
    while (item != nullptr) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

template <class T>
TStack<T>::~TStack() {
}

template class TStack<Figure>;
template std::ostream & operator <<(std::ostream &os, const TStack<Figure> &stack);
