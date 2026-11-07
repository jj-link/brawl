#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on
struct MenuEdit {
    char pad[0x68];
    int flag;
    char pad6c[8];
    unsigned int buttons;
};
extern "C" void fn_5_11924(MenuEdit* self, gfPadStatus* output, int arg) {
    unsigned int buttons = 0;
    for (int i = 0; i < 8; ++i) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_error >= 0) {
            switch (status.m_controllerType) {
            case gfPadType::WIIMOTE:
                { unsigned int combined = buttons | status.m_buttonsPressedThisFrame2.bits;
                buttons = combined | self->buttons; }
                if (status.m_buttonsPressedThisFrame.bits & 0x200000) {
                    output->m_buttonsPressedThisFrame.bits |= 0x400;
                } else if (status.m_buttonsPressedThisFrame.bits & 0x400000) {
                    output->m_buttonsPressedThisFrame.bits = (output->m_buttonsPressedThisFrame.bits | 0x10) & ~0x40;
                } else if (status.m_buttonsCurrentFrame2.bits & 0x80000) {
                    buttons = 0;
                    if (status.m_buttonsPressedThisFrame.bits & 4)
                        output->m_buttonsPressedThisFrame.bits |= 0x20;
                    else if (status.m_buttonsPressedThisFrame.bits & 8)
                        output->m_buttonsPressedThisFrame.bits |= 0x40;
                }
                break;
            case gfPadType::NUNCHUK:
                buttons |= self->buttons;
                if (arg)
                    buttons |= status.m_buttonsPressedThisFrame2.bits;
                if (status.m_buttonsPressedThisFrame.bits & 0x80000)
                    output->m_buttonsPressedThisFrame.bits |= 0x400;
                else if (status.m_buttonsPressedThisFrame.bits & 0x20000)
                    output->m_buttonsPressedThisFrame.bits |= 0x800;
                else if (status.m_buttonsPressedThisFrame.bits & 4)
                    output->m_buttonsPressedThisFrame.bits |= 0x20;
                else if (status.m_buttonsPressedThisFrame.bits & 8)
                    output->m_buttonsPressedThisFrame.bits |= 0x40;
                else if (status.m_buttonsPressedThisFrame2.bits & 0x40000) {
                    self->flag = 1;
                    buttons = 0;
                    output->m_subStickY = output->m_stickY;
                    output->m_buttonsPressedThisFrame.bits &= ~0x400;
                }
                break;
            default:
                { unsigned int combined = buttons | status.m_buttonsPressedThisFrame2.bits;
                buttons = combined | self->buttons; }
                break;
            }
        }
    }
    output->m_buttonsPressedThisFrame2.bits = buttons;
}