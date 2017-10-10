#include <iostream>
#include "point.h"
#include "triangle.h"
#include "hexagon.h"
#include "octagon.h"

int main() {
    Octagon oct(std::cin);
    oct.Print();
    std::cout << oct.Square() << std::endl;

    Triangle tr(std::cin);
    tr.Print();
    std::cout << tr.Square() << std::endl;

    Hexagon hex(std::cin);
    hex.Print();
    std::cout << hex.Square() << std::endl;
}
//0 0
//1 0
//1 2
//2 2
//3 1
//3 0
//2 -1
//1 -1

//3 4 5

//0 0
//0 1
//1 2
//2 1
//2 0
//1 -1

