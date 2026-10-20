#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" u8 fn_10_1E08() {
    return g_GameGlobal->m_setRule->m_handicap;
}
