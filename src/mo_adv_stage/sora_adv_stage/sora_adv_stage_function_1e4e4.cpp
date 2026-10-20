#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" int fn_40_1E4E4(void* p)
{
    u32 x = *(u32*)((u8*)p + 8);
    return (int)(((x >> 19) & 0x7F) << 25) >> 26;
}
