#pragma force_active on
typedef float f32;
typedef int s32;

extern "C" f32 fn_27_318BCC(char* self, s32 unused, s32 a, s32 b)
{
    s32 base = *(s32*)(self + 0x10);
    f32* p = *(f32**)(self + (a - base) * 4 + 0x18);
    return p[b];
}
