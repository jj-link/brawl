#pragma force_active on
extern int fn_8024C7EC(unsigned int, unsigned char);
extern unsigned char lbl_80529CF8[];

void fn_80238378(void) {
    unsigned char *p;
    unsigned int i;

    i = 0;
    p = lbl_80529CF8 + 0x34;
    do {
        if (p[0x119] != 0) {
            fn_8024C7EC(*(unsigned short *)p, 3);
        }
        i++;
        p += 0x11C;
    } while (i < 4);
}
