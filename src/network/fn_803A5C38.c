#pragma force_active on
extern unsigned char *lbl_805A1170;

int fn_803A5C38(int arg0) {
    unsigned char *base;
    if (lbl_805A1170 != 0) {
        base = lbl_805A1170 + 0x3600;
    } else {
        base = 0;
    }
    return *(int*)(base + ((arg0 << 4) & 0xFFFF0) + 0x88);
}
