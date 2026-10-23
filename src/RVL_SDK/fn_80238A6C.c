#pragma force_active on
extern char lbl_80529CF8[];

void fn_80238A6C(unsigned char *arg0) {
    int i;
    unsigned char *p;
    unsigned short key;

    p = (unsigned char *)lbl_80529CF8 + 0x34;
    if (arg0[0] != 0) {
        return;
    }

    key = (unsigned short)(arg0[1] + (arg0[2] << 8));
    for (i = 0; i < 4; i++) {
        if (p[0x119] != 0 && *(unsigned short *)p == key) {
            p[0x118] = arg0[3];
            *(short *)(p + 0x10A) = (short)(arg0[4] + (arg0[5] << 8));
            *(short *)(p + 0x10C) = (short)(arg0[6] + (arg0[7] << 8));
            return;
        }
        p += 0x11C;
    }
}
