#pragma force_active on
#include <math.h>

class Inner {
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
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual float v18();
};

struct Middle {
    char pad[0x5c];
    Inner* m_5c;
};

struct Outer {
    char pad[0xd8];
    Middle* m_d8;
};

extern "C" {
extern const float lbl_27_rodata_26B0[9];

void fn_27_194458(Outer* arg0, float* arg1, float farg0) {
    const float* c = lbl_27_rodata_26B0;
    float result = arg0->m_d8->m_5c->v18();
    double d = (double)result;
    double dabs = fabs(d);
    float abs_val = (float)dabs;
    if (abs_val < farg0) {
        arg1[0] = c[0];
        arg1[1] = c[0];
    } else {
        if (result > c[0]) {
            arg1[1] = c[4];
            arg1[0] = (result - farg0) / (c[4] - farg0);
        } else {
            arg1[0] = (abs_val - farg0) / (c[4] - farg0);
            arg1[1] = c[8];
        }
    }
}
}
