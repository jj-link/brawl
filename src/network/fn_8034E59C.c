#include <string.h>
#pragma force_active on

extern void *lbl_805A0FB0;

void fn_8034E59C(void *arg0) {
    lbl_805A0FB0 = arg0;
    memset(lbl_805A0FB0, 0, 0x918);
    *(unsigned short *)((char *)lbl_805A0FB0 + 0x910) = 0x5b9;
}
