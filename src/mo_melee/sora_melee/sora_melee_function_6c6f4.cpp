#include <types.h>
#pragma force_active on

extern "C" u32 fn_27_6F30C(void*);

struct Vt {
    virtual void f0();
    virtual u8* f1();
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
};

extern "C" void fn_27_6C6F4(u8* self) {
    Vt* a = *(Vt**)(self + 0x48);
    u8* b = a->f1();
    u32 x = fn_27_6F30C(b + 0x1c);
    x = *(u32*)(x + 0x44);
    x = *(u32*)(x + 0xd8);
    Vt* o = *(Vt**)(x + 0x8);
    o->f12();
}
