#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <snd/snd_system.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" void fn_800BA364(void*, u32);

static inline gfPadStatus getSysPad() {
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    return status;
}

static inline void copyPadStatus(gfPadStatus& destination, const gfPadStatus& source) {
    destination.m_buttonsCurrentFrame = source.m_buttonsCurrentFrame;
    destination.m_buttonsCurrentFrame2 = source.m_buttonsCurrentFrame2;
    destination.m_buttonsHeld = source.m_buttonsHeld;
    destination.m_buttonsPressedThisFrame = source.m_buttonsPressedThisFrame;
    destination.m_buttonsReleasedThisFrame = source.m_buttonsReleasedThisFrame;
    destination.m_buttonsPressedThisFrame2 = source.m_buttonsPressedThisFrame2;
    destination._0x18 = source._0x18;
    destination._0x1c = source._0x1c;
    destination._0x20 = source._0x20;
    destination._0x24 = source._0x24;
    destination._0x28 = source._0x28;
    destination._0x2c = source._0x2c;
    destination.m_stickX = source.m_stickX;
    destination.m_stickY = source.m_stickY;
    destination.m_subStickX = source.m_subStickX;
    destination.m_subStickY = source.m_subStickY;
    destination.m_lTriggerAnalog = source.m_lTriggerAnalog;
    destination.m_rTriggerAnalog = source.m_rTriggerAnalog;
    destination._0x36 = source._0x36;
    destination._0x37 = source._0x37;
    destination.m_error = source.m_error;
    destination.m_controllerType = source.m_controllerType;
}

extern "C" int fn_2_DC58(char* self) {
    int flags = *(int*)(self + 0x1A0);
    gfPadStatus status;
    copyPadStatus(status, getSysPad());
    int old = *(int*)(self + 0x254);
    int col = old % 2;
    int row = old / 2;
    if (flags & 2) {
        col = col < 1 ? col + 1 : 0;
        if (col == 1) fn_800BA364(self + 0x190, 2);
    }
    if (flags & 1) {
        col = col > 0 ? col - 1 : 1;
        if (col == 0) fn_800BA364(self + 0x190, 1);
    }
    if (flags & 4) {
        row = row < 1 ? row + 1 : 0;
        if (row == 1) fn_800BA364(self + 0x190, 4);
    }
    if (flags & 8) {
        row = row > 0 ? row - 1 : 1;
        if (row == 0) fn_800BA364(self + 0x190, 8);
    }
    MuObject* object;
    int selected = col + row * 2;
    if (selected != old) {
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
        object = *(MuObject**)(self + 0x148);
        float frame = selected;
        object->setFrameNode(frame);
        object->setFrameVisible(frame);
        *(int*)(self + 0x254) = (u8)selected;
    }
    if (status.m_buttonsPressedThisFrame.bits & 0x1300) {
        if (status.m_buttonsPressedThisFrame.bits & 0x1100) {
            *(u8*)(self + 0x44) = selected;
            g_sndSystem->playSE((SndID)1, -1, 0, 0, -1);
            return 0xB;
        }
        g_sndSystem->playSE((SndID)2, -1, 0, 0, -1);
        return 0xC;
    }
    return *(int*)(self + 0x238);
}
