#include <gm/gm_global.h>
#pragma force_active on

extern "C" void** fn_8004E784(GameGlobal*);

extern "C" void* fn_2_1EE08() {
    return *fn_8004E784(g_GameGlobal);
}
