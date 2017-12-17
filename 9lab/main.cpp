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
        std::uniform_int_distribution<int> distr1(1, 3);

        std::uniform_real_distribution<double> distr2(1, 100);
        switch(distr1(gen)) {
            case 1: //Triangle
                double sides[3];
                sides[0] = distr2(gen);
                sides[1] = distr2(gen);
                sides[2] = distr2(gen);
                stack.push(std::make_shared<Triangle>(sides));
                break;
            case 2: //Hexagon
                point vertex_hex[6];

                for (int i = 0; i < 6; ++i) {
                    vertex_hex[i] = {distr2(gen), distr2(gen)};
                }

                stack.push(std::make_shared<Hexagon>(vertex_hex));
                break;
            case 3: //Octagon
                point vertex_oct[8];

                for (int i = 0; i < 8; ++i) {
                    vertex_oct[i] = {distr2(gen), distr2(gen)};
                }

                stack.push(std::make_shared<Octagon>(vertex_oct));
                break;
        }
    };

    TCommand delete_less_square = [&]() {
        double square = 500;

        TStack<Figure> tmp_stack;
        while (!stack.empty()) {
            std::shared_ptr<Figure> cur = stack.pop();
            if (cur->Square() >= square) {
                tmp_stack.push(std::move(cur));
            }
        }

        while (!tmp_stack.empty()) {
            stack.push(tmp_stack.pop());
        }
    };

    TCommand print = [&]() {
        for (auto it : stack) {
            it->Print();
            std::cout << "Its square is " << it->Square() << std::endl << std::endl;
        }
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
    array.push(std::shared_ptr<TCommand>(&delete_less_square, [](TCommand *){}));
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
