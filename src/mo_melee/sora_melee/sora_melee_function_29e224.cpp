#include <cm/cm_camera_controller.h>
#pragma force_active on

struct Result { void* a; void* b; int c; int d; };
class Class_CF8 {
public:
 virtual void fn_27_1000C();
 virtual void fn_27_100D0();
 virtual signed char fn_27_100CC();
 virtual int fn_27_10094();
 virtual void fn_27_100C8();
 virtual Result fn_27_100C4();
};
extern "C" char lbl_27_data_1F88[];
struct Args {
 void* vtable;
 void* a;
 int b, c;
 int arg;
 bool error;
 Args(const Result& res, int value) { a = res.b; vtable = lbl_27_data_1F88; b = res.c; c = res.d; if (!b) c = 0; arg = value; error = false; }
};

class soPostureModuleImpl {
public:
 virtual void isNull();
 virtual ~soPostureModuleImpl();
 virtual void fn_27_2362C();
 virtual void fn_27_236B0();
 virtual Vec3f fn_27_25088();
 virtual void fn_27_23E84(const Vec3f&);
};
struct Modules { char pad[12]; soPostureModuleImpl* posture; };
struct Access { char pad[0xd8]; Modules* modules; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base { public:
 virtual void processDefault();
 virtual void processBegin();
 virtual void slot2();
 virtual void slot3();
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
 virtual void slot20();
 virtual void init();
 virtual void slot22();
 virtual void slot23();
 virtual void loadGroundData();
 virtual void slot25();
 virtual void setupMelee();
 virtual void slot27();
 virtual void setVisibilityByClipping();
 virtual void slot29();
 virtual void receiveCollMsg();
 virtual void slot31();
 virtual void receiveCollMsg_Heading();
 virtual void receiveCollMsg_Wall();
 virtual void receiveCollMsg_Attack();
 virtual void unloadData();
 virtual void getModelCount();
 virtual void slot37();
 virtual void slot38();
 virtual void setStageData();
 virtual void getStageData();
 virtual void initStageData();
 virtual void setMdlIndex();
 virtual void getMdlIndex();
 char pad2[0x20]; Access* access;
};
struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base { public:
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
 virtual void destroy();
 virtual void createObj();
 virtual void createObjPokeTrainer();
 virtual void getPokeTrainerPointNum();
 virtual void getPokeTrainerPointData();
 virtual void getPokeTrainerPositionZ();
 virtual void getPokeTrainerDrawLayer();
 virtual void isAdventureStage();
 virtual void getItemPac();
 virtual void getItemGenPac();
 virtual void getItemPacEnemyFigure();
 virtual void getEnemyPac();
 virtual void getAdvRadarData();
 virtual void initializeStage();
 virtual void closeStage();
 virtual void renderDebugPositions();
 virtual void loading();
 virtual void process();
 virtual void updateStagePositions();
 virtual void debugCollision();
 virtual void getAIRange();
 virtual void getDefaultLightSetIndex();
 virtual void getZoneLightSetIndex();
 virtual void getScrollDir();
 virtual void clearCameraParam();
 virtual void initCameraParam();
 virtual void startLoadLocalData();
 virtual void isLoadLocalData();
 virtual void entryLocalData();
 virtual void removeLocalData();
 virtual void appearanceFighterLocal();
 virtual void getFighterStartPos();
 virtual void getFighterReStartPos();
 virtual void isReStartSamePoint();
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
 virtual void getBgmID();
 virtual void getBgmID_2();
 virtual void getNowStepBgmID();
 virtual void getBgmOptionID();
 virtual void isBgmChange();
 virtual void getBgmChangeID();
 virtual void setBgmChange();
 virtual void getBgmVolume();
 virtual void getBgmPlayOffsetFrame();
 virtual void isNextStepBgmEqualNowStepBgmFromFlag();
 virtual void setFrameRuleTime();
 virtual void getFrameRuleTime();
 virtual void notifyTimmingGameStart();
 virtual void isEnd();
 virtual void isEventEnd();
 virtual void enableDevil();
 virtual void disableDevil();
 virtual void isDevil();
 virtual void setDevilScrool(float, float);
};
struct Constants { float one; char pad[0x10]; float zero; char pad2[0xa0]; float scale; };
extern "C" {
extern const Constants lbl_27_rodata_46C8;
extern char lbl_27_data_1F88[];
extern Stage* lbl_27_bss_5668;
int fn_27_737DC(Args*, int);
float fn_27_736B8(Args*, int);
}
extern "C" bool fn_27_29E224(void*, Ground* owner, Class_CF8* cmd, int arg) {
 const Constants* k = &lbl_27_rodata_46C8;
 Args args(cmd->fn_27_100C4(), arg);
 int n = cmd->fn_27_10094();
 switch (cmd->fn_27_100CC()) { case 0x12:
 if (n < 1 || n > 3) return false;
 int enabled = fn_27_737DC(&args, 0);
 float x = n > 1 ? fn_27_736B8(&args, 1) : k->zero;
 float y = n > 2 ? fn_27_736B8(&args, 2) : k->zero;
 if (args.error) return false;
 if (enabled) {
  Vec2f size(k->one, k->one);
  CameraController* camera = CameraController::getInstance();
  if (camera) {
   float* p = (float*)camera->_328;
   size.m_x = k->scale * (p[1] - p[0]);
   size.m_y = k->scale * (p[2] - p[3]);
  }
  x *= size.m_x;
  y *= size.m_y;
  lbl_27_bss_5668->enableDevil();
  lbl_27_bss_5668->setDevilScrool(x,y);
  soPostureModuleImpl* posture = owner->access->modules->posture;
  Vec3f pos = posture->fn_27_25088();
  pos.m_x += x;
  pos.m_y += y;
  posture->fn_27_23E84(pos);
  owner->getMdlIndex();
 } else {
  lbl_27_bss_5668->setDevilScrool(k->zero,k->zero);
  lbl_27_bss_5668->disableDevil();
 }
 return true;
 default: return false;
 }
}