#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <cstdlib>
#include <iostream>
#include "figure.h"

class Triangle : public Figure {
private:
    double side_a;
    double side_b;
    double side_c;
public:
    Triangle();
    Triangle(std::istream &);
    Triangle(double, double, double);
    Triangle(double *);
    Triangle(const Triangle &);

    bool DoesExist();
    double Square() override;
    void Print() override;

    virtual ~Triangle() {}
};

#endif // TRIANGLE_H
