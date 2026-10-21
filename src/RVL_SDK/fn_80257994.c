#include <types.h>
#pragma force_active on

void *fn_80257994(u8 *self, u32 lo, u32 hi) {
    u16 count = *(u16 *)(self + 0x8);
    u16 i;
    u8 *entry = self + 0xC;
    for (i = 0; i < count; i++, entry += 0xC) {
        u16 val = *(u16 *)(entry + 0x8);
        if (val >= lo && val <= hi) {
            return entry;
        }
    }
    return 0;
}
