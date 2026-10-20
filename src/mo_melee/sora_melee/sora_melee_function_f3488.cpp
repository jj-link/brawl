#include <types.h>
#pragma force_active on

struct fn27Vt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
};

struct fn27Obj {
    u32 unk0;
    u32 unk4;
    u32 unk8;
    u32 unkC;
    fn27Vt sub;
};

extern "C" void fn_27_F3488(fn27Obj* obj) {
    obj->sub.f13();
}
