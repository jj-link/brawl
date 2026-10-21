#pragma force_active on
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern "C" void fn_124_B028(u8* self, s32 p);
extern "C" void fn_124_B110(s16* dst, s16* src);
extern "C" s32 fn_124_B108(u8* self, s16* src, s32 p);

extern "C" void fn_124_B078(u8* self, s16* src, s32 p3)
{
    s16 tmp[4];
    u8* sub = self + 0xc;
    if (src[0] & 4) {
        u8 raw = (sub[5] >> 7) & 1;
        bool flag = raw;
        if (flag == 1 && sub[6] == 0) {
            fn_124_B028(sub, p3);
        }
    }
    fn_124_B110(tmp, src);
    fn_124_B108(self + 4, tmp, p3);
}
