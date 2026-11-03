#include <nw4r/ut/ut_algorithm.h>
#pragma force_active on

extern "C" int fn_803295B0(void* self, float* values, int count, void** data, float scale)
{
    int i = 0;
    int result = -1;
    float max = *(float*)((char*)self + 8) * *(float*)((char*)*data + *(signed char*)((char*)*(void**)self + 0x1c) * 0x3c + 0x1a58);
    for (i = 0; i < count; i++) {
        float value = scale * (float)(double)nw4r::ut::Abs(*values);
        if (value > max) {
            max = value;
            result = i;
        }
        values++;
    }
    return result;
}