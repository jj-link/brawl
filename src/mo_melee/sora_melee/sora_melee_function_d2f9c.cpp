#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D2F9C(void* p)
{
    u32 v = ((u32*)p)[2];
    s32 r = (s32)((v << 6) & 0xF0000000);
    return r >> 29;
}
}
