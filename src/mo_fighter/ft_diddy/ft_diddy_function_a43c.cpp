#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_115_A43C(unsigned char* work, s32 value, u32 index) {
    s32* arr = *(s32**)(work + 0xc);
    arr[index] *= value;
}
