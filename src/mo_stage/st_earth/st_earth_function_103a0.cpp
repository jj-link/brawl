#pragma force_active on
typedef unsigned char u8;
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_66_FDC8();
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
    virtual void fn_66_FCD8();
    virtual void fn_66_FDCC();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void receiveCollMsg_Heading();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_66_2D00();
    virtual void startup();
    virtual void setNode();
    virtual void fn_66_6BC();
    virtual void fn_66_2CF8();
    virtual void fn_66_2CF4();
    virtual void fn_66_2BF4();
    virtual void fn_66_2CEC();
    virtual void fn_66_2CE0();
    virtual void fn_66_2CD0();
    virtual void fn_66_BBC();
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
    virtual void fn_66_2CCC();
    virtual void fn_66_2CC8();
    virtual void fn_66_2CC0();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_66_2CB8();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_66_2D2C();
    virtual void fn_66_2D24();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_66_2D1C();
    virtual void fn_66_1105C();
    virtual void onInflict();
    virtual void onInflictEach();
    virtual void onGimmickEvent();
    virtual void enableYakumono();
    virtual void disableYakumono();
    virtual void enableHit(unsigned long, unsigned long);
    virtual void disableHit(unsigned long, unsigned long);
    virtual void disableAttack();
    virtual void enableArea();
    virtual void disableArea();
    virtual void setSleepArea();
    virtual void setTeamYakumonoOwnerId();
    virtual void setTeamYakumono();
    virtual void getTeamYakumono();
    virtual void setOffsetAttack();
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_66_FEC0();
    virtual void fn_66_FF18();
    virtual void fn_66_103A0();
    virtual void fn_66_104DC();
    virtual void fn_66_10594();
    virtual void fn_66_10C14(int, int, int, float*);
    char pad40[0x110];
    u8 output;
    char pad151[7];
    u8 state;
    char pad159[3];
    float frame;
    char pad160[4];
    u8* event;
    char pad168[0x18];
    char generator[4];
};

extern "C" {
void setPos__14snd3DGeneratorFP5Vec3f(void*, void*);
void playSE__14snd3DGeneratorF5SndIDiii(void*, int, int, int, int);

void fn_66_103A0(Ground* self) {
    switch (self->state) {
    case 0:
    case 1:
    case 3:
    case 4:
        if (self->getMotionFrame(0) >= self->frame) {
            self->fn_66_10C14(5, 1, 1, 0);
            self->enableHit(0, 0);
            self->enableHit(1, 0);
            *self->event = 3;
        }
        break;
    case 2:
        if (self->getMotionFrame(0) >= self->frame) {
            setPos__14snd3DGeneratorFP5Vec3f(self->generator, (char*)self->event + 0x14);
            playSE__14snd3DGeneratorF5SndIDiii(self->generator, 0x1cc9, 0, 0, -1);
            *self->event = 0;
            self->output = 0;
        }
        break;
    }
}
}