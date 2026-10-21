#include <types.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
u32* fn_8004E580(void*);

void fn_8004F710() {
    u32* bits = fn_8004E580(g_GameGlobal);
    bits[0] = 0;
    bits[1] = 0;
}
}
