#include <types.h>
#include <string.h>
#pragma force_active on
extern void fn_8022C0E8(void);
extern void fn_8023A460(void (*)(void));
extern int fn_8023B45C(u16, u8, u8 *, void (*)(s32));
extern u8 lbl_8047EF28[];
extern u8 lbl_805A0CE9;
extern u8 lbl_805A0CEA;

static inline int min(int a, int b) {
    return a < b ? a : b;
}

void fn_8022C494(s32 arg0) {
    u8 buf[255];
    if (arg0 != 0) {
        if (lbl_805A0CEA == lbl_805A0CE9) {
            fn_8023A460(fn_8022C0E8);
            return;
        }
        {
            u8 count = min(lbl_805A0CEA - lbl_805A0CE9, 19);
            s32 size = count * 13;
            buf[0] = count;
            memcpy(buf + 1, lbl_8047EF28 + lbl_805A0CE9 * 13 + 1, size);
            lbl_805A0CE9 += count;
            fn_8023B45C(0xFC4F, size + 1, buf, fn_8022C494);
        }
        return;
    }
    fn_8023A460(fn_8022C0E8);
}