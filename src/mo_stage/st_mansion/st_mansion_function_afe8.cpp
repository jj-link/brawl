#include <types.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <snd/snd_3d_generator.h>
#include <ec/ec_mgr.h>
#pragma force_active on

extern "C" {
extern const float lbl_47_rodata_F0[];
extern const char lbl_47_data_2BE0[];
}

struct Ground_base {
    char pad[0x3c];
};

class Ground : public Ground_base {
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
    virtual void fn_47_AE48();
    virtual void fn_47_AEB0();
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
    virtual void fn_47_1A28();
    virtual void startup();
    virtual void setNode();
    virtual void fn_47_5A0();
    virtual void fn_47_1A20();
    virtual void fn_47_1A1C();
    virtual void fn_47_1748();
    virtual void fn_47_1A14();
    virtual void fn_47_1A08();
    virtual void fn_47_19F8();
    virtual void fn_47_19E8();
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
    virtual void fn_47_19E4();
    virtual void fn_47_19E0();
    virtual void fn_47_19D8();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop(bool, unsigned long);
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_47_19D0();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_47_1A54();
    virtual void fn_47_1A4C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_47_1A44();
    virtual void onDamage();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit();
    virtual void disableHit();
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_47_AF24();
    virtual void fn_47_AFE8();
    virtual void fn_47_B4AC(int, int, int, float*);

    unsigned char pad40[0x44 - 0x40];
    nw4r::g3d::ScnMdl** field44;
    unsigned char pad48[0x64 - 0x48];
    float f64;
    unsigned char pad68[0x150 - 0x68];
    unsigned char state;
    unsigned char pad151[3];
    float f154;
    unsigned char pad158[4];
    unsigned char* ptr15c;
    unsigned char pad160[4];
    float f164;
    unsigned char u168;
    unsigned char u169;
    unsigned char pad16a[2];
    float f16c;
    float f170;
    snd3DGenerator generator;
};

extern "C" void fn_47_AFE8(Ground* self, float delta) {
    const float* c = lbl_47_rodata_F0;

    self->f154 -= delta;
    if (self->f154 < c[1])
        self->f154 = c[1];

    switch (self->state) {
    case 0:
        self->fn_47_B4AC(0, 0, 1, &self->f170);
        self->setMotionFrame(self->f170, 0);
        self->state = 2;
        self->f16c = self->f170;
        /* fall through */
    case 2:
        if (self->ptr15c[0] == 2 || self->ptr15c[1] == 2 ||
            self->ptr15c[2] == 2 || self->ptr15c[3] == 2) {
            if (self->f64 < c[1])
                self->f64 *= c[3];
            self->setMotionLoop(false, 0);
            self->setMotionFrame(self->f16c, 0);
            self->state = 4;
            break;
        }

        if (c[1] == self->f164) {
            if (self->u168 == 0)
                self->u169 = 0;
            self->u168 = 1;
            switch (self->u169) {
            case 0:
                if (self->f64 > c[1])
                    self->f64 *= c[3];
                self->setMotionLoop(true, 0);
                if (self->getMotionFrame(0) > self->f170)
                    self->setMotionFrame(self->f170 - c[4], 0);
                self->f16c = self->getMotionFrame(0);
                self->u169++;
                /* fall through */
            case 1:
                if (self->getMotionFrame(0) > self->f16c) {
                    self->setMotionFrame(c[1], 0);
                    self->setMotionLoop(false, 0);
                    self->f16c = c[1];
                    self->u169++;
                } else {
                    self->f16c = self->getMotionFrame(0);
                }
                break;
            case 2:
                break;
            }
        } else {
            if (self->u168 == 1)
                self->u169 = 0;
            self->u168 = 0;
            switch (self->u169) {
            case 0:
                if (self->f64 < c[1])
                    self->f64 *= c[3];
                self->setMotionLoop(false, 0);
                self->setMotionFrame(self->f16c, 0);
                self->u169++;
                /* fall through */
            case 1:
                if (self->getMotionFrame(0) >= self->f170) {
                    self->f16c = self->f170;
                    self->u169++;
                }
                break;
            case 2:
                break;
            }
        }

        self->f164 -= delta;
        if (self->f164 < c[1])
            self->f164 = c[1];
        break;

    case 4:
        if (self->ptr15c[0] == 4 || self->ptr15c[1] == 4 ||
            self->ptr15c[2] == 4 || self->ptr15c[3] == 4) {
            unsigned long effect = g_ecMgr->setEffect((EfID)0x350006);
            g_ecMgr->setParent(effect, *self->field44, lbl_47_data_2BE0, true);
            self->generator.playSE((SndID)0x1b6f, 0, 0, -1);

            Vec3f pos;
            pos.m_x = c[1];
            pos.m_y = c[1];
            pos.m_z = c[1];
            self->generator.setPos(&pos);
            self->state = 5;
        }
        break;

    case 5:
        if (self->ptr15c[0] == 0)
            self->state = 0;
        break;

    default:
        return;
    }
}
