#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    char pad0[0x1c];
    unsigned int flags;
    unsigned int unk20;
    char pad1[0x14];
    unsigned short unk38;
} Obj;

void fn_802022DC(Obj* arg0, unsigned short arg1) {
    BOOL status = OSDisableInterrupts();
    if (arg0->unk38 == arg1) {
        OSRestoreInterrupts(status);
        return;
    }
    arg0->unk38 = arg1;
    arg0->flags |= 4;
    if (arg1 == 0) {
        arg0->unk20 = 1;
    }
    OSRestoreInterrupts(status);
}
