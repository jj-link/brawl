#pragma force_active on
extern void fn_80232034(unsigned char *, const unsigned char *);
extern unsigned char fn_80247C00(void *, unsigned short, unsigned char *);
extern void fn_80237D10(void *, int, int, void *, int, int);
extern void fn_80237E20(void);
extern unsigned char fn_80247D90(unsigned char);
extern void fn_80237C90(void *);
extern void fn_802319E4(int, const char *);
extern unsigned char lbl_805A0D30;
extern char lbl_80529AC8[];
extern char lbl_80480188[];

void fn_80236B50(void *arg0, void *arg1) {
    unsigned char buf[8];
    unsigned char sp8;
    unsigned char *a = (unsigned char *)arg0;
    unsigned char *b = (unsigned char *)arg1;

    buf[6] = 6;
    buf[7] = 0xFF;

    switch (*(unsigned short *)(b + 0x10)) {
    case 11:
        fn_80232034(buf, b + 8);
        if (a[0x16] == 0xFF) {
            if (fn_80247C00(b + 8, *(unsigned short *)(b + 0x0E), &sp8) == 0) {
                buf[6] = 0;
                buf[7] = sp8;
                fn_80237D10(arg0, sp8, *(unsigned short *)(b + 0x0E), 0, b[0x12], b[0x13]);
                *(unsigned char *)(lbl_80529AC8 + sp8 + 0x214) = a[0x12];
            }
        } else {
            buf[7] = a[0x16];
            buf[6] = 0;
        }
        fn_80237E20();
        break;
    case 12:
        buf[7] = (unsigned char)*(unsigned short *)(b + 6);
        fn_80232034(buf, a + 8);
        if (a[0x1C] != 3 && fn_80247D90(buf[7]) == 0) {
            buf[6] = 0;
            fn_80237C90(arg0);
        }
        break;
    default:
        if (lbl_805A0D30 >= 5) {
            fn_802319E4(0x504, lbl_80480188);
        }
        break;
    }
    ((void (*)(unsigned short, unsigned char *, char *))(*(void **)(lbl_80529AC8 + 0x224)))(*(unsigned short *)(b + 0x10), buf, lbl_80529AC8);
}