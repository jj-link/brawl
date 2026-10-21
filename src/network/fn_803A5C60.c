#pragma force_active on
typedef int s32;
typedef unsigned int u32;

extern unsigned char *lbl_805A1170;

s32 fn_803A5C60(s32 arg0) {
    unsigned char *base;

    if (lbl_805A1170 != 0) {
        base = lbl_805A1170 + 0x3600;
    } else {
        base = 0;
    }
    return *(s32 *)(base + (((u32)arg0 & 0xFFFF) << 4) + 0x84);
}
