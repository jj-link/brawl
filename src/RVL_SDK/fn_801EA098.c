#include <types.h>
#pragma force_active on

extern s64 fn_801E1B54(void);
extern s64 fn_803F1470(s64, s64);

void fn_801EA098(s32 arg0, s32 arg1) {
    s64 start = fn_801E1B54();
    s64 result;

    do {
        s64 current = fn_801E1B54();
        u32 ticks = *(u32 *)0x800000F8;
        s64 elapsed = current - start;
        s64 divisor = (ticks >> 2) / 125000;

        result = fn_803F1470(elapsed * 8, divisor);
    } while (result < arg0);
}
