#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" int fn_10_D0A0() {
    s32 r0 = *((u8*)g_GameGlobal->m_selCharData + 0x4);
    switch (r0) {
    case 0x1:
    case 0x12:
        return 1;
    default:
        return 0;
    }
}
