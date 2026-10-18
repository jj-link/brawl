#include <gm/gm_global.h>
#pragma force_active on

extern "C" int fn_88_3C00() {
    gmGlobalModeMelee* mode = g_GameGlobal->m_modeMelee;
    if (mode == 0) return 0;
    unsigned char* base = (unsigned char*)mode;
    if (base[0x63] != 0) return 0;
    return (unsigned int)__cntlzw(base[0x64]) >> 5;
}
