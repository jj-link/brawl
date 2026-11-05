#pragma force_active on
extern unsigned char lbl_8052CDC0[];
extern int fn_8024C7EC(unsigned int, unsigned char);

void fn_80250060(void) {
    int i = 0;
    unsigned char *p = lbl_8052CDC0 + 8;
    do {
        if (*p != 0 && *(unsigned short *)(p + 0x28) != 0xffff) {
            fn_8024C7EC(*(unsigned short *)(p + 0x28), 0xff);
        }
        i++;
        p += 0x5c;
    } while (i < 4);
}
