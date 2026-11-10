#include <types.h>
#include <revolution/SI/SIHardware.h>
#pragma force_active on
extern u8 lbl_804DD220[];
extern u8 lbl_804DD4E8[];
extern void fn_801DB9EC(void);
extern void fn_801D64D0(void);
extern s32 OSDisableInterrupts(void);
extern void fn_801E0760(void);
extern void fn_801D81F4(void *);
extern void fn_801D7FCC(void *);
extern void fn_801D75DC(void);
extern void fn_801E83E4(void);
extern void fn_801DD320(u32);
extern void fn_801E9A30(s32);
extern void fn_801E98B0(void);
extern void fn_801E8034(s32);
extern void fn_801E8078(s32);
extern void fn_801DCF24(void);
extern s32 fn_801E9AA8(void);
extern u64 OSGetTime(void);
extern s32 fn_801DF06C(s32, s32);
extern void fn_801E4978(s32, s32);
extern void fn_801E46FC(s32);
extern void fn_801E4E7C(s32);
extern void fn_801E55DC(s32);
extern s32 fn_801E54E0(s32, s32, s32);
extern void fn_801D6410(s32, void *);
extern void GXAbortFrame(void);
extern void fn_801D7184(u32);
extern void fn_801D716C(u32);
extern s32 fn_801D713C(u8, u8, u8, u8, u8, u8, u8, void *);
extern void fn_801D8194(void *, s32);
void fn_801DB7E8(u8 *a, u8 *b, s32 c) {
    s32 t24;
    u64 t0;
    u64 now;
    u8 a0, a1, a2, a3, b0, b1, b2, b3;
    u8 *p;
    OSDisableInterrupts();
    fn_801E0760();
    fn_801D81F4(lbl_804DD220);
    fn_801D7FCC(lbl_804DD220);
    fn_801D75DC();
    fn_801E83E4();
    fn_801DD320(0x80);
    fn_801E9A30(1);
    fn_801E98B0();
    fn_801E8034(0);
    fn_801E8078(0);
    fn_801DCF24();
    t24 = fn_801E9AA8();
    do {} while ((s32)(fn_801E9AA8() - t24) < 1);
    t0 = OSGetTime();
    for (;;) {
        if (fn_801DF06C(0, 0) != 0) break;
        now = OSGetTime();
        if ((s64)(now - t0) >= (s64)(((*(u32 *)0x800000F8 >> 2) / 1000) * 1000)) break;
    }
    OSDisableInterrupts();
    fn_801DF06C(1, 0);
    fn_801E4978(0, 0);
    fn_801E4978(2, 0);
    while (fn_801E54E0(0, 1, 0) == 0) {
        fn_801E46FC(0);
        fn_801E4E7C(0);
        fn_801E55DC(0);
    }
    fn_801E55DC(0);
    do {} while ((SI_HW_REGS[0x103] & 1) == 1);
    fn_801D6410(8, fn_801D64D0);
    GXAbortFrame();
    fn_801D7184(0x81400000);
    fn_801D716C(*(u32 *)0x80000038);
    a0 = a[0];
    a1 = a[1];
    p = lbl_804DD4E8;
    *p++ = a0;
    a2 = a[2];
    a3 = a[3];
    b0 = b[0];
    b1 = b[1];
    b2 = b[2];
    b3 = b[3];
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    p[3] = b0;
    p[4] = b1;
    p[5] = b2;
    p[6] = b3;
    *(s32 *)(p + 7) = c;
    fn_801D8194(fn_801DB9EC, fn_801D713C(b2, b1, b0, a3, a2, a1, a0, lbl_804DD4E8));
}