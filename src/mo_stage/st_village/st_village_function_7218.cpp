#include <it/it_manager.h>
#include <snd/snd_3d_generator.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_70_rodata_E8[];
float randf__Fv();
unsigned int fn_8005136C(int);
void fn_27_28E48C(BaseItem*, Vec3f*, float);
}
struct GameInfo { char pad[0x16]; signed char flag; };
struct GameGlobal { char pad[8]; GameInfo* info; };
extern "C" GameGlobal* g_GameGlobal;
struct Params { char pad[0x18]; float first, min, max, chance, speed, duration; };
struct Ground_base { char pad[0x3c]; };
#define V(n) virtual void n();
class Ground : public Ground_base {
public:
V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection) V(processMapCorrection) V(fn_70_6FE8) V(processPreCollision) V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug) V(renderDebug) V(init) V(fn_70_6EF8) V(fn_70_6180) V(loadGroundData) V(bindData) V(setupMelee)
virtual void setVisibility(unsigned long);
V(setVisibilityByClipping) V(setVisibilityAttachedEffect) V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack) V(unloadData) V(fn_70_22A8) V(startup) V(fn_70_77E4) V(fn_70_78C)
virtual Params* fn_70_22A0();
V(fn_70_229C) V(fn_70_2080) V(fn_70_2294) V(fn_70_2288) V(fn_70_2278) V(fn_70_2268) V(getNodeIndex)
virtual void getNodePosition(Vec3f*, unsigned long, unsigned long);
V(getNodePosition_2) V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2) V(setValid) V(setValidAttachedEffect) V(fn_70_2264) V(fn_70_2260) V(fn_70_2258) V(fn_70_15C4) V(setMotionFrame)
virtual float getMotionFrame(unsigned long);
V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(fn_70_2250) V(invalidatedByCameraClipping) V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode) V(fn_70_22D4) V(fn_70_22CC) V(changeNodeAnim) V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_70_22C4) V(fn_70_7E38) V(onInflict) V(onInflictEach) V(onGimmickEvent) V(enableYakumono) V(disableYakumono)
virtual void enableHit(unsigned long, unsigned long);
virtual void disableHit(unsigned long, unsigned long);
V(disableAttack) V(enableArea) V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono) V(getTeamYakumono) V(setOffsetAttack) V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) V(setAttackGimmick) V(setSoCollisionAttackData) V(setAttackGimmickDetails) V(isEnableAttackPersonAttacked) V(isEnableAttackAttribute) V(fn_70_21B0) V(fn_70_794) V(fn_70_79C) V(fn_70_7A4) V(fn_70_7AC) V(fn_70_2208) V(fn_70_710C) V(fn_70_7218) V(fn_70_7718)
virtual void fn_70_64EC(unsigned long, int, int, float*);
char pad40[0x24]; float speed; char pad68[4]; unsigned char flags; char pad6d[0x57]; unsigned long node; char padc8[0x88];
unsigned char state; char pad151[3]; float timer; char pad158[0x11]; unsigned char initial; char pad16a[2]; float previous; float end; char pad174[0x58]; unsigned char motion; char pad1cd[3]; Vec3f pos; float duration; int item; char pad1e4[4]; unsigned char flag; char pad1e9[0x17]; snd3DGenerator sound;
};
#undef V
extern "C" void fn_70_7218(Ground* self, float delta) {
 const float* c = lbl_70_rodata_E8;
 Params* p = self->fn_70_22A0();
 if (!p) return;
 self->timer -= delta;
 if (self->timer < c[0]) self->timer = c[0];
 switch (self->state) {
 case 0: {
 self->fn_70_64EC(4,0,1,0);
 self->setVisibility(0);
 self->disableHit(0,0);
 if (self->initial == 1) { self->timer = p->first; self->initial = 0; }
 else { float r = randf__Fv(); float range = p->max - p->min; self->timer = p->min + range * r; }
 int id = self->item;
 self->speed = p->speed;
 self->duration = p->duration;
 if (id) {
 self->item = 0;
 itManager* manager = itManager::getInstance();
 if (!manager) return;
 BaseItem* item = manager->getItemFromInstanceId(id);
 if (!item) return;
 manager->removeItem(item);
 }
 self->state = 1;
 break;
 }
 case 1:
 if (c[0] == self->timer) self->state = 3;
 break;
 case 3: {
 if (randf__Fv() < p->chance) {
 if (self->speed > c[0]) self->speed *= c[3];
 } else {
 if (self->speed < c[0]) self->speed *= c[3];
 }
 float r = randf__Fv();
 unsigned int motion;
 if (r < c[4]) motion = 0;
 else if (r < c[5]) motion = 1;
 else motion = 2;
 if (motion == self->motion) break;
 self->fn_70_64EC(motion,1,1,&self->end);
 if (self->speed > c[0]) self->previous = c[0];
 else if (self->speed < c[0]) self->previous = self->end;
 self->motion = motion;
 self->enableHit(0,0);
 GameInfo* info = g_GameGlobal->info;
 if (!info) return;
 if (info->flag && fn_8005136C(0x40) == 1) self->flag = 1;
 self->state = 4;
 break;
 }
 case 4:
 if (!((self->flags >> 7) & 1)) self->setVisibility(1);
 if (c[0] == self->duration) {
 self->getNodePosition(&self->pos,0,self->node);
 self->fn_70_64EC(3,0,1,&self->end);
 if (self->speed < c[0]) self->speed *= c[3];
 self->disableHit(0,0);
 self->sound.playSE((SndID)0x1cf8,0,0,-1);
 int id = self->item;
 if (id) {
 self->item = 0;
 BaseItem* item = itManager::getInstance()->getItemFromInstanceId(id);
 if (!item) return;
 Vec3f vec;
 vec.m_x = c[0]; vec.m_y = c[0]; vec.m_z = c[0];
 float lr = soExternalValueAccesser::getLr(item);
 fn_27_28E48C(item,&vec,lr);
 item->setVanishMode(true);
 }
 self->state = 9;
 } else {
 if (self->speed > c[0] && self->getMotionFrame(0) < self->previous) { self->state = 0; return; }
 if (self->speed < c[0] && self->getMotionFrame(0) > self->previous) { self->state = 0; return; }
 self->previous = self->getMotionFrame(0);
 }
 break;
 case 9:
 if (self->getMotionFrame(0) >= self->end) { self->setVisibility(0); self->state = 0; }
 break;
 }
}
