#pragma force_active on
#include <gr/ground.h>
#include <snd/snd_3d_generator.h>

extern "C" { extern const float lbl_54_rodata_80[]; }

struct Params { char pad[0x48]; float a; float b; char pad50[8]; float c; };
struct Base { char pad[0x3c]; };
struct Obj : Base {
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
 virtual void fn_54_3914();
 virtual void fn_54_3A04();
 virtual void loadGroundData();
 virtual void bindData();
 virtual void setupMelee();
 virtual void setVisibility(unsigned long);
 virtual void setVisibilityByClipping();
 virtual void setVisibilityAttachedEffect();
 virtual void receiveCollMsg();
 virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading();
 virtual void receiveCollMsg_Wall();
 virtual void receiveCollMsg_Attack();
 virtual void unloadData();
 virtual void fn_54_338C();
 virtual void startup();
 virtual void setNode();
 virtual void fn_54_1310();
 virtual Params* fn_54_3150();
 virtual void fn_54_3388();
 virtual void fn_54_2C40();
 virtual void fn_54_3380();
 virtual void fn_54_3374();
 virtual void fn_54_3364();
 virtual void fn_54_3354();
 virtual void getNodeIndex();
 virtual void getNodePosition();
 virtual void getNodePosition_2();
 virtual void getNodeMatrix();
 virtual void getNodeMatrix_2();
 virtual void setNodeVisibility();
 virtual void setNodeVisibility_2();
 virtual void setNodeVisibilityAll();
 virtual void isNodeVisible();
 virtual void setNodeCollision();
 virtual void setNodeCollision_2();
 virtual void getNodeScale();
 virtual void getNodeScale_2();
 virtual void setValid();
 virtual void setValidAttachedEffect();
 virtual void fn_54_3350();
 virtual void fn_54_334C();
 virtual void fn_54_3344();
 virtual void setMotionRatio();
 virtual void setMotionFrame();
 virtual float getMotionFrame(unsigned long);
 virtual void setMotionLoop();
 virtual void setMatAlphaMul();
 virtual void setMatAlpha();
 virtual void updateG3dProcCalcWorld();
 virtual void preExit();
 virtual void fn_54_333C();
 virtual void invalidatedByCameraClipping();
 virtual void setTransparencyFlag();
 virtual void updateCallback();
 virtual void fixedPosition();
 virtual void setTgtNode();
 virtual void getTgtNode();
 virtual void fn_54_33B8();
 virtual void fn_54_33B0();
 virtual void changeNodeAnim();
 virtual void createFadeVisibleProduction();
 virtual void createSoundEffectVisibleProductionForExcel();
 virtual void createEffectVisibleProductionForExcel();
 virtual void setSimpleEffectVisibleProduction();
 virtual void dbDispInvalidatedByCameraClippingSphere();
 virtual void setTransparency();
 virtual void fn_54_33A8();
 virtual void fn_54_4C98();
 virtual void onInflict();
 virtual void onInflictEach();
 virtual void onGimmickEvent();
 virtual void enableYakumono();
 virtual void disableYakumono();
 virtual void enableHit(unsigned long, unsigned long);
 virtual void disableHit(unsigned long, unsigned long);
 virtual void disableAttack();
 virtual void enableArea();
 virtual void disableArea();
 virtual void setSleepArea();
 virtual void setTeamYakumonoOwnerId();
 virtual void setTeamYakumono();
 virtual void getTeamYakumono();
 virtual void setOffsetAttack();
 virtual void setAreaGimmick();
 virtual void setAttackGimmick();
 virtual void setSoCollisionAttackData();
 virtual void setAttackGimmickDetails();
 virtual void isEnableAttackPersonAttacked();
 virtual void isEnableAttackAttribute();
 virtual void fn_54_1654();
 virtual void fn_54_3AE8();
 virtual void fn_54_3EB4();
 virtual void fn_54_3A90();
 virtual void fn_54_43D0();
 virtual void fn_54_3F88(int,int,int,float*);
 char pad40[0x110];
 unsigned char state;
 char pad151[3];
 float timer;
 char pad158[4];
 Vec3f* positions;
 unsigned char* index;
 unsigned char* trigger;
 unsigned char* output;
 float value;
 char pad170[4];
 float end;
 char pad178[0x18];
 snd3DGenerator sound;
};
extern "C" void fn_54_3AE8(Obj* self, float delta) {
 const float* constants = lbl_54_rodata_80;
 Params* param = self->fn_54_3150();
 if (param) {
  self->timer -= delta;
  if (self->timer < constants[1]) self->timer = constants[1];
  self->end -= delta;
  if (self->end < constants[1]) self->end = constants[1];
  switch (self->state) {
  case 0:
   self->fn_54_3F88(1,0,1,0);
   self->setVisibility(0);
   ((Ground*)self)->setEnableCollisionStatus(false);
   self->disableHit(0,0);
   self->disableHit(1,0);
   self->state=1;
   break;
  case 1:
   if (*self->trigger==4) {
    self->timer=param->a;
    self->value=constants[0];
    self->state=12;
   }
   break;
  case 12:
   if (constants[1]==self->timer) {
    self->setVisibility(1);
    ((Ground*)self)->setEnableCollisionStatus(true);
    self->enableHit(0,0);
    self->enableHit(1,0);
    self->timer=param->b;
    self->state=6;
   }
   break;
  case 6:
   self->value += constants[2]*delta;
   if (self->value>=constants[3]) self->value=constants[3];
   if (constants[1]==self->timer) {
    self->fn_54_3F88(1,0,0,0);
    ((Ground*)self)->setEnableCollisionStatus(true);
    self->disableHit(0,0);
    self->disableHit(1,0);
    *self->output=7;
    self->sound.playSE((SndID)0x1bcd,0,0,-1);
    self->sound.setPos(&self->positions[*self->index]);
    self->state=7;
   }
   break;
  case 7:
   if (*self->trigger!=4) {
    self->timer=param->c;
    self->state=8;
   }
   break;
  case 8:
   if (constants[1]==self->timer) {
    self->fn_54_3F88(0,0,1,&self->end);
    ((Ground*)self)->setEnableCollisionStatus(false);
    *self->output=6;
    self->sound.playSE((SndID)0x1bcc,0,0,-1);
    self->sound.setPos(&self->positions[*self->index]);
    self->state=9;
   }
   break;
  case 9:
   if (self->getMotionFrame(0)>=self->end) self->state=0;
   break;
  }
 }
}