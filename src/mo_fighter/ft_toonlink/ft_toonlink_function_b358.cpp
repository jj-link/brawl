#pragma force_active on
typedef unsigned int u32;
typedef int s32;
typedef unsigned char u8;

extern "C" void fn_121_B358(void* self, s32 value, u32 index) {
    s32* arr = *(s32**)((u8*)self + 0xc);
    arr[index] *= value;
}
