#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_54_6974(const void *object)
{
    const u32 value = *(const u32 *)((const char *)object + 8);
    return (s32)((value << 4) & 0xF8000000u) >> 28;
}
