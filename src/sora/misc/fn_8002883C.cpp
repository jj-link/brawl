#include <gf/gf_pad_status.h>
#pragma force_active on
extern float lbl_805A1528;
void gfPadStatus::init() {
    float zero = lbl_805A1528;
    m_buttonsPressedThisFrame2.bits = 0;
    m_buttonsReleasedThisFrame.bits = 0;
    m_buttonsPressedThisFrame.bits = 0;
    m_buttonsHeld.bits = 0;
    m_buttonsCurrentFrame2.bits = 0;
    m_buttonsCurrentFrame.bits = 0;
    m_stickY = 0;
    m_stickX = 0;
    m_subStickY = 0;
    m_subStickX = 0;
    m_rTriggerAnalog = 0;
    m_lTriggerAnalog = 0;
    _0x37 = 0;
    _0x36 = 0;
    _0x24 = zero;
    _0x20 = zero;
    _0x1c = zero;
    _0x18 = zero;
    _0x2c = zero;
    _0x28 = zero;
    m_error = gfPadError::NO_CONTROLLER;
    m_controllerType = gfPadType::GCC;
}