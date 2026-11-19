#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gf/gf_homemenu.h>
#include <snd/snd_system.h>
#include <mu/mu_msg.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#pragma force_active on
extern "C" { extern char lbl_16_data_36C8[]; extern void* g_GameGlobal;
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*,void*,char*); void fn_16_4BD8(void*,int);
int fn_16_4C90(void*,const void*,int,const void*,int); int fn_8004D674(void*,int,void*);
void fn_8006BCA8(char*,const void*); }
namespace nf {
struct Model { virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11(); virtual void v12(); virtual void v13(); virtual void v14(int); virtual void v15(void*); char pad[0xE0]; int childCount; };
struct Resource { char pad[0x10]; void* object; };
struct Menu { char p0[0x88]; Resource*m88; char p8c[8]; Model*m94; int m98; int m9c; char pA0[4]; int mA4; Model*mA8; char pAC[0x10]; unsigned int mBC; char pC0[0x94]; MuMsg*m154; char p158[0x2AC]; int m404; char p408[4]; unsigned char m40C; char p40D; char m40E[12]; char m41A[0x32]; int m44C; unsigned char m450[4]; int m454; char p458[0x20]; int m478; };
}
struct Vec2 { float x,y; Vec2(){} Vec2(const Vec2&o){x=o.x;y=o.y;} };
struct PadCopy { int words[6]; Vec2 vectors[3]; unsigned char b0,b1,b2,b3,b4,b5,b6,b7,b8; int last; };
static inline gfPadStatus getSysPad(){gfPadStatus status;g_gfPadSystem->getSysPadStatus(0xF0,&status);return status;}
extern "C" int fn_16_5A18(nf::Menu*self){
 int idx;
 if(self->m478<0)return 0x18;
 idx=self->m454;
 if(self->mBC&8){int i;for(i=idx-1;i>=0;i--)if(self->m450[i])break;if(i>=0)idx=i;}
 if(self->mBC&4){int j;for(j=idx+1;j<3;j++)if(self->m450[j])break;if(j<3)idx=j;}
 if(idx!=*(int*)((char*)self+0x454)){g_sndSystem->playSE((SndID)0,-1,0,0,-1);self->m454=idx;fn_16_4BD8(self,idx);
 if(idx==0||self->m404<0)self->m94->v15(self->m88->object);else{char buf[28];char entry[12];
 fn_8004D674(g_GameGlobal,self->m404,entry);
 nf::Model*model=self->m94;nf::Resource*resource=self->m88;
 model->v15(resource->object);Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(model,resource->object,lbl_16_data_36C8);fn_8006BCA8(buf,entry);self->m154->printf(0xB,buf);}}
 PadCopy status(*(PadCopy*)&getSysPad());unsigned int pressed=status.words[3];
 if(pressed&0x1100){switch(idx){case 0:{g_sndSystem->playSE((SndID)1,-1,0,0,-1);int result=fn_16_4C90(self,self->m40E,!(((self->m40C>>7)&1)-1),self->m41A,0);switch(result){case -1:return 0x12;case -2:return 0x11;default:return 0x13;}}
 case 1:g_sndSystem->playSE((SndID)1,-1,0,0,-1);if(self->m44C==0||self->m44C==3)return 0x14;self->mA4=0x15;return 0xB;
 case 2:{g_gfHomeMenu->setBan(0,3);nf::Model*model=self->m94;while(model->childCount!=0){if(model->childCount!=0)model->v14(model->childCount-1);}self->mA8->v15(self->m94);g_sndSystem->playSE((SndID)2,-1,0,0,-1);return 2;}}}
 if(pressed&0x200){g_gfHomeMenu->setBan(0,3);nf::Model*model=self->m94;while(model->childCount!=0){if(model->childCount!=0)model->v14(model->childCount-1);}self->mA8->v15(self->m94);g_sndSystem->playSE((SndID)2,-1,0,0,-1);return 2;}
 return self->m9c;
}