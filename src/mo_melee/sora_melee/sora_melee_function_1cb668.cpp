#include <types.h>
#pragma force_active on

class soSubBase {
public:
    virtual void* getPtr0();
    virtual void* getPtr3();
};

class soOuter {
public:
    u8 m_pad[0x10];
    soSubBase m_sub;
};

extern "C" s32 fn_27_1CB668(soOuter* self) {
    return *(s32*)((u8*)self->m_sub.getPtr3() + 4);
}
