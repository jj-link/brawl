extern "C" {
#include <gm/gm_global.h>
#pragma force_active on

int fn_800526C4() {
    unsigned char b = *reinterpret_cast<unsigned char*>((char*)g_GameGlobal->m_modeMelee + 0x62);
    unsigned int x = (b >> 7) & 1;
    unsigned int y = __cntlzw(x - 1);
    return y >> 5;
}
}
