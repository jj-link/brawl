#include <types.h>
#pragma force_active on

struct fn_27_510A8_Inner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
};

struct fn_27_510A8_Outer {
    u32 unk0;
    u32 unk4;
    fn_27_510A8_Inner* unk8;
};

extern "C" void fn_27_510A8(fn_27_510A8_Outer* p) {
    p->unk8->vfunc4();
}
