#include <types.h>
#pragma force_active on

extern char lbl_805644C0[];
void fn_803D65A4(unsigned int value, short *hi, short *lo);

s32 fn_803E7BB4(unsigned char *arg0) {
    s32 idx = 0;
    s32 total = 0;
    s16 sp[2];
    u32 sp8;
    s32 off;
    while (*(unsigned short *)(arg0 + (off = idx * 2)) != 0) {
        u32 r = ((u32 (*)(unsigned char *, u32 *))(*(void **)(lbl_805644C0 + 0x4C)))(arg0 + off, &sp8);
        fn_803D65A4(r, &sp[1], &sp[0]);
        total += sp[1];
        idx += sp[0] >> 1;
    }
    return total;
}
