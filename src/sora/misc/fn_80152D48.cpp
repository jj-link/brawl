#include <types.h>
#pragma force_active on

extern "C" void* alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(int, unsigned long, long);
extern "C" void* memset(void* p, int c, unsigned long n);
extern "C" char lbl_8046167C[];

struct FnSelf {
    s32 m_00;
    void* m_04;
    void* m_08;
    void* m_0c;
    u32 m_10;
};

extern "C" FnSelf* fn_80152D48(FnSelf* self, void* heap) {
    self->m_08 = lbl_8046167C;
    void* p = alloc__13gfHeapManagerFQ25Heaps8HeapTypeUll(reinterpret_cast<int>(heap), 0x34, 0x20);
    self->m_0c = p;
    if (p != 0) {
        memset(p, 0, 0x34);
    }
    self->m_10 = 0;
    self->m_00 = 3;
    self->m_04 = heap;
    return self;
}
