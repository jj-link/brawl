#include <mu/mu_object.h>
#include <mu/mu_msg.h>
#pragma force_active on
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void f34(int,int); char pad[0xE0]; int e4; };
struct Self {
char pad0[0x40]; MuObject* o40[3];
char pad1[0x198-0x4C]; int a198,a19c;
char pad2[8]; Obj* o1a8;
char pad3[0x17B8-0x1AC]; int b8,bc; MuMsg* c0; int c4;
char pad4[0x18]; int e0[2];
};
extern "C" float lbl_9_rodata_94;
inline void stopAnimation(gfModelAnimation* anim, float value) { anim->m_anmObjChrRes->SetUpdateRate(value); }
extern "C" {
void fn_9_1AB0(void*,int);
void fn_9_1BE0(void*,int,int);
void fn_9_1F94(void*,int,int);
void fn_9_F2C(void*,int,int);
int fn_8004D6C4(void*,int,char*);
void fn_80078DAC(void*,int,int,int);
extern void* g_GameGlobal;
extern void* lbl_805A01D8;
extern float lbl_9_rodata_90,lbl_9_rodata_94,lbl_9_rodata_F8;
struct E { unsigned char i; unsigned long s; };
extern E lbl_9_rodata_E8[2];
void fn_9_D7C(Self* s) {
MuObject* q;
int m;
Self* it;
E* entry;
int v;
int i;
char buf[16];
m=s->bc;
s->o1a8->f34(s->o1a8->e4,*(int*)((char*)s->o40[0]+0x10));
fn_9_1AB0(s,m);
s->o1a8->f34(s->o1a8->e4,s->a198);
fn_9_1BE0(s,s->b8,m);
s->o1a8->f34(s->o1a8->e4,s->a19c);
fn_9_1F94(s,s->b8,m);
entry=lbl_9_rodata_E8;
it=s;
for(i=0;i<2;i++,it=(Self*)((char*)it+4),entry++) {
v=it->e0[0];
if(v>=0) {
s->o40[entry->i]->setFrameVisible(lbl_9_rodata_90);
fn_8004D6C4(g_GameGlobal,v,buf);
s->c0->printf(entry->s,buf);
}
}
fn_9_F2C(s,0,1);
if(s->bc==1) fn_9_F2C(s,1,1);
q=s->o40[2];
q->setFrameNode(lbl_9_rodata_F8);
stopAnimation(q->m_modelAnim, lbl_9_rodata_94);
s->c4=0;
fn_80078DAC(lbl_805A01D8,0x2a,0,0);
}
}