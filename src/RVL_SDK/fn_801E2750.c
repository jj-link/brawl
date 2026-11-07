#include <revolution/OS/OSCache.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern void fn_801D8690(const char *, int, const char *, ...);
extern int fn_80212D40(int, int, void *, int, void *, int);
extern char lbl_80474B30[];
extern char lbl_80474B74[];
extern int lbl_804DDFA0[8];
extern char lbl_804DDFC0[32];
extern int lbl_805A070C;
extern int lbl_805A0710;

void fn_801E2750(void)
{
    *(unsigned short *)0xCC002002 = 0;
    if (lbl_805A070C == 0) {
        fn_801D8690(lbl_80474B30, 0x159, lbl_80474B74);
    }
    fn_80212D40(lbl_805A0710, 0x2001, lbl_804DDFA0, 0x20, lbl_804DDFC0, 0x20);
    OSDisableInterrupts();
    ICFlashInvalidate();
    for (;;) {}
}