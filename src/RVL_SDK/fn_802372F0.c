#pragma force_active on
typedef unsigned short u16;
extern void *fn_8022EE58(u16 size);
extern void fn_802324E0(void *arg);
extern void *memset(void *s, int c, unsigned long n);
void fn_802372F0(short arg0) {
    short *p;
    p = (short *)fn_8022EE58(8);
    if (p != 0) {
        memset(p, 0, 8);
        p[0] = 0x1701;
        p[3] = arg0;
        fn_802324E0(p);
    }
}
