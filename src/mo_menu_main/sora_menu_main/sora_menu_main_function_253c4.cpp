#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004D138(GameGlobal*, void*);

extern "C" unsigned short fn_2_253C4(void* arg) {
    void* p = fn_8004D138(g_GameGlobal, arg);
    return *(unsigned short*)p;
}
