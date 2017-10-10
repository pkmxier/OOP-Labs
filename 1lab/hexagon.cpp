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

Hexagon::Hexagon(std::istream &is) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        is >> set[i].x >> set[i].y;
    }
}

Hexagon::Hexagon(const Hexagon &rhs) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i] = rhs.set[i];
    }
}

void Hexagon::Print() {
    std::cout << "Hexagon coordinates: " << std::endl;
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        std::cout << "x" << i + 1 << " = " << set[i].x << ", "
                  << "y" << i + 1 << " = " << set[i].y << std::endl;
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
