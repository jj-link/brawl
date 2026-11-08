#include <sr/sr_common.h>
#include <string.h>
#pragma force_active on
extern "C" {
extern const float lbl_73_rodata_0[];
extern char lbl_73_data_780[];
extern char lbl_73_data_788[];
}
struct Item {
 char pad0[6]; unsigned char f6; char pad7[0x19];
 float f20,f24,f28,f2c;
 unsigned char f30,f31,f32,f33;
 char name[0x28];
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate(); virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision(); virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera(); virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd(); virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init(); virtual void fn_73_1D4(); virtual void fn_73_2C8(); virtual void createObjPokeTrainer(); virtual void fn_73_2B2C(); virtual void fn_73_2B28(); virtual void fn_73_2B1C(); virtual void fn_73_2B14(); virtual void fn_73_2B0C(); virtual void getItemPac(); virtual void getItemGenPac(); virtual void getItemPacEnemyFigure(); virtual void getEnemyPac(); virtual void getAdvRadarData(); virtual void initializeStage(); virtual void closeStage(); virtual void renderDebugPositions(); virtual void fn_73_2C0(); virtual void process(); virtual void updateStagePositions(); virtual void debugCollision(); virtual void fn_73_2B04(); virtual void fn_73_2AFC(); virtual void getZoneLightSetIndex(); virtual void fn_73_2AE0(); virtual void clearCameraParam(); virtual void initCameraParam(); virtual void startLoadLocalData(); virtual void isLoadLocalData(); virtual void entryLocalData(); virtual void removeLocalData(); virtual void fn_73_2ADC(); virtual void getFighterStartPos(); virtual void getFighterReStartPos(); virtual void fn_73_2B34(); virtual void getPokeTrainerStartPos(); virtual void getItemPosCount(); virtual void getItemPos(); virtual void getRandItemPos(); virtual void getKirifudaPos(); virtual void getKirifudaAngle(); virtual void getKirifudaScale(); virtual void getKirifudaModelType(); virtual void getPokeTrainerPosCount(); virtual void getPokeTrainerPos(); virtual void getFighterDeadEffectSizeRate(); virtual void getEnemyDeadEffectSizeRate(); virtual void getEnableZ(); virtual void fn_73_2ACC(); virtual void fn_73_2AD4(); virtual void fn_73_2AC4(); virtual void fn_73_2ABC(); virtual void fn_73_2AB4(); virtual void fn_73_2AA0(); virtual void fn_73_2A90(); virtual void fn_73_2A84(); virtual void fn_73_2A78(); virtual void fn_73_2A70(); virtual void fn_73_2A68(); virtual void fn_73_2A60(); virtual void fn_73_2A5C(); virtual void isEnd(); virtual void isEventEnd(); virtual void enableDevil(); virtual void disableDevil(); virtual void isDevil(); virtual void setDevilScrool(); virtual void getLucarioFinalTechniquePosition(); virtual void startAppear(); virtual void setAppearKind(); virtual void endAppear(); virtual void getAppearTask(); virtual void forceStopAppear(); virtual void getFinalTechniqColor(); virtual void setMotionRatio(); virtual void saveMotionRatio(); virtual void restoreMotionRatio(); virtual void setMotionSubRatio(); virtual void saveMotionSubRatio(); virtual void restoreMotionSubRatio(); virtual void fn_73_2A54(); virtual void fn_73_2A4C(); virtual void fn_73_2A44(); virtual void isAppear(); virtual void isStartAppearTimming(); virtual void getMadeinAiData(); virtual void fn_73_2B44(); virtual void getBamperVector(); virtual void notifyEventInfoReady(); virtual void notifyEventInfoGo(); virtual void getDestroyBossParamCommon(); virtual void stAdventureEventGetItem(); virtual void setStageOutEffectInit(); virtual void setStageInEffectInit(); virtual void fn_73_2A3C(); virtual void fn_73_2A34(); virtual void fn_73_2A30(); virtual void getZoneState(); virtual void getZonePos(); virtual void getMagmaHeight(); virtual void getAcidHeight(); virtual void getIteamDropStatus(); virtual void createWind2ndOnly(); virtual void fn_73_2B3C(); virtual void updateWind2ndOnly(); virtual void setVision(); virtual void fn_73_1C9C(); virtual void setCameraLimitRange(); virtual void resetCameraLimitRange(); virtual void checkChangeScene(); virtual void resetChangeScene(); virtual void setChangeSceneNumber(); virtual void fn_73_7E4(); virtual void fn_73_8F4(); virtual void fn_73_9E0(); virtual void fn_73_B48(); virtual void fn_73_1330(); virtual void fn_73_1594(); virtual void fn_73_16E4(int);
 char pad2[0x3d0-0x40]; Item* items;
};
extern "C" void fn_73_1594(Stage* self) {
 const float* r = lbl_73_rodata_0;
 Item* a = (Item*)operator new[](0xb8, (Heaps::HeapType)0x11);
 self->items = a;
 if (a) {
  memset(a,0,0x5c);
  a->f30=0xe4; a->f31=0xdc; a->f32=0; a->f33=1;
  strcpy(a->name,lbl_73_data_780);
  self->items->f6=0xff;
  a->f20=r[0]; a->f24=r[1]; a->f28=r[2]; a->f2c=r[3];
  self->fn_73_16E4(0x23);
  a=self->items+1;
  memset(a,0,0x5c);
  a->f30=0xe5; a->f31=0xdc; a->f32=0; a->f33=1;
  strcpy(a->name,lbl_73_data_788);
  self->items->f6=0xff;
  a->f20=r[0]; a->f24=r[1]; a->f28=r[2]; a->f2c=r[3];
  self->fn_73_16E4(0x24);
 }
}