#include "tarray.h"

template <class T>
TArray<T>::TArray() {
    size = 0;
    capacity = 5;
    data = new std::shared_ptr<T>[capacity];
}

template <class T>
TArray<T>::TArray(size_t &size) {
    this->capacity = size;
    this->size = size;
    data = new std::shared_ptr<T>[size];
}

template <class T>
std::shared_ptr<T> *&TArray<T>::GetData() {
    return data;
}

template<class T>
void TArray<T>::resize(size_t size) {
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
    data[size] = val;
    ++size;
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

template class TArray<char>;
template class TArray<void *>;
template class TArray<int>;
template class TArray<Figure>;
