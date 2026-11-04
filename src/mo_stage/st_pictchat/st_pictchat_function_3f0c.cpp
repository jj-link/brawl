#pragma force_active on
class Class_3E50 {
public:
 virtual void fn_73_C58C();
 virtual void fn_73_B9AC();
 virtual void fn_73_B9BC();
 virtual float* fn_73_A9C8(int);
};
struct Entry { char pad[0x54]; unsigned char a:1, b:1, c:1, d:1, e:4; };
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
 virtual void fn_73_1D4();
 virtual void fn_73_2C8();
 virtual void createObjPokeTrainer();
 virtual void fn_73_2B2C();
 virtual void fn_73_2B28();
 virtual void fn_73_2B1C();
 virtual void fn_73_2B14();
 virtual void fn_73_2B0C();
 virtual void getItemPac();
 virtual void getItemGenPac();
 virtual void getItemPacEnemyFigure();
 virtual void getEnemyPac();
 virtual void getAdvRadarData();
 virtual void initializeStage();
 virtual void closeStage();
 virtual void renderDebugPositions();
 virtual void fn_73_2C0();
 virtual void process();
 virtual void updateStagePositions();
 virtual void debugCollision();
 virtual void fn_73_2B04();
 virtual void fn_73_2AFC();
 virtual void getZoneLightSetIndex();
 virtual void fn_73_2AE0();
 virtual void clearCameraParam();
 virtual void initCameraParam();
 virtual void startLoadLocalData();
 virtual void isLoadLocalData();
 virtual void entryLocalData();
 virtual void removeLocalData();
 virtual void fn_73_2ADC();
 virtual void getFighterStartPos();
 virtual void getFighterReStartPos();
 virtual void fn_73_2B34();
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
 virtual float getEnemyDeadEffectSizeRate(int);
 char pad2[0x110];
 unsigned char state;
 char pad3[0x1f];
 Class_3E50* data;
 Entry** entries;
 unsigned char count;
 unsigned char index;
};
extern "C" void fn_73_3F0C(Stage* self) {
 if (self->entries && self->data) {
  switch (self->state) { case 2: break; default: return; }
  float* values = self->data->fn_73_A9C8(0);
  if (values) {
   unsigned int i = self->index;
   unsigned int count = self->count;
   for (; i != count; ++i) {
    if (!(values[i+1] < self->getEnemyDeadEffectSizeRate(0))) return;
    Entry* entry = self->entries[i];
    entry->d = 1;
    entry->b = entry->d;
    self->index++;
   }
  }
 }
}