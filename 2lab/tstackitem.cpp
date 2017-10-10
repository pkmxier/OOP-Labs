#include "TStackItem.h"

TStackItem::TStackItem(const Hexagon &hexagon) {
    this->hexagon = hexagon;
    this->next = NULL;
}

TStackItem::TStackItem(const TStackItem &rhs) {
    this->hexagon = rhs.hexagon;
    this->next = rhs.next;
}

TStackItem * TStackItem::SetNext(TStackItem * next) {
    TStackItem *current = this->next;
    this->next = next;
    return current;
}

TStackItem * TStackItem::GetNext() {
    return this->next;
}

Hexagon TStackItem::GetHexagon() const {
    return this->hexagon;
}

std::ostream & operator <<(std::ostream &os, const TStackItem &rhs) {
    os << "[" << rhs.hexagon << "]" << std::endl;
    return os;
}

TStackItem::~TStackItem() {
    delete this->next;
}
