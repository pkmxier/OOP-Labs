#ifndef HEXAGON_H
#define HEXAGON_H
#include <iostream>
#include <cmath>
#include "point.h"

#define NUM_OF_POINTS 6

class Hexagon {
private:
    point set[NUM_OF_POINTS];
public:
    Hexagon();
    Hexagon(point *);
    Hexagon(const Hexagon &);

    double Square();

    Hexagon & operator =(const Hexagon &);

    friend std::ostream & operator <<(std::ostream &, const Hexagon &);
    friend std::istream & operator >>(std::istream &, Hexagon &);

    virtual ~Hexagon() {}
};

#endif // HEXAGON_H
