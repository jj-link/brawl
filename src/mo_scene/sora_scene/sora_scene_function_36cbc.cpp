#pragma force_active on
struct SceneState {
    unsigned char pad0[0x63];
    unsigned char f63;
    unsigned char f64;
    unsigned char pad1[0x68 - 0x65];
    unsigned int f68;
    unsigned int f6c;
    unsigned char pad2[0x9c - 0x70];
    signed char f9c;
    unsigned char pad3[0xf8 - 0x9d];
    signed char ff8;
};

struct GameGlobal {
    unsigned char pad0[8];
    SceneState* state;
};

extern GameGlobal* g_GameGlobal;

extern "C" {
int fn_1_36CBC() {
    SceneState* s = g_GameGlobal->state;
    unsigned int r3 = 0;
    if (s->f63 != 0 || s->f64 != 0 || ((r3 = s->f68) == 1 && s->f6c == 1)) {
        return 0;
    }
    if (r3 == 0) {
        s->f68 = 1;
        s->f9c = 0;
        s->ff8 = -1;
    } else {
        s->f68 = 0;
        s->f6c = 1;
        s->f9c = -1;
        s->ff8 = 0;
    }
    return 1;
}
}
