#include <gf/gf_pad_system.h>
#pragma force_active on

extern "C" {

int fn_80052DB0();

int fn_1_693C(void) {
    gfPadStatus status;
    int result = 0;

    int port = fn_80052DB0();
    if (port < 0 || port >= 8) {
        port = 0;
    }

    g_gfPadSystem->getSysPadStatus(port, &status);

    u32 buttons = status.m_buttonsCurrentFrame2.bits;

    if ((buttons & gfPadButtons::DUp) || status.m_stickY > 0x3C) {
        result = 4;
    }
    if ((buttons & gfPadButtons::DRight) || status.m_stickY < -0x3C) {
        result = 5;
    }
    if ((buttons & gfPadButtons::DLeft) || status.m_stickX < -0x3C) {
        result = 2;
    }
    if ((buttons & gfPadButtons::DDown) || status.m_stickX > 0x3C) {
        result = 3;
    }
    if ((buttons & gfPadButtons::R) || (buttons & gfPadButtons::L) ||
        (buttons & 0x40000)) {
        result = 1;
    }

    return result;
}

}
