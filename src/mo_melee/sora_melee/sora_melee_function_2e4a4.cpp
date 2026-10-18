#include <types.h>
#pragma force_active on

class IDispatch {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual s32 vf6(void* outer, u32 arg);
};

class Outer {
public:
    u8 pad[0x44];
    IDispatch* m_44;
};

extern "C" s32 fn_27_2E4A4(Outer* self, u32 arg) {
    return self->m_44->vf6(self, arg);
}
