#include <types.h>
#include <gf/gf_model.h>
#include <mu/mu_object.h>
#include <snd/snd_system.h>
#pragma force_active on
struct SelChar {
 int type; int state; MuObject* object;
 char pad0C[0x30-0x0C]; void* visibleA; void* visibleB;
 char pad38[0x44-0x38]; int selection;
 char pad48[0x6C-0x48]; int maxA; u16 ids[0x78];
 int timer; int ownIds[4];
};
extern "C" {
extern const float lbl_10_rodata_8A8[];
extern void* g_GameGlobal;
int fn_8004D740(void*);
void fn_10_1D4A8(void*);
void fn_10_1CF64(void*,u32);
void fn_10_1DC10(void*,int);
void fn_800B753C(void*,float);
void setFrameVisible__8MuObjectFf(void*,float);
void setFrameNode__8MuObjectFf(void*,float);
void setUpdateRate__16gfModelAnimationFf(gfModelAnimation*,float);
}
inline int getSelectionLimit(SelChar* self) {
 int limit;
 switch(self->type) {
 case 0: limit=self->maxA+1; break;
 case 1: limit=9; break;
 case 2: limit=0x1F; break;
 case 3: limit=0x1F; break;
 }
 return limit;
}
inline int isUsed(SelChar* self,int candidate) {
 if(candidate<0) return 1;
 for(int i=0;i<4;++i) {
 if(candidate==self->ownIds[i]) return 1;
 }
 return 0;
}
extern "C" int fn_10_1D5C4(SelChar* self,void* inputArg,int* result) {
 int status;
 void* input=inputArg;
 const float* ro=lbl_10_rodata_8A8;
 int leftLimit, rightLimit;
 int finalLimit;
 if(self->state==0) return 0;
 int sound;
 u32 flags=*(u32*)((char*)input+0x0C);
 if((flags&0x100)||(flags&0x200)) {
 if(flags&0x100) {
 int type=self->type;
 sound=0;
 if(type==0) {
 int current=self->selection;
 if(current==-1||current>=getSelectionLimit(self)) {
 if(fn_8004D740(g_GameGlobal)<=0) {
 float frame=ro[10]; self->timer=0x78;
 setFrameVisible__8MuObjectFf(self->visibleA,frame);
 setFrameVisible__8MuObjectFf(self->visibleB,frame);
 sound=3; status=1;
 } else {status=4;}
 } else if(current==0) {status=5;}
 else {
 int candidate=self->ids[current-1];
 int match=isUsed(self,candidate);
 if(match) {sound=3;status=1;}
 else {*result=candidate;status=2;}
 }
 } else {status=2;*result=self->selection;}
 g_sndSystem->playSE((SndID)sound,-1,0,0,-1);
 } else if(self->type!=0) {
 status=2;*result=self->selection;
 g_sndSystem->playSE((SndID)0,-1,0,0,-1);
 } else {
 status=3;g_sndSystem->playSE((SndID)2,-1,0,0,-1);
 }
 if(status!=1) {
 fn_10_1D4A8(self);
 fn_800B753C(self->object,ro[9]);
 setUpdateRate__16gfModelAnimationFf(self->object->m_modelAnim,ro[9]);
 self->state=0;return status;
 }
 }
 if((u32)(self->state-2)<=1) {
 int finished;
 if(ro[9]!=self->object->m_modelAnim->m_anmObjChrRes->GetUpdateRate()) {finished=0;}
 else {
 fn_10_1D4A8(self);
 fn_10_1CF64(self,self->selection);
 if(self->type==0&&self->timer>0) {
 float frame=ro[9];
 setFrameVisible__8MuObjectFf(self->visibleA,frame);
 setFrameVisible__8MuObjectFf(self->visibleB,frame);
 self->timer=0;
 }
 setFrameNode__8MuObjectFf(self->object,ro[9]);finished=1;
 }
 if(finished) self->state=1;
 }
 if(self->state==1) {
 if((*(u32*)((char*)input+0x14)&8)&&self->selection>-(self->type==0)) {
 fn_10_1DC10(self,1);
 int type=self->type;
 int candidate=--self->selection;
 self->state=2;
 int lower=candidate>-(type==0);
 leftLimit=getSelectionLimit(self);
 if(type==0) ++leftLimit;
 int upper=candidate<leftLimit-1;
 float frame;
 if(lower) {if(upper) frame=ro[10];else frame=ro[11];}
 else if(upper) frame=ro[12];else frame=ro[9];
 setFrameVisible__8MuObjectFf(self->object,frame);
 g_sndSystem->playSE((SndID)0,-1,0,0,-1);
 }
 if(*(u32*)((char*)input+0x14)&4) {
 int type=self->type;
 rightLimit=getSelectionLimit(self);
 if(type==0) ++rightLimit;
 if(self->selection<rightLimit-1) {
 fn_10_1DC10(self,0);
 type=self->type;
 int candidate=++self->selection;
 self->state=3;
 int lower=candidate>-(type==0);
 finalLimit=getSelectionLimit(self);
 if(type==0) ++finalLimit;
 int upper=candidate<finalLimit-1;
 float frame;
 if(lower) {if(upper) frame=ro[10];else frame=ro[11];}
 else if(upper) frame=ro[12];else frame=ro[9];
 setFrameVisible__8MuObjectFf(self->object,frame);
 g_sndSystem->playSE((SndID)0,-1,0,0,-1);
 }
 }
 }
 if(self->timer>0) {
 --self->timer;
 if(self->timer<=0) {
 float frame=ro[9];
 setFrameVisible__8MuObjectFf(self->visibleA,frame);
 setFrameVisible__8MuObjectFf(self->visibleB,frame);
 }
 }
 return 1;
}
