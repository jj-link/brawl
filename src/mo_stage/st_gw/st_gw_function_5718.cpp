#include <mt/mt_vector.h>
#include <st/se_util.h>
#pragma force_active on
struct Params { char pad[0x14]; float value; };
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug(); virtual void renderDebug(); virtual void init();
 virtual void fn_63_56AC(); virtual void fn_63_5718(); virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee();
 virtual void setVisibility(unsigned long); virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect();
 virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing(); virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack();
 virtual void unloadData(); virtual void fn_63_3378(); virtual void startup(); virtual void setNode(); virtual void fn_63_59C();
 virtual Params* fn_63_3370(); virtual void fn_63_336C(); virtual void fn_63_2B64(); virtual void fn_63_3364(); virtual void fn_63_3358(); virtual void fn_63_3348(); virtual void fn_63_3338();
 virtual void getNodeIndex(); virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_63_3334(); virtual void fn_63_3330(); virtual void fn_63_3328();
 virtual void setMotionRatio(); virtual void setMotionFrame(float, unsigned long); virtual float getMotionFrame(unsigned long);
 virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld(); virtual void preExit();
 virtual void fn_63_3320(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag(); virtual void updateCallback(); virtual void fixedPosition();
 virtual void setTgtNode(); virtual void getTgtNode(); virtual void fn_63_1884(); virtual void fn_63_339C(); virtual void changeNodeAnim();
 virtual void createFadeVisibleProduction(); virtual void createSoundEffectVisibleProductionForExcel(); virtual void createEffectVisibleProductionForExcel();
 virtual void setSimpleEffectVisibleProduction(); virtual void dbDispInvalidatedByCameraClippingSphere(); virtual void setTransparency();
 virtual void fn_63_3394(); virtual void onDamage(); virtual void onInflict(); virtual void onInflictEach(); virtual void onGimmickEvent();
 virtual void enableYakumono(); virtual void disableYakumono(); virtual void enableHit(); virtual void disableHit(); virtual void disableAttack();
 virtual void enableArea(); virtual void disableArea(); virtual void setSleepArea(); virtual void setTeamYakumonoOwnerId(); virtual void setTeamYakumono();
 virtual void getTeamYakumono(); virtual void setOffsetAttack(); virtual void setAreaGimmick();
 virtual void setAttackGimmick(); virtual void setSoCollisionAttackData(); virtual void setAttackGimmickDetails(); virtual void isEnableAttackPersonAttacked();
 virtual void isEnableAttackAttribute(); virtual void fn_63_2D00(); virtual void fn_63_2E10(); virtual void fn_63_59A4(int,int,int,float*);
 virtual void fn_63_8FC(); virtual void fn_63_904(); virtual float fn_63_5D78();
 char pad40[0x24]; float speed; char pad68[0xe8]; unsigned char state; char pad151[3]; float timer;
 unsigned char* trigger; unsigned char triggerValue; char pad15d[7]; float endFrame; char pad168[0xc]; float* value; char seq[0x20];
};
extern "C" {
void fn_63_2C98(Ground*, float);
extern const float lbl_63_rodata_80;
extern const float lbl_63_rodata_84;
void fn_63_5718(Ground* self, float delta) {
 fn_63_2C98(self, delta);
 Params* params = self->fn_63_3370();
 if (params) {
  self->timer -= delta;
  if (self->timer < lbl_63_rodata_80) self->timer = lbl_63_rodata_80;
  switch (self->state) {
  case 0:
   self->fn_63_59A4(1,0,1,&self->endFrame);
   self->setMotionFrame(self->endFrame,0);
   self->setVisibility(0);
   self->state = 1;
   break;
  case 1:
   if (*self->trigger == self->triggerValue) self->state = 2;
   break;
  case 2:
   if (*self->trigger != self->triggerValue) self->state = 0;
   if (*self->value < params->value) {
    self->fn_63_59A4(0,1,0,&self->endFrame);
    self->setVisibility(1);
    ((StSeUtil::SeSeq*)self->seq)->playFrame(0,self->getMotionFrame(0),lbl_63_rodata_80);
    self->state = 3;
   }
   break;
  case 3:
   ((StSeUtil::SeSeq*)self->seq)->playFrame(0,self->getMotionFrame(0));
   if (*self->trigger != self->triggerValue) {
    self->fn_63_59A4(1,0,0,&self->endFrame);
    if (self->speed < lbl_63_rodata_80) self->speed *= lbl_63_rodata_84;
    self->state = 4;
   }
   break;
  case 4:
   if (self->fn_63_5D78() >= self->endFrame) self->state = 0;
   break;
  }
 }
}
}