#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E6B8(GameGlobal*);

extern "C" void* fn_2_1EC50() {
    return *static_cast<void**>(fn_8004E6B8(g_GameGlobal));
}
