#ifndef OCTAGON_H
#define OCTAGON_H
#include <cstdlib>
#include <iostream>
#include "point.h"
#include "figure.h"

#define NUM_OF_POINTS 8

class Octagon : public Figure {
private:
    point set[NUM_OF_POINTS];
public:
    Octagon();
    Octagon(std::istream &);
    Octagon(point *);
    Octagon(const Octagon &);

    double Square() override;
    void Print() override;

    virtual ~Octagon() {}
};

#endif // OCTAGON_H
