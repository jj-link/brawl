#pragma force_active on
#include <types.h>

extern "C" s32 OSDisableInterrupts();
extern "C" void OSRestoreInterrupts(s32);

extern "C" void fn_801B8CB0(u8** arg0, s16 arg1) {
    s32 level = OSDisableInterrupts();
    if (*arg0 == nullptr) {
        OSRestoreInterrupts(level);
        return;
    }

    s32 level2 = OSDisableInterrupts();
    u8* p = *arg0;
    if (p == nullptr) {
        OSRestoreInterrupts(level2);
    } else {
        *(s16*)(p + 0x96) = arg1;
        u32* q = (u32*)*arg0;
        if (!(q[7] & 0x400)) {
            q[7] |= 0x800;
        }
        OSRestoreInterrupts(level2);
    }
    OSRestoreInterrupts(level);
}
