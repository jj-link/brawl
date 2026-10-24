#include <types.h>
#pragma force_active on

extern u64 fn_803A2088(void);
extern u64 fn_803F1798(u64, u32);
extern u64 fn_803F17BC(u32, u32, u32);

s32 fn_803A1FF0(void) {
    u64 acc = fn_803A2088();
    s32 i = 0;
    do {
        if (fn_803F17BC(acc >> 32, (u32)acc, 0x35 - (i + 1)) & 1) {
            acc ^= fn_803F1798(0x635, 0x2a - i);
        }
        i++;
    } while (i < 0x2b);
    if (acc) {
        return -0x25;
    }
    return 0;
}
