#pragma force_active on
extern unsigned char lbl_80529994[];
extern void fn_80232034(unsigned char *dst, const unsigned char *src);

void fn_80234510(unsigned char *arg0) {
    unsigned char buf[8];
    if (arg0[0] == 0) {
        fn_80232034(buf, arg0 + 3);
        buf[6] = 1;
        buf[7] = arg0[2];
        ((void (*)(int, unsigned char *))(*(void **)(lbl_80529994 + 0x50)))(7, buf);
    }
}