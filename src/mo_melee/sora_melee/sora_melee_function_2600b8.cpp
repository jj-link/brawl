#include <types.h>
#pragma force_active on

struct SoIface {
    virtual void pad0();
    virtual void funcA(int, int, int);
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void funcB(int, int);
};

struct SoParent {
    u8 pad0[0x44];
    SoIface** m_array;
    u8 pad1[0x58 - 0x48];
    s32 m_count;
    u8 pad2[0x6C - 0x5C];
    u8 m_flags;
};

extern "C" void fn_27_2600B8(SoParent* self) {
    u32 offset;
    u32 count = self->m_count;
    u32 i = 0;
    offset = 0;
    while (i < count) {
        SoIface* obj = *(SoIface**)((u8*)self->m_array + offset);
        obj->funcB(2, 0);
        obj->funcA(1, 0, 0);
        obj->funcB(2, 1);
        offset += 4;
        i++;
    }
    self->m_flags |= 2;
}
