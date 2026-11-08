#include <types.h>
#pragma force_active on

extern void fn_80397748(void *, u32, u32);
extern void fn_80397818(void *, const void *, s32);
extern s32 fn_8039EDE8(void *, s32, void *, s32, s32 *);
extern s32 fn_80398BD8(s32, s32, s32);
extern char lbl_8049217C[];
extern int lbl_805A1170;
extern s32 lbl_805A1190;

s32 fn_8039EFE0(u8 *self) {
    u8 *entry;
    u8 *out;
    u32 i;
    s32 total = 0;
    s32 remain;
    s32 result = 0;
    s32 len;

    out = (u8 *)lbl_805A1170;
    fn_80397748(out, 0, 0x400);
    entry = self + 0x88;
    remain = 0x3FE;
    for (i = 0; i < self[0xC8]; i++) {
        fn_80397818(out, lbl_8049217C, remain);
        out += 9;
        result = fn_8039EDE8(entry, *(s32 *)(self + 4), out, remain, &len);
        if (result != 0) {
            break;
        }
        out += len;
        out[0] = 0xD;
        out[1] = 0xA;
        out += 2;
        remain -= len + 0xB;
        total += len + 0xB;
        if (remain <= 0) {
            result = -0xB;
            break;
        }
        entry += 8;
    }

    if (result == 0) {
        result = fn_80398BD8(lbl_805A1170, total, lbl_805A1190);
        if (result == 0) {
            *(s32 *)(self + 8) += total;
        }
    }
    return result;
}
