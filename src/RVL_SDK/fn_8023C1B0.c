#pragma force_active on
extern unsigned char fn_8023A5A4(void);
extern int fn_8022EFF8(int);
extern void fn_80246E84(int p, int arg1);
extern unsigned char lbl_80529CF8[];

int fn_8023C1B0(int arg0) {
    int r;

    if ((unsigned int)arg0 != 0 && (unsigned int)arg0 != 1) {
        return 5;
    }
    if (!(lbl_80529CF8[0x643] & 0x40)) {
        return 4;
    }
    if (!fn_8023A5A4()) {
        return 6;
    }
    r = fn_8022EFF8(2);
    if (r != 0) {
        fn_80246E84(r, arg0);
    } else {
        return 3;
    }
    return 0;
}
