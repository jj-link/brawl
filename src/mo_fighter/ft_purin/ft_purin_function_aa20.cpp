#include <types.h>
#pragma force_active on

extern "C" void fn_124_A9D0(void* a, void* b);
extern "C" void fn_124_B110(s16* dst, s16* src);
extern "C" s32 fn_124_AAB0(void* a, s16* b, void* c);

struct PurinFlagByte {
    u8 flag : 1;
    u8 pad : 7;
};

extern "C" void fn_124_AA20(u8* self, s16* src, void* arg) {
    s16 tmp[4];
    u8* p = self + 0xc;
    if (src[0] & 1) {
        PurinFlagByte* f = reinterpret_cast<PurinFlagByte*>(p + 5);
        bool b = f->flag;
        if (b == 1 && p[6] == 0) {
            fn_124_A9D0(p, arg);
        }
    }
    fn_124_B110(tmp, src);
    fn_124_AAB0(self + 4, tmp, arg);
}
