#include <types.h>
#pragma force_active on

extern "C" void* fn_8004E5A0(void* arg0);
extern "C" void* g_GameGlobal;

extern "C" void fn_8004F428() {
    void* r = fn_8004E5A0(g_GameGlobal);
    *static_cast<u32*>(r) = 0;
}
