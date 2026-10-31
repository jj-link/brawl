#include <math.h>
#include <so/so_value_accesser.h>

#pragma force_active on

struct A {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7(float);
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual int s21();
};

struct B {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual int s3();
};

struct C {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual double s12(unsigned long);
};

struct Holder {
    char pad0[0x08];
    A* a;
    char pad1[0x08];
    B* b;
    char pad2[0x4C];
    C* c;
};

struct Module {
    char pad[0xD8];
    Holder* holder;
};

extern "C" float lbl_123_rodata_28;
extern "C" float lbl_123_rodata_2C;

extern "C" void fn_123_F7D0(void*, Module* self) {
    if (self->holder->a->s21() == 0x1D9) {
        float value;
        if (self->holder->b->s3() == 0) {
            double magnitude = fabs(
                self->holder->c->s12(0x21000004UL));
            value = (float)magnitude;
            value /= soValueAccesser::getConstantFloat(
                (soModuleAccesser*)self, 0xFBE, 0);
        } else {
            double magnitude = fabs(
                self->holder->c->s12(0x21000005UL));
            value = (float)magnitude;
            value /= soValueAccesser::getConstantFloat(
                (soModuleAccesser*)self, 0xFBE, 0);
        }

        if (value < lbl_123_rodata_28) {
            value = lbl_123_rodata_28;
        } else if (value > lbl_123_rodata_2C) {
            value = lbl_123_rodata_2C;
        }

        A* a = self->holder->a;
        float constant = soValueAccesser::getConstantFloat(
            (soModuleAccesser*)self, 0xFBF, 0);
        float product = value * constant;
        a->s7(product);
    }
}
