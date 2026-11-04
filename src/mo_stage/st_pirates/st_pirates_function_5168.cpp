#include <ec/ec_mgr.h>
#pragma force_active on
extern "C" const float lbl_52_rodata_E8;
extern "C" const float lbl_52_rodata_FC;
extern "C" char lbl_52_data_103C[];

struct Ground_base { char pad[0x3c]; };
class Ground : public Ground_base {
public:
 virtual void processDefault(); virtual void processBegin(); virtual void fn_52_4E70(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection(); virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch(); virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect(); virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu(); virtual void processDebug();
 virtual void renderDebug(); virtual void init(); virtual void fn_52_4DE0(); virtual void fn_52_4F0C();
 virtual void loadGroundData(); virtual void bindData(); virtual void setupMelee(); virtual void setVisibility();
 virtual void setVisibilityByClipping(); virtual void setVisibilityAttachedEffect(); virtual void receiveCollMsg(); virtual void receiveCollMsg_Landing();
 virtual void receiveCollMsg_Heading(); virtual void receiveCollMsg_Wall(); virtual void receiveCollMsg_Attack(); virtual void unloadData();
 virtual void fn_52_36EC(); virtual void startup(); virtual void setNode(); virtual void fn_52_83C();
 virtual void fn_52_36E4(); virtual void fn_52_36E0(); virtual void fn_52_35C8(); virtual void fn_52_36D8();
 virtual void fn_52_36CC(); virtual void fn_52_36BC(); virtual void fn_52_36AC(); virtual void getNodeIndex();
 virtual void getNodePosition(); virtual void getNodePosition_2(); virtual void getNodeMatrix(); virtual void getNodeMatrix_2();
 virtual void setNodeVisibility(); virtual void setNodeVisibility_2(); virtual void setNodeVisibilityAll(); virtual void isNodeVisible();
 virtual void setNodeCollision(); virtual void setNodeCollision_2(); virtual void getNodeScale(); virtual void getNodeScale_2();
 virtual void setValid(); virtual void setValidAttachedEffect(); virtual void fn_52_36A8(); virtual void fn_52_36A4();
 virtual void fn_52_369C(); virtual void setMotionRatio(); virtual void setMotionFrame(float, unsigned long); virtual void getMotionFrame();
 virtual void setMotionLoop(); virtual void setMatAlphaMul(); virtual void setMatAlpha(); virtual void updateG3dProcCalcWorld();
 virtual void preExit(); virtual void fn_52_3694(); virtual void invalidatedByCameraClipping(); virtual void setTransparencyFlag();
 virtual void updateCallback(); virtual void fixedPosition(); virtual void setTgtNode(); virtual void getTgtNode();
 virtual void fn_52_3718(); virtual void fn_52_3710(); virtual void changeNodeAnim(); virtual void createFadeVisibleProduction();
 virtual void createSoundEffectVisibleProductionForExcel(); virtual void createEffectVisibleProductionForExcel(); virtual void setSimpleEffectVisibleProduction(); virtual void dbDispInvalidatedByCameraClippingSphere();
 virtual void setTransparency(); virtual void fn_52_3708(); virtual void onDamage(); virtual void onInflict();
 virtual void onInflictEach(); virtual void onGimmickEvent(); virtual void enableYakumono(); virtual void disableYakumono();
 virtual void enableHit(); virtual void disableHit(); virtual void disableAttack(); virtual void enableArea();
 virtual void disableArea(); virtual void setSleepArea(); virtual void setTeamYakumonoOwnerId(); virtual void setTeamYakumono();
 virtual void getTeamYakumono(); virtual void setOffsetAttack(); virtual void setAreaGimmick();
 virtual void setAttackGimmick(); virtual void setSoCollisionAttackData(); virtual void setAttackGimmickDetails(); virtual void isEnableAttackPersonAttacked();
 virtual void isEnableAttackAttribute(); virtual void fn_52_B70(); virtual void fn_52_A24(); virtual void fn_52_5000();
 virtual void fn_52_5168(); virtual void fn_52_552C(); virtual void fn_52_578C(); virtual void fn_52_59C8();
 virtual void fn_52_5AB8(); virtual void fn_52_5E94(); virtual void fn_52_5FE4(int, int, int, float*);
 unsigned char pad40[4]; nw4r::g3d::ScnMdl** model;
 unsigned char pad48[0x108]; unsigned char state;
 unsigned char pad151[0xf]; unsigned char phase, count;
 unsigned char pad162[2]; float* frame;
 unsigned char pad168[8]; unsigned char* selector; unsigned char selected;
 unsigned char pad175[3]; unsigned char* limit; unsigned char kind;
 unsigned char pad17d[3]; float timer;
 unsigned char pad184[0x18]; unsigned long effect;
};
extern "C" void fn_52_5168(Ground* self, float delta) {
 self->timer -= delta;
 if (self->timer < lbl_52_rodata_E8) self->timer = lbl_52_rodata_E8;
 switch ((int)self->state) {
 case 0:
  self->fn_52_5FE4(1, 1, 1, &self->timer);
  g_ecMgr->setDrawPrio(1);
  self->effect = g_ecMgr->setEffect((EfID)0x3a0005);
  g_ecMgr->setDrawPrio(-1);
  g_ecMgr->setParent(self->effect, *self->model, lbl_52_data_103C, false);
  self->state = 1;
 case 1:
  if (self->phase == 1) {
   unsigned int val = 20;
   int flag = 1;
   switch (self->kind) {
   case 7: case 10: case 13: val = 0; break;
   case 5: case 8: case 15: val = 2; break;
   case 6: case 9: case 12: val = 3; break;
   case 4: case 11: case 14: val = 1; break;
   case 16: if (--self->count == 0) val = 0; break;
   case 17: if (--self->count == 0) { val = 18; flag = 0; self->count = *self->limit; } break;
   case 18: if (--self->count == 0) { self->count = 1; val = 19; flag = 0; } break;
   case 19: if (--self->count == 0) val = 0; break;
   }
   unsigned int current = *self->selector;
   if (current != self->selected) {
    unsigned char old = (unsigned char)val;
    switch (current) {
    case 1:
     switch (self->kind) {
     case 0: val = 4; break; case 2: val = 11; break; case 3: val = 14; break;
     case 16: val = 4; break; case 19: val = 4; break;
     } break;
    case 2:
     switch (self->kind) {
     case 0: val = 5; break; case 1: val = 8; break; case 3: val = 15; break;
     case 16: val = 5; break; case 19: val = 5; break;
     } break;
    case 3:
     switch (self->kind) {
     case 0: val = 6; break; case 1: val = 9; break; case 2: val = 12; break;
     case 16: val = 6; break; case 19: val = 6; break;
     } break;
    case 5: case 8:
     switch ((int)self->kind) {
     case 1: val = 7; break; case 2: val = 10; break; case 3: val = 13; break;
     } break;
    case 6: self->count = 3; val = 16; break;
    case 9: if ((int)self->kind >= 20 || (int)self->kind < 17) { self->count = 3; val = 17; } break;
    }
    if (val != (unsigned int)old) flag = 0;
    self->selected = *self->selector;
   }
   if (val != 20) {
    self->fn_52_5FE4(val, flag, 1, &self->timer);
    self->setMotionFrame(lbl_52_rodata_FC - *self->frame, 0);
   }
  }
  break;
 }
}
