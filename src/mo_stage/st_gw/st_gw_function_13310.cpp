#pragma force_active on
#pragma fp_contract off
#include <mt/mt_vector.h>
extern "C" {
extern void* g_aiMgr;
extern int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(void*, Vec2f*, Vec2f*, int, bool, bool);
extern void fn_27_1F299C(void*, int);
extern const float lbl_63_rodata_170[];
}
struct GroundBase { char pad[0x3c]; };
class Ground : public GroundBase {
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
virtual void fn_63_13288();
virtual void fn_63_10DFC();
virtual void loadGroundData();
virtual void bindData();
virtual void setupMelee();
virtual void setVisibility(int);
virtual void setVisibilityByClipping();
virtual void setVisibilityAttachedEffect();
virtual void receiveCollMsg();
virtual void receiveCollMsg_Landing();
virtual void receiveCollMsg_Heading();
virtual void receiveCollMsg_Wall();
virtual void receiveCollMsg_Attack();
virtual void unloadData();
virtual void fn_63_3378();
virtual void startup();
virtual void setNode();
virtual void fn_63_59C();
virtual float* fn_63_3370();
virtual void fn_63_336C();
virtual void fn_63_2B64();
virtual void fn_63_3364();
virtual void fn_63_3358();
virtual void fn_63_3348();
virtual void fn_63_3338();
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
virtual void fn_63_3334();
virtual void fn_63_3330();
virtual void fn_63_3328();
virtual void setMotionRatio();
virtual void setMotionFrame(int, float);
virtual float getMotionFrame(int);
virtual void setMotionLoop();
virtual void setMatAlphaMul();
virtual void setMatAlpha();
virtual void updateG3dProcCalcWorld();
virtual void preExit();
virtual void fn_63_3320();
virtual void invalidatedByCameraClipping();
virtual void setTransparencyFlag();
virtual void updateCallback();
virtual void fixedPosition();
virtual void setTgtNode();
virtual void getTgtNode();
virtual void fn_63_1884();
virtual void fn_63_339C();
virtual void changeNodeAnim();
virtual void createFadeVisibleProduction();
virtual void createSoundEffectVisibleProductionForExcel();
virtual void createEffectVisibleProductionForExcel();
virtual void setSimpleEffectVisibleProduction();
virtual void dbDispInvalidatedByCameraClippingSphere();
virtual void setTransparency();
virtual void fn_63_3394();
virtual void fn_63_11CF8();
virtual void onInflict();
virtual void onInflictEach();
virtual void onGimmickEvent();
virtual void enableYakumono();
virtual void disableYakumono();
virtual void enableHit();
virtual void disableHit();
virtual void disableAttack(int);
virtual void enableArea();
virtual void disableArea();
virtual void setSleepArea();
virtual void setTeamYakumonoOwnerId();
virtual void setTeamYakumono();
virtual void getTeamYakumono();
virtual void setOffsetAttack();
virtual void setAreaGimmick__10grYakumonoFP10soAreaDataP19soSet();
virtual void setAttackGimmick();
virtual void setSoCollisionAttackData();
virtual void setAttackGimmickDetails();
virtual void isEnableAttackPersonAttacked();
virtual void isEnableAttackAttribute();
virtual void fn_63_2D00();
virtual void fn_63_13874();
virtual void fn_63_2ED8(int, int, int, void*);
virtual void fn_63_1F28();
virtual void fn_63_1F30();
virtual void fn_63_10E94();
virtual void fn_63_13310();
virtual void fn_63_120B0();
virtual void fn_63_1F38();
virtual void fn_63_1F40();
virtual void fn_63_139C4();
char pad40[0x24]; float value64; char pad68[0xE8]; unsigned char state; char pad151[3]; float timer154; char pad158[5]; unsigned char flag15d; char pad15e[2]; float value160; float value164; char pad168[0x0C]; unsigned char* data174; unsigned char* data178; unsigned char index17c; char pad17d[3]; float pos180; float pos184; float pos188; char pad18c[0x20]; unsigned char flag1ac; char pad1ad[3]; int danger1b0; float timer1b4;
};
extern "C" void fn_63_13310(Ground* self, float delta) {
const float* c = lbl_63_rodata_170;
float* result = self->fn_63_3370();
if (result != 0) {
self->timer154 -= delta;
if (self->timer154 < c[7]) self->timer154 = c[7];
self->timer1b4 -= delta;
if (self->timer1b4 < c[7]) self->timer1b4 = c[7];
switch (self->state) {
case 0:
self->fn_63_2ED8(1,0,1,0); self->setVisibility(0); self->disableAttack(0); self->flag1ac=0; self->state=1; break;
case 1:
if (*self->data178 == self->index17c) {
self->fn_63_2ED8(0,1,1,&self->value164); self->setMotionFrame(0,self->value164); self->value160=self->value164;
if (self->value64 > c[7]) self->value64 *= c[6];
self->state=3;
} break;
case 3:
if (*self->data178 != self->index17c) {
self->fn_63_2ED8(0,0,1,&self->value164);
if (self->value64 < c[7]) self->value64 *= c[6];
self->state=4;
} else if (self->data174[0x60] == 1) {
self->timer154=result[27]; self->timer1b4=c[8]; self->state=5;
} else if (self->getMotionFrame(0) > self->value160 && self->flag15d == 0) {
self->fn_63_2ED8(1,0,0,0);
} else { self->value160=self->getMotionFrame(0); }
break;
case 5:
if (*self->data178 != self->index17c) {
self->fn_63_2ED8(0,0,1,&self->value164);
if (self->value64 < c[7]) self->value64 *= c[6];
self->state=4;
} else if (self->data174[0x60] == 0) {
self->setVisibility(0); self->disableAttack(0); self->flag1ac=0;
if (self->data174[0x61] > 4) self->data174[0x61] -= 4;
if (self->danger1b0 != -1) { fn_27_1F299C(g_aiMgr,self->danger1b0); self->danger1b0=-1; }
self->state=3;
} else if (c[7] == self->timer154) {
self->data174[0x60]=0;
} else {
if (c[7] == self->timer1b4) {
self->data174[0x61] += 4;
if (self->data174[0x61] >= 8) self->data174[0x61] -= 8;
if (self->data174[0x61] < 4) { self->setVisibility(0); self->disableAttack(0); self->flag1ac=0; }
else { self->setVisibility(1); self->fn_63_139C4(); }
self->timer1b4=c[8];
}
unsigned char* point = self->data174 + self->data174[0x61] * 12;
Vec3f* values=(Vec3f*)point;
Vec3f pos;
pos.m_x=values->m_x; pos.m_y=values->m_y; pos.m_z=values->m_z;
Vec2f bounds[2] = { Vec2f(pos.m_x-c[9], c[8]+pos.m_y), Vec2f(c[9]+pos.m_x, pos.m_y-c[8]) };
self->danger1b0=setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(g_aiMgr,&bounds[0],&bounds[1],self->danger1b0,false,false);
}
break;
case 4:
if (self->getMotionFrame(0) >= self->value164) {
if (self->danger1b0 != -1) { fn_27_1F299C(g_aiMgr,self->danger1b0); self->danger1b0=-1; }
self->state=0;
}
break;
default: break;
}
unsigned char* point=self->data174+self->data174[0x61]*12;
self->pos180=*(float*)point; self->pos184=*(float*)(point+4); self->pos188=*(float*)(point+8);
}
}