#include <types.h>
#pragma force_active on

struct FnBase {
    u32 unk0;
    u32 unk4;
};

struct FnObj : public FnBase {
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
    virtual void f12(u32 arg);
};

extern "C" void fn_27_A20A8(void* self, u32 arg) {
    FnObj* obj = *(FnObj**)((u8*)self + ((arg >> 26) & 0x3C) + 0x1c);
    obj->f12(arg & 0xFFFFFF);
}
