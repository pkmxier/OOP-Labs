#include "tstackitem.h"

TStackItem::TStackItem(const std::shared_ptr<Figure> &figure) {
    this->figure = figure;
    this->next = nullptr;
}

//TStackItem::TStackItem(const TStackItem &rhs) {
//    this->hexagon = rhs.hexagon;
//    this->next = rhs.next;
//}

std::shared_ptr<TStackItem> TStackItem::SetNext(std::shared_ptr<TStackItem> &next) {
    std::shared_ptr<TStackItem> current = this->next;
    this->next = next;
    return current;
}

std::shared_ptr<TStackItem> TStackItem::GetNext() {
    return this->next;
}

std::shared_ptr<Figure> TStackItem::GetFigure() const {
    return this->figure;
}

std::ostream & operator <<(std::ostream &os, const TStackItem &rhs) {
    os << *rhs.figure;
    return os;
}

TStackItem::~TStackItem() {
}
