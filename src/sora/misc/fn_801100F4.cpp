#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" {

extern s32 lbl_8045D938[4];

s32 fn_801100F4(s32 mask) {
    gfPadStatus sp8;
    for (s32 i = 0; i < 8; i++) {
        if (mask & (1 << i)) {
            g_gfPadSystem->getSysPadStatus(i, &sp8);
            if (sp8.m_buttonsPressedThisFrame.bits & lbl_8045D938[sp8.m_controllerType]) {
                return 1;
            }
        }
    }
    return 0;
}

}
