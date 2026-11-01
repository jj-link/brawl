#pragma force_active on

#include <ec/ec_mgr.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>

extern "C" {
extern const float lbl_27_rodata_61E8;
extern const float lbl_27_rodata_61E0;
void fn_800606F4(ecMgr*, u32, s32);
void* fn_800607C8(ecMgr*, u32);
}

struct Object {
    u32 field00;
    u32 field04;
    u32 field08;
    u32 effectHandle;
    MuMsg* message;
    u32 messageIndex;
    u8 padding18[0x0C];
    u32 field24;
};

extern "C" void fn_27_2D5788(Object* self, u32 arg1, MuMsg* arg2, u32 arg3) {
    s32 animation = arg1;
    Vec3f position;
    void* model;
    void* attachedModel;
    u32 manager = (u32)g_ecMgr;

    position.m_x = lbl_27_rodata_61E8;
    position.m_y = lbl_27_rodata_61E8;
    position.m_z = lbl_27_rodata_61E8;

    self->effectHandle =
        ((ecMgr*)manager)->setEffect((EfID)0x01360001, &position);
    fn_800606F4((ecMgr*)manager, self->effectHandle, animation);
    ((ecMgr*)manager)->setMdlEnableUpdate(self->effectHandle, 0, 0x12);

    model = fn_800607C8((ecMgr*)manager, self->effectHandle);
    if (model != 0) {
        ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(1, 1);
        ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(6, 1);
        ((nw4r::g3d::ScnMdlSimple*)model)->SetScnObjOption(7, 1);
    }

    self->message = arg2;
    self->messageIndex = arg3;

    attachedModel = fn_800607C8((ecMgr*)manager, self->effectHandle);
    self->message->attachScnMdlSimple(
        self->messageIndex, (nw4r::g3d::ScnMdlSimple*)attachedModel, 1,
        lbl_27_rodata_61E0);
    self->message->attachScnMdlSimple(
        self->messageIndex + 1, (nw4r::g3d::ScnMdlSimple*)attachedModel, 2,
        lbl_27_rodata_61E0);
    self->message->attachScnMdlSimple(
        self->messageIndex + 2, (nw4r::g3d::ScnMdlSimple*)attachedModel, 3,
        lbl_27_rodata_61E0);

    self->message->setAlignMode(self->messageIndex, MuMsg::Align_Center);
    self->message->setAlignMode(self->messageIndex + 1, MuMsg::Align_Center);
    self->message->setAlignMode(self->messageIndex + 2, MuMsg::Align_Center);

    self->message->attachScnMdlSimple(
        self->messageIndex + 3,
        (nw4r::g3d::ScnMdlSimple*)attachedModel, 0, lbl_27_rodata_61E0);
    self->message->setAlignMode(self->messageIndex + 3, MuMsg::Align_Center);

    self->field00 = 0;
    self->field08 = 0;
    self->field04 = 0;
    self->field24 = 0x100;
}
