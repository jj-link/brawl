#include <revolution/BASE/PPCArch.h>
#pragma force_active on

typedef void (*PFN_voidfunc)();
__declspec(section ".init") extern PFN_voidfunc _dtors[];

void exit() {
    PFN_voidfunc* dtor;
    for (dtor = _dtors; *dtor; dtor++) {
        (*dtor)();
    }
    PPCHalt();
}
