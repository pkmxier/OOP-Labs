#include "tallocationblock.h"

TAllocationBlock::TAllocationBlock(size_t size, size_t count) {
    this->size = size;
    this->count = count;

    usedBlocks = (char *)malloc(this->size * this->count);
    freeBlocks = (void **)malloc(sizeof(void *) * this->count);

    for (int i = 0; i < this->count; ++i) {
        freeBlocks[i] = usedBlocks + (i * this->size);
    }

    freeCount = this->count;
}

void * TAllocationBlock::Allocate() {
    void *memory = nullptr;
    if (!IsFull()) {
        memory = freeBlocks[--freeCount];
    }

    return memory;
}

void TAllocationBlock::Deallocate(void *ptr) {
    freeBlocks[freeCount++] = ptr;
}

bool TAllocationBlock::IsFull() {
    return freeCount == 0;
}

TAllocationBlock::~TAllocationBlock() {
    delete freeBlocks;
    delete usedBlocks;
}
