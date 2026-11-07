#include <stdio.h>
#pragma force_active on
extern int fn_80210118(void *, void *, int);
extern char lbl_8059EC98[6];
extern char lbl_8059ECA0[3];
int fn_80210344(unsigned int *value) {
    char buf[11];
    if (fn_80210118(lbl_8059EC98, buf, 11) && sscanf(buf, lbl_8059ECA0, value) == 1) {
        return 1;
    }
    return 0;
}