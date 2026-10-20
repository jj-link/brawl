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
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual ~fn27Inner() { }
};

class fn27Outer {
public:
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    fn27Inner inner;
};

extern "C" {
void fn_27_1C49CC(fn27Outer* p) {
    p->inner.vf13();
}
}
