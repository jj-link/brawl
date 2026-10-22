#include <types.h>
#pragma force_active on

extern unsigned char lbl_8052CDC0[];

void *fn_8024FC18(unsigned int arg0, unsigned int arg1) {
    unsigned char *var_r5;
    unsigned char *p;

    var_r5 = 0;
    if (arg1 >= 0x40) {
        p = lbl_8052CDC0 + (unsigned short)(arg1 - 0x40) * 0x7C;
        var_r5 = p + 0x178;
        if (p[0x178] == 0) {
            var_r5 = 0;
        } else if (arg0 != 0 && arg0 != *(unsigned int *)(var_r5 + 0x10)) {
            var_r5 = 0;
        }
    }
    return var_r5;
}
