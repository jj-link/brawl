#include <types.h>
#pragma force_active on

extern void fn_803A9644(void *a, void *b, int c);
extern void fn_803A9958(u8 *a, u32 b);

void fn_803B2DB0(u8 *dst, u8 *base, s32 idx, s32 val, s32 flag) {
    u8 *src;
    if (flag != 0) {
        dst[0] = idx | 0x40;
    } else {
        dst[0] = idx;
    }
    dst[0xB] = 0xF;
    dst[0xD] = val;
    dst[0xC] = 0;
    *(u16 *)(dst + 0x1A) = 0;
    src = base + (idx - 1) * 0x1A;
    if (flag != 0) {
        u16 *p = (u16 *)src;
        u16 *last = (u16 *)(src + 0x1A);
        while (p < last) {
            if (*p == 0) {
                p++;
                break;
            }
            p++;
        }
        for (; p < last; p++) {
            *p = 0xFFFF;
        }
    }
    fn_803A9644(dst + 1, src, 0xA);
    fn_803A9644(dst + 0xE, src + 0xA, 0xC);
    fn_803A9644(dst + 0x1C, src + 0x16, 4);
    fn_803A9958(dst + 1, 0xA);
    fn_803A9958(dst + 0xE, 0xC);
    fn_803A9958(dst + 0x1C, 4);
}
