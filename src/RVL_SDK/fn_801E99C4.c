#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern unsigned char lbl_804DE640[0x58];
extern int lbl_805A07F0;
extern void fn_801E8980(void *, void *, void *, void *, void *);

void fn_801E99C4(int arg0)
{
    BOOL level = OSDisableInterrupts();
    *(int *)(lbl_804DE640 + 0x30) = arg0;
    lbl_805A07F0 = 1;
    fn_801E8980(lbl_804DE640, lbl_804DE640 + 0x34,
                lbl_804DE640 + 0x38, lbl_804DE640 + 0x4C,
                lbl_804DE640 + 0x50);
    OSRestoreInterrupts(level);
}
