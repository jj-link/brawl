#include <types.h>
#pragma force_active on

class Target {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual s32 s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11(f32);
};

struct Element {
    Target* target;
};

class Inner {
public:
    virtual void s0();
    virtual Element* s1(s32);
    virtual void s2();
    virtual s32 s3();
};

class Self {
public:
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual s32 m18();
    char pad[0x28];
    Inner* inner;
};

extern "C" void fn_27_943C4(Self* self, s32 arg1, f32 farg) {
    if (self->m18()) {
        s32 i = 0;
        while (i < self->inner->s3()) {
            if (self->inner->s1(i)->target != 0) {
                if (arg1 == self->inner->s1(i)->target->s6()) {
                    self->inner->s1(i)->target->s11(farg);
                }
            }
            i++;
        }
    }
}
