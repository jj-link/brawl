#pragma force_active on
extern void *fn_8022EFF8(int);
extern void fn_80242908(void *);

int fn_80244B64(int arg0, int arg1) {
    unsigned char *p;

    p = fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(unsigned short *)(p + 0x2) = 6;
    *(unsigned short *)(p + 0x4) = 0;
    p[0x8] = 6;
    p[0x9] = 4;
    p[0xA] = 3;
    p[0xB] = arg0;
    p[0xC] = (arg0 >> 8) & 0xFF;
    p[0xD] = arg1;
    fn_80242908(p);
    return 1;
}
