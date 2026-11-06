#pragma force_active on
extern void fn_802501E4(void *);
extern unsigned char lbl_8052CDC0[];

void fn_8024D3AC(void) {
    unsigned char *p;
    int i;

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