#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_1D578(void* p)
{
    u32 w = *(u32*)((char*)p + 8);
    s32 v = (s32)(((w << 4) | (w >> 28)) & 0xF8000000);
    return v >> 28;
}
}
