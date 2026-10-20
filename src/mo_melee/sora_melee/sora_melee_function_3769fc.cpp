#include <types.h>
#pragma force_active on

extern "C" s32 fn_27_10B500(void* mgr, u32 id);
extern void* g_ftManager;

struct FtSomething {
    u8 pad[4];
    s16 m4;
    s32 m8;
    u32 mc;
    u32 m10;
};

extern "C" {
void fn_27_3769FC(FtSomething* p) {
    s32 v = fn_27_10B500(g_ftManager, p->m10);
    if (p->m4 != (s16)v) {
        p->m4 = (s16)v;
        if ((s16)v > -1) {
            p->m8 = 0;
        }
    }
}
}
