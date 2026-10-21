#include <math.h>
#pragma force_active on

extern const float lbl_27_rodata_26B0[];

class Obj {
public:
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

class Q {
public:
    char pad[0x5c];
    Obj* m_5c;
};

class Self {
public:
    char pad[0xd8];
    Q* m_d8;
};

class Out {
public:
    float m_0;
    float m_4;
};

extern "C" {
void fn_27_194390(Self* self, Out* out, float f) {
    const float* c = lbl_27_rodata_26B0;
    Obj* o = self->m_d8->m_5c;
    float x = o->v18();
    double d = fabs(x);
    float ax = (float)d;
    if (ax < f) {
        out->m_0 = c[0];
        out->m_4 = c[0];
        return;
    }
    if (x > c[0]) {
        out->m_4 = c[4];
        out->m_0 = (x - f) / (c[4] - f);
        return;
    }
    out->m_0 = (ax - f) / (c[4] - f);
    out->m_4 = c[8];
}
}
