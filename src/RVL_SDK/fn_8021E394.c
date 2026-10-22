#include <types.h>
#pragma force_active on

extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int);

s32 fn_8021E394(u8 *self, s8 arg1) {
    s8 v;
    s32 size;
    u8 a;
    int intr;

    intr = OSDisableInterrupts();
    a = self[0];
    v = self[1] - a;
    if (v < 0) {
        v += *(s32 *)(self + 8);
    }
    OSRestoreInterrupts(intr);
    size = *(s32 *)(self + 8);
    if ((u32)(v + arg1) <= (u32)(size - 1)) {
        return 1;
    }
    return 0;
}
