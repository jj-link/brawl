#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

s32 fn_8035D200(s32 *arg0)
{
    BOOL enabled = OSDisableInterrupts();
    s32 old = *arg0;
    s32 result = old - 1;
    *arg0 = result;
    OSRestoreInterrupts(enabled);
    return result;
}
