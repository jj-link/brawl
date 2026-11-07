#pragma force_active on
#pragma fp_contract off

extern "C" float randf__Fv();
extern "C" const float lbl_63_rodata_54;

struct Params {
    char pad[0x18];
    float low;
    float high;
};
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
    virtual void processDefault();
    virtual void processBegin();
    virtual void fn_63_3C84();
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
    virtual void fn_63_3BE4();
    virtual void fn_63_3D84();
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
    virtual void fn_63_3378();
    virtual void startup();
    virtual void setNode();
    virtual void fn_63_59C();
    virtual Params* fn_63_3370();
    virtual void fn_63_336C();
    virtual void fn_63_2B64();
    virtual void fn_63_3364();
    virtual void fn_63_3358();
    virtual void fn_63_3348();
    virtual void fn_63_3338();
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
    virtual void fn_63_3334();
    virtual void fn_63_3330();
    virtual void fn_63_3328();
    virtual void setMotionRatio();
    virtual void setMotionFrame();
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_63_3320();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_63_1884();
    virtual void fn_63_339C();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_63_3394();
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
    virtual void fn_63_2D00();
    virtual void fn_63_2E10();
    virtual void fn_63_2ED8();
    virtual void fn_63_8FC();
    virtual void fn_63_904();
    virtual void fn_63_3DD4();
    virtual void fn_63_3E24();
    virtual void fn_63_462C();
    virtual void fn_63_470C();
    virtual void fn_63_484C();
    virtual void fn_63_4D18();
    virtual void fn_63_90C();
    virtual void fn_63_914();
    virtual void fn_63_91C();
    virtual void fn_63_924();
    virtual void fn_63_92C();
    virtual void fn_63_3E58();
    virtual void fn_63_3F00();
    virtual void fn_63_49B8();
    char pad40[0x11d];
    unsigned char state;
    char pad15e[0x2a];
    unsigned char* flag;
    char pad18c[8];
    float timer;
};

extern "C" void fn_63_462C(Ground* self, float delta) {
    if (*self->flag == 1 && self->state == 1) {
        Params* params = self->fn_63_3370();
        if (params != 0) {
            self->timer -= delta;
            if (self->timer < lbl_63_rodata_54)
                self->timer = lbl_63_rodata_54;
            if (lbl_63_rodata_54 == self->timer) {
                self->fn_63_49B8();
                self->timer = params->low + (params->high - params->low) * randf__Fv();
            }
        }
    }
}
