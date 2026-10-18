#include <types.h>
#pragma force_active on

extern "C" float fn_27_896EC(float a, float b, float c, float d);

extern "C" void fn_27_8964C(u32* dest, const u32* src1, const u32* src2, const u32* src3, const u32* src4) {
    dest[0] = src1[0];
    dest[1] = src1[1];
    dest[2] = src1[2];
    ((float*)dest)[0] = fn_27_896EC(((const float*)src1)[0], ((const float*)src2)[0], ((const float*)src3)[0], ((const float*)src4)[0]);
    ((float*)dest)[1] = fn_27_896EC(((const float*)src1)[1], ((const float*)src2)[1], ((const float*)src3)[1], ((const float*)src4)[1]);
    ((float*)dest)[2] = fn_27_896EC(((const float*)src1)[2], ((const float*)src2)[2], ((const float*)src3)[2], ((const float*)src4)[2]);
}
