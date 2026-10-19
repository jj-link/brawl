#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" s32 fn_97_B778();

extern "C" s32 fn_97_B784(u32 base, s32 unused, s32 i, s32 j) {
    s32 k = fn_97_B778() * 0x34;
    char* p = (char*)(base - 0x10000) + k;
    p = p + i * 4;
    s32* arr = *(s32**)(p - 0x7600);
    return arr[j];
}
