#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

extern unsigned char lbl_804E8940[];
extern int lbl_805A0AC4;
extern int lbl_805A0AB0;
extern void (*lbl_805A0A98)(void);
extern void *fn_8020999C(void *);
extern void fn_801E1790(int *);
extern void fn_801FEC94(void);

void fn_80201078(void) {
    BOOL state = OSDisableInterrupts();
    lbl_805A0AC4 = 0;
    fn_8020999C(lbl_804E8940);
    fn_801E1790(&lbl_805A0AB0);
    fn_801FEC94();
    lbl_805A0A98 = 0;
    OSRestoreInterrupts(state);
}
