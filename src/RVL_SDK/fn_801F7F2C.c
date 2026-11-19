#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

extern void fn_801F7008(void);
extern void fn_801F71FC(void);
extern void fn_801F80CC(void);
extern void fn_801FC1C0(u32, void (*)(void));
extern void fn_801FD7F8(void *, u32, u32, void (*)(void));
extern void fn_801FDC88(void (*)(void));
extern void fn_801FEA54(u32);
extern void fn_801F69D8(u32, u32, u32);

extern u8 lbl_804E4320[];
extern u8 lbl_804E4340[];
extern DVDErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern u32 lbl_805A0918;
extern void *lbl_805A0954;

void fn_801F7F2C(u32 arg0)
{
    BOOL enabled = OSDisableInterrupts();
    if (lbl_805A0900 == 0) {
        lbl_804E4580.info[4].intType = arg0;
    } else {
        *(u32 *)(((u8 *)&lbl_804E4580 + 0x28) +
                 (lbl_805A0900 - 1) * 0x14) = arg0;
    }
    OSRestoreInterrupts(enabled);
    if (arg0 == 0x10) {
        fn_801FC1C0(0x01234568, fn_801F7008);
    } else if (arg0 == 0x20) {
        fn_801FC1C0(0x01234569, fn_801F7008);
    } else if (arg0 & 1) {
        lbl_805A0918 = 0;
        lbl_805A0954 = lbl_804E4320;
        fn_801FEA54(0);
        enabled = OSDisableInterrupts();
        if (lbl_805A0900 >= 5U) {
            lbl_805A0900 = 0;
        }
        lbl_804E4580.info[lbl_805A0900].command = 0x21;
        lbl_804E4580.info[lbl_805A0900].param1 = 0x10008;
        lbl_804E4580.info[lbl_805A0900].param2 = 0x20;
        lbl_804E4580.info[lbl_805A0900].tick = OSGetTick();
        lbl_805A0900++;
        OSRestoreInterrupts(enabled);
        fn_801FD7F8(lbl_804E4340, 0x20, 0x10008, fn_801F80CC);
    } else {
        fn_801F69D8(0x27, 0, 0);
        fn_801FDC88(fn_801F71FC);
    }
}
