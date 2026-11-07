#pragma force_active on
#define D(n) virtual void n();
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
D(processDefault) D(processBegin) D(slot2) D(processUpdate) D(processPreMapCorrection) D(processMapCorrection) D(processFixPosition) D(processPreCollision)
D(processCollision) D(processCatch) D(processHit) D(processCamera) D(processFixCamera) D(processEffect) D(processGameProc) D(processEnd)
D(renderPre) D(renderOpa) D(renderXlu) D(processDebug) D(renderDebug) D(init) D(slot22) D(slot23)
D(loadGroundData) D(bindData) D(setupMelee) D(setVisibility) D(setVisibilityByClipping) D(setVisibilityAttachedEffect) D(receiveCollMsg) D(slot31)
D(receiveCollMsg_Heading) D(receiveCollMsg_Wall) D(receiveCollMsg_Attack) D(unloadData) D(fn_52_36EC)
virtual void startup(void*, int, int);
D(setNode)
virtual void fn_52_83C(void*);
D(fn_52_36E4) D(fn_52_36E0) D(fn_52_35C8) D(fn_52_36D8) D(fn_52_36CC) D(fn_52_36BC) D(fn_52_36AC)
D(getNodeIndex) D(getNodePosition) D(getNodePosition_2) D(getNodeMatrix) D(getNodeMatrix_2) D(setNodeVisibility) D(setNodeVisibility_2) D(setNodeVisibilityAll)
D(isNodeVisible) D(setNodeCollision) D(setNodeCollision_2) D(getNodeScale) D(getNodeScale_2) D(setValid) D(setValidAttachedEffect) D(fn_52_36A8)
D(fn_52_36A4) D(fn_52_369C) D(setMotionRatio) D(setMotionFrame) D(getMotionFrame) D(setMotionLoop) D(setMatAlphaMul) D(setMatAlpha)
D(updateG3dProcCalcWorld) D(preExit) D(fn_52_3694) D(invalidatedByCameraClipping) D(setTransparencyFlag) D(updateCallback) D(fixedPosition) D(setTgtNode)
D(getTgtNode) D(fn_52_3718) D(fn_52_3710) D(changeNodeAnim) D(createFadeVisibleProduction) D(createSoundEffectVisibleProductionForExcel) D(createEffectVisibleProductionForExcel) D(setSimpleEffectVisibleProduction)
D(dbDispInvalidatedByCameraClippingSphere) D(setTransparency) D(fn_52_3708) D(onDamage) D(onInflict) D(onInflictEach) D(onGimmickEvent) D(enableYakumono)
D(disableYakumono) D(enableHit) D(disableHit) D(disableAttack) D(enableArea) D(disableArea) D(setSleepArea) D(setTeamYakumonoOwnerId)
D(setTeamYakumono) D(getTeamYakumono) D(setOffsetAttack) D(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) D(setAttackGimmick) D(setSoCollisionAttackData) D(setAttackGimmickDetails) D(isEnableAttackPersonAttacked)
D(isEnableAttackAttribute) D(slot112) D(fn_52_A24) D(slot114) D(slot115) D(slot116) D(slot117) D(slot118) D(slot119)
virtual void slot120(void*);
virtual void slot121(void*);
virtual void slot122(void*);
virtual void slot123(void*);
virtual void slot124(void*);
virtual void slot125(void*);
};
#undef D
struct Stage {
char pad0[0x9c]; void* at9c; char padA0[0x100]; void* at1a0; char pad1a4[0x40]; char at1e4[0x384]; char at568[7]; char at56f[1]; char at570[0x64]; char at5d4[1];
};
extern "C" {
extern const char lbl_52_data_2A8[];
extern const char lbl_52_data_2B8[];
Ground* fn_52_D7D4(int, const char*, const char*);
void addGround__5StageFP6Ground(Stage*, Ground*);
void fn_52_15B8(Stage* self) {
Ground* ground = fn_52_D7D4(2, lbl_52_data_2A8, lbl_52_data_2B8);
if (ground) {
addGround__5StageFP6Ground(self, ground);
ground->startup(self->at1a0, 0, 0);
ground->fn_52_83C(self->at9c);
ground->slot120(self->at1e4);
ground->slot121(self->at1e4);
ground->slot122(self->at570);
ground->slot123(self->at568);
ground->slot124(self->at56f);
ground->slot125(self->at5d4);
}
}
}