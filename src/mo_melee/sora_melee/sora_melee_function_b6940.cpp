#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern "C" {
extern char* lbl_27_bss_5668;

int fn_27_B6940() {
    char* p = *(char**)(lbl_27_bss_5668 + 0xc4);
    u32 w = *(u32*)(p + 0x40);
    s32 r = (s32)(((w << 24) | (w >> 8)) & 0xFF800000) >> 24;
    switch (r) {
    case 0:
        return 0;
    case 1:
        return 1;
    default:
        return 0;
    }
}
}
