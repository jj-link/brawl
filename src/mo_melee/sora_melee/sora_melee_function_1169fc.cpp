#include <types.h>
#pragma force_active on

extern "C" void fn_27_11967C(void* a, u32 b, void* c, void* d, u32 e, s32 f);
extern "C" void fn_27_124830(void* s, void* v);
extern void* g_ftEntryManager;

extern "C" void fn_27_1169FC(u8* self, void* arg) {
    if (*(s32*)(self + 0x50) != -1) {
        u8* mgr = (u8*)g_ftEntryManager;
        if (mgr[0x3c] == 1) {
            fn_27_11967C(mgr, 0, *(void**)(mgr + 0x44), *(void**)(mgr + 0x48), 0, -1);
        }
    }
    fn_27_124830(*(void**)(self + 0x2c), arg);
    *(void**)(self + 0x70) = arg;
}
