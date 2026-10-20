#include <types.h>
#pragma force_active on

class fn27Inner {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
};

class fn27Outer {
public:
    s32 unk0;
    s32 unk4;
    s32 unk8;
    fn27Inner inner;
};

extern "C" void fn_27_D5A38(fn27Outer* p) {
    p->inner.vf4();
}
