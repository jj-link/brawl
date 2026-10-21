#include "gm/gm_global.h"
#pragma force_active on

extern "C" int fn_800526E4(void) {
    unsigned char b = reinterpret_cast<unsigned char*>(g_GameGlobal->m_modeMelee)[0x62];
    unsigned v = ((b >> 6) & 1) - 1;
    unsigned u = __cntlzw(v);
    return u >> 5;
}
