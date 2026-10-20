#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_54360(void* p)
{
    u32 w = *(u32*)((char*)p + 8);
    s32 v = (s32)(((w << 18) | (w >> 14)) & 0xFFC00000);
    return v >> 23;
}
}
