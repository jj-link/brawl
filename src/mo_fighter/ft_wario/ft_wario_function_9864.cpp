#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_110_9864(unsigned char* work, u32 mask, u32 index) {
    u32* flags = *(u32**)(work + 0x1c);
    flags[index] &= ~mask;
}
