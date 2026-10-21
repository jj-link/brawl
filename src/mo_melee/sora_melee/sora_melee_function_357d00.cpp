#include <types.h>
#pragma force_active on

class Dummy {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(s32 a, u32 b);
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18(u32 a);
    virtual void f19(u32 a);
};

extern "C" {
void fn_27_357D00(u32 unused, char* p, s32 flag) {
    char* q = *(char**)(p + 0xd8);
    Dummy* obj = *(Dummy**)(q + 0x64);
    if ((u32)(flag - 4) <= 1U) {
        obj->f18(0x12000040);
    } else {
        obj->f19(0x12000040);
    }
    obj->f5(0, 0x10000040);
    obj->f19(0x12000041);
}
}
