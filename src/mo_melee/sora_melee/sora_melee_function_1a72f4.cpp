#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_1A72F4(const void* p)
{
    u32 x = *(const u32*)((const char*)p + 8);
    u32 field = (x >> 19) & 0x1F;
    return (s32)(field << 27) >> 28;
}
}
