#ifndef FIGURE_H
#define FIGURE_H
#include <iostream>
class Figure {
public:
    virtual void Print() = 0;
    virtual double Square() = 0;
    bool areEqual(Figure &rhs) {
        return Square() == rhs.Square();
    }
    virtual ~Figure() {}
    friend std::ostream & operator <<(std::ostream &os, Figure &figure) {
        figure.Print();
        return os;
    }
};

#endif // FIGURE_H
