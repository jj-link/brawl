#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Inner { char pad[0xfe]; short value; };
struct Outer { Inner* inner; unsigned int flags; };

extern "C" void fn_801B9330(Outer* arg0, short arg1) {
    BOOL status = OSDisableInterrupts();
    Inner* inner = arg0->inner;
    if (inner == 0) {
        OSRestoreInterrupts(status);
        return;
    }
    inner->value = arg1;
    arg0->flags |= 0x800000;
    OSRestoreInterrupts(status);
}
