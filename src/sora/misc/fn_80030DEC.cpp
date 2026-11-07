#include <gf/gf_heap_manager.h>
#pragma force_active on
extern "C" int fn_8004EAEC();
extern "C" int fn_8004EFA0();

struct Data {
    void* buffer;
    unsigned int capacity;
    char pad[0xe8];
    int busy;
    char pad2[0x18];
    void* current;
    unsigned int size;
    Heaps::HeapType heap;
};

static unsigned int calc(int mode, unsigned int n) {
    unsigned int size = 0;
    if (mode == 0 || mode == 2) {
        size = n + 4;
        if (size & 31) size += 32 - (size & 31);
    } else if (mode == 1) {
        size = (n + 4) * 51;
        if (size & 31) size += 32 - (size & 31);
    }
    return size;
}

extern "C" void* fn_80030DEC(Data* self, int mode) {
    if (self->busy) return 0;
    unsigned int size = 0;
    if (mode == 0) {
        size = calc(mode, fn_8004EAEC());
    } else if (mode == 2) {
        size = calc(mode, 0x2804);
    } else if (mode == 1) {
        size = fn_8004EFA0() + 4;
    }
    if (!size) return 0;
    if (self->capacity < size) {
        if (self->buffer) gfHeapManager::free(self->buffer);
        self->buffer = gfHeapManager::alloc(self->heap, size, 32);
        self->capacity = size;
    }
    self->current = self->buffer;
    self->size = size;
    return self->buffer;
}