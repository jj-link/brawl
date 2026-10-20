#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_1454C0(const void* self);

extern "C" {
float fn_27_384530(const void* self, s32 unused, s32 i, s32 j) {
    s32 idx = fn_27_1454C0(self);
    float** tbl = (float**)((const char*)self + idx * 0x28 - 0x3E70);
    return tbl[i][j];
}
}
