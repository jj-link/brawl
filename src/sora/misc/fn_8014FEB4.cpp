#pragma force_active on
struct X {
    int a;
    int b;
};

struct G {
    char pad[0x38];
    X* x;
};

extern "C" G* g_GameGlobal;

extern "C" X fn_8014FEB4(void) {
    return *g_GameGlobal->x;
}
