#pragma force_active on
typedef int s32;

extern "C" {
float fn_27_3BAA58(s32* p, s32 unused, s32 a, s32 c)
{
    float* arr = ((float**)(p + (a - p[4])))[6];
    return arr[c];
}
}
