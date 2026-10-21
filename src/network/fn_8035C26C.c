#include <revolution/SO/SOBasic.h>
#pragma force_active on

extern int lbl_805A1044;

int socket(int domain, int type) {
    int result = SOSocket(domain, type, 0);
    if (result >= 0)
        return result;
    lbl_805A1044 = result;
    return -1;
}
