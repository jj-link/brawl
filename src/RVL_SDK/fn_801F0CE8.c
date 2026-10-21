#include <types.h>
#pragma force_active on

extern s32 lbl_805A08C4;
extern void OSDisableInterrupts(void);
extern void OSRestoreInterrupts(void);

s32 fn_801F0CE8(s32 arg0) {
    s32 old;

    old = lbl_805A08C4;
    OSDisableInterrupts();
    lbl_805A08C4 = arg0;
    OSRestoreInterrupts();
    return old;
}
