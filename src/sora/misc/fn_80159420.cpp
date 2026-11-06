#include <types.h>
#pragma force_active on
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* fn_8015B0E0(void*);
extern "C" void fn_8015B1E0(void*);

struct Obj {
    u8 pad0[8];
    void* m8;
    u8 padC[0x18];
    u32 m24;
};

extern "C" void fn_80159420(Obj* self) {
    if (self->m8 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x7D04, 0x10);
        if (p != 0) {
            p = fn_8015B0E0(p);
        }
        self->m8 = p;
    }
    self->m24 |= 0x80000000;
    fn_8015B1E0(self->m8);
}