#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern int fn_802324E0(int arg);

void fn_80234D38(void) {
    short *p;

    p = (short *)fn_8022EE58(8);
    if (p != 0) {
        *p = 0x201;
        fn_802324E0((int)p);
    }
}
