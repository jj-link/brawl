#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern "C" s32 fn_27_1A1924(void *p) {
    u32 x = *(u32 *)((char *)p + 8);
    u32 t = (x << 6) & 0xFE000000;
    return (s32)t >> 26;
}
