#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" void* fn_8004D138(GameGlobal* a, void* b);

extern "C" u32 fn_2_25864(void* arg) {
    void* p = fn_8004D138(g_GameGlobal, arg);
    return *(u32*)((char*)p + 0x34);
}
