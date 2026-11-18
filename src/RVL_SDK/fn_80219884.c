#pragma force_active on
extern void *fn_8022E1E4(void);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern unsigned char lbl_804FBD58[];
extern unsigned char lbl_805A0C68[4];
extern unsigned char lbl_805A0C71;

int fn_80219884(void) {
    void *addr = fn_8022E1E4();
    int i;
    for (i = 0; i < 4; i++) {
        if (fn_803F6150(lbl_804FBD58 + (i + 10) * 0x46 + 1, addr, 6) == 0 && lbl_805A0C68[i] == 0) {
            lbl_805A0C68[i] = 1;
            return i;
        }
    }
    for (i = 0; i < 4; i++) {
        if (lbl_805A0C68[i] == 0) {
            lbl_805A0C68[i] = 1;
            memcpy(lbl_804FBD58 + (i + 10) * 0x46 + 1, addr, 6);
            lbl_805A0C71 = 1;
            return i;
        }
    }
    return -1;
}
