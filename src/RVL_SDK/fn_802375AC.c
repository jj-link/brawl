#pragma force_active on
typedef unsigned short u16;

extern void *fn_8022EE58(u16 size);
extern void fn_802324E0(void *arg);
extern void *memset(void *s, int c, unsigned long n);

void fn_802375AC(void) {
    short *p;

    p = (short *)fn_8022EE58(8);
    if (p != 0) {
        memset(p, 0, 8);
        p[0] = 0x170E;
        fn_802324E0(p);
    }
}
