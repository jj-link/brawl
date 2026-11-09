#pragma force_active on
extern int fn_8025FA94(void);
extern int fn_8025FB38(unsigned char *buffer, unsigned int size);
extern int fn_80406318(void *self, const unsigned char *src, unsigned int size);
extern unsigned char lbl_8059C3E8[];

int gdev_cc_peek(void) {
    unsigned char sp8[0x500];
    int temp_r3;

    temp_r3 = fn_8025FA94();
    if (temp_r3 <= 0) {
        return 0;
    }
    if (fn_8025FB38(sp8, temp_r3) == 0) {
        fn_80406318(lbl_8059C3E8, sp8, temp_r3);
    } else {
        return -0x2719;
    }
    return temp_r3;
}
