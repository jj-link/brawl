#include <types.h>
#pragma force_active on

class Inner {
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
};

class Visitor {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void visit(void** p);
};

extern "C" {
void fn_27_D86F4(u8* self, Visitor* visitor) {
    u8* e;
    void* p;
    u32 w = *(u32*)(self + 0x14);
    s32 idx = (s32)(((w << 5) | (w >> 27)) & 0xFC000000) >> 27;
    while (idx >= 0) {
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        e = self + idx * 0x18;
        p = e + 0x1C;
        visitor->visit(&p);
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        idx = *(s8*)(e + 0x2D);
    }
}
}
