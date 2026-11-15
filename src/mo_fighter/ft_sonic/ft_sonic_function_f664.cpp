#include <so/so_value_accesser.h>

#pragma force_active on

struct P5 { virtual void s0(); virtual void s1(); virtual void s2(); virtual int s3(); };
struct P11 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual float s9();
};
struct P18 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual float s16();
};
struct Pad8 { int a, b; };
struct P21 : Pad8 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(int, int);
};
struct P23 {
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual int s21();
};
struct Holder {
    char pad0[0x08]; P23* a; P11* b; P21* d; P5* e; char pad1[0x44]; P18* c;
};
struct Module { char pad[0xD8]; Holder* holder; };
extern "C" float lbl_123_rodata_28;

extern "C" void fn_123_F664(void*, Module* self) {
    if (self->holder->e->s3() != 0)
        return;
    switch (self->holder->a->s21()) {
    case 0x1D9: {
        int sgn;
        if (self->holder->b->s9() < lbl_123_rodata_28)
            sgn = -1;
        else
            sgn = 1;
        float fsgn = (float)sgn;
        P18* c = self->holder->c;
        float v = soValueAccesser::getConstantFloat((soModuleAccesser*)self, 0xC5C, 0);
        float t = c->s16();
        float p = t * fsgn;
        if (p <= v)
            self->holder->d->s19(2, 0);
        else
            self->holder->d->s19(1, 0);
        break;
    }
    }
}