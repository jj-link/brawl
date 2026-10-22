#include <math.h>
#pragma force_active on

struct V { float x, y, z; };
struct Mod { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual float getFloat(unsigned long); };
struct Mod2 { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual V get(); };
struct Mods { char p[0xC]; Mod2* m; char q[0x54]; Mod* w; };
struct F { char p[0xD8]; Mods* mods; };

extern "C" {
extern const float lbl_121_rodata_64;
extern const float lbl_121_rodata_68;
void fn_121_10598(V*, F*);
void fn_121_F12C(V*, const V&);
V fn_121_10470(const V*, const V*);
float fn_121_FEB4(const float*);
float rsqrtf__Ff(float);
}

extern "C" bool fn_121_1031C(F* f) {
    Mod* w = f->mods->w;
    V b, d, g, a;
    fn_121_10598(&a, f);
    fn_121_F12C(&b, a);
    fn_121_F12C(&d, f->mods->m->get());
    fn_121_F12C(&g, fn_121_10470(&b, &d));
    g.z = lbl_121_rodata_64;
    float h[2];
    h[0] = w->getFloat(0x11000013);
    h[1] = w->getFloat(0x11000014);
    float s = g.z * g.z + (g.x * g.x + g.y * g.y);
    float r;
    if ((float)fabs(s) <= lbl_121_rodata_68) {
        r = lbl_121_rodata_64;
    } else {
        r = s * rsqrtf__Ff(s);
    }
    return r <= fn_121_FEB4(h);
}
