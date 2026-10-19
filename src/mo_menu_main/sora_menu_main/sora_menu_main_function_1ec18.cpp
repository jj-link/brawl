#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E634(GameGlobal*);

extern "C" void* fn_2_1EC18() {
    return *(void**)fn_8004E634(g_GameGlobal);
}
