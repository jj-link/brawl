#include <revolution/OS/OSThread.h>
#include <types.h>
#pragma force_active on

extern int gUnk805a03d8;
extern u8 lbl_805A03E4;
extern int lbl_805A0434;

extern "C" {
void fn_80146B80() {
    if (gUnk805a03d8 == 0) {
        return;
    }
    if (lbl_805A03E4 != 1) {
        return;
    }
    OSResumeThread(reinterpret_cast<OSThread*>(lbl_805A0434 + 0xA0));
}
}
