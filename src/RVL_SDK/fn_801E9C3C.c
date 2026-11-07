#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct {
    u16 pad : 13;
    u16 bit : 1;
    u16 rest : 2;
} Reg;

s32 fn_801E9C3C(void) {
    s32 r;
    BOOL status = OSDisableInterrupts();
    if ((u32)(*(u16 *)0xCC00206C & 1) == 1) {
        r = 2;
    } else {
        r = ((Reg *)0xCC002002)->bit != 0;
    }
    OSRestoreInterrupts(status);
    return r;
}
