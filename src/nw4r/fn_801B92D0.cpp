#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Inner { char pad[0x3a]; s16 value; };
struct Outer { Inner* inner; unsigned int flags; };

extern "C" void fn_801B92D0(Outer* arg0, s16 arg1) {
    BOOL status = OSDisableInterrupts();
    Inner* inner = arg0->inner;
    if (inner == 0) {
        OSRestoreInterrupts(status);
        return;
    }
    inner->value = arg1;
    arg0->flags |= 0x8;
    OSRestoreInterrupts(status);
}
