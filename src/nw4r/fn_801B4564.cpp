#include <types.h>
#pragma force_active on

struct Vt {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9(u32* p);
};

extern "C" void fn_801B4564(u8* self, u32* arg1) {
    u32 tmp = *arg1;
    Vt* o = *(Vt**)(self + 0xe8);
    o->f9(&tmp);
}
