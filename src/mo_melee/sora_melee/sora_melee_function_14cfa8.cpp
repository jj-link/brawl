#pragma force_active on
typedef unsigned int u32;

extern "C" {
u32 fn_27_14CFA8(char* a, char* b)
{
    u32 x = *(u32*)(b + 0x30);
    u32 y = *(u32*)(b + 0x38);
    u32 p = *(u32*)(a + ((y & 0x1f) << 2) + 0x50);
    u32 q = *(u32*)(a + ((x & 0x1f) << 2) + 0xb8);
    return p + q;
}
}
