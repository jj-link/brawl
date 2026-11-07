#include <revolution/OS/OSMutex.h>
#pragma force_active on

extern "C" int fn_801D7AD8();
extern "C" void fn_801E0CC0();
extern unsigned char lbl_8049ED70[];

extern "C" int fn_8015D804(void) {
    OSLockMutex((OSMutex*)(lbl_8049ED70 + 4));
    if (lbl_8049ED70[0] != 0) {
        while (fn_801D7AD8() != 0) {
            fn_801E0CC0();
        }
        return 1;
    }
    OSUnlockMutex((OSMutex*)(lbl_8049ED70 + 4));
    return 0;
}
