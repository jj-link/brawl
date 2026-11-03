#pragma force_active on
struct Vec { float x,y,z; };
struct Constants { float x[43]; };
extern "C" const Constants lbl_49_rodata_58;
struct Attack {
 char pad[36]; Vec v; int a,b; unsigned upper:27; unsigned flags:5; int c;
 Attack(const Constants* d) { v.x=d->x[14]; v.y=d->x[14]; v.z=d->x[14]; flags=0; }
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
#define V(n) virtual void n();
 V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection)
 V(processMapCorrection) V(processFixPosition) V(processPreCollision) V(processCollision) V(processCatch)
 V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc)
 V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug)
 V(fn_49_E58) V(init) V(fn_49_12C) V(fn_49_1A0) V(createObjPokeTrainer)
 V(fn_49_11A0) V(fn_49_119C) V(fn_49_1190) V(fn_49_1188) V(fn_49_1180)
 V(getItemPac) V(getItemGenPac) V(getItemPacEnemyFigure) V(getEnemyPac) V(getAdvRadarData)
 V(initializeStage) V(closeStage) V(renderDebugPositions) V(fn_49_198) V(process)
 V(updateStagePositions) V(debugCollision) V(fn_49_1178) V(fn_49_1170) V(fn_49_E5C)
 V(fn_49_1154) V(clearCameraParam) V(initCameraParam) V(startLoadLocalData) V(isLoadLocalData)
 V(entryLocalData) V(removeLocalData) V(fn_49_1150) V(getFighterStartPos) V(getFighterReStartPos)
 V(fn_49_11A8) V(getPokeTrainerStartPos) V(getItemPosCount) V(getItemPos) V(getRandItemPos)
 V(getKirifudaPos) V(getKirifudaAngle) V(getKirifudaScale) V(getKirifudaModelType) V(getPokeTrainerPosCount)
 V(getPokeTrainerPos) V(getFighterDeadEffectSizeRate) V(getEnemyDeadEffectSizeRate) V(getEnableZ) V(fn_49_1140)
 V(fn_49_1148) V(fn_49_1138) V(fn_49_1130) V(fn_49_1128) V(fn_49_1114)
 V(fn_49_1104) V(fn_49_10F8) V(fn_49_10EC) V(fn_49_10E4) V(fn_49_10DC)
 V(fn_49_10D4) V(fn_49_10D0) V(isEnd) V(isEventEnd) V(enableDevil)
 V(disableDevil) V(isDevil) V(setDevilScrool) V(getLucarioFinalTechniquePosition) V(startAppear)
 V(setAppearKind) V(endAppear) V(getAppearTask) V(forceStopAppear) V(getFinalTechniqColor)
 V(setMotionRatio)
 virtual void saveMotionRatio(int, int);
 V(restoreMotionRatio) V(setMotionSubRatio) V(saveMotionSubRatio) V(restoreMotionSubRatio)
 V(fn_49_10C8) V(fn_49_10C0) V(fn_49_10B8) V(isAppear) V(isStartAppearTimming)
 V(getMadeinAiData) V(fn_49_11B8) V(getBamperVector)
 virtual void notifyEventInfoReady(Attack*, int, Vec*, int, int, int, int,
 float,float,float,float,
 int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int,int);
#undef V
 char q[0x14c-0x40]; void* module; char s[0x15d-0x150]; unsigned char state;
};
extern "C" void fn_27_2636F0(void*,int,int,Attack*);
extern "C" void fn_49_4FA0(Stage* o) {
 const Constants* d=&lbl_49_rodata_58;
 if(o->state!=1) {
  o->saveMotionRatio(0,0);
  Attack a(d);
  Vec p;
  p.x=d->x[0]; p.y=d->x[0]; p.z=d->x[0];
  o->notifyEventInfoReady(&a,15,&p,90,55,0,80,d->x[42],d->x[14],d->x[14],d->x[14],
  0,1023,7,0,15,0,2,1,0,0,0,1,0,0,0,60,0,0,0,0,0,0,0,0,0,0,0);
  fn_27_2636F0(o->module,0,0,&a);
  o->state=1;
 }
}