#include <gr/gr_gimmick.h>

#pragma force_active on

namespace Matching {
struct Ground_base { char pad[0x3C]; };
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
    virtual void fn_52_A408();
    virtual void fn_52_A498();
    virtual void loadGroundData();
    virtual void bindData();
    virtual void setupMelee();
    virtual void setVisibility();
    virtual void setVisibilityByClipping();
    virtual void setVisibilityAttachedEffect();
    virtual void receiveCollMsg();
    virtual void fn_52_B8D8();
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
    virtual void getMotionFrame();
    virtual void setMotionLoop();
    virtual void setMatAlphaMul();
    virtual void setMatAlpha();
    virtual void updateG3dProcCalcWorld();
    virtual void preExit();
    virtual void fn_52_3694();
    virtual void invalidatedByCameraClipping();
    virtual void setTransparencyFlag();
    virtual void updateCallback();
    virtual void fixedPosition();
    virtual void setTgtNode();
    virtual void getTgtNode();
    virtual void fn_52_3718();
    virtual void fn_52_3710();
    virtual void changeNodeAnim();
    virtual void createFadeVisibleProduction();
    virtual void createSoundEffectVisibleProductionForExcel();
    virtual void createEffectVisibleProductionForExcel();
    virtual void setSimpleEffectVisibleProduction();
    virtual void dbDispInvalidatedByCameraClippingSphere();
    virtual void setTransparency();
    virtual void fn_52_3708();
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
    virtual void fn_52_864();
    virtual void fn_52_A24();
    virtual void fn_52_A584(float);
    virtual void fn_52_A5DC(float);
    virtual void fn_52_A6B8(float);
    virtual void fn_52_A70C(float);
    virtual void fn_52_AA98(float);
    virtual void fn_52_ADD4(float);
    virtual void fn_52_AEA8(float);

    unsigned char padding40[0x88];
    unsigned char active;
};
}

extern "C" void fn_52_A498(Matching::Ground* self, float deltaFrame)
{
    reinterpret_cast<grGimmick*>(self)->grGimmick::update(deltaFrame);
    if (self->active) {
        self->fn_52_A584(deltaFrame);
        self->fn_52_A5DC(deltaFrame);
        self->fn_52_A6B8(deltaFrame);
        self->fn_52_A70C(deltaFrame);
        self->fn_52_AA98(deltaFrame);
        self->fn_52_ADD4(deltaFrame);
        self->fn_52_AEA8(deltaFrame);
    }
}
