#include <revolution/GX/GXInit.h>
#include <revolution/OS/OSThread.h>
#pragma force_active on

extern short *__cpReg;
extern int lbl_805A089C;
extern void (*lbl_805A08A4)(void);
extern int lbl_805A08A8;
extern OSThread *lbl_805A08AC;

extern void fn_801D81F4(void *);
extern void fn_801D7FCC(void *);

void fn_801EE720(int unused, void *context)
{
    unsigned char ctx[0x2d0];
    GXData *gx = __GXData;

    gx->cpStatReg = (unsigned short)__cpReg[0];

    if (((gx->cpCtrlReg >> 3) & 1) && ((gx->cpStatReg >> 1) & 1)) {
        OSResumeThread(lbl_805A08AC);
        lbl_805A08A8 = 0;
        *(u32 *)(*(GXData **)&__GXData)->UNK_0x10 |= 3;
        __cpReg[2] = *(u32 *)(*(GXData **)&__GXData)->UNK_0x10;
        gx->cpCtrlReg = (gx->cpCtrlReg | 4) & ~8;
        __cpReg[1] = gx->cpCtrlReg;
    }

    if (((gx->cpCtrlReg >> 2) & 1) && (gx->cpStatReg & 1)) {
        GXData *data = *(GXData **)&__GXData;
        u32 original;
        u32 value;

        lbl_805A089C++;
        original = gx->cpCtrlReg;
        value = original & ~4;
        value |= 8;
        gx->cpCtrlReg = value;
        __cpReg[1] = value;
        *(u32 *)data->UNK_0x10 = (*(u32 *)data->UNK_0x10 | 1) & ~2;
        __cpReg[2] = *(u32 *)data->UNK_0x10;
        lbl_805A08A8 = 1;
        OSSuspendThread(lbl_805A08AC);
    }

    if (((gx->cpCtrlReg >> 5) & 1) && ((gx->cpStatReg >> 4) & 1)) {
        gx->cpCtrlReg &= ~32;
        __cpReg[1] = gx->cpCtrlReg;
        if (lbl_805A08A4 != 0) {
            fn_801D81F4(ctx);
            fn_801D7FCC(ctx);
            lbl_805A08A4();
            fn_801D81F4(ctx);
            fn_801D7FCC(context);
        }
    }
}
