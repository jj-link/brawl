#include <mu/mu_msg.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <nw4r/g3d/g3d_scnmdl.h>

#pragma force_active on

extern "C" {
void fn_28_175C(void*, int, void*);
int fn_800B61C0(MuObject*);
void fn_800B9488(MuMsg*, unsigned long, unsigned long);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
extern char lbl_28_data_0[];
extern const float lbl_28_rodata_8C;
extern const float lbl_28_rodata_94;
}

struct NameMenu {
    char pad00[0x50];
    int mode0;
    int mode1;
    int flag0;
    int flag1;
    char pad60[0xAC];
    int selection0;
    int selection1;
    int page0;
    int page1;
    char pad11C[8];
    unsigned char secondEnabled;
    char pad125[7];
    MuMsg* msg;
    MuObject* object130;
    MuObject* object134;
    MuObject* object138;
    MuObject* object13C;
    MuObject* object140;
    char pad144[4];
    MuObject* object148;
    char pad14C[0xC];
    nw4r::g3d::ScnGroup* group158;
    nw4r::g3d::ScnGroup* group15C;
    char pad160[8];
    int result;
    char pad16C[0xB0];
    int state0;
    char pad220[0xB4];
    int state1;
    char pad2D8[0x36];
    char name0[0x15];
    char name1[0x15];
    char pad338[0x14];
    int field34C;
};

extern "C" int fn_28_1F84(NameMenu* self) {
    char* data = lbl_28_data_0;
    MuObject* object138 = self->object138;
    MuObject* object134 = self->object134;
    MuObject* object13C = self->object13C;

    fn_28_175C(self, 0, self->object140);

    if (self->state0 == 1) {
        self->state0 = 2;
        self->group15C->Remove(self->object140->m_sceneModel);
        if (self->mode0 == 0) {
            object138->changeNodeAnimNIf(data + 0x174);
            object138->changeVisAnimNIf(data + 0x174);
            object138->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_28_rodata_94);
            object138->setFrameNode(lbl_28_rodata_8C);
            object138->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_28_rodata_94);
            object138->setFrameVisible(lbl_28_rodata_8C);
        } else if (self->mode0 == 2) {
            object138->changeNodeAnimNIf(data + 0x18C);
            object138->changeVisAnimNIf(data + 0x18C);
        }
    }

    if (self->secondEnabled) {
        fn_28_175C(self, 1, object13C);
        if (self->state1 == 1) {
            self->state1 = 2;
            self->group158->Remove(self->object13C->m_sceneModel);
            if (self->mode1 == 0) {
                object134->changeNodeAnimNIf(data + 0x174);
                object134->changeVisAnimNIf(data + 0x174);
                object134->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_28_rodata_94);
                object134->setFrameNode(lbl_28_rodata_8C);
                object134->m_modelAnim->m_anmObjVisRes->SetUpdateRate(lbl_28_rodata_94);
                object134->setFrameVisible(lbl_28_rodata_8C);
                self->object130->setFrameVisible(lbl_28_rodata_94);
            } else if (self->mode1 == 2) {
                object134->changeNodeAnimNIf(data + 0x18C);
                object134->changeVisAnimNIf(data + 0x18C);
                if (self->field34C == -1) {
                    self->object130->setFrameVisible(lbl_28_rodata_8C);
                }
            }
        }
    }

    if (self->state0 == 2 && fn_800B61C0(object138)) {
        self->state0 = 3;
        if (self->mode0 == 0) {
            fn_800B9488(self->msg, 10, 1);
            self->msg->setAlignMode(10, MuMsg::Align_Center);
            self->msg->setFontColor(10, 0, 0, 0, 255);
            self->msg->printf(10, self->name0);
            if (self->page0 == 0 && self->selection0 == 0) {
                fn_800B9488(self->msg, 10, 0);
                self->msg->printIndex(10, 3, NULL);
            }
        } else if (self->mode0 == 2) {
            MuObject* object = self->object148;
            object->m_modelAnim->m_anmObjChrRes->SetUpdateRate(lbl_28_rodata_8C);
            object->setFrameNode(lbl_28_rodata_8C);
            self->object130->setFrameNode(lbl_28_rodata_8C);
        }
    }

    if (self->state1 == 2 && fn_800B61C0(object134)) {
        self->state1 = 3;
        if (self->mode1 == 0) {
            fn_800B9488(self->msg, 11, 1);
            self->msg->setAlignMode(11, MuMsg::Align_Center);
            self->msg->setFontColor(11, 0, 0, 0, 255);
            self->msg->printf(11, self->name1);
            if (self->page1 == 0 && self->selection1 == 0) {
                fn_800B9488(self->msg, 11, 0);
                self->msg->printIndex(11, 3, NULL);
            }
        } else if (self->mode1 == 2) {
            self->secondEnabled = 0;
            self->mode1 = 0;
            self->state1 = 0;
        }
    }

    if (!self->secondEnabled) {
        if (self->state0 == 3) {
            if (self->mode0 == 0) {
                self->result = 4;
            } else if (self->mode0 == 2) {
                self->result = 1;
            }
        }
    } else {
        if (self->state0 == 3 && self->state1 == 3) {
            if (self->mode0 == 0 && self->mode1 == 0) {
                self->result = 4;
            } else {
                self->result = 1;
            }
        }

        if (self->state0 == 3 && self->state1 != 3) {
            if (self->flag0 == 2) {
                self->flag0 = 0;
                self->state0 = 0;
                self->msg->printf(10, data + 0x1A4);
                MuObject* object = self->object138;
                object->changeNodeAnimNIf(data + 0x12C);
                object->changeVisAnimNIf(data + 0x12C);
                object->setFrameNode(lbl_28_rodata_8C);
                object->setFrameVisible(lbl_28_rodata_8C);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                    self->group15C, self->object140->m_sceneModel, data + 0xEC);
            }
            if (self->flag1 == 2) {
                self->flag1 = 0;
                self->state1 = 0;
                self->msg->printf(11, data + 0x1A4);
                MuObject* object = self->object134;
                object->changeNodeAnimNIf(data + 0x12C);
                object->changeVisAnimNIf(data + 0x12C);
                object->setFrameNode(lbl_28_rodata_8C);
                object->setFrameVisible(lbl_28_rodata_8C);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                    self->group158, self->object13C->m_sceneModel, data + 0xEC);
            }
        }

        if (self->state0 != 3 && self->state1 == 3 && self->flag1 == 2) {
            self->flag1 = 0;
            self->state1 = 0;
            self->msg->printf(11, data + 0x1A4);
            MuObject* object = self->object134;
            object->changeNodeAnimNIf(data + 0x12C);
            object->changeVisAnimNIf(data + 0x12C);
            object->setFrameNode(lbl_28_rodata_8C);
            object->setFrameVisible(lbl_28_rodata_8C);
            Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                self->group158, self->object13C->m_sceneModel, data + 0xEC);
        }
    }

    return self->result;
}
