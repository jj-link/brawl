#include <types.h>
#pragma force_active on

class Target {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual s32 getId();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void apply(f32);
};

struct Element {
    Target* target;
};

class Inner {
public:
    virtual void v0();
    virtual Element* get(s32);
    virtual void v2();
    virtual s32 size();
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
    Inner* m_inner;
};

extern "C" void fn_27_942B4(Self* self, s32 arg1, f32 farg) {
    if (self->m18()) {
        s32 i = 0;
        while (i < self->m_inner->size()) {
            if (self->m_inner->get(i)->target != 0) {
                Target* t = self->m_inner->get(i)->target;
                if (arg1 == t->getId()) {
                    Target* t2 = self->m_inner->get(i)->target;
                    t2->apply(farg);
                }
            }
            i++;
        }
    }
}