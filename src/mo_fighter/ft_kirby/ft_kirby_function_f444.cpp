#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_96_F444(u8* self, u32 mask, u32 index) {
    u32* flags = *(u32**)(self + 0x1c);
    flags[index] &= ~mask;
}
