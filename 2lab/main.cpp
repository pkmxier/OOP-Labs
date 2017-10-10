#include <iostream>
#include <cstring>
#include "tstack.h"

int main() {
    TStack stack;
    Hexagon hexagon1;
    Hexagon hexagon2;
    Hexagon hexagon3;
    std::cin >> hexagon1 >> hexagon2 >> hexagon3;
    stack.push(hexagon1);
    stack.push(hexagon2);
    stack.push(hexagon3);
    //std::cout << stack;
    //return 0;
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top();
    stack.pop();
}
//0 0
//0 1
//1 2
//2 1
//2 0
//1 -1

//0 0
//0 2
//2 4
//4 2
//4 0
//2 -2

//0 0
//0 3
//3 6
//6 3
//6 0
//3 -3
