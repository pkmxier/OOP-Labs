#include "octagon.h"

Octagon::Octagon() {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i].x = set[i].y = 0;
    }
}

Octagon::Octagon(std::istream &is) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        is >> set[i].x >> set[i].y;
    }
}

Octagon::Octagon(point *data) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i] = data[i];
    }
}

Octagon::Octagon(const Octagon &orig) {
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        set[i] = orig.set[i];
    }
}

void Octagon::Print() {
    std::cout << "Octagon coordinates: " << std::endl;
    for (int i = 0; i < NUM_OF_POINTS; ++i) {
        std::cout << "x" << i + 1 << " = " << set[i].x << ", "
                  << "y" << i + 1 << " = " << set[i].y << std::endl;
    }
    std::cout << "Square = " << Square() << std::endl;
}

double Octagon::Square() {
    double s = 0;
    for (int i = 0; i < NUM_OF_POINTS - 1; ++i) {
        s += set[i].x * set[i + 1].y - set[i + 1].x * set[i].y;
    }
    s += set[NUM_OF_POINTS - 1].x * set[0].y - set[0].x * set[NUM_OF_POINTS - 1].y;
    s /= 2;
    return s >= 0 ? s : -s;
}
