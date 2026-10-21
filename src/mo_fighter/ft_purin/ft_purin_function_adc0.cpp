#include <types.h>
#pragma force_active on

extern "C" void fn_124_AD70(u8* p, s32 arg);
extern "C" void fn_124_B110(s16* dst, s16* src);
extern "C" s32 fn_124_AE50(u8* p, s16* src, s32 arg);

extern "C" void fn_124_ADC0(u8* self, s16* src, s32 arg)
{
    s16 tmp[4];
    u8* sub = self + 0xc;
    if (src[0] & 2) {
        u8 raw = (sub[5] >> 7) & 1;
        bool flag = raw;
        if (flag == 1 && sub[6] == 0) {
            fn_124_AD70(sub, arg);
        }
    }
    fn_124_B110(tmp, src);
    fn_124_AE50(self + 4, tmp, arg);
}
