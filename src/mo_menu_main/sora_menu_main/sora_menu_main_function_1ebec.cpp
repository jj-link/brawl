#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E628(GameGlobal*);

extern "C" void* fn_2_1EBEC() {
    return *static_cast<void**>(fn_8004E628(g_GameGlobal));
}
