#include <types.h>
#pragma force_active on

extern u8 lbl_805639C0[];

void fn_803D8E00(u32 arg0, s32 arg1) {
    u16 i;
    u8 *p;
    u32 *flags;
    u32 flg;
    void (*f640)(u32 *, u32);
    void (*f63C)(u32 *, u32);
    for (i = 0; i < 0x1A; i++) {
        p = lbl_805639C0 + i * 0x28;
        flg = *(u32 *)(p + 0x61C);
        flags = (u32 *)(p + 0x61C);
        if ((flg & 1) && (*(u32 *)(p + 0x620) == arg0)) {
            *flags = flg | 2;
            if (arg1 == 0) {
                f640 = (void (*)(u32 *, u32)) *(void **)(p + 0x640);
                if (f640 != 0) {
                    f640(flags, flg);
                    goto done;
                }
            }
            f63C = (void (*)(u32 *, u32)) *(void **)(p + 0x63C);
            if (f63C != 0) {
                f63C(flags, flg);
            }
        }
    done:
        ;
    }
}