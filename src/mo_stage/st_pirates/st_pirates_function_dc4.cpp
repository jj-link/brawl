#include <st/stage.h>
#include <gr/ground.h>
#pragma force_active on

#define V(name) virtual void name();
struct PiratesGroundBase { char pad[0x3c]; };
class PiratesGround : public PiratesGroundBase {
public:
    V(processDefault) V(processBegin) V(slot2) V(processUpdate)
    V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision)
    V(processCollision) V(processCatch) V(processHit) V(processCamera)
    V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd)
    V(renderPre) V(renderOpa) V(renderXlu) V(processDebug) V(renderDebug) V(init)
    V(slot22) V(slot23) V(loadGroundData) V(bindData) V(setupMelee)
    V(setVisibility) V(setVisibilityByClipping) V(setVisibilityAttachedEffect)
    V(receiveCollMsg) V(slot31) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall)
    V(receiveCollMsg_Attack) V(unloadData) V(fn_52_36EC)
    virtual void startup(gfArchive*, int, int);
    V(setNode)
    virtual void fn_52_83C(void*);
    V(fn_52_36E4) V(fn_52_36E0) V(fn_52_35C8) V(fn_52_36D8)
    V(fn_52_36CC) V(fn_52_36BC) V(fn_52_36AC)
    V(getNodeIndex) V(getNodePosition) V(getNodePosition_2) V(getNodeMatrix)
    V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll)
    V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale)
    V(getNodeScale_2) V(setValid) V(setValidAttachedEffect) V(fn_52_36A8)
    V(fn_52_36A4) V(fn_52_369C) V(setMotionRatio) V(setMotionFrame)
    V(getMotionFrame) V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha)
    V(updateG3dProcCalcWorld) V(preExit) V(fn_52_3694) V(invalidatedByCameraClipping)
    V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode)
    V(getTgtNode) V(fn_52_3718) V(fn_52_3710) V(changeNodeAnim)
    V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel)
    V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction)
    V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_52_3708)
    V(onDamage) V(onInflict) V(onInflictEach) V(onGimmickEvent) V(enableYakumono)
    V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack) V(enableArea)
    V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono)
    V(getTeamYakumono) V(setOffsetAttack)
    V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab)
    V(setAttackGimmick) V(setSoCollisionAttackData) V(setAttackGimmickDetails)
    V(isEnableAttackPersonAttacked) V(isEnableAttackAttribute)
    V(slot112) V(fn_52_A24) V(slot114) V(slot115) V(slot116) V(slot117)
    V(slot118) V(slot119) V(slot120) V(slot121) V(slot122) V(slot123)
    virtual void slot124(void*);
    virtual void slot125(void*);
};
#undef V

extern "C" {
extern const char lbl_52_data_108[];
extern const char lbl_52_data_118[];
PiratesGround* fn_52_A27C(int, const char*, const char*);

void fn_52_DC4(Stage* self) {
    PiratesGround* ground = fn_52_A27C(13, lbl_52_data_108, lbl_52_data_118);
    if (ground) {
        self->addGround((Ground*)ground);
        ground->startup(*(gfArchive**)((char*)self + 0x1a0), 0, 0);
        ground->fn_52_83C(*(void**)((char*)self + 0x9c));
        ground->slot124((char*)self + 0x334);
        ground->slot125((char*)self + 0x568);
        self->createCollision(*(gfArchive**)((char*)self + 0x1a0), 5, (Ground*)ground);
    }
}
}