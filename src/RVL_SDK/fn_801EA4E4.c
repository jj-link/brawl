#include <types.h>
#include <revolution/os/OSInterrupt.h>
#pragma force_active on

extern s64 fn_801E1B54(void);
extern s64 fn_803F1470(s64, s64);
extern s32 fn_801EA130(s32);
extern int lbl_8059EA40;
extern int lbl_805A0850;

#define GPIO_OUT (*(u32 *)0xCD8000C0)
#define GPIO_DIR (*(u32 *)0xCD8000C4)
#define GPIO_IN (*(u32 *)0xCD8000C8)
#define DELAY() do { \
    s64 start = fn_801E1B54(); \
    s64 result; \
    do { \
        s64 current = fn_801E1B54(); \
        u32 ticks = *(u32 *)0x800000F8; \
        s64 elapsed = current - start; \
        s64 divisor = (ticks >> 2) / 125000; \
        result = fn_803F1470(elapsed * 8, divisor); \
    } while (result < 2); \
} while (0)

int fn_801EA4E4(int arg0, u8 *data, int length)
{
    int enabled;
    int i;
    u8 value;
    if (lbl_805A0850 == 0) {
        lbl_8059EA40 = 1;
        lbl_805A0850 = 1;
    }
    enabled = OSDisableInterrupts();
    GPIO_DIR = (GPIO_DIR & ~0x8000) | 0xC000;
    GPIO_OUT = (GPIO_OUT & ~0x4000) | 0x4000;
    if (lbl_8059EA40 == 0)
        GPIO_OUT &= ~0x8000;
    else
        GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
    DELAY();
    DELAY();
    if (!fn_801EA130(arg0)) {
        OSRestoreInterrupts(enabled);
        return 0;
    }
    GPIO_DIR = (GPIO_DIR & ~0x8000) | 0xC000;
    while (length != 0) {
        value = *data++;
        for (i = 0; i < 8; i++) {
            if (value & 0x80) {
                if (lbl_8059EA40 == 0)
                    GPIO_OUT &= ~0x8000;
                else
                    GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
            } else {
                if (lbl_8059EA40 == 0)
                    GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
                else
                    GPIO_OUT &= ~0x8000;
            }
            DELAY();
            GPIO_OUT = (GPIO_OUT & ~0x4000) | 0x4000;
            DELAY();
            GPIO_OUT &= ~0x4000;
            value <<= 1;
        }
        GPIO_DIR = (GPIO_DIR & ~0x8000) | 0x4000;
        DELAY();
        GPIO_OUT = (GPIO_OUT & ~0x4000) | 0x4000;
        DELAY();
        if (*(u32 *)&lbl_8059EA40 == 1 && ((GPIO_IN >> 15) & 1)) {
            OSRestoreInterrupts(enabled);
            return 0;
        }
        if (lbl_8059EA40 == 0)
            GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
        else
            GPIO_OUT &= ~0x8000;
        length--;
        GPIO_DIR = (GPIO_DIR & ~0x8000) | 0xC000;
        GPIO_OUT &= ~0x4000;
    }
    GPIO_DIR = (GPIO_DIR & ~0x8000) | 0xC000;
    if (lbl_8059EA40 == 0)
        GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
    else
        GPIO_OUT &= ~0x8000;
    DELAY();
    GPIO_OUT = (GPIO_OUT & ~0x4000) | 0x4000;
    DELAY();
    if (lbl_8059EA40 == 0)
        GPIO_OUT &= ~0x8000;
    else
        GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
    OSRestoreInterrupts(enabled);
    return 1;
}