#include <types.h>
#pragma force_active on

extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801E000C(s32, u16);
extern void fn_801E6BCC(u32);
extern void fn_802153F8(s32);

extern u32 lbl_805A0C2C;
extern u32 lbl_805A0C30;
extern u32 lbl_805A0C34;
extern u32 lbl_805A0C38;
extern u32 lbl_805A0C44;

void fn_8021565C(s32 arg0, u32 arg1) {
    s32 level;
    u32 mask;
    u32 nmask;
    u32 t8;
    u32 t7;
    u32 t6;
    u32 t5;
    u32 t0;

    mask = 0x80000000U >> arg0;
    if (lbl_805A0C44 & mask) {
        if ((arg1 & 0xF) == 0) {
            fn_802153F8(arg0);
        }
        if (arg1 & 8) {
            level = OSDisableInterrupts();
            fn_801E6BCC(mask);
            nmask = ~mask;
            t8 = lbl_805A0C44 & nmask;
            t7 = lbl_805A0C38 & nmask;
            t6 = lbl_805A0C34 & nmask;
            t5 = lbl_805A0C30 & nmask;
            t0 = lbl_805A0C2C & nmask;
            lbl_805A0C44 = t8;
            lbl_805A0C38 = t7;
            lbl_805A0C34 = t6;
            lbl_805A0C30 = t5;
            lbl_805A0C2C = t0;
            fn_801E000C(arg0, 0);
            OSRestoreInterrupts(level);
        }
    }
}
