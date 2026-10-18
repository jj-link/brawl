#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void fn_108_B2B8(u8* work, u32 value, u32 index) {
    u32* arr = *(u32**)(work + 0xc);
    arr[index] *= value;
}
