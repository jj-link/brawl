#include <types.h>
#pragma force_active on

struct fn_8015DD80_Base {
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
    virtual void f15();
    virtual u8 f16();
};

struct Result {
    u8 a, b, c;
};

extern "C" Result fn_8015DD80(fn_8015DD80_Base* obj) {
    u8 value = obj->f16();
    Result result;
    result.a = 0;
    result.b = value;
    result.c = value;
    return result;
}
