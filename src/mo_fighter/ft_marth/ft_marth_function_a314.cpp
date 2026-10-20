#include <types.h>
#pragma force_active on

extern "C" {
void fn_106_A2C4(void* self, s32 arg);
void fn_106_A3AC(s16* dst, const s16* src);
void fn_106_A3A4(void* self, s16* src, s32 arg);

void fn_106_A314(void* self, s16* src, s32 arg)
{
    u8* p = (u8*)self + 0xc;
    if ((src[0] & 4) != 0) {
        u8 f = (p[5] >> 7) & 1;
        if ((bool)f == 1 && p[6] == 0) {
            fn_106_A2C4(p, arg);
        }
    }
    s16 tmp[4];
    fn_106_A3AC(tmp, src);
    fn_106_A3A4((u8*)self + 4, tmp, arg);
}
}
