#include <types.h>
#include <ctype.h>
#pragma force_active on

extern __Locale lbl_804942B8;

static inline u32 hash_string(s8 *s)
{
    u32 hash = 0;
    while (*s != 0) {
        int c = *s;
        hash = hash * 0x9CCF9319 + ((c < 0 || c >= 256) ? c : lbl_804942B8.cmap->to_lower_table[c]);
        s++;
    }
    return hash;
}

u32 fn_80388508(s8 **arg0, u32 arg1)
{
    return hash_string(*arg0) % arg1;
}