#include <string.h>
#pragma force_active on

extern unsigned char lbl_8052C9B8[0x408];

void fn_80247A5C(void) {
    memset(lbl_8052C9B8, 0, 0x404);
    lbl_8052C9B8[0x401] = 0;
}
