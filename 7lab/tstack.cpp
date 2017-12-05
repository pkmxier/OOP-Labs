#include "tstack.h"

template <class T, class Z>
TStack<T, Z>::TStack() : head(nullptr), _size(0) {
}

template<class T, class Z>
void TStack<T, Z>::insert(std::shared_ptr<Z> &&val) {
    if (head != nullptr && head->GetFigure()->GetSize() < MAX_COUNT) {
        head->GetFigure()->push(val);

        std::cout << "Element added" << std::endl;
        return;
    }

    std::shared_ptr<T> tmp(new T);
    tmp->push(val);
    std::shared_ptr< TStackItem<T> > tmp_item(new TStackItem<T>(tmp));
    tmp_item->SetNext(head);
    head = tmp_item;
    ++_size;

    std::cout << "Created new stack node" << std::endl;
    std::cout << "Element added" << std::endl;
}

template<class T, class Z>
void TStack<T, Z>::remove(TRemoveCriteria<Z> *criteria) {
    if (head != nullptr) {
        if (head->GetFigure()->GetSize()) {
            std::shared_ptr<T> tmp = head->GetFigure();
            T temp;
            for (int i = 0; i < tmp->GetSize(); ++i) {
                if (criteria->doesFit((*tmp)[i])) {
                    std::cout << "Deleting element " << i + 1 << ": " << *(*tmp)[i];
                } else {
                    temp.push((*head->GetFigure())[i]);
                }
            }

            int size = head->GetFigure()->GetSize();
            for (int i = 0; i < size; ++i) {
                head->GetFigure()->pop(0);
            }

            for (int i = 0; i < temp.GetSize(); ++i) {
                head->GetFigure()->push(temp[i]);
            }

            if (!head->GetFigure()->GetSize()) {
                std::shared_ptr< TStackItem<T> > next = head->GetNext();
                head->SetNext(nullptr);
                head.reset();
                head = next;
                --_size;
            }
        }
    }
}

template <class T, class Z>
unsigned int TStack<T, Z>::size() {
    return this->_size;
}

template <class T, class Z>
bool TStack<T, Z>::empty() {
    return this->head == nullptr;
}

template <class T, class Z>
TIterator<TStackItem<T>, T> TStack<T, Z>::begin() {
    return TIterator<TStackItem<T>, T>(head);
}

template <class T, class Z>
TIterator<TStackItem<T>, T> TStack<T, Z>::end() {
    return TIterator<TStackItem<T>, T>(nullptr);
}

template <class T, class Z>
std::ostream & operator <<(std::ostream &os, const TStack<T, Z> &stack) {
    std::shared_ptr< TStackItem<T> > item = stack.head;
    std::cout << "Stack:" << std::endl;
    while (item != nullptr) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

template <class T, class Z>
TStack<T, Z>::~TStack() {
}

template class TStack< TArray<Figure>, Figure >;
template std::ostream & operator <<(std::ostream &os, const TStack< TArray<Figure>, Figure > &stack);
