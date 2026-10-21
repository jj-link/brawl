#include <types.h>
#pragma force_active on

extern "C" void* g_GameGlobal;
extern "C" unsigned int* fn_8004E594(void*);

extern "C" void fn_8004F884(void) {
    unsigned int* bits = fn_8004E594(g_GameGlobal);
    bits[0] = 0;
}
