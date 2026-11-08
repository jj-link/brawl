#include <gf/gf_pad_system.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#pragma force_active on
extern char lbl_8059E3D4[4];
struct Self {
    char pad[0x60];
    int result;
    int timer;
    int flag;
    char pad6c[0x20];
    MuMsg* msg;
};
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
static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xf0, &status);
    return status;
}
extern "C" int fn_800F3DD0(Self* self) {
    if (++self->timer < 15)
        return self->result;
    PadCopy status(*(PadCopy*)&getSysPad());
    if ((status.words[3] & 0x100) || self->timer >= 420) {
        g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
        unsigned int index = 5;
        if (self->flag == 0)
            index = 4;
        self->msg->printf(index, lbl_8059E3D4);
        return 5;
    }
    return self->result;
}