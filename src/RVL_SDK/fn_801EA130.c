#include <types.h>
#pragma force_active on

extern s64 fn_801E1B54(void);
extern s64 fn_803F1470(s64, s64);
extern int lbl_8059EA40;

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

s32 fn_801EA130(u8 value)
{
    int i;
    if (lbl_8059EA40 == 0)
        GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
    else
        GPIO_OUT &= ~0x8000;
    DELAY();
    GPIO_OUT &= ~0x4000;
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
        return 0;
    }
    if (lbl_8059EA40 == 0)
        GPIO_OUT = (GPIO_OUT & ~0x8000) | 0x8000;
    else
        GPIO_OUT &= ~0x8000;
    GPIO_DIR = (GPIO_DIR & ~0x8000) | 0xC000;
    GPIO_OUT &= ~0x4000;
    return 1;
}
