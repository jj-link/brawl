#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" s32 fn_800BA1FC(s32 arg0) {
    gfPadStatus status;

    for (int i = 0; i < 8; i++) {
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_error == 0 &&
            ((status.m_buttonsPressedThisFrame.bits & arg0) ||
             ((arg0 & 1) && status.m_stickX < -0x3C) ||
             ((arg0 & 2) && status.m_stickX > 0x3C) ||
             ((arg0 & 8) && status.m_stickY < -0x3C) ||
             ((arg0 & 4) && status.m_stickY > 0x3C))) {
            return i;
        }
    }
    return -1;
}
