#include <string.h>
#pragma force_active on

extern int fn_803A73D8(int, void *);
extern int lbl_805A1044;

int fn_8035C384(int arg0, void *arg1, int arg2) {
    unsigned char buf[8];
    int result;
    memcpy(buf, arg1, 8);
    buf[0] = arg2;
    result = fn_803A73D8(arg0, buf);
    if (result >= 0) return result;
    lbl_805A1044 = result;
    return -1;
}