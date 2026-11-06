#include <gf/gf_pad_system.h>
#pragma force_active on

extern float lbl_805A1528;
extern "C" void fn_8002C78C(gfRumble*);
extern "C" void fn_80028A08(gfPadStatus*, gfPadStatus*);

void gfPadSystem::updateGame() {
    if (m_gfRumble) fn_8002C78C(m_gfRumble);
    gfPadStatus empty;
    empty.m_buttonsPressedThisFrame2.bits = 0;
    empty.m_buttonsReleasedThisFrame.bits = 0;
    empty.m_buttonsPressedThisFrame.bits = 0;
    empty.m_buttonsHeld.bits = 0;
    empty.m_buttonsCurrentFrame2.bits = 0;
    empty.m_buttonsCurrentFrame.bits = 0;
    empty.m_stickY = 0;
    empty.m_stickX = 0;
    empty.m_subStickY = 0;
    empty.m_subStickX = 0;
    empty.m_rTriggerAnalog = 0;
    empty.m_lTriggerAnalog = 0;
    empty._0x37 = 0;
    empty._0x36 = 0;
    empty._0x24 = lbl_805A1528;
    empty._0x20 = lbl_805A1528;
    empty._0x1c = lbl_805A1528;
    empty._0x18 = lbl_805A1528;
    empty._0x2c = lbl_805A1528;
    empty._0x28 = lbl_805A1528;
    empty.m_error = gfPadError::NO_CONTROLLER;
    empty.m_controllerType = (gfPadType::PadType)0;
    gfPadStatus queued[8];
    if ((_0x34 >> 3) & 1) {
        if (m_padQueue->pop(queued)) {
            gfPadStatus* dst = m_gameGcnPads;
            gfPadStatus* src = queued;
            for (unsigned int i = 0; i < 8; ++i, ++dst, ++src) {
                if ((1 << i) & _0x3e) fn_80028A08(dst, &empty);
                else fn_80028A08(dst, src);
            }
            _0x34 |= 0x80;
        } else {
            gfPadStatus* dst = m_gameGcnPads;
            gfPadSystem* p = this;
            for (unsigned int i = 0; i < 8; ++i, ++dst, p = (gfPadSystem*)((char*)p + 0x40)) {
                if ((1 << i) & _0x3e) fn_80028A08(dst, &empty);
                else {
                    p->m_gameGcnPads[0].m_buttonsReleasedThisFrame.bits = 0;
                    p->m_gameGcnPads[0].m_buttonsPressedThisFrame.bits = 0;
                    p->m_gameGcnPads[0].m_buttonsHeld.bits = p->m_gameGcnPads[0].m_buttonsCurrentFrame2.bits;
                }
            }
            _0x34 |= 0x80;
        }
    } else {
        gfPadStatus* dst = m_gameGcnPads;
        gfPadStatus* src = m_systemPads;
        for (unsigned int i = 0; i < 8; ++i, ++dst, ++src) {
            if ((1 << i) & _0x3e) fn_80028A08(dst, &empty);
            else fn_80028A08(dst, src);
        }
        _0x34 |= 0x80;
        if ((unsigned short)m_unkCounter != 0) _0x34 &= 0x7f;
    }
    if (_0x34 & 1) {
        for (int i = 0; i < 8; ++i) {
            m_gameGcnPads[i].m_buttonsCurrentFrame.bits &= ~0x10;
            m_gameGcnPads[i].m_buttonsCurrentFrame2.bits &= ~0x10;
        }
    }
    merge(m_gameGcnPads, 8, m_gamePadMask, &m_gamePadMerged);
    if (_0x3e & 0x100) {
        m_gamePadMerged.m_buttonsCurrentFrame = empty.m_buttonsCurrentFrame;
        m_gamePadMerged.m_buttonsCurrentFrame2 = empty.m_buttonsCurrentFrame2;
        m_gamePadMerged.m_buttonsHeld = empty.m_buttonsHeld;
        m_gamePadMerged.m_buttonsPressedThisFrame = empty.m_buttonsPressedThisFrame;
        m_gamePadMerged.m_buttonsReleasedThisFrame = empty.m_buttonsReleasedThisFrame;
        m_gamePadMerged.m_buttonsPressedThisFrame2 = empty.m_buttonsPressedThisFrame2;
        m_gamePadMerged._0x18 = empty._0x18;
        m_gamePadMerged._0x1c = empty._0x1c;
        m_gamePadMerged._0x20 = empty._0x20;
        m_gamePadMerged._0x24 = empty._0x24;
        m_gamePadMerged._0x28 = empty._0x28;
        m_gamePadMerged._0x2c = empty._0x2c;
        m_gamePadMerged.m_stickX = empty.m_stickX;
        m_gamePadMerged.m_stickY = empty.m_stickY;
        m_gamePadMerged.m_subStickX = empty.m_subStickX;
        m_gamePadMerged.m_subStickY = empty.m_subStickY;
        m_gamePadMerged.m_lTriggerAnalog = empty.m_lTriggerAnalog;
        m_gamePadMerged.m_rTriggerAnalog = empty.m_rTriggerAnalog;
        m_gamePadMerged._0x36 = empty._0x36;
        m_gamePadMerged._0x37 = empty._0x37;
        m_gamePadMerged.m_error = empty.m_error;
        m_gamePadMerged.m_controllerType = empty.m_controllerType;
    }
    *(unsigned short*)&m_unkCounter += 1;
}