#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void* fn_801970EC(void* p, unsigned int index);
extern "C" void fn_80195FD8(void** pp, void* p, float f);

extern "C" void* fn_8019D3F8(u8* a, u8* b, s32 c) {
    void* r = fn_801970EC(a + 0x20, c);
    if (r == 0) {
        *(u32*)(b + 4) = 0;
        return b;
    }
    u32 base = *(u32*)(a + 0x2c);
    if (base != 0) {
        return (void*)(base + (*(u32*)((u8*)r + 0xc) << 6));
    }
    fn_80195FD8(&r, b, *(float*)(a + 0xc));
    return b;
}
