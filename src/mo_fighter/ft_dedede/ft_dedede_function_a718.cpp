#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" void fn_117_A718(void* work, s32 value, u32 index) {
    s32* intWorks = *(s32**)((char*)work + 0x1c);
    intWorks[index] |= value;
}
