#pragma force_active on
extern unsigned char lbl_8052CDC0[0x7E8];

void *fn_8024FC74(short arg0)
{
    unsigned char *p = lbl_8052CDC0 + 0x650;
    unsigned char i;
    for (i = 0; i < 8; i++) {
        if (*p == 0) {
            *p = 1;
            *(short *)(p + 2) = arg0;
            return p;
        }
        p += 0x2C;
    }
    return 0;
}
