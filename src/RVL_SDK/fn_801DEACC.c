#pragma force_active on
#include <revolution/OS/OSHardware.h>
extern s32 OSDisableInterrupts(void);
extern void OSRestoreInterrupts(s32);
extern void OSRegisterShutdownFunction(void *);
extern void fn_801DCF5C(s32, void *);
extern void fn_801DD2A0(u32);
extern void fn_801DD320(u32);
extern void fn_801DE97C(void);
extern char fn_801DE3D4[];
extern char lbl_804689D0[];
void fn_801DEACC(void) {
    s32 level = OSDisableInterrupts();
    MI_HW_REGS[MI_REG_0x20] = 0;
    MI_HW_REGS[MI_PROT_MEM0] = 0xFF;
    fn_801DD2A0(0xF0000000);
    fn_801DCF5C(0, fn_801DE3D4);
    fn_801DCF5C(1, fn_801DE3D4);
    fn_801DCF5C(2, fn_801DE3D4);
    fn_801DCF5C(3, fn_801DE3D4);
    fn_801DCF5C(4, fn_801DE3D4);
    OSRegisterShutdownFunction(lbl_804689D0);
    fn_801DE97C();
    fn_801DD320(0x08000000);
    OSRestoreInterrupts(level);
}