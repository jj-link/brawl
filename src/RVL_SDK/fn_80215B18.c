#include <types.h>
#pragma force_active on
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void fn_801E000C(s32, u16);
extern void fn_801E6BCC(u32);
extern void fn_801E6DE8(s32, char *, int, unsigned char *, int, void (*)(void), u64);
extern void fn_8021565C(void);
extern u32 lbl_805A0C2C, lbl_805A0C30, lbl_805A0C34, lbl_805A0C38, lbl_805A0C44;
extern unsigned char lbl_804F6760[];
extern char lbl_8059ECF8;
static inline void helper(u32 mask, s32 arg0, u32 arg1) {
    s32 level;
    u32 lowbits;
    if (lbl_805A0C44 & mask) {
        lowbits = arg1 & 0xF;
        lbl_805A0C38 &= ~mask;
        lbl_805A0C34 &= ~mask;
        arg1 &= 0xFFFFFF00;
        if (lowbits == 0 && (arg1 & 0x80000000) && (arg1 & 0x00100000) && (arg1 & 0x40000000) && !(arg1 & 0x04000000) && !(arg1 & 0x00080000) && !(arg1 & 0x00040000)) {
            unsigned char *entry = lbl_804F6760 + arg0 * 12;
            fn_801E6DE8(arg0, &lbl_8059ECF8, 1, entry, 10, fn_8021565C, 0);
            return;
        }
        level = OSDisableInterrupts();
        fn_801E6BCC(mask);
        lbl_805A0C44 &= ~mask;
        lbl_805A0C38 &= ~mask;
        lbl_805A0C34 &= ~mask;
        lbl_805A0C30 &= ~mask;
        lbl_805A0C2C &= ~mask;
        fn_801E000C(arg0, 0);
        OSRestoreInterrupts(level);
    }
}
void fn_80215B18(s32 arg0, u32 arg1) {
    helper(0x80000000U >> arg0, arg0, arg1);
}