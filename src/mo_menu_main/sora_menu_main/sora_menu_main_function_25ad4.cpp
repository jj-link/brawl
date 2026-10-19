#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);

extern "C" void* fn_2_25AD4(void* arg) {
    void* p = fn_8004E5D8(g_GameGlobal, arg);
    return ((void**)p)[0x94 / 4];
}
