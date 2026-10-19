#include <gf/gf_pad_system.h>
#include <string.h>
#pragma force_active on

extern "C" const unsigned int lbl_10_rodata_788[4];

struct Menu {
    char pad[0x1DC];
    int controller;

    gfPadStatus getStatus() {
        gfPadStatus status;
        if (controller >= 0)
            g_gfPadSystem->getSysPadStatus(controller, &status);
        else
            memset(&status, 0, sizeof(status));
        return status;
    }
};

extern "C" bool fn_10_19508(Menu* menu) {
    gfPadStatus status = menu->getStatus();
    return (status.m_buttonsPressedThisFrame.bits &
            lbl_10_rodata_788[status.m_controllerType]) != 0;
}
