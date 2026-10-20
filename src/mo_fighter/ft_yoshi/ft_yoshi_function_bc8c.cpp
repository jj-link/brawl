#include <types.h>
#pragma force_active on

extern "C" s32 fn_95_BC80();

extern "C" s32 fn_95_BC8C(unsigned char* p, void* unused, s32 e, s32 f) {
    unsigned char* q = p - 0x10000;
    unsigned char* a = q + fn_95_BC80() * 0x1c;
    s32* t = *(s32**)(a + e * 4 - 0x7458);
    return t[f];
}
