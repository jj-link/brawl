#pragma force_active on
typedef unsigned char u8;
struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void processAnim(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void fn_63_164C0(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void renderDebug(); virtual void init(); virtual void fn_63_16454(); virtual void fn_63_16514();
 virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility(unsigned long);
 virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
 virtual void fn_63_3378(); virtual void fn_63_164BC(); virtual void setNode(); virtual void fn_63_59C();
 virtual void fn_63_3370(); virtual void fn_63_336C(); virtual void fn_63_2B64(); virtual void fn_63_3364();
 virtual void fn_63_3358(); virtual void fn_63_3348(); virtual void fn_63_3338(); virtual void getNodeIndex();
 virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void setInitializeFlag(); virtual void fn_63_3330();
 virtual void fn_63_3328(); virtual void setMotionRatio(); virtual void setMotionFrame(); virtual void getMotionFrame();
 virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
 virtual void preExit(); virtual void fn_63_3320(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
 virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(); virtual void getTgtNode();
 virtual void fn_63_1884(); virtual void fn_63_339C(); virtual void changeNodeAnim(); virtual void createFadeVisibleProduction();
 virtual void createSoundEffectVisibleProductionForExcel(); virtual void createEffectVisibleProductionForExcel(); virtual void setSimpleEffectVisibleProduction(); virtual void dbDispInvalidatedByCameraClippingSphere();
 virtual void setTransparency(); virtual void fn_63_3394(); virtual void onDamage(); virtual void onInflict();
 virtual void onInflictEach(); virtual void fn_63_16A54(); virtual void enableYakumono(); virtual void disableYakumono();
 virtual void enableHit(); virtual void disableHit(); virtual void disableAttack(); virtual void enableArea();
 char pad40[0x118];
 u8 state;
 char pad159[0x43];
 u8* selection;
 u8 id;
 char pad1a1[3];
 u8* event;
 u8 previous;
 char pad1a9[8];
 u8 flag;
};
extern "C" void fn_63_167C0(Ground* self) {
 switch (self->state) {
 case 0:
  self->setVisibility(0);
  self->flag = 1;
  self->previous = 1;
  self->state = 1;
  break;
 case 1:
  if (*self->selection == self->id) self->state = 2;
  break;
 case 2:
  if (*self->selection != self->id) {
   self->state = 0;
   break;
  }
  if (self->previous != *self->event) {
   switch (*self->event) {
   case 1:
    self->setVisibility(0);
    self->flag = 1;
    break;
   case 0:
    self->setVisibility(1);
    self->enableArea();
    break;
   }
  }
  self->previous = *self->event;
  break;
 }
}