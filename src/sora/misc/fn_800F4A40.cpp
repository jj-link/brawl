#include <gf/gf_pad_system.h>
#include <gf/gf_homemenu.h>
#include <gf/gf_shutdown_manager.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern char lbl_8059E3D4[4];

struct Self {
    char pad0[0x60];
    int result;
    int timer;
    char pad68[0x24];
    MuMsg* msg;
    int state;
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

extern "C" int fn_800F4A40(Self* self) {
    if (++self->timer < 15)
        return self->result;
    PadCopy status(*(PadCopy*)&getSysPad());
    if ((status.words[3] & 0x100) || self->timer >= 60) {
        g_gfHomeMenu->setBan(0, 5);
        g_gfShutdownManager.unkD = true;
        self->msg->printf(3, lbl_8059E3D4);
        self->state = 1;
        return 11;
    }
    return self->result;
}