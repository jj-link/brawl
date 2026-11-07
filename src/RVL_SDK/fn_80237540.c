#include <string.h>
#pragma force_active on
extern void *fn_8022EE58(unsigned short size);
extern void fn_802324E0(void *arg);
void fn_80237540(short arg0) {
    short *p = (short *)fn_8022EE58(0x1c);
    if (p != 0) {
        memset(p, 0, 0x1c);
        p[0] = 0x170a;
        p[8] = 0xc;
        p[3] = arg0;
        fn_802324E0(p);
    }
}