#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#pragma force_active on

extern "C" void fn_800B9984(void*);

struct MenuMain {
    char padding[0x68];
    unsigned int current;
    unsigned int unknown;
    unsigned int pressed;
};

extern "C" void fn_2_12C6C(MenuMain* self, gfPadStatus* output) {
    fn_800B9984((char*)self + 0x60);
    output->m_buttonsPressedThisFrame2.bits |= self->pressed;
    output->m_buttonsCurrentFrame2.bits |= self->current;

    for (int i = 0; i < 8; ++i) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(i, &status);
        if (status.m_error < 0)
            continue;

        switch (status.m_controllerType) {
        case gfPadType::WIIMOTE:
            if (status.m_buttonsCurrentFrame2.bits & 0x400000) {
                output->m_buttonsCurrentFrame2.bits = 0;
                output->m_buttonsPressedThisFrame2.bits = 0;

                if (status.m_buttonsPressedThisFrame.bits & 0x200)
                    output->m_buttonsPressedThisFrame.bits ^= 0x200;

                if ((status.m_buttonsPressedThisFrame2.bits & 0x10000) ||
                    (status.m_buttonsPressedThisFrame2.bits & 1)) {
                    output->m_buttonsPressedThisFrame2.bits |= 0x40;
                } else if ((status.m_buttonsPressedThisFrame2.bits & 0x20000) ||
                           (status.m_buttonsPressedThisFrame2.bits & 2)) {
                    output->m_buttonsPressedThisFrame2.bits |= 0x20;
                }

                if ((status.m_buttonsCurrentFrame2.bits & 0x10000) ||
                    (status.m_buttonsCurrentFrame2.bits & 1)) {
                    output->m_buttonsCurrentFrame2.bits |= 0x40;
                } else if ((status.m_buttonsCurrentFrame2.bits & 0x20000) ||
                           (status.m_buttonsCurrentFrame2.bits & 2)) {
                    output->m_buttonsCurrentFrame2.bits |= 0x20;
                }
            }
            break;

        case gfPadType::NUNCHUK:
            if (status.m_buttonsCurrentFrame2.bits & 0x40000)
                output->m_buttonsPressedThisFrame2.bits &= ~0x400;

            if ((status.m_buttonsPressedThisFrame2.bits & 0x10000) ||
                (status.m_buttonsPressedThisFrame2.bits & 0x80000)) {
                output->m_buttonsPressedThisFrame2.bits |= 0x40;
            } else if ((status.m_buttonsPressedThisFrame2.bits & 0x20000) ||
                       (status.m_buttonsPressedThisFrame2.bits & 0x1000)) {
                output->m_buttonsPressedThisFrame2.bits |= 0x20;
            }

            if ((status.m_buttonsCurrentFrame2.bits & 0x10000) ||
                (status.m_buttonsCurrentFrame2.bits & 0x80000)) {
                output->m_buttonsCurrentFrame2.bits |= 0x40;
            } else if ((status.m_buttonsCurrentFrame2.bits & 0x20000) ||
                       (status.m_buttonsCurrentFrame2.bits & 0x1000)) {
                output->m_buttonsCurrentFrame2.bits |= 0x20;
            }
            break;
        }
    }
}
