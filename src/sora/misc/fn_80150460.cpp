#pragma force_active on
#include <gm/gm_global.h>

extern "C" void fn_80150460() {
    *(unsigned char*)(*(char**)((char*)g_GameGlobal + 0x38) + 0x8) = 0;
}
