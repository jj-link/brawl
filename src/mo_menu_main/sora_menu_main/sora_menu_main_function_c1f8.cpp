#include <gf/gf_pad_system.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern char lbl_2_data_1234[4];

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

extern "C" int fn_2_C1F8(char* self) {
    PadCopy status(*(PadCopy*)&getSysPad());
    if ((status.words[3] != 0) || (*(int*)(self + 0x19c) != 0)) {
        MuMsg* msg = *(MuMsg**)(self + 0xd4);
        msg->printf(6, lbl_2_data_1234);
        if (status.words[3] & 0x1100) {
            return 4;
        }
        return 3;
    }
    return *(int*)(self + 0x238);
}
