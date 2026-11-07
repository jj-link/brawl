#pragma force_active on
typedef unsigned char u8;
struct Vec { float x,y,z; };
struct Attack { char pad[36]; Vec v; int a,b; unsigned upper:27; unsigned flags:5; int c; };
struct Constants { float f[19]; };
extern "C" const Constants lbl_61_rodata_168;
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
#define V(n) virtual void n();
V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection)
V(processMapCorrection) V(processFixPosition) V(processPreCollision) V(processCollision) V(processCatch)
V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc)
V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug)
V(renderDebug) V(init) V(fn_61_248) V(fn_61_2C8) V(createObjPokeTrainer)
V(fn_61_21E4) V(fn_61_21E0) V(fn_61_21D4) V(fn_61_21CC) V(fn_61_21C4)
V(getItemPac) V(getItemGenPac) V(getItemPacEnemyFigure) V(getEnemyPac) V(getAdvRadarData)
V(initializeStage) V(closeStage) V(renderDebugPositions) V(fn_61_2C0) V(process)
V(updateStagePositions) V(debugCollision) V(fn_61_21BC) V(fn_61_21B4) V(getZoneLightSetIndex)
V(fn_61_2198) V(clearCameraParam) V(initCameraParam) V(startLoadLocalData) V(isLoadLocalData)
V(entryLocalData) V(removeLocalData) V(fn_61_2194) V(getFighterStartPos) V(getFighterReStartPos)
V(fn_61_21EC) V(getPokeTrainerStartPos) V(getItemPosCount) V(getItemPos) V(getRandItemPos)
V(getKirifudaPos) V(getKirifudaAngle) V(getKirifudaScale) V(getKirifudaModelType) V(getPokeTrainerPosCount)
V(getPokeTrainerPos) V(getFighterDeadEffectSizeRate) V(getEnemyDeadEffectSizeRate) V(getEnableZ) V(fn_61_2184)
V(fn_61_218C) V(fn_61_217C) V(fn_61_2174) V(fn_61_216C) V(fn_61_2158)
V(fn_61_2148) V(fn_61_213C) V(fn_61_2130) V(fn_61_2128) V(fn_61_2120)
V(fn_61_2118) V(fn_61_2114) V(isEnd) V(fn_61_2070) V(enableDevil)
V(disableDevil) V(isDevil) V(setDevilScrool) V(getLucarioFinalTechniquePosition) V(startAppear)
V(setAppearKind) V(endAppear) V(getAppearTask) V(forceStopAppear) V(fn_61_21FC)
V(setMotionRatio) V(saveMotionRatio) V(restoreMotionRatio) V(setMotionSubRatio) V(saveMotionSubRatio)
V(restoreMotionSubRatio) V(fn_61_210C) V(fn_61_2104) V(fn_61_20FC) V(isAppear)
V(isStartAppearTimming) V(getMadeinAiData) V(isBamperVector) V(getBamperVector)
virtual void notifyEventInfoReady(Attack*,int,Vec*,int,int,int,int,float,float,float,float,
int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
#undef V
};
extern "C" void fn_27_2636F0(void*,int,int,Attack*);
extern "C" void fn_61_E310(u8* self) {
 const Constants* d=&lbl_61_rodata_168;
 if(self[0x18a]!=1) {
  Attack a; Vec p;
  a.v.x=d->f[1]; a.v.y=d->f[1]; a.v.z=d->f[1];
  a.flags=0;
  p.x=d->f[8]; p.y=d->f[0]; p.z=d->f[0];
  ((Stage*)self)->notifyEventInfoReady(&a,15,&p,90,50,100,80,d->f[18],d->f[1],d->f[1],d->f[1],
  0,1023,7,0,15,0,2,2,0,0,0,0,0,0,0,60,0,0,0,0,0,0,0,0,0,0,1);
  fn_27_2636F0(*(void**)(self+0x14c),0,0,&a);
  self[0x18a]=1;
 }
}