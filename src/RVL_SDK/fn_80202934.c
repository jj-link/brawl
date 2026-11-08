#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_80203208(void *);
extern int fn_80202798(void *);

int fn_80202934(unsigned char *arg0) {
    BOOL level1;
    BOOL level2;
    int *flag = (int *)(arg0 + 0x10C);
    level1 = OSDisableInterrupts();
    *flag |= 1;
    level2 = OSDisableInterrupts();
    *flag |= 1;
    fn_80203208(arg0);
    OSRestoreInterrupts(level2);
    if (fn_80202798(arg0) == 0) {
        level2 = OSDisableInterrupts();
        *flag |= 1;
        fn_80203208(arg0);
        OSRestoreInterrupts(level2);
        OSRestoreInterrupts(level1);
        return 0;
    }
    *flag = (*flag | 2) & ~1;
    OSRestoreInterrupts(level1);
    return 1;
}
