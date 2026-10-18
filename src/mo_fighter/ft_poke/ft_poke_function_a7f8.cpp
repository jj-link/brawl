#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_116_A7F8(void* self, u32 mask, u32 index) {
    u32* p = *(u32**)((u8*)self + 0x1c);
    p[index] &= ~mask;
}
