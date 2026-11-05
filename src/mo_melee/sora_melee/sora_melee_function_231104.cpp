#include <gf/gf_heap_manager.h>
#include <string.h>
#pragma force_active on

struct Object {
    char pad[0x1f8];
    void* a;
    void* b;
    void* c;
    void* d;
};

extern "C" void fn_27_231104(Object* self, unsigned char x, unsigned char y) {
    if (self->a || self->b) {
        if (self->a) {
            gfHeapManager::free(self->a);
            self->a = 0;
        }
        if (self->b) {
            gfHeapManager::free(self->b);
            self->b = 0;
        }
        if (self->c) {
            gfHeapManager::free(self->c);
            self->c = 0;
        }
        if (self->d) {
            gfHeapManager::free(self->d);
            self->d = 0;
        }
    }
    if (x) {
        unsigned long size = x * 4;
        self->a = gfHeapManager::alloc((Heaps::HeapType)15, size, 0x20);
        if (self->a) memset(self->a, 0, size);
        self->c = gfHeapManager::alloc((Heaps::HeapType)15, size, 0x20);
        if (self->c) memset(self->c, 0, size);
    }
    if (y) {
        unsigned long size = y * 4;
        self->b = gfHeapManager::alloc((Heaps::HeapType)15, size, 0x20);
        if (self->b) memset(self->b, 0, size);
        self->d = gfHeapManager::alloc((Heaps::HeapType)15, size, 0x20);
        if (self->d) memset(self->d, 0, size);
    }
}