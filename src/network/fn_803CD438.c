#pragma force_active on
typedef unsigned char u8;
typedef int s32;

extern s32 lbl_805A1250;
extern u8 lbl_805A1258;

s32 fn_803CD438(void) {
    u8 *ptr;
    ptr = &lbl_805A1258;
    if (lbl_805A1250 != 0) {
        ptr = (u8 *)(lbl_805A1250 + 0x1B3C);
    }
    return *ptr & 1;
}
