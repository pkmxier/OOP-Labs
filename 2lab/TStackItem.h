#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include "hexagon.h"

class TStackItem {
private:
    Hexagon hexagon;
    TStackItem *next;
public:
    TStackItem(const Hexagon &);
    TStackItem(const TStackItem &);

    TStackItem * SetNext(TStackItem *);
    TStackItem * GetNext();
    Hexagon GetHexagon() const;

    friend std::ostream & operator <<(std::ostream &os, const TStackItem &rhs);

    virtual ~TStackItem();
};

#endif // TSTACKITEM_H
