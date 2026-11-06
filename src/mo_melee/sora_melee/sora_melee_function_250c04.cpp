#include <gf/gf_pad_system.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" int fn_27_250C04(void* self, int action) {
    for (int i = 0; i < 8; i++) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_error == 0) {
            switch (action) {
            case 1:
                switch (status.m_controllerType) {
                case 0:
                case 1:
                    if (status.m_buttonsPressedThisFrame.bits & 0x20) return 1;
                    break;
                case 2:
                    if ((status.m_buttonsCurrentFrame2.bits & 0x80000) && (status.m_buttonsPressedThisFrame.bits & 8)) return 1;
                    break;
                case 3:
                    if (status.m_buttonsPressedThisFrame.bits & 8) return 1;
                    break;
                }
                break;
            case 2:
                switch (status.m_controllerType) {
                case 0:
                case 1:
                    if (status.m_buttonsPressedThisFrame.bits & 0x40) return 1;
                    break;
                case 2:
                    if ((status.m_buttonsCurrentFrame2.bits & 0x80000) && (status.m_buttonsPressedThisFrame.bits & 4)) return 1;
                    break;
                case 3:
                    if (status.m_buttonsPressedThisFrame.bits & 4) return 1;
                    break;
                }
                break;
            case 3:
                if (status.m_buttonsPressedThisFrame.bits & 0x1000) {
                    *(int*)((char*)g_GameGlobal->m_setRule + 0x24) = i;
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}