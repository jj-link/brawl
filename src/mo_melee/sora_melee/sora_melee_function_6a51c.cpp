#include <types.h>
#pragma force_active on

extern "C" void fn_27_6F3CC(void* list, void* node);
extern "C" u8 lbl_27_bss_110[0x10];

class SoraObj {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15(s32 a, s32* b);
    virtual void vf16(s32 a, s32* b, s32 c);
};

struct Locals {
    s32 d;
    s8 c;
    s32 a;
    s8 b;
};

extern "C" void fn_27_6A51C(SoraObj* self) {
    Locals l;
    l.a = 4;
    l.b = 0;
    self->vf15(-1, &l.a);
    l.d = 0;
    l.c = 0;
    self->vf16(-1, &l.d, 0);
    self->vf5();
    self->vf7();
    fn_27_6F3CC(lbl_27_bss_110, (u8*)self + 0x2C);
}
