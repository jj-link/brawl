#include <types.h>
#include <revolution/GX/GXInit.h>
#include <revolution/GX/GXHardware.h>
#include <revolution/OS/OSHardware.h>
#include <revolution/OS/OSTime.h>

#pragma force_active on

extern __typeof__(MI_HW_REGS[0])* __memReg;
extern __typeof__(MI_HW_REGS[0])* __cpReg;
extern u32 lbl_805A0880;
extern s64 lbl_805A0888;
extern u32 lbl_805A088C;
extern s32 lbl_805A0890;
extern s32 fn_801EF020(s32);
extern s32 fn_801F0C20(s32);
extern s32 fn_801F0CE8(s32);
extern void fn_801D50A0(void);
extern void fn_801F05C0(void);

static u32 readCounter(void) {
    u32 hi, lo, old;
    hi = __memReg[39];
    do {
        old = hi;
        lo = __memReg[40];
        hi = __memReg[39];
    } while (hi != old);
    return (hi << 16) | lo;
}

s32 fn_801ED66C(s32 arg0) {
    s64 now;
    u32 current;

    if (arg0 == 0) {
        if (lbl_805A0890 == 0) {
            lbl_805A0880 = readCounter();
            lbl_805A0888 = OSGetTime();
            lbl_805A0890 = 1;
            return 0;
        }
        now = OSGetTime();
        current = readCounter();
        if (now - lbl_805A0888 < 10) {
            return 0;
        }
        if (current != lbl_805A0880) {
            *(s32 *)&lbl_805A0888 = (s32)(now >> 32);
            lbl_805A0880 = current;
            lbl_805A088C = (u32)now;
            return 0;
        }
    } else {
        fn_801EF020(0);
        fn_801F0C20(0);
        fn_801F0CE8(0);
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        WGPIPE.i = 0;
        fn_801D50A0();
        __cpReg[1] = 0;
        __cpReg[2] = 3;
        __GXData->BYTE_0x5FA = 1;
        fn_801F05C0();
    }
    return 1;
}