#include <types.h>
#pragma force_active on

extern "C" void* __nwa__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" void* memset(void*, int, unsigned long);

struct fn27Obj {
    u8 pad0[0x4c];
    void* m_4c;
    void* m_50;
    void* m_54;
};

extern "C" {
void fn_27_23224C(fn27Obj* self) {
    if (self->m_4c == 0) {
        self->m_4c = __nwa__FUlQ25Heaps8HeapType(0x200, 0xf);
        memset(self->m_4c, 0, 0x200);
    }
    if (self->m_54 == 0) {
        self->m_54 = __nwa__FUlQ25Heaps8HeapType(0x100, 0xf);
        memset(self->m_54, 0, 0x100);
    }
}
}
