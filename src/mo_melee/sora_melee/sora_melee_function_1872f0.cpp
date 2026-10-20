#include <types.h>
#pragma force_active on

class Obj {
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
    virtual void f10(int, int);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19(int);
};

extern "C" void fn_27_1872F0(void*, char* p, s32 type) {
    if (type == 0xea) {
        return;
    }
    if (type < 0xea && type == 0x42) {
        return;
    }
    ((Obj*)*(char**)(*(char**)(p + 0xd8) + 0x40))->f19(0);
    ((Obj*)*(char**)(*(char**)(p + 0xd8) + 0x40))->f10(0, 0);
}
