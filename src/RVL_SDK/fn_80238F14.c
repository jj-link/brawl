#pragma force_active on
extern char lbl_80529CF8[];

void fn_80238F14(unsigned int arg0, short arg1) {
    unsigned char *base = (unsigned char *)lbl_80529CF8;
    unsigned int r6 = 0;

    if (base[0x14D] != 0) {
        if (*(unsigned short *)(base + 0x34) == arg0) goto done;
    }
    r6 = 1;
    if (base[0x269] != 0) {
        if (*(unsigned short *)(base + 0x150) == arg0) goto done;
    }
    r6 = 2;
    if (base[0x385] != 0) {
        if (*(unsigned short *)(base + 0x26C) == arg0) goto done;
    }
    r6 = 3;
    if (base[0x4A1] != 0) {
        if (*(unsigned short *)(base + 0x388) == arg0) goto done;
    }
    r6 = 4;
done:
    if (r6 >= 4) {
        return;
    }
    *(short *)(lbl_80529CF8 + r6 * 0x11C + 0x3A) = arg1;
}
