#include <types.h>
#pragma force_active on

struct SoObj;

extern "C" void fn_27_2EA70(SoObj* self, void* a, void* b);

struct SoChild {
    virtual void v0();
    virtual SoObj* v3(int index);
    virtual void v4();
    virtual int v5();
};

struct SoOwner {
    u8 pad0[0x28];
    SoChild* m_child;
    u8 pad1[0x50 - 0x2C];
    u8 m_flags;
};

extern "C" void fn_27_262B8(SoOwner* self, void* a, void* b) {
    int count = self->m_child->v5();
    for (int i = 0; i < count; i++) {
        SoObj* obj = self->m_child->v3(i);
        fn_27_2EA70(obj, a, b);
    }
    self->m_flags = (self->m_flags & ~0x60) | 0x10;
}
