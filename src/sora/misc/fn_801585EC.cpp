#include <stdio.h>
#pragma force_active on

extern char lbl_80462120[];

extern "C" void fn_801585EC(int a, int b, int c, int d) {
    char buf[0x28];
    buf[0] = 0;
    if (d != 0) {
        sprintf(buf, lbl_80462120, d);
    }
}
