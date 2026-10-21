#include <types.h>
#pragma force_active on

extern "C" void fn_124_AC88(void* p, s32 v);
extern "C" void fn_124_B110(s16* dst, s16* src);
extern "C" s32 fn_124_AD68(void* p, s16* src, s32 v);

struct FtPurinFlags {
    u8 flag : 1;
    u8 pad : 7;
    u8 next;
};

extern "C" void fn_124_ACD8(u8* p1, s16* p2, s32 p3) {
    s16 local[4];
    u8* p = p1 + 0xc;
    FtPurinFlags* f = reinterpret_cast<FtPurinFlags*>(p + 5);
    if (*p2 & 1) {
        bool b = f->flag;
        if (b == true && p[6] == 0) {
            fn_124_AC88(p, p3);
        }
    }
    fn_124_B110(local, p2);
    fn_124_AD68(p1 + 4, local, p3);
}
