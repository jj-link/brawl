#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSTime.h>
#include <mt/mt_prng.h>
#pragma force_active on

extern OSMutex lbl_8049EC60;
extern OSCond lbl_805A03C8;
extern signed char lbl_805A03D0;
extern mtRand lbl_805A0420;

extern "C" {
void init__6mtRandFl(mtRand*, u32);

void fn_8014734C(void) {
    OSInitMutex(&lbl_8049EC60);
    OSInitCond(&lbl_805A03C8);
    lbl_805A03D0 = 0;
    init__6mtRandFl(&lbl_805A0420, OSGetTick());
}
}
