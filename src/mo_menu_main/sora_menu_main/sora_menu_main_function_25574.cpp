#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);

extern "C" u16 fn_2_25574(u32 arg) {
    u16* p = static_cast<u16*>(fn_8004E5D8(g_GameGlobal, reinterpret_cast<void*>(arg)));
    return p[0x60 / 2];
}
