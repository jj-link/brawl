#pragma force_active on
typedef unsigned char u8;

struct Ground_base { char pad[0x3c]; };
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
    virtual void fn_76_1258();
    virtual void fn_76_12B0();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility(unsigned long);
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void receiveCollMsg_Landing();
    virtual void fn_76_19CC();
    virtual void receiveCollMsg_Wall();
    virtual void receiveCollMsg_Attack();
    virtual void unloadData();
    virtual void fn_76_110C();
    virtual void startup();
    virtual void setNode();
    virtual void fn_76_4F4();
    virtual void fn_76_1104();
    virtual void fn_76_1100();
    virtual void fn_76_BD8();
    virtual void fn_76_10F8();
    virtual void fn_76_10EC();
    virtual void fn_76_10DC();
    virtual void fn_76_10CC();
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
    virtual void fn_76_10C8();
    virtual void fn_76_10C4();
    virtual void fn_76_10BC();
    virtual void setMotionRatio();
    virtual void setMotionFrame(float, unsigned long);
    virtual float getMotionFrame(unsigned long);
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_76_10B4();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_76_1138();
    virtual void fn_76_1130();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_76_1128();
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
    virtual void setAreaGimmick();
    virtual void setAttackGimmick();
    virtual void setSoCollisionAttackData();
    virtual void setAttackGimmickDetails();
    virtual void isEnableAttackPersonAttacked();
    virtual void isEnableAttackAttribute();
    virtual void fn_76_1324();
    virtual void fn_76_14DC();
    virtual void fn_76_1584(int, int, int, float*);
    char pad40[0x11C];
    u8* ptr15C;
    char pad160[1];
    u8 state;
    char pad162[2];
    float frame;
    u8* ptr168;
};

extern "C" {
extern float lbl_76_rodata_24;
extern float lbl_76_rodata_28;
void setEnableCollisionStatus__6GroundFb(void*, bool);
}

extern "C" void fn_76_1324(Ground* self) {
    switch (self->state) {
    case 0:
        if (self->ptr168 != 0 && *self->ptr168 != 0) {
            self->fn_76_1584(1, 0, 1, &self->frame);
            setEnableCollisionStatus__6GroundFb(self, false);
        }
        break;
    case 1:
        if (self->getMotionFrame(0) >= self->frame) {
            self->fn_76_1584(2, 0, 1, &self->frame);
        }
        break;
    case 2:
        if (self->getMotionFrame(0) >= self->frame) {
            self->fn_76_1584(0, 0, 1, &self->frame);
            setEnableCollisionStatus__6GroundFb(self, true);
            *self->ptr168 = 100;
        } else if (self->getMotionFrame(0) >= lbl_76_rodata_24) {
            if (self->ptr15C != 0 && *self->ptr15C == 0) {
                self->setMotionFrame(lbl_76_rodata_28, 0);
            }
        }
        break;
    default:
        self->state = 0;
        break;
    }
}
