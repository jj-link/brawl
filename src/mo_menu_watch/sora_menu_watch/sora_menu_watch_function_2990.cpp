#pragma force_active on
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>

extern "C" void fn_80075F1C(void*, u32, int);

struct Vec2 {
    float x, y;
    Vec2() {}
    Vec2(const Vec2& o) { x = o.x; y = o.y; }
};

struct PadStatus {
    int w[6];
    Vec2 v[3];
    unsigned char b0, b1, b2, b3, b4, b5, b6, b7, b8;
    int last;
};

struct Raw {
    int w[16];
};

inline Raw getRaw() {
    Raw s;
    g_gfPadSystem->getSysPadStatus(0xF0, (gfPadStatus*)&s);
    return s;
}

extern "C" int fn_15_2990(char* self) {
    int ret = *(int*)(self + 0x504);
    int state = *(int*)(self + 0x4ec);

    if (state == 3)
        goto state3;
    if (state >= 3)
        goto state_ge3;
    if (state >= 2)
        goto state2;
    goto state_done;

state_ge3:
    if (state == 5)
        goto state_done;
    if (state >= 5)
        goto state_done;
    ret = 9;
    goto state_done;

state3:
    if (*(u32*)(self + 0xd68) + 0x10000 != 0xffff) {
        fn_80075F1C(g_sndSystem, *(u32*)(self + 0xd68), 0);
        *(int*)(self + 0xd68) = -1;
    }
    g_sndSystem->playSE((SndID)0x1EF3, -1, 0, 0, -1);
    ret = 2;
    goto state_done;

state2:
    if (*(u32*)(self + 0xd68) + 0x10000 == 0xffff) {
        *(int*)(self + 0xd68) = g_sndSystem->playSE((SndID)0x1EF2, -1, 0, 0, -1);
    }

state_done:
    int t = *(int*)(self + 0x518) - 1;
    *(int*)(self + 0x518) = t;
    if (t < 0) {
        PadStatus b(*(PadStatus*)&getRaw());
        if ((b.w[3] & 0x200) || (b.w[3] & 0x100) || (b.w[3] & 0x1000)) {
            g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
            if (state == 2) {
                return 10;
            }
            *(int*)(self + 0x48) = 2;
            return 11;
        }
    }
    return ret;
}