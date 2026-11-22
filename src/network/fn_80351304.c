#include <types.h>
#pragma force_active on
extern void fn_80350908(u32 *, u32);
extern u32 fn_80350A78(u32 *, u8 *, u32);
static inline u32 swap(u32 v) {
    u32 t = ((v >> 8) & 0x00FF00FF) | ((v << 8) & 0xFF00FF00);
    return (t << 16) | (t >> 16);
}
int fn_80351304(const u32 *arg0)
{
    u32 data[16], table[256];
    int i;
    fn_80350908(table, 0xEDB88320);
    for (i = 0; i < 16; i++) {
        data[i] = swap(arg0[i]);
    }
    return (arg0[15] - fn_80350A78(table, (u8 *)data, 0x3C)) == 0;
}
