#ifndef TARRAY_H
#define TARRAY_H
#include <cstdlib>
#include <iostream>
#include <memory>
#include "figure.h"

template<class T>
class TArray {
private:
    std::shared_ptr<T> *data;
    int capacity;
    int size;
public:
    TArray();
    TArray(size_t &size);

    std::shared_ptr<T> *& GetData();
    void resize(size_t size);
    std::shared_ptr<T> & operator [](int i);
    int GetSize();
    void pop(int i);
    void push(std::shared_ptr<T> &val);

    void Print();

    template <class X>
    friend std::ostream & operator <<(std::ostream &os, TArray<X> &rhs);

    ~TArray();
};

#endif // TARRAY_H
