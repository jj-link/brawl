#include <types.h>
#pragma force_active on

struct fn_27_A22A8_Base {
    u32 unk0;
    u32 unk4;
};

class fn_27_A22A8_Obj : public fn_27_A22A8_Base {
public:
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
    virtual void f14();
    virtual void f15(u32 arg);
};

extern "C" {
void fn_27_A22A8(char* base, u32 idx) {
    fn_27_A22A8_Obj* obj = *(fn_27_A22A8_Obj**)(base + ((idx >> 28) << 2) + 0x1c);
    obj->f15(idx & 0xFFFFFF);
}
}
