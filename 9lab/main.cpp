#include <iostream>
#include <memory>
#include <functional>
#include <random>
#include <future>
#include <chrono>
#include "tarray.h"
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include "tstack.h"

typedef std::function<void(void)> TCommand;

int main(int argc, char *argv[]) {
    TStack<Figure> stack;
    TArray<TCommand> array(100);

    TCommand insert = [&]() {
        std::default_random_engine gen(std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_real_distribution<double> distr(1, 100);

        double sides[3];
        sides[0] = distr(gen);
        sides[1] = distr(gen);
        sides[2] = distr(gen);
        stack.push(std::make_shared<Triangle>(sides));
    };

    TCommand print = [&]() {
        std::cout << stack;
    };

    TCommand reverse = [&]() {
        TStack<Figure> tmp;
        while (!stack.empty()) {
            tmp.push(stack.pop());
        }

        stack.Swap(tmp);
    };

    array.push(std::shared_ptr<TCommand>(&print, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&reverse, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&print, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));
    array.push(std::shared_ptr<TCommand>(&insert, [](TCommand *){}));


    while (array.GetSize()) {
        std::shared_ptr<TCommand> cmd = array.pop();
        std::future<void> future = std::async(*cmd);
        future.get();
    }
}
