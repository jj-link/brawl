#include <revolution/GX/GXInit.h>
#include <revolution/OS/OSTime.h>
#include <revolution/OS/OSHardware.h>
#pragma force_active on

extern __typeof__(MI_HW_REGS[0])* __memReg;
extern u8 fn_801EEF74(void);

static u32 readCounter(void) {
    u32 lo, old, hi;
    hi = __memReg[39];
    do {
        old = hi;
        lo = __memReg[40];
        hi = __memReg[39];
    } while (hi != old);
    return (hi << 16) | lo;
}

static void delay(s64 ticks) {
    s64 start = OSGetTime();
    while (OSGetTime() - start <= ticks) {
    }
}

void fn_801F05C0(void) {
    u32 current;
    u32 previous;

    if (__GXData->BYTE_0x5FA && fn_801EEF74()) {
        current = readCounter();
        do {
            delay(8);
            previous = current;
            current = readCounter();
        } while (current != previous);
    }

    PI_HW_REGS[PI_REG_0x18] = 1;
    delay(50);
    PI_HW_REGS[PI_REG_0x18] = 0;
    delay(5);
}
