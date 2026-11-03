#pragma force_active on
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef int s32;

extern s32 fn_803D6A50(void *, const void *, u32, s32, s32);
extern u32 fn_803D66F4(void *);
extern void *fn_803D6724(void *, u32);
extern u8 lbl_8059FEE4;
extern u8 lbl_8059FEF4;
extern u8 lbl_8059FEF8;
extern u8 lbl_8059FEFC;
extern u8 lbl_8059FF00;
extern u8 lbl_8059FF0C;
extern const u8 lbl_805A4AF8;
extern const u8 lbl_805A4AF9;

static inline s32 is_separator(void *arg0, u32 arg1, s16 i) {
    s32 sep = 0;
    if (fn_803D6A50(arg0, &lbl_8059FEF4, arg1, i, 1) == 0 ||
        fn_803D6A50(arg0, &lbl_8059FEF8, arg1, i, 1) == 0) {
        sep = 1;
    }
    return sep;
}

s32 fn_803E88BC(void *arg0, u32 arg1, u32 arg2) {
    u8 buf[2];
    s32 result;
    s16 i;
    u32 flag;
    s16 digit;
    s32 sep;
    buf[0] = lbl_805A4AF8;
    buf[1] = lbl_805A4AF9;
    result = 0;
    flag = 0;
    if (fn_803D6A50(arg0, buf, arg1, 0, 2) == 0 ||
        (fn_803D6A50(arg0, &lbl_8059FF00, arg1, 0, 1) == 0 &&
         (fn_803D6A50(arg0, &lbl_8059FF00, arg1, 1, 1) == 0 ||
          fn_803D6A50(arg0, &lbl_8059FEFC, arg1, 0, 1) == 0)) ||
        fn_803D6A50(arg0, &lbl_8059FEFC, arg1, 0, 1) == 0) {
        for (i = 2; i < 8 &&
             is_separator(arg0, arg1, i) == 0 &&
             fn_803D6A50(arg0, &lbl_8059FF0C, arg1, i, 1) != 0 &&
             fn_803D6A50(arg0, &lbl_8059FEE4, arg1, i, 1) != 0; i++) {
            if (fn_803D66F4(arg0) == 1) {
                digit = ((s8 *)fn_803D6724(arg0, arg1))[i] - '0';
            } else {
                digit = ((u16 *)fn_803D6724(arg0, arg1))[i] - '0';
            }
            if (digit < 0 || digit > 9) {
                if (arg2 == 0) {
                    break;
                }
                if (fn_803D6A50(arg0, &lbl_8059FEFC, arg1, i, 1) != 0 &&
                    fn_803D6A50(arg0, &lbl_8059FF00, arg1, i, 1) != 0) {
                    break;
                }
                if (arg2 == 1 &&
                    fn_803D6A50(arg0, &lbl_8059FEFC, arg1, i, 1) == 0) {
                    flag = 1;
                }
            }
        }
        if (i == 8 || flag == 1) {
            if (fn_803D6A50(arg0, &lbl_8059FF0C, arg1, i, 1) == 0 ||
                is_separator(arg0, arg1, i) == 0 ||
                fn_803D6A50(arg0, &lbl_8059FEE4, arg1, i, 1) == 0) {
                result = i;
            }
        }
    }
    return result;
}
