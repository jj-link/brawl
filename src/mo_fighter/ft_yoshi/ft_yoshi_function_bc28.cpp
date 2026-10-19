#include <types.h>
#pragma force_active on

extern "C" s32 fn_95_BC80();

extern "C" float fn_95_BC28(unsigned char* base, s32 unused, s32 i, s32 j) {
    unsigned char* q = base + fn_95_BC80() * 0x14c;
    float* p = *(float**)(q + i * 4 - 0x3e70);
    return p[j];
}
