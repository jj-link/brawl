#include <types.h>
#pragma force_active on

extern "C" s32 fn_121_B688();

extern "C" float fn_121_B630(char* self, void*, s32 x, s32 y) {
    char* p = self + fn_121_B688() * 0x54;
    float* arr = *(float**)(p + x * 4 - 0x3E70);
    return arr[y];
}
