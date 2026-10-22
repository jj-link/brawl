#pragma force_active on
extern void *fn_8024E73C();
extern void fn_802501E4(void *);
extern unsigned char lbl_8052CDC0[];

void fn_8024D32C(int unused, unsigned char arg1) {
    unsigned char *temp_r3;
    unsigned char *p;
    int i;

    temp_r3 = (unsigned char *)fn_8024E73C(unused);
    if (temp_r3 != 0) {
        temp_r3[0x30] = arg1;
    }
    i = 0;
    p = lbl_8052CDC0 + 8;
    do {
        if (p[0] != 0 && *(int *)(p + 4) == 2) {
            fn_802501E4(p);
        }
        i++;
        p += 0x5C;
    } while (i < 4);
}
