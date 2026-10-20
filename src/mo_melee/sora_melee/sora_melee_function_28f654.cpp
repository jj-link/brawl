#include <types.h>
#pragma force_active on

struct Pad8 {
    u32 unk0;
    u32 unk4;
};

struct Obj : public Pad8 {
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
};

struct Mid {
    u8 pad[0x38];
    Obj* obj;
};

struct Outer {
    u8 pad[0x1a4];
    Mid* mid;
};

extern "C" int fn_27_28F654(Outer* p) {
    return p->mid->obj->f8();
}
