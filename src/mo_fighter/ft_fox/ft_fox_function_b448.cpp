#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" void fn_97_B448(char* work, s32 value, u32 index) {
    s32* arr = *(s32**)(work + 0xc);
    arr[index] *= value;
}
