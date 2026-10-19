#include <types.h>
#pragma force_active on

extern "C" int fn_106_8698();

extern "C" float fn_106_8640(char* base, s32 unused, s32 i, s32 j) {
    char* p = base + (fn_106_8698() << 7);
    p = p + (i << 2);
    float* arr = *(float**)(p - 0x3E70);
    return arr[j];
}
