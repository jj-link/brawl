#pragma force_active on
struct Sub {
    unsigned char pad[0x1b];
    unsigned char v;
};

struct GameGlobal {
    unsigned char pad[0x38];
    Sub* sub;
};

extern GameGlobal* g_GameGlobal;

extern "C" {
unsigned int fn_8014FDC4(void) {
    unsigned int v = g_GameGlobal->sub->v;
    return (unsigned int)(-v | v) >> 31;
}
}
