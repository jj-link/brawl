#include <revolution/BASE/PPCArch.h>
#pragma force_active on

extern void fn_801D5080(u32);

void fn_801D5158(void) {
    fn_801D5080(PPCMfhid0() | 0x200);
}
