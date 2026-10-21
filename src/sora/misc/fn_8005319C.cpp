#include <types.h>
#pragma force_active on

extern "C" void* fn_8004E6D0(void* arg0);
extern void* g_GameGlobal;

extern "C" {
void fn_8005319C(void) {
    u32* p = static_cast<u32*>(fn_8004E6D0(g_GameGlobal));
    u32 v = *p;
    u32 r = 99999999U;
    if (v <= 99999998U) {
        r = v + 1;
    }
    *p = r;
}
}
