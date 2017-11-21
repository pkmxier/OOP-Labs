#ifndef TALLOCATIONBLOCK_H
#define TALLOCATIONBLOCK_H
#include <cstdlib>
#include "tarray.h"

class TAllocationBlock {
private:
    size_t size;
    size_t count;
    size_t freeCount;

    TArray<char> usedBlocks;
    TArray<void *> freeBlocks;
public:
    TAllocationBlock(size_t size, size_t count);
    void * Allocate();
    void Deallocate(void *ptr);
    bool IsFull();

    virtual ~TAllocationBlock();
};

#endif // TALLOCATIONBLOCK_H
