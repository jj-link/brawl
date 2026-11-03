#pragma force_active on
extern unsigned char lbl_8052CDC0[];

int fn_8024D2C0(void) {
    unsigned char *p;
    unsigned char *q;
    unsigned char *obj;
    unsigned int v;

    obj = *(unsigned char **)(lbl_8052CDC0 + 0x7bc);
    if (obj == 0 || (p = *(unsigned char **)(obj + 0x50)) == 0) {
        return 1;
    }
    q = p + *(unsigned short *)(p + 4);
    v = q[0xc] + ((unsigned int)q[0xd] << 8);
    if ((int)(unsigned short)v > (int)*(unsigned short *)(p + 2) - 8) {
        return 0;
    }
    *(unsigned char **)(obj + 0x50) = 0;
    return 1;
}
