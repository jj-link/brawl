#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void fn_40_152F4(u8* self, u32 a, u32 b, u32 c)
{
    *(u32*)(self + 0x40) = a;
    *(u32*)(self + 0x50) = b;
    *(u32*)(self + 0x54) = c;
    *(u8*)(self + 0x4D) = 1;
}
