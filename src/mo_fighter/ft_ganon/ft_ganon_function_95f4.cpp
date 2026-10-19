#include <types.h>
#pragma force_active on

extern "C" s32 fn_109_964C();

extern "C" float fn_109_95F4(char* base, s32 unused, s32 i, s32 j) {
    char* p = (char*)base + fn_109_964C() * 0x6c;
    float* arr = *(float**)(p + (i << 2) - 0x3e70);
    return arr[j];
}
