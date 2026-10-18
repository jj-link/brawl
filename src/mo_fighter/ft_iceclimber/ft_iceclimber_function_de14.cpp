#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" void fn_105_DE14(u8* self, s32 value, u32 index) {
    s32* arr = *(s32**)(self + 0xc);
    arr[index] += value;
}
