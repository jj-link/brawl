#include <nw4r/g3d/g3d_resmat.h>
#pragma force_active on

using namespace nw4r::g3d;

static inline GXColor makeColor(u32 ra, u32 bg) {
    GXColor c;
    c.r = ra;
    c.g = bg >> 12;
    c.b = bg;
    c.a = ra >> 12;
    return c;
}

extern "C" int fn_80191500(const ResMatTevColor* self, int id, GXColor* out) {
    u32 ra;
    u32 bg;
    const u8* e = self->ref().dl.m_tevKColor[id];
    if (e[0] == 0) {
        return 0;
    }
    ra = e[1] << 24;
    ra |= e[2] << 16;
    ra |= e[3] << 8;
    ra |= e[4];
    bg = e[6] << 24;
    bg |= e[7] << 16;
    bg |= e[8] << 8;
    bg |= e[9];
    GXColor t = makeColor(ra, bg);
    out->r = t.r;
    out->g = t.g;
    out->b = t.b;
    out->a = t.a;
    return 1;
}