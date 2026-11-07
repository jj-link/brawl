#include <string.h>
#pragma force_active on

extern char lbl_80534030[];
extern char lbl_80534200[];
extern int lbl_805A0FD0;
extern int lbl_805A0FD4;
extern int lbl_805A0FD8;

void fn_80352040(int arg0) {
    memset(lbl_80534030, 0, 0x1D0);
    memset(lbl_80534200, 0, 0x174);
    lbl_805A0FD4 = 0;
    lbl_805A0FD8 = 0;
    lbl_805A0FD0 = arg0;
    *(int *)(lbl_80534030 + 0x1B8) = 0;
}
