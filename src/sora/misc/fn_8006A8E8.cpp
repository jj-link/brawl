#include <gf/gf_application.h>
#pragma force_active on

struct Ctx {
    int f0;
    int f4;
    int f8;
    int fC;
    int f10;
    unsigned char* f14;
    unsigned char f18;
    unsigned char f19;
    unsigned char f1A;
    unsigned char f1B;
    unsigned char f1C;
    unsigned char f1D;
};

struct Obj {
    unsigned char pad[0x1D0];
    Ctx* unk1D0;
};

extern "C" unsigned char* fn_8006A76C(unsigned char* self, unsigned char* script);

extern "C" unsigned char fn_8006A8E8(void* arg0) {
    int rate = g_gfApplication->m_frameRate;
    if (rate <= 0) rate = 1;
    Ctx* c = ((Obj*)arg0)->unk1D0;
    if (c->f0 != 0 && ((*(unsigned int*)((char*)g_gfApplication + 0xEC) >> 27) == 0)) {
        int v = c->f10 - (0x0E100000 / rate);
        c->f10 = v;
        if (v <= 0) {
            c->f14 = fn_8006A76C((unsigned char*)arg0, c->f14);
        }
    }
    return c->f1D;
}