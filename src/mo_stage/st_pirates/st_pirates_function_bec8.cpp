#include <types.h>
#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#pragma force_active on

extern "C" int getNodeIndex__6GroundFPUlUlPCc(void* self, u32* out, u32 mdl, const char* name);
extern "C" char lbl_52_data_25D8[];
extern "C" const float lbl_52_rodata_1B8[];

struct GroundBase {
    unsigned char pad[0x3C];
};

class Ground : public GroundBase {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void processAnim();
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
    virtual void fn_52_BAD8();
    virtual void fn_52_BB40();
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
    virtual void getNodePosition(Vec3f* pos, u32 a, u32 b);
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
    virtual float getMotionFrame(u32 frame);

    unsigned char pad40[0x16D - 0x40];
    unsigned char flag16D;
    unsigned char pad16E[0x178 - 0x16E];
    snd3DGenerator gen;
    int id180;
    unsigned char state184;
};

extern "C" void fn_52_BEC8(Ground* self) {
    const float* c = lbl_52_rodata_1B8;
    Vec3f spC;
    u32 sp8;

    if (self->flag16D == 0) {
        if (getNodeIndex__6GroundFPUlUlPCc(self, &sp8, 0, lbl_52_data_25D8) != 0) {
            self->getNodePosition(&spC, 0, sp8);
            self->gen.setPos(&spC);
            switch (self->state184) {
            case 0:
                self->id180 = self->gen.playSE((SndID)0x1B9F, 0, 0, -1);
                self->state184++;
                break;
            case 1:
                if (!(self->getMotionFrame(0) < c[5])) {
                    if (self->id180 != -1) {
                        self->gen.stopSE(self->id180, 0x5A);
                    }
                    self->id180 = self->gen.playSE((SndID)0x1BA0, 0, 0, -1);
                    self->state184++;
                }
                break;
            case 2:
                if (!(self->getMotionFrame(0) < c[6])) {
                    if (self->id180 != -1) {
                        self->gen.stopSE(self->id180, 0x5A);
                    }
                    self->id180 = self->gen.playSE((SndID)0x1BA1, 0, 0, -1);
                    self->state184++;
                }
                break;
            case 3:
                if (!(self->getMotionFrame(0) < c[7])) {
                    if (self->id180 != -1) {
                        self->gen.stopSE(self->id180, 0x5A);
                    }
                    self->id180 = self->gen.playSE((SndID)0x1BA2, 0, 0, -1);
                    self->state184++;
                }
                break;
            case 4:
                if (!(self->getMotionFrame(0) < c[8])) {
                    if (self->id180 != -1) {
                        self->gen.stopSE(self->id180, 0x5A);
                    }
                    self->id180 = -1;
                    self->gen.playSE((SndID)0x1BA3, 0, 0, -1);
                    self->state184++;
                }
                break;
            }
        }
    }
}
