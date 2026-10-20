#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

extern "C" {
s32 fn_27_303F7C(u8* p1, u32 p2, u32 p3) {
    return ((s32*)(p1 + 0x24))[p3 - *(s32*)(p1 + 0x18)];
}
}
