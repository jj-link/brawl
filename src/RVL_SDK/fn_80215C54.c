#pragma force_active on
typedef unsigned int u32;
typedef int s32;

extern s32 OSDisableInterrupts(void);
extern s32 OSRestoreInterrupts(s32);
extern void fn_801E6BCC(u32);
extern void fn_801E73B8(s32, void (*)(void));
extern void fn_802157F8(void);
extern void *memset(void *, int, unsigned long);
extern s32 __cntlzw(u32);

extern unsigned char lbl_804F6760[];
extern s32 lbl_8059ECE4;
extern u32 lbl_8059ECF0;
extern u32 lbl_805A0C2C;
extern u32 lbl_805A0C30;
extern u32 lbl_805A0C34;
extern u32 lbl_805A0C38;
extern u32 lbl_805A0C3C;
extern u32 lbl_805A0C40;
extern u32 lbl_805A0C44;

s32 fn_80215C54(u32 arg0)
{
    s32 enabled;
    u32 active;
    s32 index;

    enabled = OSDisableInterrupts();
    arg0 |= lbl_805A0C30;
    arg0 &= ~(lbl_805A0C38 | lbl_805A0C34);
    lbl_805A0C30 = 0;
    lbl_805A0C40 |= arg0;
    active = lbl_805A0C40 & lbl_805A0C44;
    lbl_805A0C44 &= ~arg0;
    lbl_805A0C2C &= ~arg0;

    if (lbl_8059ECF0 == 4U) {
        lbl_805A0C3C |= arg0;
    }

    fn_801E6BCC(active);

    if (lbl_8059ECE4 == 32) {
        index = __cntlzw(lbl_805A0C40);
        lbl_8059ECE4 = index;
        if (index != 32) {
            lbl_805A0C40 &= ~(0x80000000U >> index);
            memset(lbl_804F6760 + index * 12, 0, 12);
            fn_801E73B8(lbl_8059ECE4, fn_802157F8);
        }
    }

    OSRestoreInterrupts(enabled);
    return 1;
}
