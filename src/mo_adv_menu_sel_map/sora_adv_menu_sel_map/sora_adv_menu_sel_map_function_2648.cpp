#include <gf/gf_pad_system.h>
#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#pragma force_active on

extern "C" int fn_800BA3D8(void*);

extern const float lbl_31_rodata_0[];

struct SelMapMenu {
    char pad00[0x50];
    int f50;
    int f54;
    char pad58[0x5A - 0x58];
    unsigned char f5A;
    char pad5B[0x64 - 0x5B];
    char sub64[0x1C0 - 0x64];
    MuMsg* msg;
    char pad1C4[0x1D4 - 0x1C4];
    MuObject* obj;
    char pad1D8[0x4C9 - 0x1D8];
    char text4C9[0x549 - 0x4C9];
    char text549[0x5CC - 0x549];
    int f5CC;
    int f5D0;
};

extern "C" void fn_31_2648(SelMapMenu* self, u32 arg1) {
    const float* ro = lbl_31_rodata_0;
    gfPadStatus status;
    MuObject* obj = self->obj;

    g_gfPadSystem->getSysPadStatus(fn_800BA3D8(&self->sub64), &status);

    switch (status.m_controllerType) {
    case 0:
        obj->setFrameTex(ro[0x40 / 4]);
        break;
    case 1:
        obj->setFrameTex(ro[0x100 / 4]);
        break;
    case 3:
        obj->setFrameTex(ro[0xF8 / 4]);
        break;
    case 2:
        obj->setFrameTex(ro[0xFC / 4]);
        break;
    default:
        obj->setFrameTex(ro[0x34 / 4]);
        break;
    }

    switch (arg1) {
    case 0:
        obj->setFrameNode(ro[0x34 / 4]);
        obj->setFrameMatCol(ro[0x34 / 4]);
        break;
    case 1:
        obj->setFrameNode(ro[0x40 / 4]);
        obj->setFrameMatCol(ro[0x40 / 4]);
        break;
    case 2:
        obj->setFrameNode(ro[0xF8 / 4]);
        obj->setFrameMatCol(ro[0xF8 / 4]);
        break;
    case 3:
        obj->setFrameNode(ro[0xFC / 4]);
        obj->setFrameMatCol(ro[0xFC / 4]);
        break;
    case 4:
        obj->setFrameNode(ro[0x100 / 4]);
        obj->setFrameMatCol(ro[0x100 / 4]);
        break;
    case 5:
        obj->setFrameNode(ro[0x104 / 4]);
        obj->setFrameMatCol(ro[0x104 / 4]);
        break;
    case 6:
        obj->setFrameNode(ro[0x108 / 4]);
        obj->setFrameMatCol(ro[0x108 / 4]);
        break;
    }

    if ((s32)arg1 == 0) {
        self->msg->setFontColor(4, 0xB8, 0x2E, 0x2E, 0xFF);
    } else {
        self->msg->setFontColor(4, 0x9A, 0x65, 0x65, 0xFF);
    }

    if (self->f5CC == 0 && self->f50 == 0) {
        self->msg->printIndex(4, 0x22, NULL);
    } else {
        self->msg->printf(4, self->text4C9);
    }

    if ((s32)arg1 == 1) {
        self->msg->setFontColor(5, 0x2E, 0x2E, 0xB8, 0xFF);
    } else {
        self->msg->setFontColor(5, 0x65, 0x65, 0x9A, 0xFF);
    }

    if (self->f5A != 0) {
        if (self->f5D0 == 0 && self->f54 == 0) {
            self->msg->printIndex(5, 0x23, NULL);
            return;
        }
        self->msg->printf(5, self->text549);
    }
}
