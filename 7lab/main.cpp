#include <iostream>
#include <memory>
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "tstack.h"
#include <ctime>
#include "tremovecriteriaall.h"
#include "tremovecriteriavalue.h"
#include "tremovecriterialesssquare.h"

int main(int argc, char *argv[]) {
    point hexagon[6] = {{0, 0}, {0, 1}, {1, 2},
                        {2, 1}, {2, 0}, {1, -1}};

    double triangle[3] = {3, 4, 5};

    point octagon[8] = {{0, 0}, {0, 1}, {1, 2}, {2, 2},
                        {3, 1}, {3, 0}, {2, -1}, {1, -1}};

    TStack< TArray<Figure>, Figure > stack;

    stack.insert(std::make_shared<Hexagon>(hexagon));
    stack.insert(std::make_shared<Triangle>(triangle));
    stack.insert(std::make_shared<Octagon>(octagon));
    stack.insert(std::make_shared<Hexagon>(hexagon));
    stack.insert(std::make_shared<Hexagon>(hexagon));

    for (auto i : stack) {
        std::cout << *i;
    }

    TRemoveCriteriaLessSquare<Figure> criteria(6);

    stack.remove(&criteria);
}
