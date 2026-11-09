#include <gm/gm_global.h>
#pragma force_active on
extern "C" unsigned int* fn_8004E5F8(void*);
inline bool testBit(unsigned int* bits, int idx) {
    int n = idx * 2;
    return bits[n / 32] & (1 << (n % 32));
}
inline void setBit(unsigned int* bits, int idx) {
    int n = idx * 2;
    bits[n / 32] |= (1 << (n % 32));
}
extern "C" void fn_80056DB0(int arg0) {
    int idx;
    switch (arg0) {
    case 0: idx = 30; break;
    case 1: idx = 31; break;
    case 2: idx = 32; break;
    }
    if (!testBit(fn_8004E5F8(g_GameGlobal), idx)) {
        setBit(fn_8004E5F8(g_GameGlobal), idx);
    }
}
