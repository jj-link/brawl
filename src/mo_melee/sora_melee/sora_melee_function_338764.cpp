#pragma force_active on
typedef int s32;

extern "C" float fn_27_338764(void* self, s32 unused, s32 a, s32 b)
{
    s32* base = (s32*)self;
    char* p = (char*)self + (a - base[4]) * 4;
    float* arr = *(float**)(p + 0x18);
    return arr[b];
}
