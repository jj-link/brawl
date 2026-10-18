#include <string.h>
#pragma force_active on

extern "C" {
extern void* g_GameGlobal;
}

extern "C" void* fn_1_7058(void* unused, const void* src) {
    char* gg = (char*)g_GameGlobal;
    char* p = *(char**)(gg + 0x1c);
    return memcpy(p + 0x30, src, 0x58);
}
