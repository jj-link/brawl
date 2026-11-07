#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" int fn_800BA2E8() {
    gfPadStatus status;
    for (int i = 0; i < 8; i++) {
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_error == 0 && (status.m_buttonsPressedThisFrame.bits & 0x1100)) {
            gmSetRule* rule = g_GameGlobal->m_setRule;
            *(int*)((char*)rule + 0x24) = i;
            *((char*)rule + 0x20) = status.m_controllerType;
            return 1;
        }
    }
    return 0;
}