#include <types.h>
#pragma force_active on
extern u8 *lbl_804F6810[];

static inline void mix(u8 a, u8 b, u8 *value)
{
    u8 tmp = *value ^ b;
    *value = a + tmp;
}
void fn_80224704(s32 arg0, u8 *arg1, u16 arg2, s32 arg3)
{
    u8 *base = lbl_804F6810[arg0];
    u16 i;
    for (i = 0; i < arg2; i++) {
        u8 k = (arg3 + i) % 8;
        mix(base[0x924 + k], base[0x92c + k], &arg1[i]);
    }
}
