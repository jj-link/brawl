#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

u64 fn_801E1BB8(u32 arg0, u32 arg1) {
    BOOL enabled = OSDisableInterrupts();
    u64 result = *(s64 *)0x800030D8 + (((u64)arg0 << 32) | (u64)arg1);
    OSRestoreInterrupts(enabled);
    return result;
}
