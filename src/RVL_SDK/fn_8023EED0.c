#pragma force_active on
extern char lbl_80529CF8[];
extern int fn_803F6150(const void *, const void *, unsigned long);

void fn_8023EED0(const void *arg0) {
    char *p;
    unsigned short i;
    void (*fp)(unsigned short);

    p = lbl_80529CF8 + 0x1854;
    i = 0;
    while (i < 3) {
        if (*(unsigned short *)(p + 8) != 0 && 
            (arg0 == 0 || (fn_803F6150(p + 0x28, arg0, 6) == 0 && 
             *(unsigned char *)(p + 0xD) != 0))) {
            *(unsigned short *)(p + 8) = 0;
            *(int *)(p + 0x10) = 0;
            fp = *(void (**)(unsigned short))(p + 4);
            fp(i);
        }
        i++;
        p += 0x34;
    }
}
