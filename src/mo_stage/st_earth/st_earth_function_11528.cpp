#include <mt/mt_vector.h>
#include <snd/snd_3d_generator.h>
#include <nw4r/math/math_arithmetic.h>
#include <revolution/OS/OSFastCast.h>
#pragma force_active on
extern "C" {
extern const float lbl_66_rodata_220[];
void update__9grGimmickFf(void*, float);
float fn_801622C4(float);
int fn_800797A4(snd3DGenerator*, int);
}
struct Param { char pad[0xcc]; float value; };
struct Ground_base { char pad[0x3c]; };
#define V(n) virtual void n();
class Ground : public Ground_base {
public:
V(processDefault) V(processBegin) V(processAnim) V(processUpdate) V(processPreMapCorrection) V(processMapCorrection) V(processFixPosition) V(processPreCollision) V(processCollision) V(processCatch) V(processHit) V(processCamera) V(processFixCamera) V(processEffect) V(processGameProc) V(processEnd) V(renderPre) V(renderOpa) V(renderXlu) V(processDebug) V(renderDebug) V(init) V(fn_66_114C0) V(fn_66_11528) V(loadGroundData) V(bindData) V(setupMelee)
virtual void setVisibility(unsigned long);
V(setVisibilityByClipping) V(setVisibilityAttachedEffect) V(receiveCollMsg) V(receiveCollMsg_Landing) V(receiveCollMsg_Heading) V(receiveCollMsg_Wall) V(receiveCollMsg_Attack) V(unloadData) V(fn_66_2D00) V(startup) V(setNode) V(fn_66_6BC)
virtual Param* fn_66_2CF8();
V(fn_66_2CF4) V(fn_66_2BF4) V(fn_66_2CEC) V(fn_66_2CE0) V(fn_66_2CD0) V(fn_66_BBC) V(getNodeIndex) V(getNodePosition) V(getNodePosition_2) V(getNodeMatrix) V(getNodeMatrix_2) V(setNodeVisibility) V(setNodeVisibility_2) V(setNodeVisibilityAll) V(isNodeVisible) V(setNodeCollision) V(setNodeCollision_2) V(getNodeScale) V(getNodeScale_2) V(setValid) V(setValidAttachedEffect) V(fn_66_2CCC) V(fn_66_2CC8) V(fn_66_2CC0) V(setMotionRatio) V(setMotionFrame)
virtual float getMotionFrame(unsigned long);
V(setMotionLoop) V(setMatAlphaMul) V(setMatAlpha) V(updateG3dProcCalcWorld) V(preExit) V(fn_66_2CB8) V(invalidatedByCameraClipping) V(setTransparencyFlag) V(updateCallback) V(fixedPosition) V(setTgtNode) V(getTgtNode) V(fn_66_2D2C) V(fn_66_2D24) V(changeNodeAnim) V(createFadeVisibleProduction) V(createSoundEffectVisibleProductionForExcel) V(createEffectVisibleProductionForExcel) V(setSimpleEffectVisibleProduction) V(dbDispInvalidatedByCameraClippingSphere) V(setTransparency) V(fn_66_2D1C) V(onDamage) V(onInflict) V(onInflictEach) V(onGimmickEvent) V(enableYakumono) V(disableYakumono) V(enableHit) V(disableHit) V(disableAttack) V(enableArea) V(disableArea) V(setSleepArea) V(setTeamYakumonoOwnerId) V(setTeamYakumono) V(getTeamYakumono) V(setOffsetAttack) V(setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet_10soAreaData_P10ykAreaDatab) V(setAttackGimmick) V(setSoCollisionAttackData) V(setAttackGimmickDetails) V(isEnableAttackPersonAttacked) V(isEnableAttackAttribute) V(fn_66_11B90) V(fn_66_11BBC)
virtual void fn_66_11BDC(int,int,float*);
char pad40[0x118]; unsigned char state; char pad159[3]; float timer; unsigned char flag; char pad161[3]; float* out; float previous; float end; snd3DGenerator sound; int handle;
};
#undef V
inline float clampRange(float value, float lo, float hi) {
    float t = nw4r::math::FSelect(value - lo, value, lo);
    return nw4r::math::FSelect(t - hi, hi, t);
}
extern "C" void fn_66_11528(Ground* self, float delta) {
 const float* c = lbl_66_rodata_220;
 update__9grGimmickFf(self,delta);
 Param* p=self->fn_66_2CF8();
 if (!p) return;
 self->timer -= delta;
 if (self->timer < c[0]) self->timer=c[0];
 switch(self->state) {
 case 0:
 self->fn_66_11BDC(3,0,0); self->setVisibility(0); self->state=1; break;
 case 2: {
 self->fn_66_11BDC(0,0,&self->end); self->setVisibility(1);
 Vec3f pos; pos.m_x=c[1]; pos.m_y=c[0]; pos.m_z=c[0]; self->sound.setPos(&pos);
 self->handle=self->sound.playSE((SndID)0x1cda,0,0,-1); self->state=3; break;
 }
 case 3:
 if (self->getMotionFrame(0)>=c[2]) *self->out=p->value;
 else if (self->getMotionFrame(0)>=c[3]) {
 float t=(self->getMotionFrame(0)-c[3])/c[4];
 t=clampRange(t,c[0],c[5]);
 u16 a=(u16)(c[6]*t);
 *self->out=c[8]+(p->value-c[8])*fn_801622C4(c[7]*__OSu16tof32(&a));
 } else if (self->getMotionFrame(0)>=c[9]) {
 float t=(self->getMotionFrame(0)-c[9])/c[10];
 t=clampRange(t,c[0],c[5]);
 u16 a=(u16)(c[6]*t);
 *self->out=c[8]+(p->value-c[8])*fn_801622C4(c[7]*__OSu16tof32(&a));
 } else *self->out=c[0];
 if (self->getMotionFrame(0)>=self->end) {
 if (self->flag==1) self->state=6; else self->state=4;
 }
 if (self->handle==-1 || !fn_800797A4(&self->sound,self->handle)) {
 if(self->handle!=-1) self->sound.stopSE(self->handle,60);
 Vec3f pos; pos.m_x=c[1]; pos.m_y=c[0]; pos.m_z=c[0]; self->sound.setPos(&pos);
 self->handle=self->sound.playSE((SndID)0x1cdb,0,60,-1);
 }
 break;
 case 4:
 self->fn_66_11BDC(1,1,&self->end); self->state=5; self->previous=c[0]; break;
 case 5:
 if (self->flag==1 && self->getMotionFrame(0)<self->previous) self->state=6;
 else self->previous=self->getMotionFrame(0);
 break;
 case 6: {
 self->fn_66_11BDC(2,0,&self->end);
 if(self->handle!=-1) self->sound.stopSE(self->handle,60);
 Vec3f pos; pos.m_x=c[1]; pos.m_y=c[0]; pos.m_z=c[0]; self->sound.setPos(&pos);
 self->sound.playSE((SndID)0x1cdc,0,60,-1);
 self->flag=0; self->state=7; break;
 }
 case 7:
 if(self->getMotionFrame(0)>=c[11]) *self->out=c[0];
 else if(self->getMotionFrame(0)>=c[12]) {
 float t=(self->getMotionFrame(0)-c[12])/c[13];
 t=clampRange(t,c[0],c[5]);
 *self->out=c[8]-c[8]*t;
 } else if(self->getMotionFrame(0)>=c[14]) {
 float t=(self->getMotionFrame(0)-c[14])/c[15];
 t=clampRange(t,c[0],c[5]);
 *self->out=c[16]-c[17]*t;
 } else *self->out=c[16];
 if(self->getMotionFrame(0)>=self->end) self->state=0;
 break;
 }
}
