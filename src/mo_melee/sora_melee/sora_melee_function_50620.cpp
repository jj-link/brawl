#include <types.h>
#pragma force_active on

struct fn27Base1 {
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct fn27IBase {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

struct fn27Outer : public fn27Base1, public fn27IBase {
};

extern "C" void fn_27_50620(fn27Outer& p) {
    p.vf4();
}
