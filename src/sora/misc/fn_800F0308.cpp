#include <gf/gf_pad_system.h>
#pragma force_active on
extern u32 lbl_80408BE8[4][2];
struct Vec2 { float x, y; Vec2() {} Vec2(const Vec2& o) { x = o.x; y = o.y; } };
struct PadCopy {
    int words[6];
    Vec2 vectors[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};
struct Self { char pad[0x48]; unsigned char port; };
static inline gfPadStatus getSysPad(int port) {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(port, &status);
    return status;
}
static inline int getType(PadCopy s) { return s.last; }
struct Pair { gfPadStatus raw; PadCopy b; Pair(int port) : raw(getSysPad(port)), b(*(PadCopy*)&raw) {} };
extern "C" int fn_800F0308(Self* self, int arg1) {
    int type = getType(*(PadCopy*)&getSysPad(self->port));
    u32 mask;
    if (type == 4) {
        mask = 0;
    } else {
        mask = lbl_80408BE8[type][arg1];
    }
    if (mask == 0) {
        return 0;
    }
    Pair p(self->port);
    return (p.b.words[3] & mask) != 0;
}
