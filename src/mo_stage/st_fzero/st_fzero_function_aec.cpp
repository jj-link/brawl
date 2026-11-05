#pragma force_active on
struct Ground_base { char pad[0x3c]; };
#define D(n) virtual void n();
class Ground : public Ground_base {
public:
 D(processDefault) D(processBegin) D(slot2) D(processUpdate) D(processPreMapCorrection) D(processMapCorrection) D(processFixPosition) D(processPreCollision)
 D(processCollision) D(processCatch) D(processHit) D(processCamera) D(processFixCamera) D(processEffect) D(processGameProc) D(processEnd)
 D(renderPre) D(renderOpa) D(renderXlu) D(processDebug) D(renderDebug) D(init) D(slot22) D(slot23)
 D(loadGroundData) D(bindData) D(setupMelee) D(setVisibility) D(setVisibilityByClipping) D(setVisibilityAttachedEffect) D(receiveCollMsg) D(receiveCollMsg_Landing)
 D(receiveCollMsg_Heading) D(receiveCollMsg_Wall) D(receiveCollMsg_Attack) D(unloadData) D(fn_61_3A50)
 virtual void startup(void*, int, int);
 D(slot38)
 virtual void fn_61_6D8(void*);
 D(fn_61_3504) D(fn_61_3A4C) D(fn_61_2318) D(fn_61_3A44) D(fn_61_3A38) D(fn_61_3A28) D(fn_61_3A18)
 D(getNodeIndex) D(getNodePosition) D(getNodePosition_2) D(getNodeMatrix) D(getNodeMatrix_2) D(setNodeVisibility) D(setNodeVisibility_2)
 D(setNodeVisibilityAll) D(isNodeVisible) D(setNodeCollision) D(setNodeCollision_2) D(getNodeScale) D(getNodeScale_2) D(setValid) D(setValidAttachedEffect)
 D(fn_61_3A14) D(fn_61_3A10) D(fn_61_3A08) D(setMotionRatio) D(slot66) D(slot67) D(setMotionLoop) D(setMatAlphaMul)
 D(setMatAlpha) D(updateG3dProcCalcWorld) D(preExit) D(fn_61_3A00) D(invalidatedByCameraClipping) D(setTransparencyFlag) D(updateCallback) D(fixedPosition)
 D(setTgtNode) D(getTgtNode) D(fn_61_3A7C) D(fn_61_3A74) D(changeNodeAnim) D(createFadeVisibleProduction) D(createSoundEffectVisibleProductionForExcel) D(createEffectVisibleProductionForExcel)
 D(setSimpleEffectVisibleProduction) D(dbDispInvalidatedByCameraClippingSphere) D(setTransparency) D(fn_61_3A6C) D(onDamage) D(onInflict) D(onInflictEach) D(onGimmickEvent)
 D(enableYakumono) D(disableYakumono) D(enableHit) D(disableHit) D(disableAttack) D(enableArea) D(disableArea) D(setSleepArea)
 D(setTeamYakumonoOwnerId) D(setTeamYakumono) D(getTeamYakumono) D(setOffsetAttack) D(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) D(setAttackGimmick) D(setSoCollisionAttackData) D(setAttackGimmickDetails)
 D(isEnableAttackPersonAttacked) D(isEnableAttackAttribute) D(slot112) D(slot113)
 virtual void slot114(void*);
 virtual void slot115(void*);
 virtual void slot116(void*);
 virtual void slot117(void*);
};
#undef D
struct Stage {
 char pad0[0x9c];
 void* unk9C;
 char padA0[0x100];
 void* unk1A0;
 char pad1A4[0x3c];
 char unk1E0[2];
 char unk1E2[2];
 char unk1E4[0x9fc];
 char unkBE0[1];
};
extern "C" {
extern char lbl_61_data_17C[];
extern char lbl_61_data_188[];
Ground* fn_61_CAF0(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void createCollision__5StageFP9gfArchiveiP6Ground(Stage*, void*, int, Ground*);
void fn_61_AEC(Stage* stage, int kind) {
 Ground* ground;
 switch (kind) {
 case 9:
  ground = fn_61_CAF0(0x5a, lbl_61_data_17C, lbl_61_data_188);
  break;
 default:
  ground = 0;
  break;
 }
 if (ground) {
  addGround__5StageFP6Ground(stage, ground);
  ground->startup(stage->unk1A0, 0, 0);
  ground->fn_61_6D8(stage->unk9C);
  ground->slot114(stage->unk1E0);
  ground->slot115(stage->unk1E2);
  ground->slot116(stage->unkBE0);
  ground->slot117(stage->unk1E4);
  createCollision__5StageFP9gfArchiveiP6Ground(stage, stage->unk1A0, 0x5a, ground);
 }
}
}