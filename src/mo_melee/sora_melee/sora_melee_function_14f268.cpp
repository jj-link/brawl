#pragma force_active on
typedef unsigned int u32;
typedef signed int s32;

extern "C" {
int fn_27_14F268(void *p) {
    u32 x = *(u32 *)((char *)p + 8);
    u32 r = (x << 7) | (x >> 25);
    return (s32)(r & 0xFF000000) >> 25;
}
}
