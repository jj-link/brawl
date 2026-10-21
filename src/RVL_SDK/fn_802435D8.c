#include <string.h>
#pragma force_active on

extern short lbl_805297D0[];

void fn_802435D8(void) {
    memset(lbl_805297D0, 0, 0x84);
    lbl_805297D0[0x3F] = 0x2A4;
    lbl_805297D0[0x40] = 1;
}
