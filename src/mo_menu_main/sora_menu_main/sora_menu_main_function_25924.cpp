#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004D138(GameGlobal*, void*);

extern "C" void* fn_2_25924(void* arg) {
    void* p = fn_8004D138(g_GameGlobal, arg);
    return *(void**)((char*)p + 0x3C);
}
