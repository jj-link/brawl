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
    virtual void v10(void** p);
};

extern "C" void fn_27_714A4(s16*, void*);

extern "C" {
void fn_27_D854C(u8* self, s16* mask, Visitor* visitor) {
    u8* elem;
    s32 idx = (s32)(((s32)(*(s32*)(self + 0x14) << 5)) & 0xFC000000) >> 27;
    while (idx >= 0) {
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        elem = self + idx * 0x18;
        s16 sp8;
        fn_27_714A4(&sp8, elem + 0x1C);
        if ((sp8 & *mask) != 0) {
            if (idx >= 0) {
                ((Inner*)(self + 0x10))->f13();
            }
            void* sp = elem + 0x1C;
            visitor->v10(&sp);
        }
        if (idx >= 0) {
            ((Inner*)(self + 0x10))->f13();
        }
        idx = (s8)(*(s8*)(elem + 0x2D));
    }
}
}
