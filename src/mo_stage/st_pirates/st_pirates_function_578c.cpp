#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" const float lbl_52_rodata_E8[];
extern "C" char lbl_52_data_103C[];

struct FnStageBase {
    unsigned char pad[0x3c];
};

class FnStageObj : public FnStageBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_52_4E70();
    virtual void processUpdate();
    virtual void processPreMapCorrection();
    virtual void processMapCorrection();
    virtual void processFixPosition();
    virtual void processPreCollision();
    virtual void processCollision();
    virtual void processCatch();
    virtual void processHit();
    virtual void processCamera();
    virtual void processFixCamera();
    virtual void processEffect();
    virtual void processGameProc();
    virtual void processEnd();
    virtual void renderPre();
    virtual void renderOpa();
    virtual void renderXlu();
    virtual void processDebug();
    virtual void renderDebug();
    virtual void init();
    virtual void fn_52_4DE0();
    virtual void fn_52_4F0C();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_52_36EC();
    virtual void startup();
    virtual void setNode();
    virtual void fn_52_83C();
    virtual void fn_52_36E4();
    virtual void fn_52_36E0();
    virtual void fn_52_35C8();
    virtual void fn_52_36D8();
    virtual void fn_52_36CC();
    virtual void fn_52_36BC();
    virtual void fn_52_36AC();
    virtual void getNodeIndex();
    virtual void getNodePosition();
    virtual void getNodePosition_2();
    virtual void getNodeMatrix();
    virtual void getNodeMatrix_2();
    virtual void setNodeVisibility();
    virtual void setNodeVisibility_2();
    virtual void setNodeVisibilityAll();
    virtual void isNodeVisible();
    virtual void setNodeCollision();
    virtual void setNodeCollision_2();
    virtual void getNodeScale();
    virtual void getNodeScale_2();
    virtual void setValid();
    virtual void setValidAttachedEffect();
    virtual void fn_52_36A8();
    virtual void fn_52_36A4();
    virtual void fn_52_369C();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);

    unsigned char unk40[4];
    nw4r::g3d::ScnMdl** unk44;
    unsigned char unk48[0x134];
    unsigned char unk17C;
    unsigned char unk17D[0x1f];
    unsigned long unk19C;
    unsigned char unk1A0;
};

extern "C" void fn_52_578C(FnStageObj* self) {
    const float* c = lbl_52_rodata_E8;

    switch (self->unk17C) {
    case 16:
        switch (self->unk1A0) {
        case 0:
            if (self->getMotionFrame(0) < c[5]) {
                return;
            }
            if (self->unk19C != 0) {
                g_ecMgr->endEffect(self->unk19C);
            }
            self->unk19C = 0;
            self->unk1A0 = self->unk1A0 + 1;
            break;
        case 1:
            if (self->getMotionFrame(0) < c[9]) {
                return;
            }
            g_ecMgr->setDrawPrio(1);
            self->unk19C = g_ecMgr->setEffect((EfID)0x3A0005);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setParent(self->unk19C, *self->unk44, lbl_52_data_103C, false);
            self->unk1A0 = self->unk1A0 + 1;
            break;
        }
        break;
    case 17:
        switch (self->unk1A0) {
        case 0:
            if (!(self->getMotionFrame(0) < c[10])) {
                if (self->unk19C != 0) {
                    g_ecMgr->endEffect(self->unk19C);
                }
                self->unk19C = 0;
                self->unk1A0 = self->unk1A0 + 1;
            }
        }
        break;
    case 18:
        break;
    case 19:
        switch (self->unk1A0) {
        case 0:
            if (!(self->getMotionFrame(0) < c[11])) {
                g_ecMgr->setDrawPrio(1);
                self->unk19C = g_ecMgr->setEffect((EfID)0x3A0005);
                g_ecMgr->setDrawPrio(-1);
                g_ecMgr->setParent(self->unk19C, *self->unk44, lbl_52_data_103C, false);
                self->unk1A0 = self->unk1A0 + 1;
            }
        }
    }
}
