#pragma force_active on
typedef int s32;
typedef unsigned char u8;

extern s32 lbl_805A1250;
extern s32 lbl_8059FEA0[2];
extern u8 lbl_805A1258;
extern s32 fn_803CE570(void);

s32 fn_803CD32C(void) {
    u8 *ptr;
    s32 result;
    u8 b;
    s32 *p;

    if (lbl_805A1250 == 0) {
        return lbl_8059FEA0[0];
    }
    if (fn_803CE570() != 0) {
        return 6;
    }
    p = (s32 *) lbl_805A1250;
    ptr = &lbl_805A1258;
    if (p != 0) {
        ptr = (u8 *) p + 0x1B3C;
    }
    b = *ptr;
    result = 1;
    if ((b & 4) == 0) {
        if ((b & 8) == 0) {
            result = 0;
        }
    }
    if (result != 0) {
        return 5;
    }
    return p[0x6D0];
}
