#pragma force_active on
typedef unsigned int u32;

extern "C" void fn_97_B340(unsigned char* work, u32 mask, u32 index) {
    u32* flags = *(u32**)(work + 0x1c);
    flags[index] |= mask;
}
