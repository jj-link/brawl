#pragma force_active on
extern int fn_803F6150(const void *, const void *, unsigned long);
extern unsigned char lbl_8052CDC0[];

unsigned char *fn_8024E73C(void *arg0) {
    int i;
    unsigned char *p;

    for (i = 0, p = lbl_8052CDC0 + 8; i < 4; i++, p += 0x5C) {
        if (*p != 0 && fn_803F6150(p + 0x2A, arg0, 6) == 0) {
            return p;
        }
    }
    return 0;
}
