#include <iostream>
#include <memory>
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "tstack.h"
#include <random>
#include <chrono>

int main(int argc, char *argv[]) {
    point hexagon[6] = {{0, 0}, {0, 1}, {1, 2},
                        {2, 1}, {2, 0}, {1, -1}};

    double triangle[3] = {3, 4, 5};

    point octagon[8] = {{0, 0}, {0, 1}, {1, 2}, {2, 2},
                        {3, 1}, {3, 0}, {2, -1}, {1, -1}};

    TStack<Figure> stack1;
    TStack<Figure> stack2;

    std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_real_distribution<double> distr(1.0, 10.0);

    for (int i = 0; i < 1000; ++i) {
        double a = distr(gen);
        double b = distr(gen);
        double c = sqrt(a * a + b * b);
        stack1.push(std::make_shared<Triangle> (a, b, c));
        stack2.push(std::make_shared<Triangle> (a, b, c));
    }

    auto begin = std::chrono::high_resolution_clock::now();
    stack1.sort();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;

    begin = std::chrono::high_resolution_clock::now();
    stack2.thread_sort();
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Thread sort: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
}
