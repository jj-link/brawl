#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern int fn_802324E0(int arg);

void fn_80233B28(unsigned char *self) {
    short *p = (short *)fn_8022EE58(0x110);
    if (p != 0) {
        p[0] = 0x203;
        ((unsigned char *)p)[8] = self[1];
        fn_802324E0((int)p);
    }
}
