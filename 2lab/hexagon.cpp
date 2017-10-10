#include "hexagon.h"

Hexagon::Hexagon() {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i].x = set[i].y = 0;
    }
}

Hexagon::Hexagon(point *data) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i] = data[i];
    }
}

Hexagon::Hexagon(const Hexagon &rhs) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i] = rhs.set[i];
    }
}

double Hexagon::Square() {
    double s = 0;
    for (int i = 0; i < NUM_OF_POINTS - 1; ++i) {
        s += set[i].x * set[i + 1].y - set[i + 1].x * set[i].y;
    }
    s += set[NUM_OF_POINTS - 1].x * set[0].y - set[0].x * set[NUM_OF_POINTS - 1].y;
    s /= 2;
    return fabs(s);
}

Hexagon & Hexagon::operator =(const Hexagon &hexagon) {
    if (this != &hexagon) {
        for (int i = 0; i < NUM_OF_POINTS; ++i) {
            this->set[i] = hexagon.set[i];
        }
    }
    return *this;
}

std::ostream & operator <<(std::ostream &os, const Hexagon &hexagon) {
    os << "Hexagon coordinates: " << std::endl;
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        os << "x" << i + 1 << " = " << hexagon.set[i].x
           << ", y" << i + 1 << " = " << hexagon.set[i].y << std::endl;
    }
    return os;
}

std::istream & operator >>(std::istream &is, Hexagon &hexagon) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        is >> hexagon.set[i].x;
        is >> hexagon.set[i].y;
    }
    return is;
}

