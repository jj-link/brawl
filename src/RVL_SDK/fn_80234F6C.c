#include <types.h>
#pragma force_active on

extern void (*lbl_8040D7E0[])(unsigned short *);
extern char lbl_8040D814[];

int fn_80234F6C(unsigned short *arg0) {
    unsigned char *table = (unsigned char *)lbl_8040D814;
    int i;
    unsigned short v;
    unsigned char c;

    for (i = 0; i < 2; i++) {
        v = *arg0;
        c = *((unsigned char *)(i + (unsigned int)table) +
              (((v << 2) & 0x3FC) - (v & 0xFF)));
        if (c == 0xD) {
            break;
        }
        lbl_8040D7E0[c](arg0);
    }
    return 1;
}
