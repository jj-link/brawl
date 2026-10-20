#include <gm/gm_global.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_27_5C250(GameGlobal* global) {
    if ((s32)global->m_nteData != 1) {
        s32 v = (s32)global->m_nteData / (s32)g_GameGlobal->getSlowRate();
        if (v < 1) {
            v = 1;
        }
        global->m_record = (gmGlobalRecord*)v;
    }
}
}
