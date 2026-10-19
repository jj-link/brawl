#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E5D8(void*, void*);

extern "C" void* fn_2_258F4(void* arg) {
    void* p = fn_8004E5D8(g_GameGlobal, arg);
    return ((void**)p)[0x80 / 4];
}
