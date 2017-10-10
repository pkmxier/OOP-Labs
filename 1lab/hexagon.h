#ifndef HEXAGON_H
#define HEXAGON_H
#include <iostream>
#include <cmath>
#include "point.h"
#include "figure.h"

#define NUM_OF_POINTS 6

class Hexagon : public Figure {
private:
    point set[NUM_OF_POINTS];
public:
    Hexagon();
    Hexagon(std::istream &);
    Hexagon(point *);
    Hexagon(const Hexagon &);

    double Square() override;
    void Print() override;

    virtual ~Hexagon() {}
};

#endif // HEXAGON_H
