#ifndef TARRAY_H
#define TARRAY_H
#include <cstdlib>

template<class T>
class TArray {
private:
    T *data;
public:
    TArray();
    TArray(size_t &size);

    T *& GetData();

    T & operator [](int i);
    void resize(size_t size);

    ~TArray();
};

#endif // TARRAY_H
