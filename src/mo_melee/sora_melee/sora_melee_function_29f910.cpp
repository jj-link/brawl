#include <types.h>
#pragma force_active on

class fnObj {
public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5(s32 a, u32 b);
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
    virtual void f18(u32 a);
};

extern "C" {
void fn_27_29F910(u32 unused, char* p, s32 flag) {
    if (flag == 0) {
        char* a = *(char**)(p + 0x60);
        char* b = *(char**)(a + 0xd8);
        fnObj* obj = *(fnObj**)(b + 0x64);
        obj->f18(0x12000000);
        obj->f5(-1, 0x1000000b);
    }
}
}
