#include <math.h>
#pragma force_active on

struct V {
    float x, y, z;
};

struct Mod {
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
    virtual float getFloat(unsigned long);
};

struct Mod2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual V get();
};

struct Mods {
    char p[0xC];
    Mod2* m;
    char q[0x54];
    Mod* w;
};

struct F {
    char p[0xD8];
    Mods* mods;
};

extern "C" {
extern const float lbl_93_rodata_64;
extern const float lbl_93_rodata_68;
void fn_93_1054C(V*, F*);
void fn_93_F174(V*, const V&);
V fn_93_10424(const V*, const V*);
float fn_93_FE68(const float*);
float rsqrtf__Ff(float);
}

extern "C" bool fn_93_102D0(F* f) {
    Mod* w = f->mods->w;
    V b, d, g, a;
    fn_93_1054C(&a, f);
    fn_93_F174(&b, a);
    fn_93_F174(&d, f->mods->m->get());
    fn_93_F174(&g, fn_93_10424(&b, &d));
    g.z = lbl_93_rodata_64;

    float h[2];
    h[0] = w->getFloat(0x11000013);
    h[1] = w->getFloat(0x11000014);

    float s = g.z * g.z + (g.x * g.x + g.y * g.y);
    float r;
    if ((float)fabs(s) <= lbl_93_rodata_68) {
        r = lbl_93_rodata_64;
    } else {
        r = s * rsqrtf__Ff(s);
    }
    return r <= fn_93_FE68(h);
}
