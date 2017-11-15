#include <iostream>
#include <memory>
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "tstack.h"

int main(int argc, char *argv[]) {
    point hexagon[6] = {{0, 0}, {0, 1}, {1, 2},
                        {2, 1}, {2, 0}, {1, -1}};

    double triangle[3] = {3, 4, 5};

    point octagon[8] = {{0, 0}, {0, 1}, {1, 2}, {2, 2},
                        {3, 1}, {3, 0}, {2, -1}, {1, -1}};

    TStack<Figure> stack;

    stack.push(std::make_shared <Hexagon>(hexagon));
    stack.push(std::make_shared <Triangle>(triangle));
    stack.push(std::make_shared <Octagon>(octagon));

    for(auto i : stack) {
        std::cout << *i;
    }
}
