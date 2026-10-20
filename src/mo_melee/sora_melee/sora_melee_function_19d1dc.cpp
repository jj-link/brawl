#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_19D1DC(const void* p)
{
    u32 x = *(const u32*)((const char*)p + 8);
    return (s32)((x << 4) & 0xF8000000) >> 28;
}
}
