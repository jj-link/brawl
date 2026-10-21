#pragma force_active on
extern unsigned char *lbl_805A1170;

unsigned char fn_803A5C88(int arg0) {
    unsigned char *base;
    if (lbl_805A1170 != 0)
        base = lbl_805A1170 + 0x3600;
    else
        base = 0;
    return *(base + ((arg0 * 0x10) & 0xFFFF0) + 0x8C);
}
