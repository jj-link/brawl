#include <mt/mt_prng.h>
#pragma force_active on
extern "C" const float lbl_74_rodata_0;
struct Params { char pad[0x4c]; float value; char pad50[8]; float initial; char pad5c[4]; float delay, chance; char pad68[4]; unsigned char min, max; };
struct Pattern { unsigned short times[8]; float delay; };
struct Data { char pad[4]; unsigned int count; };
class Class_1E10 {
public:
 virtual void fn_74_9ADC();
 virtual void fn_74_8FA4();
 virtual void fn_74_8FB4();
 virtual Pattern* fn_74_6B18(unsigned char);
 char pad[4];
 Data* data;
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
 virtual void fn_74_3B4();
 virtual void fn_74_A6C();
 virtual void createObjPokeTrainer();
 virtual void fn_74_2508();
 virtual void fn_74_2504();
 virtual void fn_74_24F8();
 virtual void fn_74_24F0();
 virtual void fn_74_24E8();
 virtual void getItemPac();
 virtual void getItemGenPac();
 virtual void getItemPacEnemyFigure();
 virtual void getEnemyPac();
 virtual void getAdvRadarData();
 virtual void initializeStage();
 virtual void closeStage();
 virtual void renderDebugPositions();
 virtual void fn_74_A64();
 virtual void process();
 virtual void updateStagePositions();
 virtual void debugCollision();
 virtual void fn_74_24E0();
 virtual void fn_74_24D8();
 virtual void getZoneLightSetIndex();
 virtual void fn_74_24BC();
 virtual void clearCameraParam();
 virtual void initCameraParam();
 virtual void startLoadLocalData();
 virtual void isLoadLocalData();
 virtual void entryLocalData();
 virtual void removeLocalData();
 virtual void fn_74_24B8();
 virtual void getFighterStartPos();
 virtual void getFighterReStartPos();
 virtual void fn_74_2510();
 virtual void getPokeTrainerStartPos();
 virtual void getItemPosCount();
 virtual void getItemPos();
 virtual void getRandItemPos();
 virtual void getKirifudaPos();
 virtual void getKirifudaAngle();
 virtual void getKirifudaScale();
 virtual void getKirifudaModelType();
 virtual void getPokeTrainerPosCount();
 virtual void getPokeTrainerPos();
 virtual void getFighterDeadEffectSizeRate();
 virtual void getEnemyDeadEffectSizeRate();
 virtual void getEnableZ();
 virtual void fn_74_24A8();
 virtual void fn_74_24B0();
 virtual void fn_74_24A0();
 virtual void fn_74_2498();
 virtual void fn_74_2490();
 virtual void fn_74_247C();
 virtual void fn_74_246C();
 virtual void fn_74_2460();
 virtual void fn_74_2454();
 virtual void fn_74_244C();
 virtual void fn_74_2444();
 virtual void fn_74_243C();
 virtual void fn_74_2438();
 virtual void isEnd();
 virtual void fn_74_2320();
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
 virtual void fn_74_2528();
 virtual void setMotionRatio();
 virtual void saveMotionRatio();
 virtual void restoreMotionRatio();
 virtual void setMotionSubRatio();
 virtual void saveMotionSubRatio();
 virtual void restoreMotionSubRatio();
 virtual void fn_74_2430();
 virtual void fn_74_2428();
 virtual void fn_74_2420();
 virtual void isAppear();
 virtual void isStartAppearTimming();
 virtual void getMadeinAiData();
 virtual void fn_74_2520();
 virtual void getBamperVector();
 virtual void fn_74_1E14();
 virtual void fn_74_1E18();
 virtual void getDestroyBossParamCommon();
 virtual void stAdventureEventGetItem();
 virtual void setStageOutEffectInit();
 virtual void setStageInEffectInit();
 virtual void fn_74_2418();
 virtual void fn_74_2410();
 virtual void fn_74_240C();
 virtual void getZoneState();
 virtual void getZonePos();
 virtual void getMagmaHeight();
 virtual void getAcidHeight();
 virtual void getIteamDropStatus();
 virtual void createWind2ndOnly();
 virtual void fn_74_2518();
 virtual void updateWind2ndOnly();
 virtual void setVision();
 virtual void fn_74_15D8();
 virtual void setCameraLimitRange();
 virtual void resetCameraLimitRange();
 virtual void checkChangeScene();
 virtual void resetChangeScene();
 virtual void setChangeSceneNumber();
 virtual void fn_74_E08();
 virtual void fn_74_F1C();
 virtual void fn_74_FD4();
 virtual void fn_74_1318();
 virtual void fn_74_13F0();
 virtual void fn_74_1500();
 virtual void fn_74_15D4();
 virtual void fn_74_170C();
 virtual void fn_74_1754();
 virtual void fn_74_17DC();
 virtual void fn_74_1B20();
 virtual void fn_74_1BC8();
 virtual void fn_74_1C64();
 virtual void fn_74_1E24();
 virtual void fn_74_1EA4(float);
 char pad40[0x9c-0x40];
 Params* params;
 char pada0[0x1e2-0xa0];
 unsigned char state;
 char pad1e3;
 float timer, timer2;
 char pad1ec[0xe94-0x1ec];
 Class_1E10* patterns;
 unsigned char index, repeats, step;
};
extern "C" void fn_74_17DC(Stage* self, float delta) {
 Params* p = self->params;
 if (p) {
  self->timer2 -= delta;
  if (self->timer2 < lbl_74_rodata_0) self->timer2 = lbl_74_rodata_0;
  switch (self->state) {
  case 0:
   self->timer2 = p->initial;
   self->timer = p->delay;
   self->state = 1;
  case 1:
   self->timer -= delta;
   if (self->timer < lbl_74_rodata_0) self->timer = lbl_74_rodata_0;
   if (lbl_74_rodata_0 == self->timer && randf() < p->chance) {
    unsigned int count = self->patterns->data->count;
    self->index = (int)(count * randf());
    if (!self->patterns->fn_74_6B18(self->index)) {
     self->timer = p->delay;
     return;
    }
    unsigned char min = p->min;
    float r = randf();
    float range = p->max - min;
    float value = range * r;
    self->step = 0;
    self->state = 3;
    self->repeats = (int)(min + value);
    return;
   }
   if (lbl_74_rodata_0 == self->timer2) {
    self->fn_74_1EA4(p->value);
    self->timer2 = p->initial;
    return;
   }
   break;
  case 3: {
   Pattern* pattern = self->patterns->fn_74_6B18(self->index);
   self->timer += delta;
   if (self->timer >= pattern->times[self->step]) {
    self->fn_74_1EA4(p->value);
    unsigned int done = 0;
    ++self->step;
    if (self->step != 0 && pattern->times[self->step] == 0) done = 1;
    if (self->step == 8) done = 1;
    if (done == 1) {
     self->timer = pattern->delay;
     self->state = 4;
     return;
    }
   }
   break;
  }
  case 4:
   self->timer -= delta;
   if (self->timer < lbl_74_rodata_0) self->timer = lbl_74_rodata_0;
   if (lbl_74_rodata_0 == self->timer) {
    if (self->repeats == 0) {
     self->timer = p->delay;
     self->state = 1;
     return;
    }
    --self->repeats;
    self->step = 0;
    self->state = 3;
   }
   break;
  }
 }
}