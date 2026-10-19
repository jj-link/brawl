#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" void* fn_8004D138(GameGlobal* a, void* b);

extern "C" void* fn_2_25484(void* arg) {
    void* p = fn_8004D138(g_GameGlobal, arg);
    return *(void**)((char*)p + 0x10);
}
