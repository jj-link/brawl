#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_D11A4(void* p)
{
    u32 v = ((u32*)p)[2];
    s32 t = (s32)(((v >> 15) & 0x1FF) << 23);
    return t >> 24;
}
}
