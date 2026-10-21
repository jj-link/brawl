#include <types.h>
#pragma force_active on

extern int gUnk805a03d8;
extern char lbl_8045FC14[];
extern "C" void netReport__FPCce(const char*, ...);

extern "C" void fn_80148A74() {
    if (gUnk805a03d8 != 7) {
        netReport__FPCce(lbl_8045FC14);
    }
}
