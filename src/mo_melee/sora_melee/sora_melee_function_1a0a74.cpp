#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_27_1A0A74(const void *p)
{
    u32 value = *(const u32 *)((const char *)p + 8);
    value = (value << 10) & 0xFC000000;
    return (s32)value >> 27;
}
