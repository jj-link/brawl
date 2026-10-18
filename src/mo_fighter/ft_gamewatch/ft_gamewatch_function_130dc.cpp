#include <math.h>
#pragma force_active on

class VD {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual double s12(unsigned long id);
};

class VF {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual float s12(unsigned long id);
};

class VV {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(float v);
};

extern "C" void fn_107_130DC(void* unused, char* self) {
    VD* a = *(VD**)(*(char**)(self + 0xd8) + 0x64);
    double x = a->s12(0x21000005UL);
    double ax = fabs(x);
    float f31 = (float)ax;

    VF* b = *(VF**)(*(char**)(self + 0xd8) + 0x64);
    float y = b->s12(0x21000007UL);
    float prod = f31 * y;

    VV* c = *(VV**)(*(char**)(self + 0xd8) + 0x08);
    c->s7(prod);
}
