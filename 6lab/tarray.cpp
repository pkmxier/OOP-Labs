#include "tarray.h"

template <class T>
TArray<T>::TArray() {
    data = nullptr;
}

template <class T>
TArray<T>::TArray(size_t &size) {
    data = new T[size];
}

template <class T>
T *& TArray<T>::GetData() {
    return data;
}

template <class T>
T &TArray<T>::operator [](int i) {
    return data[i];
}

template<class T>
void TArray<T>::resize(size_t size) {
    delete data;
    data = new T[size];
}

template <class T>
TArray<T>::~TArray() {
    delete [] data;
}

template class TArray<char>;
template class TArray<void *>;
