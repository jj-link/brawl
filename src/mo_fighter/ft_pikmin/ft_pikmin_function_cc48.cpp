#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" {
void fn_113_CC48(u8* work, u32 mask, u32 index) {
    u32* flags = *(u32**)(work + 0x1c);
    flags[index] &= ~mask;
}
}
