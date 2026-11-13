#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" s32 fn_80110190(s32* arg0, s32* arg1, s32* arg2) {
    gfPadStatus status;
    s32 i;
    u8* p;
    s32 idx;
    s32 j;

    *arg0 = -1;
    *arg1 = -1;
    i = 0;
    while (i < 8) {
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_buttonsPressedThisFrame.bits & arg2[status.m_controllerType]) {
            *arg0 = i;
            break;
        }
        i++;
    }
    idx = *arg0;
    if (idx < 0) {
        return 0;
    }
    j = 0;
    p = (u8*)g_GameGlobal->m_modeMelee;
    while (j < 4) {
        u32 base = 0x99 + j * 0x5C;
        if (p[base] == 0 && ((p[base + 0x3D] >> 7) & 1) && idx == p[base + 0x3C] - 1) {
            *arg1 = j;
            break;
        }
        j++;
    }
    return 1;
}
