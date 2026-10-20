#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
u32 fn_27_3BAA78(char* p, s32 unused, s32 a, s32 b) {
    char* q = p + ((a - *(s32*)(p + 0x14)) << 2);
    u32* arr = *(u32**)(q + 0x28);
    return arr[b];
}
}
