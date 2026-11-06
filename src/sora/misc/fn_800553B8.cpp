#pragma force_active on
#include <gm/gm_global.h>
#include <types.h>

extern "C" void* fn_8004E5AC(void*);

extern "C" void fn_800553B8(s32 arg0) {
    u32* p = static_cast<u32*>(fn_8004E5AC(g_GameGlobal));
    p[arg0 / 32] |= 1 << (arg0 % 32);
}
