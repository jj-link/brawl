#include <types.h>
#pragma force_active on

// Object accessed at (holder + 8); virtual call through its vtable slot 0x50.
struct Target;
struct Holder {
    void* p0;
    void* p1;
    Target* obj;
};

struct Target {
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual s32 vfunc(int* a, s32 b, short* c, s8 d);
};

extern "C" s16 fn_27_1B1798(Holder* holder, int a, s8 b) {
    short s = 0;
    return holder->obj->vfunc(&a, -1, &s, b);
}
