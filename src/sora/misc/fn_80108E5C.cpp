#include <gf/gf_model.h>
#include <gm/gm_global.h>
#include <mu/mu_object.h>
#include <types.h>
#pragma force_active on
class Object_vptr_0 { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(void*); virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(void*);
};
class Anim_vptr { public:
virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
virtual void slot8(float);
};
struct State {
char pad0[4]; MuObject* first; MuObject* second; char padC[0xC]; void* arg18;
void* arg1C; char pad20[0x10]; u8 count0,count1,count2,count3,count4,count5,count6,count7,count8,count9;
};
extern "C" {
extern char lbl_8045D1FC[], lbl_8045D214[];
extern const float lbl_805A2820, lbl_805A2824, lbl_805A2828, lbl_805A282C;
extern double lbl_805A2830;
extern MuObject* lbl_805A0330;
extern Object_vptr_0* lbl_805A0334;
void fn_80108E5C(State* self) {
if(self->count5) {
self->count0=self->count0+1;
if(self->count0==1) { MuObject* o=self->first; o->changeAnimN(lbl_8045D1FC); o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2824); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2824); }
if(self->count0==14) { self->count0=0; self->count5=0; }
}
if(self->count7) {
self->count2=self->count2+1;
if(self->count2==1) { MuObject* o=self->first; o->changeAnimN(lbl_8045D214); o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2824); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2824); }
if(self->count2==60) { self->count2=0; self->count7=0; lbl_805A0334->slot13(self->arg18); MuObject* o=self->first; o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2820); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2820); }
}
if(self->count6) {
self->count1=self->count1+1;
if(self->count1==1) { MuObject* o=self->second; o->changeAnimN(lbl_8045D1FC); o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2824); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2824); }
if(self->count1==14) { self->count1=0; self->count6=0; }
}
if(self->count8) {
self->count3=self->count3+1;
if(self->count3==1) { MuObject* o=self->second; o->changeAnimN(lbl_8045D214); o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2824); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2824); }
if(self->count3==60) { self->count3=0; self->count8=0; lbl_805A0334->slot13(self->arg1C); MuObject* o=self->second; o->setFrameNode(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjChrRes)->slot8(lbl_805A2820); o->setFrameMatCol(lbl_805A2820); ((Anim_vptr*)o->m_modelAnim->m_anmObjMatClrRes)->slot8(lbl_805A2820); }
}
if(!self->count9) {
self->count4=0;
if(!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28]>>7)&1)) { int n=0; lbl_805A0330->setFrameNode(lbl_805A2828+(float)n); }
else { int n=0; lbl_805A0330->setFrameNode(lbl_805A282C+(float)n); }
} else {
u8 n=self->count4;
if(n<8) {
int value=(int)n;
if(!((((u8*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28]>>7)&1)) lbl_805A0330->setFrameNode(lbl_805A2828+(float)value);
else lbl_805A0330->setFrameNode(lbl_805A282C+(float)value);
self->count4=self->count4+1;
}
}
}
}