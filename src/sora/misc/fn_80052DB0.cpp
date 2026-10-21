#include <gm/gm_global.h>
#pragma force_active on

extern "C" void* fn_80052DB0() {
    return *(void**)((char*)g_GameGlobal->m_setRule + 0x24);
}
