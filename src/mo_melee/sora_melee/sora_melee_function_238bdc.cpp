#pragma force_active on
#include <types.h>
#include <mt/mt_prng.h>
#include <so/so_world.h>
#include <gf/gf_3d_scene.h>
#include <ef/ef_screen.h>
extern "C" {
void __ct__15stCommonGimmickFPCcQ26Stages11srStageKind(void*, const char*, int);
extern char lbl_27_data_4CA48[];
extern char lbl_27_bss_58F0[];
extern const float lbl_27_rodata_3930;
extern const float lbl_27_rodata_3934;
extern char* g_GameGlobal;
}
struct SceneFlags { unsigned char high:1; unsigned char copy:1; unsigned char low:6; };
struct stMelee {
char pad0[0x3C]; char* unk3C; char pad40[0x160];
int unk1A0, unk1A4, unk1A8;
unsigned char unk1AC, unk1AD; char pad1AE[6];
int unk1B4, unk1B8, unk1BC, unk1C0, unk1C4, unk1C8, unk1CC;
float unk1D0, unk1D4;
};
extern "C" stMelee* __ct__7stMeleeFPCcQ26Stages11srStageKind(stMelee* self, const char* name, int kind) {
__ct__15stCommonGimmickFPCcQ26Stages11srStageKind(self,name,kind);
self->unk3C=lbl_27_data_4CA48;
self->unk1D0=lbl_27_rodata_3930;
self->unk1D4=lbl_27_rodata_3930;
self->unk1AC=0; self->unk1A0=0; self->unk1A4=0; self->unk1A8=0;
self->unk1AD=0; self->unk1C4=0; self->unk1C8=0;
self->unk1B4=0; self->unk1B8=1; self->unk1BC=2; self->unk1C0=3;
unsigned char* st=*(unsigned char**)(g_GameGlobal+8);
unsigned int t=(st[8]>>2)&0x3F;
switch(t) {
case 0: case 1: case 14: case 23: case 24: case 28: case 33: {
int var=0;
if(st[0x99]!=3) var=1;
if(st[0xF5]!=3) var+=1;
if(st[0x151]!=3) var+=1;
if(st[0x1AD]!=3) var+=1;
unsigned int ia,m;
int n=var-1;
int k=3;
if(n<=3) k=n;
if(k>0) {
m=(unsigned int)(k+1);
for(int cnt=0;cnt<0x20;cnt++) {
ia=(unsigned int)randi(m);
if(ia>=(unsigned int)k) ia=(unsigned int)k;
unsigned int ib=(unsigned int)randi(m);
if(ib>=(unsigned int)k) ib=(unsigned int)k;
char* pa=(char*)self+ia*4;
char* pb=(char*)self+ib*4;
int tmp=*(int*)(pa+0x1B4);
*(int*)(pa+0x1B4)=*(int*)(pb+0x1B4);
*(int*)(pb+0x1B4)=tmp;
}
}
break;
}
}
((SceneFlags*)((char*)g_gfSceneRoot+0x464))->copy=true;
g_soWorld->m_gravityUp=lbl_27_rodata_3934;
g_soWorld->m_gravityDown=lbl_27_rodata_3934;
*(void**)(lbl_27_bss_58F0+8)=self;
*(char**)((char*)g_efScreen+0x1DC)=lbl_27_bss_58F0;
self->unk1CC=0xFFFF;
return self;
}