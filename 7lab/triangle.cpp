#include "triangle.h"
#include <cmath>

Triangle::Triangle() : side_a(0), side_b(0), side_c(0) {
}

Triangle::Triangle(double a, double b, double c) : side_a(a), side_b(b), side_c(c) {
    if (!(this->DoesExist())) {
        std::cout << "Can`t create triangle with such sides" << std::endl;
        side_a = side_b = side_c = 0;
    }
}

Triangle::Triangle(double *list) : side_a(list[0]), side_b(list[1]), side_c(list[2]) {
}

Triangle::Triangle(std::istream &is) {
    is >> side_a >> side_b >> side_c;
    if (!(this->DoesExist())) {
        std::cout << "Can`t create triangle with such sides" << std::endl;
        side_a = side_b = side_c = 0;
    }
}

Triangle::Triangle(const Triangle &orig) {
    side_a = orig.side_a;
    side_b = orig.side_b;
    side_c = orig.side_c;
    std::cout << "Triangle copy created" << std::endl;
}

void Triangle::Print() {
    std::cout << "Sides of triangle: " << side_a << ", " << side_b << ", " << side_c << std::endl;
    std::cout << "Square = " << Square() << std::endl;
}

bool Triangle::DoesExist() {
    return (side_a + side_b > side_c) && (side_a + side_c > side_b) && (side_b + side_c > side_a);
}

double Triangle::Square() {
    double p = (side_a + side_b + side_c) / 2;
    return sqrt(p * (p - side_a) * (p - side_b) * (p - side_c));
}
