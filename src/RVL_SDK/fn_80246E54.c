#pragma force_active on
extern void fn_80242908(void *p, int b);

void fn_80246E54(void *p, int arg1) {
    unsigned char *b = (unsigned char *)p;
    *(short *)(b + 0x2) = 4;
    *(short *)(b + 0x4) = 0;
    b[0x8] = 0x43;
    b[0x9] = 0xC;
    b[0xA] = 1;
    b[0xB] = arg1;
    fn_80242908(p, arg1);
}
