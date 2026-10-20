#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" u32 fn_27_34C984(char* self, u32 unused, s32 a, s32 b) {
    s32 idx = a - *(s32*)(self + 0x14);
    u32* arr = *(u32**)(self + 0x48 + idx * 4);
    return arr[b];
}
