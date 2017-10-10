#include <iostream>
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "tstack.h"

int main(int argc, char *argv[]) {
    point hexagon_data[6];
    hexagon_data[0].x = 0;
    hexagon_data[0].y = 0;
    hexagon_data[1].x = 0;
    hexagon_data[1].y = 1;
    hexagon_data[2].x = 1;
    hexagon_data[2].y = 2;
    hexagon_data[3].x = 2;
    hexagon_data[3].y = 1;
    hexagon_data[4].x = 2;
    hexagon_data[4].y = 0;
    hexagon_data[5].x = 1;
    hexagon_data[5].y = -1;

    point octagon_data[8];
    octagon_data[0].x = 0;
    octagon_data[0].y = 0;
    octagon_data[1].x = 0;
    octagon_data[1].y = 1;
    octagon_data[2].x = 1;
    octagon_data[2].y = 2;
    octagon_data[3].x = 2;
    octagon_data[3].y = 2;
    octagon_data[4].x = 3;
    octagon_data[4].y = 1;
    octagon_data[5].x = 3;
    octagon_data[5].y = 0;
    octagon_data[6].x = 2;
    octagon_data[6].y = -1;
    octagon_data[7].x = 1;
    octagon_data[7].y = -1;

    TStack stack;

    stack.push(std::shared_ptr<Figure> (new Hexagon(hexagon_data)));
    stack.push(std::shared_ptr<Figure> (new Triangle(3, 4, 5)));
    stack.push(std::shared_ptr<Figure> (new Octagon(octagon_data)));
    std::shared_ptr<Figure> figure;
    std::cout << stack << std::endl;
    for (int i = 0; i < 3; ++i) {
        figure = stack.pop();
        std::cout << *figure;
    }
}
