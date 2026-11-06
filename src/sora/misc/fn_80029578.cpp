#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <types.h>
#pragma force_active on

struct PADStatus {
    u16 button;
    s8 stickX;
    s8 stickY;
    s8 substickX;
    s8 substickY;
    u8 triggerL;
    u8 triggerR;
    u8 analogA;
    u8 analogB;
    s8 err;
    s8 pad;
};

extern "C" void fn_80215FC4(PADStatus* status);
extern "C" s32 fn_80215C54(u32 mask);
extern float lbl_805A1528;

void gfPadSystem::updateLowGC(gfPadStatus* dest) {
    PADStatus pads[4];
    PADStatus* src;
    gfPadStatus* out;
    u32 connected;
    u32 noCtrl;
    u32 shift;
    u32 tmp;
    f32 zero;
    int i;

    fn_80215FC4(pads);
    connected = *(u32*)&_0x944[0];
    noCtrl = 0;
    shift = 0;
    src = pads;
    for (i = 0; i < 2; i++) {
        switch (src[0].err) {
        case 0:
        case -3:
            connected |= 0x80000000U >> shift;
            break;
        case -1:
            noCtrl |= 0x80000000U >> shift;
            break;
        }
        tmp = shift + 1;
        switch (src[1].err) {
        case 0:
        case -3:
            connected |= 0x80000000U >> tmp;
            break;
        case -1:
            noCtrl |= 0x80000000U >> tmp;
            break;
        }
        src += 2;
        shift = tmp + 1;
    }
    *(u32*)&_0x944[0] = connected;
    if (noCtrl != 0) {
        fn_80215C54(noCtrl);
    }

    zero = lbl_805A1528;
    src = pads;
    out = dest;
    for (i = 0; i < 4; i++) {
        out->m_buttonsPressedThisFrame2.bits = 0;
        out->m_buttonsReleasedThisFrame.bits = 0;
        out->m_buttonsPressedThisFrame.bits = 0;
        out->m_buttonsHeld.bits = 0;
        out->m_buttonsCurrentFrame2.bits = 0;
        out->m_buttonsCurrentFrame.bits = 0;
        out->m_stickY = 0;
        out->m_stickX = 0;
        out->m_subStickY = 0;
        out->m_subStickX = 0;
        out->m_rTriggerAnalog = 0;
        out->m_lTriggerAnalog = 0;
        out->_0x37 = 0;
        out->_0x36 = 0;
        out->_0x24 = zero;
        out->_0x20 = zero;
        out->_0x1c = zero;
        out->_0x18 = zero;
        out->_0x2c = zero;
        out->_0x28 = zero;
        out->m_error = gfPadError::NO_CONTROLLER;
        out->m_controllerType = gfPadType::GCC;
        if (src->err == 0) {
            out->m_buttonsCurrentFrame.bits = src->button;
            out->m_buttonsCurrentFrame2.bits = src->button;
            out->m_stickX = src->stickX;
            out->m_stickY = src->stickY;
            out->m_subStickX = src->substickX;
            out->m_subStickY = src->substickY;
            out->m_lTriggerAnalog = src->triggerL;
            out->m_rTriggerAnalog = src->triggerR;
            out->_0x36 = src->analogB;
            out->m_error = (gfPadError::PadError)src->err;
            out->m_controllerType = gfPadType::GCC;
        } else {
            out->m_error = (gfPadError::PadError)src->err;
            out->m_controllerType = gfPadType::GCC;
        }
        out++;
        src++;
    }
}
