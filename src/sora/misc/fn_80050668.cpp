#include <types.h>
#pragma force_active on

extern "C" {

s64 OSGetTime(void);
s64 fn_803F1470(s64, s64);

u32 fn_80050668(void) {
    u64 result = fn_803F1470(
        OSGetTime(), (s64)(*(u32*)0x800000F8 >> 2));

    if (result > 0xFFFFFFFFULL) {
        result = 0xFFFFFFFFULL;
    }

    return (u32)result;
}

}
