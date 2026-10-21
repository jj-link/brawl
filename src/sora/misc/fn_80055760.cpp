#pragma force_active on
#include <types.h>
#include <gm/gm_global.h>

extern "C" void fn_80055760(u32 arg0, s32 arg1) {
    if (arg0 == 5) {
        s32 v = 0;
        switch (arg1) {
        case 1:
            v = 3;
            break;
        case 2:
            v = 2;
            break;
        }
        if (v != 0) {
            g_GameGlobal->m_stageData->m_exSetting = (short)v;
        }
    }
}
