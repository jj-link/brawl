#include <types.h>
#pragma force_active on

struct Work;

extern "C" Work* fn_27_1D53E4(Work* w, u32 a, u32 b);

struct Head {
    Work* w;
    u32 x;
    u32 y;
};

struct Outer : public Head {
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
    virtual void f13(u32 a, u32 b, u32 c);
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18(void* p);
};

extern "C" void* fn_27_1D6614(void* self, u32 unused, Outer* obj) {
    struct Arg {
        void* p;
        void* self;
        u32 zero;
    } arg;
    obj->f13(1, 0xc, 0);
    Work* r = fn_27_1D53E4((Work*)((char*)obj->w + 0x9e8), 0xc, 0);
    arg.p = r;
    arg.self = self;
    arg.zero = 0;
    obj->f18(&arg);
    return r;
}
