#include <types.h>
#pragma force_active on

struct FnBase {
    s32 m_baseVal;
};

struct FnChild : FnBase {
    virtual void vf1();
    virtual ~FnChild();
    virtual void vf3();
};

struct FnObj {
    u8 m_pad0[0x18];
    FnChild* m_child;
    u8 m_pad1[0x10];
    u8 m_sub[0x10];
};

extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern "C" FnChild* fn_27_236CE0(void* p, void* p2, float p3);

extern "C" void fn_27_2344E8(FnObj* self, float f) {
    FnChild* result = (FnChild*)__nw__FUlQ25Heaps8HeapType(0x18, 0xf);
    if (result) {
        result = fn_27_236CE0(result, self->m_sub, f);
    }
    if (self->m_child) {
        delete self->m_child;
    }
    self->m_child = result;
}
