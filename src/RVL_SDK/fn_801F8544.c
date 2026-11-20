#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

extern DVDErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern u32 lbl_805A0918;
extern u8 lbl_804E4240[];
extern void fn_801F69D8(u32, u32, u32);
extern void fn_801FC1C0(u32, void (*)(void));
extern void fn_801FDC88(void (*)(void));
extern int fn_801FE420(void *, u32, u32, void (*)(void));
extern void fn_801FEA54(int);
extern void fn_801F7008(void);
extern void fn_801F71FC(void);
extern void fn_801F89F8(void);

#define FN_STAMP(cmd, p1, p2) { \
    BOOL enabled = OSDisableInterrupts(); \
    if (lbl_805A0900 >= 5) { \
        lbl_805A0900 = 0; \
    } \
    lbl_804E4580.info[lbl_805A0900].command = (cmd); \
    lbl_804E4580.info[lbl_805A0900].param1 = (p1); \
    lbl_804E4580.info[lbl_805A0900].param2 = (p2); \
    lbl_804E4580.info[lbl_805A0900].tick = OSGetTick(); \
    lbl_805A0900++; \
    OSRestoreInterrupts(enabled); \
}

void fn_801F8544(u32 arg0)
{
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (lbl_805A0900 == 0) {
        lbl_804E4580.info[DVD_ERROR_CMD_MAX - 1].intType = arg0;
    } else {
        *(u32 *)(((u8 *)&lbl_804E4580 + 0x28) +
                 (lbl_805A0900 - 1) * 0x14) = arg0;
    }
    OSRestoreInterrupts(enabled);
    if (arg0 == 0x10) {
        fn_801FC1C0(0x01234568, fn_801F7008);
        return;
    }
    if (arg0 == 0x20) {
        fn_801FC1C0(0x01234569, fn_801F7008);
        return;
    }
    if (arg0 & 1) {
        lbl_805A0918 = 0;
        fn_801FEA54(0);
        FN_STAMP(1, 0x108, 0x20);
        fn_801FE420(lbl_804E4240, 0x20, 0x108, fn_801F89F8);
        return;
    }
    fn_801F69D8(0x27, 0, 0);
    fn_801FDC88(fn_801F71FC);
}
