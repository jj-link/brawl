#include <types.h>
#pragma force_active on

extern "C" unsigned char fn_8004EAD4(void* a);
extern void* g_GameGlobal;

extern "C" s32 fn_8003CD6C(void) {
    return (fn_8004EAD4(g_GameGlobal) >> 3) & 1;
}
