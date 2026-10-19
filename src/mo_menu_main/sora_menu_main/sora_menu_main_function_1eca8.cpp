#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E6D0(void*);

extern "C" void* fn_2_1ECA8() {
    return *static_cast<void**>(fn_8004E6D0(g_GameGlobal));
}
