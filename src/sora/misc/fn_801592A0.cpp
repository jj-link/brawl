#include <types.h>
#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_8015B0E0(void*);
}

struct Fn15Obj {
    u8 pad0[0x8];
    void* m8;
};

extern "C" void fn_801592A0(Fn15Obj* self) {
    if (self->m8 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x7D04, 0x10);
        if (p != 0) {
            p = fn_8015B0E0(p);
        }
        self->m8 = p;
    }
}
