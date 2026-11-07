#pragma force_active on
struct Vec { float x,y,z; };
struct Attack { char pad[36]; Vec v; int a,b; unsigned upper:27; unsigned flags:5; int c; };
extern "C" const float lbl_54_rodata_1BC;
extern "C" const float lbl_54_rodata_1C4;
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
#define V(n) virtual void n();
V(processDefault) V(processBegin) V(fn_54_F1F0) V(processUpdate) V(processPreMapCorrection)
V(processMapCorrection) V(processFixPosition) V(processPreCollision) V(processCollision) V(processCatch)
V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc)
V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug)
V(renderDebug) V(init) V(fn_54_F16C) V(fn_54_F244) V(loadGroundData)
V(bindData) V(setupMelee) V(setVisibility) V(setVisibilityByClipping) V(setVisibilityAttachedEffect)
V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack)
V(unloadData) V(fn_54_338C) V(startup) V(fn_54_F890) V(fn_54_1310)
V(fn_54_3150) V(fn_54_3388) V(fn_54_2C40) V(fn_54_3380) V(fn_54_3374)
V(fn_54_3364) V(fn_54_3354) V(getNodeIndex) V(getNodePosition) V(getNodePosition_2)
V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll)
V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2)
V(setValid) V(setValidAttachedEffect) V(fn_54_3350) V(fn_54_334C) V(fn_54_3344)
V(setMotionRatio) V(setMotionFrame) V(getMotionFrame) V(setMotionLoop) V(setMatAlphaMul)
V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(fn_54_333C) V(invalidatedByCameraClipping)
V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode)
V(fn_54_33B8) V(fn_54_33B0) V(changeNodeAnim) V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel)
V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_54_33A8)
V(onDamage) V(onInflict) V(onInflictEach) V(onGimmickEvent) V(enableYakumono)
V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack) V(enableArea)
V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono) V(getTeamYakumono)
V(setOffsetAttack) V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) V(setAttackGimmick) V(setSoCollisionAttackData)
virtual void setAttackGimmickDetails(Attack*, int, Vec*, int,int,int,int, float,float,float,float,
int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
#undef V
char q[0x14c-0x40]; void* module;
};
extern "C" void fn_27_2636F0(void*,int,int,Attack*);
extern "C" void fn_54_FE98(Ground* self, int index, int arg, Vec* pos) {
 Attack a;
 a.v.x=lbl_54_rodata_1BC; a.v.y=lbl_54_rodata_1BC; a.v.z=lbl_54_rodata_1BC;
 a.flags=0;
 self->setAttackGimmickDetails(&a,14,pos,90,50,0,80,lbl_54_rodata_1C4,lbl_54_rodata_1BC,lbl_54_rodata_1BC,lbl_54_rodata_1BC,
 arg,1023,7,0,15,5,2,8,0,0,0,1,0,0,0,60,0,0,0,2,0,0,1,0,0,0,0);
 fn_27_2636F0(self->module,index,0,&a);
}