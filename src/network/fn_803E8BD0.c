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
extern const u8 lbl_805A4AFC;
extern const u8 lbl_805A4AFD;

s32 fn_803E8BD0(void *arg0, s32 *arg1) {
    u8 buf[2];
    s32 result;
    s16 r29;
    s32 accum;
    s32 offset;
    s16 digit;

    buf[0] = lbl_805A4AFC;
    result = 0;
    buf[1] = lbl_805A4AFD;
    if (fn_803D6A50(arg0, buf, 1, 0, 2) == 0) {
        accum = 0;
        r29 = 2;
        offset = 4;
        while (r29 < 8 || fn_803D6A50(arg0, &lbl_8059FEE4, 1, r29, 1) != 0) {
            if (fn_803D66F4(arg0) == 1) {
                digit = (s8)((u8 *)fn_803D6724(arg0, 1))[r29] - 0x30;
            } else {
                digit = *(u16 *)((char *)fn_803D6724(arg0, 1) + offset) - 0x30;
            }
            if (digit < 0 || digit > 9) {
                break;
            }
            accum *= 10;
            offset += 2;
            r29++;
            accum += digit;
        }
        if (r29 == 8) {
            offset = 0;
            if (fn_803D6A50(arg0, &lbl_8059FEF4, 1, r29, 1) == 0 ||
                fn_803D6A50(arg0, &lbl_8059FEF8, 1, r29, 1) == 0) {
                offset = 1;
            }
            if (offset == 0 || fn_803D6A50(arg0, (void *)0, 1, r29, 1) == 0) {
                *arg1 = accum;
                result = 1;
            }
        }
    }
    return result;
}