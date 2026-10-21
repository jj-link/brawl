#include <types.h>
#pragma force_active on

extern "C" void fn_124_AF40(void* p, s32 v);
extern "C" void fn_124_B110(s16* dst, s16* src);
extern "C" s32 fn_124_B020(void* p, s16* src, s32 v);

struct FtPurinFlags {
    u8 flag : 1;
    u8 pad : 7;
};

extern "C" void fn_124_AF90(u8* self, s16* src, s32 arg) {
    s16 tmp[4];
    u8* p = self + 0xC;
    if (src[0] & 8) {
        FtPurinFlags* f = reinterpret_cast<FtPurinFlags*>(p + 5);
        bool b = f->flag;
        if (b == 1 && p[6] == 0) {
            fn_124_AF40(p, arg);
        }
    }
    fn_124_B110(tmp, src);
    fn_124_B020(self + 4, tmp, arg);
}
