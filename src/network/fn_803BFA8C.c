#include <types.h>
#pragma force_active on

extern s32 fn_803A9DF8(void *, const void *, u32, s32, s32);
extern u32 fn_803A9A78(void *);
extern void *fn_803A9AA8(void *, u32);
extern u8 lbl_8059FE64;
extern u8 lbl_8059FE74;
extern u8 lbl_8059FE78;
extern u8 lbl_8059FE7C;
extern u8 lbl_8059FE80;
extern u8 lbl_8059FE8C;
extern const u8 lbl_805A49DC;
extern const u8 lbl_805A49DD;

static inline s32 is_separator(void *arg0, u32 arg1, s16 i) {
    s32 sep = 0;
    if (fn_803A9DF8(arg0, &lbl_8059FE74, arg1, i, 1) == 0 ||
        fn_803A9DF8(arg0, &lbl_8059FE78, arg1, i, 1) == 0) {
        sep = 1;
    }
    return sep;
}

s32 fn_803BFA8C(void *arg0, u32 arg1, u32 arg2) {
    u8 buf[2];
    s32 offset;
    s32 result;
    s16 i;
    u32 flag;
    s16 digit;
    buf[0] = lbl_805A49DC;
    result = 0;
    buf[1] = lbl_805A49DD;
    flag = 0;
    if (arg0 == 0) {
        return 10;
    }
    if (fn_803A9DF8(arg0, buf, arg1, 0, 2) == 0 ||
        (fn_803A9DF8(arg0, &lbl_8059FE80, arg1, 0, 1) == 0 &&
         (fn_803A9DF8(arg0, &lbl_8059FE80, arg1, 1, 1) == 0 ||
          fn_803A9DF8(arg0, &lbl_8059FE7C, arg1, 0, 1) == 0)) ||
        fn_803A9DF8(arg0, &lbl_8059FE7C, arg1, 0, 1) == 0) {
        i = 2;
        offset = 4;
        for (; i < 8 &&
             is_separator(arg0, arg1, i) == 0 &&
             fn_803A9DF8(arg0, &lbl_8059FE8C, arg1, i, 1) != 0 &&
             fn_803A9DF8(arg0, &lbl_8059FE64, arg1, i, 1) != 0; offset += 2, i++) {
            if (fn_803A9A78(arg0) == 1) {
                digit = ((s8 *)fn_803A9AA8(arg0, arg1))[i] - '0';
            } else {
                digit = *(u16 *)((char *)fn_803A9AA8(arg0, arg1) + offset) - '0';
            }
            if (digit < 0 || digit > 9) {
                if (arg2 == 0) {
                    break;
                }
                if (fn_803A9DF8(arg0, &lbl_8059FE7C, arg1, i, 1) != 0 &&
                    fn_803A9DF8(arg0, &lbl_8059FE80, arg1, i, 1) != 0) {
                    break;
                }
                if (arg2 == 1 &&
                    fn_803A9DF8(arg0, &lbl_8059FE7C, arg1, i, 1) == 0) {
                    flag = 1;
                }
            }
        }
        if (i == 8 || flag == 1) {
            if (fn_803A9DF8(arg0, &lbl_8059FE8C, arg1, i, 1) == 0 ||
                is_separator(arg0, arg1, i) == 0 ||
                fn_803A9DF8(arg0, &lbl_8059FE64, arg1, i, 1) == 0) {
                result = i;
            }
        }
    }
    return result;
}
