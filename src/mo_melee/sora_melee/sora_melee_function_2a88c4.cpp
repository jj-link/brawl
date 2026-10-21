#include <types.h>
#pragma force_active on

class Obj27 {
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
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual s32 f25(s32 a);
};

struct Low {
    u8 pad[0x90];
    Obj27* obj;
};

struct Mid {
    u8 pad[0xD8];
    Low* low;
};

struct Actor {
    u8 pad[0x60];
    Mid* mid;
};

class Inner {
public:
    virtual void v0();
    virtual void** get(s32 index);
    virtual void v2();
    virtual s32 count();
};

struct Outer {
    u8 pad[0x6D8];
    Inner inner;
};

extern "C" {
void* fn_27_2A88C4(Outer* self, s32 arg1) {
    for (s32 i = 0; i < self->inner.count(); i++) {
        void** slot = self->inner.get(i);
        Actor* a = (Actor*)*slot;
        if (a != NULL) {
            if (a->mid->low->obj->f25(arg1) >= 0) {
                return *slot;
            }
        }
    }
    return NULL;
}
}
