#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);

extern "C" u32 fn_2_256F4(u32 arg) {
    void* p = fn_8004E5D8(g_GameGlobal, reinterpret_cast<void*>(arg));
    return ((u32*)p)[0x68 / 4] / 60;
}
