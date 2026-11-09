#pragma force_active on
extern unsigned char lbl_8052CDC0[];
void *fn_8024FCD0(unsigned int id) {
    unsigned char *p = lbl_8052CDC0 + 0x650;
    unsigned char i;
    for (i = 0; i < 8; i++, p += 0x2c) {
        if (p[0] && *(unsigned short *)(p + 2) == id)
            return p;
    }
    return 0;
}