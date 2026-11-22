#include <gf/gf_pad_system.h>
#pragma force_active on
extern unsigned int lbl_80408C38[];
struct Self { char pad[0x48]; unsigned char port; };
struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(const Vec2& other) { x = other.x; y = other.y; }
};
struct PadCopy {
    int words[6];
    Vec2 vectors[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};
static inline PadCopy getPadCopy(int port) {
    gfPadStatus raw;
    g_gfPadSystem->getSysPadStatus(port, &raw);
    gfPadStatus copy = raw;
    return PadCopy(*(PadCopy*)&copy);
}
static inline int getType(int port) {
    return getPadCopy(port).last;
}
extern "C" bool fn_800F0CD8(Self* self) {
    PadCopy status = getPadCopy(self->port);
    int type = getType(self->port);
    if (type == 4)
        return false;
    unsigned int mask = lbl_80408C38[type];
    return (mask & status.words[1]) != 0;
}
