#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_8004E76C(void*);

extern "C" void* fn_2_1EDB0() {
    return *(void**)fn_8004E76C(g_GameGlobal);
}
