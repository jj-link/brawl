#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void CXInitUncompContextRL(u8* self, u32 a)
{
    *(u32*)(self + 0x0) = a;
    *(u32*)(self + 0x4) = 0;
    *(u8*)(self + 0xE) = 0;
    *(u16*)(self + 0xC) = 0;
    *(u8*)(self + 0xF) = 8;
    *(u32*)(self + 0x8) = 0;
}
