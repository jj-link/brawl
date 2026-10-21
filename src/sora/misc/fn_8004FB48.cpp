#pragma force_active on
extern unsigned int lbl_8042BDC0[];
extern void* g_GameGlobal;
extern "C" unsigned int* fn_8004E588(void*);

inline int findIndex(unsigned int value) {
    for (int i = 0; i < 102; ++i) {
        if (value == lbl_8042BDC0[i]) {
            return i;
        }
    }
    return 102;
}

extern "C" void fn_8004FB48(unsigned int value) {
    int i = findIndex(value);
    if (i != 102) {
        unsigned int* bits = fn_8004E588(g_GameGlobal);
        bits[(i * 2) / 32] |= 1 << ((i * 2) % 32);
    }
}
