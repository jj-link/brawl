#pragma force_active on
extern void fn_80239968(void *p);
extern char lbl_804FB4A0[];

int fn_8022A964(void) {
    int i;
    char *p;
    char *base = lbl_804FB4A0;

    p = base + 0xE4;
    for (i = 0; i < 10; i++) {
        if ((unsigned char)p[0x59] > 1) {
            fn_80239968(p + 0x40);
        }
        p += 0x60;
    }
    p = base + 0x4A4;
    for (i = 0; i < 6; i++) {
        if ((unsigned char)p[0x59] > 1) {
            fn_80239968(p + 0x40);
        }
        p += 0x60;
    }
    return 3;
}
