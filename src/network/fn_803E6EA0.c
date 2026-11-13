#include <types.h>
#pragma force_active on
typedef struct { u8 *saved; u8 *cur; u8 *third; u32 mode; } Arg;
extern s32 fn_803D6A50(Arg *, void *, u32, s32, u16);
extern void fn_803D674C(Arg *, s16);
extern u32 fn_803D66F4(Arg *);
extern s32 fn_803E88BC(Arg *, u32, u32);
extern char lbl_805644C0[];
extern u8 lbl_8041B080[];
extern u8 lbl_8059FEE4, lbl_8059FEF4, lbl_8059FEF8, lbl_8059FEFC, lbl_8059FF00;
static inline s32 isvalid(u16 input) {
    s32 result = 0;
    u16 c = input;
    if (c >= 0x20 && !(c & 0xff00) && (lbl_8041B080[(u8)(c - 0x20)] & 1)) result = 1;
    return result;
}
s32 fn_803E6EA0(Arg *a, u32 b) {
    s32 n;
    Arg *arg0 = a;
    u32 arg1 = b;
    char *base;
    u8 *tab;
    u32 mode;
    u8 c;
    u32 w;
    s32 flag;
    n = 0;
    arg0->saved = arg0->cur;
    if (fn_803D6A50(arg0, &lbl_8059FEE4, 1, 0, 1) == 0) {
        arg0->cur = 0; arg0->saved = 0; return 0;
    }
    if (fn_803D6A50(arg0, &lbl_8059FEF4, 1, 0, 1) == 0 ||
        fn_803D6A50(arg0, &lbl_8059FEF8, 1, 0, 1) == 0) fn_803D674C(arg0, 1);
    if (fn_803D6A50(arg0, &lbl_8059FEF4, 1, 0, 1) == 0 ||
        fn_803D6A50(arg0, &lbl_8059FEF8, 1, 0, 1) == 0) return 2;
    mode = fn_803D66F4(arg0);
    arg0->cur = arg0->saved;
    base = lbl_805644C0;
    if ((*(u32 *)(lbl_805644C0 + 0x60) & 2) == 2) {
        n = fn_803E88BC(arg0, 2, arg1);
        if (n != 0) {
            if (mode == 1) arg0->cur += n;
            else arg0->cur += n * 2;
        }
    }
    if (n == 0) {
    base = lbl_805644C0;
    tab = lbl_8041B080;
    while (fn_803D6A50(arg0, &lbl_8059FEE4, 2, 0, 1) != 0) {
        if (mode == 1 && (*(s32 (**)(s32, s32))(lbl_805644C0 + 0x54))((s8)*arg0->cur, 1)) {
            arg0->cur++;
            if ((*(s32 (**)(s32, s32))(lbl_805644C0 + 0x54))((s8)*arg0->cur, 2) == 0 ||
                (s8)*arg0->cur == 0) return 2;
            goto inc;
        }
        if (fn_803D6A50(arg0, &lbl_8059FEF4, 2, 0, 1) == 0 ||
            fn_803D6A50(arg0, &lbl_8059FEF8, 2, 0, 1) == 0) break;
        if (*(u32 *)(lbl_805644C0 + 0x38) & 0x10000) goto inc;
        if (mode != 1 || (c = *arg0->cur) >= 0x80 || (c >= 0x20 && (lbl_8041B080[c - 0x20] & 1))) {
            if (mode == 2) {
                w = (arg0->cur[0] << 8) + arg0->cur[1];
                flag = 1;
                if ((u16)w < 0x80) {
                    s32 sep;
                    c = (u8)w;
                    sep = isvalid(c);
                    if (sep == 0) flag = 0;
                }
                if (flag == 0) goto block36;
            }
            goto inc;
        }
block36:
        if (arg1 == 0 || (fn_803D6A50(arg0, &lbl_8059FEFC, 2, 0, 1) != 0 &&
             fn_803D6A50(arg0, &lbl_8059FF00, 2, 0, 1) != 0)) return 2;
inc:
        if (mode == 1) arg0->cur++;
        else arg0->cur += 2;
    }
    }
    return 0;
}