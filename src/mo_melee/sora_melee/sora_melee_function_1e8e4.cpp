#include <types.h>
#pragma force_active on

class soVBase {
public:
    virtual void d0();
    virtual void d1();
    virtual void d2();
    virtual void d3();
    virtual void d4();
    virtual void d5();
    virtual void d6();
    virtual void d7();
    virtual void d8();
    virtual void d9();
    virtual void d10();
    virtual void d11();
    virtual void d12();
    virtual void d13();
    virtual void d14();
    virtual void d15();
    virtual void d16();
    virtual void d17();
    virtual void d18();
    virtual void d19();
    virtual void d20();
    virtual void d21();
    virtual void d22();
    virtual void d23();
    virtual void d24();
    virtual void d25();
};

class soVGetA : public soVBase {
public:
    virtual u32* get();
};

class soVGetB : public soVBase {
public:
    virtual u32* get(u32 idx);
};

extern "C" {
void fn_27_1E8E4(soVGetA* self, int unused, u32 idx) {
    u32* src = self->get();
    u32* dst = ((soVGetB*)self)->get(idx);
    *dst = *src;
}
}
