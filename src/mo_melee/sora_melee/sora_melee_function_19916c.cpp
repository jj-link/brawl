#pragma force_active on
typedef unsigned long u32;
typedef long s32;

extern "C" {
s32 fn_27_19916C(void* p)
{
    u32 x = *(u32*)((char*)p + 8);
    u32 r = (x << 3) | (x >> 29);
    r &= 0xF0000000;
    return (s32)r >> 29;
}
}
