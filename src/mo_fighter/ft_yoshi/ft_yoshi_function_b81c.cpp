#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_95_B81C(void* work, u32 mask, u32 index) {
    u32* flags = *(u32**)((u8*)work + 0x1c);
    flags[index] &= ~mask;
}
