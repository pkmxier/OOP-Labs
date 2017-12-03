#ifndef TARRAY_H
#define TARRAY_H
#include <cstdlib>
#include <iostream>
#include <memory>
#include <functional>
#include "figure.h"

template<class T>
class TArray {
private:
    std::shared_ptr<T> *data;
    int capacity;
    int size;
public:
    TArray();
    TArray(int size);

    std::shared_ptr<T> * GetData();
    void resize(int size);
    std::shared_ptr<T> & operator [](int i);
    int GetSize();
    std::shared_ptr<T> & pop();
    void push(std::shared_ptr<T> &&val);

    void Print();


    ~TArray();
};

#endif // TARRAY_H
