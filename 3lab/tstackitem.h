#ifndef TSTACKITEM_H
#define TSTACKITEM_H
#include <memory>
#include <iostream>
#include "figure.h"

class TStackItem {
private:
    std::shared_ptr<Figure> figure;
    std::shared_ptr<TStackItem> next;
public:
    TStackItem(const std::shared_ptr<Figure> &);
    //TStackItem(const TStackItem &);

    std::shared_ptr<TStackItem> SetNext(std::shared_ptr<TStackItem> &);
    std::shared_ptr<TStackItem> GetNext();
    std::shared_ptr<Figure> GetFigure() const;

    friend std::ostream & operator <<(std::ostream &os, const TStackItem &rhs);

    virtual ~TStackItem();
};

#endif // TSTACKITEM_H
