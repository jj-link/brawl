#pragma force_active on
extern char lbl_80529CF8[];

void fn_8023E27C(int arg0) {
    char *p;
    unsigned int idx;
    int mode;
    unsigned int sub;
    void (*fn)(void *, int, int, int);

    idx = *(unsigned char *)(lbl_80529CF8 + 0x564);
    if (idx < 4) {
        p = lbl_80529CF8 + idx * 0x22;
        if (arg0 == 0) {
            *(unsigned char *)(p + 0x4EC) = 4;
            mode = 4;
        } else {
            mode = 5;
        }
        sub = *(unsigned char *)(lbl_80529CF8 + 0x565);
        if (sub != 0x80) {
            p = lbl_80529CF8 + (sub << 3 & 0x7F8);
            if (*(unsigned char *)(p + 0x558) & 2) {
                fn = *(void (**)(void *, int, int, int))(p + 0x554);
                fn(lbl_80529CF8 + 0x3C + *(unsigned char *)(lbl_80529CF8 + 0x564) * 0x11C, mode, 0, arg0);
            }
        }
        *(unsigned char *)(lbl_80529CF8 + 0x564) = 4;
    }
}
