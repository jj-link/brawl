#include <types.h>
#pragma force_active on

extern "C" void* fn_8004E5C4(void*);
extern void* g_GameGlobal;

extern "C" s32 fn_800557F8(s32 arg0, s32 arg1, s32 arg2) {
    s32 off = arg2 * 0xCC;
    s32 base = (arg0 - 1) * 0x264;
    s32 sh = arg1 * 4;
    s32 i;
    for (i = arg2; i < 3; i++) {
        u32 t = (u32)fn_8004E5C4(g_GameGlobal);
        t = t + base;
        t = t + off;
        u32 v = *(u32*)(t + sh + 0x32C);
        if ((v >> 30) != 0) {
            return 1;
        }
        off += 0xCC;
    }
    return 0;
}
