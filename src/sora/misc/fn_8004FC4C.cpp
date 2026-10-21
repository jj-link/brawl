#pragma force_active on
extern int lbl_8042BDC0[];
extern void* g_GameGlobal;
extern "C" void* fn_8004E588(void*);

static inline int findIndex(unsigned int arg) {
    for (int i = 0; i < 102; ++i) {
        if (arg == (unsigned int)lbl_8042BDC0[i])
            return i;
    }
    return 102;
}

extern "C" void fn_8004FC4C(unsigned int arg) {
    int i = findIndex(arg);
    if (i != 102) {
        unsigned int* bits = (unsigned int*)fn_8004E588(g_GameGlobal);
        bits[(i * 2) / 32] &= ~(1 << ((i * 2) % 32));
    }
}
