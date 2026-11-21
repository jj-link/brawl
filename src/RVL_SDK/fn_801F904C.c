#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvderror.h>
#pragma force_active on

extern DVDErrorInfo lbl_804E4580;
extern unsigned char lbl_804E4300[];
typedef __typeof__(__DVDLayoutFormat) u32v;
extern u32v lbl_805A0900;
extern u32v lbl_805A0910;
extern int lbl_805A0914;
extern u32v lbl_805A0918;
extern DVDCommandCallback lbl_805A0980;
extern u32 lbl_805A0984;
extern DVDCommandBlock *executing_805A0990;
extern DVDCommandBlock DummyCommandBlock_804E4260;
extern void (*lbl_805A0994)(DVDCommandBlock *);

extern void fn_801F7008(void);
extern void fn_801F71FC(void);
extern void fn_801F928C(DVDCommandBlock *);
extern void fn_801F9404(u32);
extern void fn_801FC1C0(u32, void (*)(void));
extern void fn_801D76BC(void *, u32);
extern void fn_801F9688(void);
extern void fn_801F99B0(DVDCommandBlock *);
extern void fn_801FEA54(int);
extern void fn_801FCB9C(void *, void (*)(u32));
extern void fn_801F69D8(int, int, int);
extern void fn_801FDC88(void (*)(void));

void fn_801F904C(u32 arg0)
{
    BOOL enabled = OSDisableInterrupts();

    if (lbl_805A0900 == 0)
        lbl_804E4580.info[4].intType = arg0;
    else
        *(u32 *)(((u8 *)&lbl_804E4580 + 0x28) +
                 (lbl_805A0900 - 1) * 0x14) = arg0;

    OSRestoreInterrupts(enabled);

    if (arg0 == 0x10) {
        fn_801FC1C0(0x01234568, fn_801F7008);
    } else if (arg0 == 0x20) {
        fn_801FC1C0(0x01234569, fn_801F7008);
    } else if (arg0 & 1) {
        fn_801D76BC(lbl_804E4300, 0x20);
        lbl_805A0994 = fn_801F928C;

        if (lbl_805A0984 == 0x28) {
            DVDCommandBlock *block;
            int canceled;

            lbl_805A0918 = 0;
            if (lbl_805A0910) {
                block = executing_805A0990;
                lbl_805A0914 = 0;
                lbl_805A0910 = 0;
                executing_805A0990 = &DummyCommandBlock_804E4260;
                block->state = 10;

                if (block->callback)
                    block->callback(-3, block);
                if (lbl_805A0980)
                    lbl_805A0980(0, block);

                fn_801F9688();
                canceled = 1;
            } else {
                canceled = 0;
            }

            if (!canceled) {
                executing_805A0990->state = 1;
                fn_801F99B0(executing_805A0990);
            }
        } else {
            fn_801FEA54(0);
            enabled = OSDisableInterrupts();

            if (lbl_805A0900 >= 5)
                lbl_805A0900 = 0;

            lbl_804E4580.info[lbl_805A0900].command = 5;
            lbl_804E4580.info[lbl_805A0900].param1 = 0;
            lbl_804E4580.info[lbl_805A0900].param2 = 0x20;
            lbl_804E4580.info[lbl_805A0900].tick = OSGetTick();
            lbl_805A0900++;

            OSRestoreInterrupts(enabled);
            fn_801FCB9C(lbl_804E4300, fn_801F9404);
        }
    } else {
        fn_801F69D8(0x27, 0, 0);
        fn_801FDC88(fn_801F71FC);
    }
}
