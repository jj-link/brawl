#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" {
s32 fn_27_1B23D8(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    return (s32)((x << 14) & 0xFF000000) >> 25;
}
}
