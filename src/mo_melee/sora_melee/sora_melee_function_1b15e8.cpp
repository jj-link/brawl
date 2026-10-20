#include <types.h>
#pragma force_active on

class Sec {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
};

class Pri {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    s32 a;
    s32 b;
    s32 c;
};

extern "C" {
void fn_27_1B15E8(Pri* p) {
    ((Sec*)((char*)p + 0x10))->f3();
}
}
