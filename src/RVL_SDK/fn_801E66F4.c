#include <types.h>
#pragma force_active on
extern int OSDisableInterrupts(void);
extern void OSRestoreInterrupts(int level);
extern void fn_801E667C(int arg0);
extern u32 lbl_804DE4F0[];
int fn_801E66F4(u32 arg0) {
    int level;
    int i;
    int status;
    level = OSDisableInterrupts();
    for (i = 0; i < 4; i++) {
        u32 *p = &lbl_804DE4F0[i];
        if (*p == arg0) {
            lbl_804DE4F0[i] = 0;
            for (status = 0; status < 4; status++) {
                if (lbl_804DE4F0[status] != 0) break;
            }
            if (status == 4) fn_801E667C(0);
            OSRestoreInterrupts(level);
            return 1;
        }
    }
    OSRestoreInterrupts(level);
    return 0;
}