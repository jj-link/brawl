#pragma force_active on
extern "C" const float lbl_79_rodata_50;
struct State { char pad[4]; float value; char pad8[0x11]; unsigned char mode; };
struct Params { char pad[4]; float value; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
#define V(n) virtual void n();
V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision)
V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd)
V(renderPre) V(renderOpa) V(renderXlu) V(processDebug) V(renderDebug) V(init) V(fn_79_A7C0) V(fn_79_A818)
V(loadGroundData) V(bindData) V(setupMelee)
virtual void setVisibility(unsigned long);
V(setVisibilityByClipping) V(setVisibilityAttachedEffect) V(receiveCollMsg) V(receiveCollMsg_Landing) V(fn_79_AC3C) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack) V(unloadData)
V(fn_79_1B64) V(startup) V(setNode) V(fn_79_624) V(fn_79_1B5C) V(fn_79_1B58) V(fn_79_1A5C) V(fn_79_1B50)
V(fn_79_1B44) V(fn_79_1B34) V(fn_79_1B24) V(getNodeIndex) V(getNodePosition) V(getNodePosition_2) V(getNodeMatrix) V(getNodeMatrix_2)
V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2)
V(setValid) V(setValidAttachedEffect) V(fn_79_1B20) V(fn_79_1B1C) V(fn_79_1B14) V(setMotionRatio) V(setMotionFrame) V(getMotionFrame)
V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(fn_79_1B0C) V(invalidatedByCameraClipping) V(setTransparencyFlag)
V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode) V(fn_79_1B90) V(fn_79_1B88) V(changeNodeAnim) V(createFadeVisibleProduction)
V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_79_1B80) V(onDamage) V(onInflict)
V(onInflictEach) V(onGimmickEvent) V(enableYakumono) V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack) V(enableArea)
V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono) V(getTeamYakumono) V(setOffsetAttack) V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) V(setAttackGimmick)
V(setSoCollisionAttackData) V(setAttackGimmickDetails) V(isEnableAttackPersonAttacked) V(isEnableAttackAttribute) V(fn_79_A8A4)
virtual void fn_79_AA08(float);
#undef V
void setEnableCollisionStatus(bool);
char pad1[0x2c];
unsigned char enabled : 1;
unsigned char flags : 7;
char pad2[0xe3];
unsigned char phase;
char pad3[3];
float timer;
float value;
Params* params;
State* state;
};
extern "C" void fn_79_A8A4(Ground* self, float delta) {
 self->timer -= delta;
 if (self->timer < lbl_79_rodata_50) self->timer = lbl_79_rodata_50;
 switch (self->phase) {
 case 0:
  self->setVisibility(0);
  self->setEnableCollisionStatus(false);
  self->phase = 1;
  self->value = lbl_79_rodata_50;
  break;
 case 1:
  switch (self->state->mode) {
  case 0: self->state->value = self->params->value;
  case 1: self->phase = 2; break;
  }
  break;
 case 2:
  if (!self->enabled) {
   self->setVisibility(1);
   self->setEnableCollisionStatus(true);
  }
  if (self->state->mode == 4) {
   self->state->mode = 5;
   self->phase = 0;
  } else self->fn_79_AA08(delta);
  break;
 }
}