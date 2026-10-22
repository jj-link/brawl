#pragma force_active on
extern void *fn_8022EFF8(int size);
extern void fn_80242908(void *p);

int fn_80245468(unsigned char *arg0) {
    unsigned char *p = (unsigned char *)fn_8022EFF8(2);
    if (p == 0) {
        return 0;
    }
    *(unsigned short *)(p + 2) = 9;
    *(unsigned short *)(p + 4) = 0;
    p[8] = 0x1a;
    p[9] = 4;
    p[10] = 6;
    p[11] = arg0[5];
    p[12] = arg0[4];
    p[13] = arg0[3];
    p[14] = arg0[2];
    p[15] = arg0[1];
    p[16] = arg0[0];
    fn_80242908(p);
    return 1;
}
