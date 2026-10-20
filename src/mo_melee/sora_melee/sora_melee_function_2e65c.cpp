#include <types.h>
#pragma force_active on

class fnInner {
public:
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
    virtual void f15(void* self, u32 arg, s32 flag);
};

class fnOuter {
public:
    u8 pad[0x44];
    fnInner* m_44;
};

extern "C" {
void fn_27_2E65C(fnOuter* self, u32 arg) {
    self->m_44->f15(self, arg, 1);
}
}
