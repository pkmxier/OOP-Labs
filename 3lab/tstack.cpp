#include "tstack.h"

TStack::TStack() : head(nullptr), _size(0) {
}

//TStack::TStack(const TStack &rhs) {
//    this->head = rhs.head;
//    this->_size = rhs._size;
//}

void TStack::push(std::shared_ptr<Figure> &&figure) {
    std::shared_ptr<TStackItem> temp(new TStackItem(figure));
    temp->SetNext(this->head);
    this->head = temp;
    this->_size++;
}

std::shared_ptr<Figure> TStack::pop() {
    std::shared_ptr<Figure> result;
    if (this->head != nullptr) {
        result = head->GetFigure();
        this->head = this->head->GetNext();
        this->_size--;
    }
    return result;
}

unsigned int TStack::size() {
    return this->_size;
}

bool TStack::empty() {
    return this->head == nullptr;
}

std::ostream & operator <<(std::ostream &os, const TStack &stack) {
    std::shared_ptr<TStackItem> item = stack.head;
    std::cout << "Stack:" << std::endl;
    while (item != nullptr) {
        os << *item;
        item = item->GetNext();
    }
    return os;
}

TStack::~TStack() {
}
