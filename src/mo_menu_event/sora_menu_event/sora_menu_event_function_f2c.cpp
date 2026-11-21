#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on
extern "C" int fn_800BA3D8(void*);
extern unsigned char lbl_9_rodata_AC[];
struct Entry { char data[0xa8]; };
struct Self {
    char pad0[0x188];
    MuObject* objects[2];
    char pad190[0x28];
    Entry entries[1];
    char pad260[0x155c];
    int count;
    char pad17c0[0x18];
    int ports[2];
};
static inline gfPadStatus getStatus(Self* self, int port) {
    gfPadStatus pads[2];
    gfPadStatus status;
    int count = (self->count == 1) + 1;
    if (port < 0) {
        for (int i = 0; i < count; i++)
            g_gfPadSystem->getSysPadStatus(self->ports[i], &pads[i]);
        gfPadSystem::merge(pads, count, &status);
    } else {
        g_gfPadSystem->getSysPadStatus(port, &status);
    }
    return status;
}
static inline void setIcon(Self* self, int index, int flag, int port, const gfPadStatus& pad, gfPadStatus& status) {
    status.m_buttonsCurrentFrame = pad.m_buttonsCurrentFrame;
    status.m_buttonsCurrentFrame2 = pad.m_buttonsCurrentFrame2;
    status.m_buttonsHeld = pad.m_buttonsHeld;
    status.m_buttonsPressedThisFrame = pad.m_buttonsPressedThisFrame;
    status.m_buttonsReleasedThisFrame = pad.m_buttonsReleasedThisFrame;
    status.m_buttonsPressedThisFrame2 = pad.m_buttonsPressedThisFrame2;
    status._0x18 = pad._0x18;
    status._0x1c = pad._0x1c;
    status._0x20 = pad._0x20;
    status._0x24 = pad._0x24;
    status._0x28 = pad._0x28;
    status._0x2c = pad._0x2c;
    status.m_stickX = pad.m_stickX;
    status.m_stickY = pad.m_stickY;
    status.m_subStickX = pad.m_subStickX;
    status.m_subStickY = pad.m_subStickY;
    status.m_lTriggerAnalog = pad.m_lTriggerAnalog;
    status.m_rTriggerAnalog = pad.m_rTriggerAnalog;
    status._0x36 = pad._0x36;
    status._0x37 = pad._0x37;
    status.m_error = pad.m_error;
    status.m_controllerType = pad.m_controllerType;
    bool valid = status.m_error == 0;
    if (flag || valid) {
        int type;
        if (!valid) {
            if (port < 4)
                type = 0;
            else
                type = 2;
        } else {
            type = status.m_controllerType;
        }
        MuObject* object = index == 0 ? self->objects[0] : self->objects[1];
        object->setFrameTex((float)lbl_9_rodata_AC[type]);
    }
}
extern "C" void fn_9_F2C(Self* self, int index, int flag) {
    int port = fn_800BA3D8(&self->entries[index + 1]);
    gfPadStatus status;
    gfPadStatus pad = getStatus(self, port);
    setIcon(self, index, flag, port, pad, status);
}