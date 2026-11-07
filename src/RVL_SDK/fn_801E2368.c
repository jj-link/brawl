#pragma force_active on
extern unsigned short lbl_80468CC8[32];
unsigned char fn_801E2368(unsigned int arg0) {
    unsigned short *p;
    int i;
    if (arg0 > 0xffU) return 0;
    if (arg0 < 0x80U || arg0 > 0x9fU) return arg0;
    if (arg0 >= 0x152U && arg0 <= 0x2122U) {
        p = lbl_80468CC8;
        for (i = 0; i < 32; i++) {
            if (arg0 == *p) return i + 0x80;
            p++;
        }
    }
    return 0;
}