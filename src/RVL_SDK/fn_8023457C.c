#pragma force_active on
extern unsigned char lbl_80529994[];
extern void fn_80232034(unsigned char *dst, const unsigned char *src);

void fn_8023457C(unsigned char *arg0) {
    unsigned char buf[9];
    if (arg0[0] == 0) {
        fn_80232034(buf, arg0 + 3);
        buf[6] = 2;
        buf[8] = arg0[2];
        ((void (*)(int, unsigned char *))(*(void **)(lbl_80529994 + 0x50)))(7, buf);
    }
}