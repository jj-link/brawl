#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_8014FE9C(u32 arg) {
    u8* data = (u8*)g_GameGlobal->m_nteData;
    data[0x86] = (u8)(arg >> 8);
    data[0x87] = (u8)arg;
}
