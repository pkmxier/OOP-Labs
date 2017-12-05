#include "tarray.h"

template <class T>
TArray<T>::TArray() {
    size = 0;
    capacity = 6;
    data = new std::shared_ptr<T>[capacity];
}

template <class T>
TArray<T>::TArray(size_t &size) {
    this->capacity = size;
    this->size = size;
    data = new std::shared_ptr<T>[size];
}

template <class T>
std::shared_ptr<T> * TArray<T>::GetData() {
    return data;
}

template<class T>
void TArray<T>::resize(int size) {
    this->capacity = size;
    size = 0;
    delete [] data;
    data = new std::shared_ptr<T>[size];
}

template <class T>
std::shared_ptr<T> & TArray<T>::operator [](int i) {
    return data[i];
}

template<class T>
int TArray<T>::GetSize() {
    return size;
}

template<class T>
void TArray<T>::pop(int i) {
    for (int j = i; j < size - 1; ++j) {
        data[j] = data[j + 1];
    }
    --size;
}

template<class T>
void TArray<T>::push(std::shared_ptr<T> &val) {
    int i = 0;
    for (i = 0; i < size; ++i) {
        if (data[i]->Square() > val->Square()) {
            for (int j = size; j > i; --j) {
                data[j] = data[j - 1];
            }

            data[i] = val;
            ++size;
            return;
        }
    }

    if (i == size) {
        data[size++] = val;
    }

}

template<class T>
void TArray<T>::Print() {
    std::cout << *this;
}

template<class T>
std::ostream & operator <<(std::ostream &os, TArray<T> &rhs) {
    for (int i = 0; i < rhs.size; ++i){
        std::cout << *rhs[i];
    }
}


template <class T>
TArray<T>::~TArray() {
    delete [] data;
}

template class TArray<Figure>;
