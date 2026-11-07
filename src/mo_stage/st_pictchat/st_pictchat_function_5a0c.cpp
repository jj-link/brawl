#pragma force_active on
#include <stdio.h>
#include <string.h>
struct Vec { float x,y,z; };
struct Constants { float x[19]; };
extern "C" const Constants lbl_73_rodata_78;
extern "C" char lbl_73_data_10CC[], lbl_73_data_1190[];
struct Attack {
 char pad[36]; Vec v; int a,b; unsigned upper:27; unsigned flags:5; int c;
 Attack(const Constants* d) { v.x=d->x[4]; v.y=d->x[4]; v.z=d->x[4]; flags=0; }
};
struct Ground_base { char pad[0x3c]; };
#define V(n) virtual void n();
class Ground : public Ground_base {
public:
 V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision) V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug) V(renderDebug) V(init) V(fn_73_551C) V(fn_73_363C) V(loadGroundData) V(bindData) V(setupMelee) V(setVisibility) V(setVisibilityByClipping) V(setVisibilityAttachedEffect) V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack) V(unloadData) V(fn_73_33D0) V(startup) V(fn_73_58DC) V(fn_73_8DC) V(fn_73_33C8) V(fn_73_33C4) V(fn_73_2C5C) V(fn_73_33BC) V(fn_73_33B0) V(fn_73_33A0) V(fn_73_3390) V(getNodeIndex) V(getNodePosition) V(getNodePosition_2) V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2) V(setValid) V(setValidAttachedEffect) V(fn_73_338C) V(fn_73_3388) V(fn_73_3380) V(setMotionRatio) V(setMotionFrame) V(getMotionFrame) V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(fn_73_3378) V(invalidatedByCameraClipping) V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode) V(fn_73_1848) V(fn_73_33F4) V(changeNodeAnim) V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_73_33EC) V(onDamage) V(onInflict) V(onInflictEach) V(onGimmickEvent) V(enableYakumono) V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack) V(enableArea) V(disableArea) V(setSleepArea) V(setTeamYakumoOwnerId) V(setTeamYakumono) V(getTeamYakumono) V(setOffsetAttack) V(setAreaGimmick) V(setAttackGimmick) V(setSoCollisionAttackData)
 virtual void setAttackGimmickDetails(Attack*, int, Vec*, float, int, int, int, int, float, float, float, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int);
 bool getNodeIndex(unsigned long*, unsigned long, const char*);
 char q[0x14c-0x40]; void* module; char r[0x17a-0x150]; char name[0x107]; unsigned char done;
};
#undef V
extern "C" void fn_27_2636F0(void*,int,int,Attack*);
extern "C" void fn_73_5A0C(Ground* o, int i) {
 const Constants* d=&lbl_73_rodata_78;
 if (o->done != 1) {
  Attack a(d); char name[128]; unsigned long idx; Vec p; int angle;
  strcpy(name,lbl_73_data_10CC);
  sprintf(name,lbl_73_data_1190,o->name,i+1);
  if (o->getNodeIndex(&idx,0,name)) {
   switch(i) {
   case 0: angle=0; p.x=d->x[16]; p.y=d->x[0]; p.z=d->x[0]; break;
   case 1: angle=0; p.x=d->x[16]; p.y=d->x[0]; p.z=d->x[0]; break;
   case 2: angle=0; p.x=d->x[16]; p.y=d->x[0]; p.z=d->x[0]; break;
   case 3: angle=180; p.x=d->x[17]; p.y=d->x[0]; p.z=d->x[0]; break;
   case 4: angle=180; p.x=d->x[17]; p.y=d->x[0]; p.z=d->x[0]; break;
   case 5: angle=180; p.x=d->x[17]; p.y=d->x[0]; p.z=d->x[0]; break;
   default: angle=0; p.x=d->x[0]; p.y=d->x[0]; p.z=d->x[0]; break;
   }
   o->setAttackGimmickDetails(&a,20,&p,d->x[18],angle,100,70,70,d->x[4],d->x[4],d->x[4],idx,1023,7,0,15,2,0,3,0,0,0,1,0,0,0,60,0,0,0,3,0,0,0,0,0,0,1);
   fn_27_2636F0(o->module,i,0,&a);
  }
 }
}