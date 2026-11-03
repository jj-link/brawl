#include <gf/gf_error_manager.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" void fn_42_2DC() {
    gmGlobalModeMelee* modeMelee = g_GameGlobal->m_modeMelee;
    if (modeMelee != NULL) {
        u32 r31 = 0;
        u32 r30 = 0;
        u8 val = *(u8*)((char*)modeMelee + 0x89);
        switch (val - 0xc9) {
            case 0: r31 = 1; break;
            case 1: r31 = 2; break;
            case 2: r31 = 3; break;
            case 3: r31 = 4; break;
            case 4: r31 = 5; break;
            case 5: r31 = 6; break;
            case 6: r31 = 7; break;
            case 7: r31 = 8; break;
            case 8: r31 = 9; r30 = 0x7148; break;
            case 9: r31 = 0xa; r30 = 0x7149; break;
            case 10: r31 = 0xb; r30 = 0x3039; break;
        }
        if (r31 != 0) {
            gfErrorManager::getInstance()->notifyError(r31, r30);
        }
    }
}
