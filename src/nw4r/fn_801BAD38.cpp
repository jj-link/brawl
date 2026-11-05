#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

struct Inner { char pad[0x30]; short a; short b; };
struct Outer { Inner* inner; unsigned int flags; };

extern "C" void fn_801BAD38(Outer* arg0, int arg1) {
    BOOL status = OSDisableInterrupts();
    Inner* inner = arg0->inner;
    if (inner == 0) {
        OSRestoreInterrupts(status);
        return;
    }
    switch (arg1) {
    case 0: inner->a = 2; break;
    case 1: inner->a = 1; break;
    case 2: inner->a = 0; arg0->inner->b = 0; break;
    case 3: inner->a = 0; arg0->inner->b = 1; break;
    case 4: inner->a = 0; arg0->inner->b = 2; break;
    }
    arg0->flags |= 1;
    OSRestoreInterrupts(status);
}
