#include <gf/gf_pad_system.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on

extern const float lbl_2_rodata_1750;
extern const float lbl_2_rodata_1760;
extern int g_muWifiInterfaceTask;
extern "C" void fn_800C753C();

struct MenuState {
    char pad_000[0x40];
    int mode;
    MuObject* object;
    char pad_048[0x3C];
    unsigned int direction;
    char pad_088[0x9C];
    unsigned char selected;
    char pad_125[3];
    int state;
    char pad_12C[0xC];
    int fallback;
};

extern "C" int fn_2_390F8(MenuState* self) {
    int result;
    gfPadStatus status;
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    unsigned int direction = self->direction;
    if ((direction & 1) && self->selected == 0) {
        self->object->setFrameMatCol(lbl_2_rodata_1750);
        self->selected = 1;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
    if ((direction & 2) && self->selected != 0) {
        self->object->setFrameMatCol(lbl_2_rodata_1760);
        self->selected = 0;
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
    unsigned int buttons = status.m_buttonsPressedThisFrame.bits;
    if ((buttons & 0x1100) || (buttons & 0x200)) {
        unsigned char selected;
        if (buttons & 0x200) {
            selected = 0;
        } else {
            selected = self->selected;
        }
        if (selected != 0) {
            if (self->mode == 0) {
                result = 4;
            } else {
                result = 5;
            }
        } else {
            self->state = 3;
            if (self->mode == 0 && g_muWifiInterfaceTask != 0) {
                fn_800C753C();
            }
            result = 10;
        }
    } else {
        result = self->fallback;
    }
    return result;
}
