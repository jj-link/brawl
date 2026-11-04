#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern int fn_803A66F0(void);
extern void fn_803A6828(int, void *, int);

void fn_803A848C(void *arg0) {
    BOOL enabled = OSDisableInterrupts();
    if (fn_803A66F0() == 1 && arg0 != 0) {
        fn_803A6828  (10, arg0, 0x840);
    }
    OSRestoreInterrupts(enabled);
}
