#include <types.h>
#pragma force_active on

class Visitor {
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
    virtual void f10(void** p);
};

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

extern "C" {
void fn_27_D8CF0(u8* self, Visitor* visitor) {
    u8* elem;
    void* sp8;
    s32 idx = (s32)((*(u32*)(self + 0x14) << 5) & 0xFC000000) >> 27;
    while (idx >= 0) {
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        elem = self + idx * 0x14;
        sp8 = elem + 0x1C;
        visitor->f10(&sp8);
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        idx = *(s8*)(elem + 0x29);
    }
}
}
