#include <types.h>
#pragma force_active on

class soInnerArray {
public:
    u32 m_pad0;
    s32 m_count;
};

class soOwner {
public:
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc4(s32 index, s32 arg);
    u8 m_pad[0x20 - 4];
    soInnerArray* m_array;
};

extern "C" void fn_27_5B640(soOwner* self) {
    for (s32 i = 0; i < self->m_array->m_count; i++) {
        self->vfunc4(i, -1);
    }
}
