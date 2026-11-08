#pragma force_active on
struct FirstBase { int data; };
class First : public FirstBase {
public:
 virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void stop(int);
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
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
 virtual void fn_85_1A4();
 virtual void fn_85_404();
 virtual void createObjPokeTrainer();
 virtual void fn_85_5420();
 virtual void fn_85_541C();
 virtual void fn_85_5410();
 virtual void fn_85_5408();
 virtual void fn_85_5400();
 virtual void getItemPac();
 virtual void getItemGenPac();
 virtual void getItemPacEnemyFigure();
 virtual void getEnemyPac();
 virtual void getAdvRadarData();
 virtual void initializeStage();
 virtual void closeStage();
 virtual void renderDebugPositions();
 virtual void fn_85_3FC();
 virtual void process();
 virtual void updateStagePositions();
 virtual void debugCollision();
 virtual void fn_85_53F8();
 virtual void fn_85_53F0();
 virtual void getZoneLightSetIndex();
 virtual void fn_85_53D4();
 virtual void clearCameraParam();
 virtual void initCameraParam();
 virtual void startLoadLocalData();
 virtual void isLoadLocalData();
 virtual void entryLocalData();
 virtual void removeLocalData();
 virtual void fn_85_53D0();
 virtual void fn_85_44B4();
 virtual void fn_85_44D8();
 virtual void fn_85_5428();
 virtual void fn_85_44F4();
 virtual void fn_85_5438();
 virtual void fn_85_46B4();
 virtual void fn_85_45CC();
 virtual void getKirifudaPos();
 virtual void getKirifudaAngle();
 virtual void getKirifudaScale();
 virtual void getKirifudaModelType();
 virtual void getPokeTrainerPosCount();
 virtual void getPokeTrainerPos();
 virtual void getFighterDeadEffectSizeRate();
 virtual void getEnemyDeadEffectSizeRate();
 virtual void getEnableZ();
 virtual void fn_85_44AC();
 virtual void fn_85_53C8();
 virtual void fn_85_53C0();
 virtual void fn_85_53B8();
 virtual void fn_85_53B0();
 virtual void fn_85_539C();
 virtual void fn_85_538C();
 virtual void fn_85_5380();
 virtual void fn_85_5374();
 virtual void fn_85_536C();
 virtual void fn_85_5364();
 virtual void fn_85_535C();
 virtual void fn_85_5358();
 virtual void isEnd();
 virtual void isEventEnd();
 virtual void enableDevil();
 virtual void disableDevil();
 virtual void isDevil();
 virtual void setDevilScrool();
 virtual void getLucarioFinalTechniquePosition();
 virtual void startAppear();
 virtual void setAppearKind();
 virtual void endAppear();
 virtual void getAppearTask();
 virtual void forceStopAppear();
 virtual void fn_85_5124();
 virtual void setMotionRatio();
 virtual void saveMotionRatio();
 virtual void restoreMotionRatio();
 virtual void setMotionSubRatio();
 virtual void saveMotionSubRatio();
 virtual void restoreMotionSubRatio();
};
extern "C" void fn_85_4C54(char* self) {
 if (self[0x1e7] & 4) {
  int n = *(int*)(self + 0x2c0);
  char* p = self + 0x4f4;
  for (int i = 0; i < n; i++, p += 0x18) {
   unsigned int type = *(unsigned int*)(p + 4) & 0xF;
   if (type == 1) {
    First* obj = *(First**)(p + 0x10);
    if (obj != 0) obj->stop(1);
   } else if (type == 3) {
    Stage* obj = *(Stage**)(p + 8);
    if (obj != 0) obj->restoreMotionSubRatio();
   }
  }
  self[0x1e7] &= ~4;
 }
}