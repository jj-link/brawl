#include <types.h>
#include <if/if_mngr.h>
#pragma force_active on
struct MenuInfo {
 u8 kind,player,slot,pad03; s8 signedValue; u8 pad05,color,pad07[4],value0B;
 u16 name[7]; u8 pad1A,flags1B,flags1C,flags1D,pad1E[4]; u16 value22,value24;
};
struct MenuBits {
 u8 pad[0x1b];
 u8 b0:1; u8 b1:1; u8 b2:1; u8 f1B_3:1; u8 f1B_4:1; u8 b5:3;
 u8 f1C_0:1; u8 f1C_1:1; u8 f1C_2:1; u8 f1C_r:5;
 u8 d0:4; u8 f1D_4:1; u8 d5:3;
};
struct Bits0C { u8 b7:1; u8 rest:7; };
struct GameInfo {
 u8 pad00[8],kind,mode,pad0A,flags0B,flags0C,flags0D,pad0E[0x55],state63,state64;
};
struct DisplayData {
 int type,player,fighter; u8 index,color; char rank; u8 pad0F;
 int status,value; u8 special,pad19[3]; int level,value0B;
 bool flag; u8 flag2,pad26[2]; u16* name; void* wifi[4];
 u8 enabled,pad3D[3]; int extra;
 DisplayData():type(0),player(0),fighter(0),index(0),color(0),rank(-1),
 status(0),value(0),special(0),level(3),value0B(0),flag(0),flag2(0),
 name(0),enabled(1),extra(0) { wifi[0]=0; wifi[1]=0; wifi[2]=0; wifi[3]=0; }
};
struct gfTask_base { char pad[0x3c]; };
class gfTask:public gfTask_base {
public:
 virtual void processDefault(); virtual void fn_27_23B5F0();
 virtual void processAnim(); virtual void processUpdate();
 virtual void processPreMapCorrection(); virtual void processMapCorrection();
 virtual void processFixPosition(); virtual void processPreCollision();
 virtual void processCollision(); virtual void processCatch();
 virtual void processHit(); virtual void processCamera();
 virtual void processFixCamera(); virtual void processEffect();
 virtual void processGameProc(); virtual void processEnd();
 virtual void renderPre(); virtual void renderOpa(); virtual void renderXlu();
 virtual void processDebug(); virtual void renderDebug(); virtual void init();
 virtual void fn_27_23B580(); virtual void fn_27_23DFC0();
 virtual void fn_27_23E394(); virtual void fn_27_23EB4C();
 virtual void fn_27_23E814(); virtual void fn_27_23E70C();
 virtual void fn_27_23C5D4(); virtual void fn_27_23C7DC();
 virtual void fn_27_23CEEC(); virtual void fn_27_23E128();
 virtual void fn_27_23D7E4(); virtual void fn_27_23DAD8();
 virtual void fn_27_23E614(); virtual void fn_27_23E65C();
 virtual void fn_27_23E6A4(); virtual MenuInfo* fn_27_23B5D8();
};
extern "C" {
extern void* g_IfAdvMngr;
extern void* g_ftManager;
extern void* g_muWifiInterfaceTask;
extern u8 lbl_1_bss_1738[];
int fn_27_10AAEC(void*,void*);
u8 fn_800D81AC(void*,int,u8*);
void fn_800D28AC(void*,u32,int,u16*);
void fn_800E08A0(void*,DisplayData*,u8);
void fn_800E3684(void*,int);
}
extern "C" void fn_27_23C7DC(void* arg0,int arg1) {
 u8* object=(u8*)arg0;
#define game (*(GameInfo**)(object+0x40))
#define objectIndex (*(u32*)(object+0x48))
 if ((u32)((game->kind>>2)&0x3f)!=0x1f && object[0x57]!=6) {
  if(g_IfMngr) {
   MenuInfo* menu=((gfTask*)arg0)->fn_27_23B5D8();
   DisplayData data;
   u16 wifiData[4][0x15];
   data.player=menu->player;
   data.fighter=fn_27_10AAEC(g_ftManager,*(void**)(object+0x4c));
   data.index=objectIndex; data.color=menu->color;
   if((u32)((game->kind>>2)&0x3f)==0x21 && data.player==1) data.player=0;
   if(((game->kind>>2)&0x3f)==0) data.status=0;
   else if((menu->flags1B>>3)&1) data.status=2;
   else if((menu->flags1B>>4)&1) data.status=1;
   else data.status=0;
   if((menu->flags1C>>7)&1) {
    data.value=menu->value24; data.special=1; data.enabled=0;
   } else {
    data.value=menu->value22; data.special=0;
    data.enabled=((u32)((game->mode>>5)&7)==1 && (u32)((game->flags0C>>7)&1)==1);
   }
   if(arg1) { u8 value=(u8)menu->signedValue; data.level=(s8)(value & ~((s8)value>>31)); }
   else data.level=0;
   data.value0B=menu->value0B;
   data.name=menu->name[0]?menu->name:0;
   if(&lbl_1_bss_1738[0]!=0 && ((lbl_1_bss_1738[0x10]>>6)&1) && menu->player==0) {
    u8 local;
    void* wifi=g_muWifiInterfaceTask;
    u8 remote=fn_800D81AC(wifi,menu->slot,&local);
    int j=0;
    for(int i=0;i<4;++i,++j) {
     fn_800D28AC(wifi,remote,i,wifiData[i]);
     data.wifi[j]=wifiData[j];
    }
   }
   if(((menu->flags1C>>5)&1) && menu->player==1 && menu->value0B==0) data.flag2=1;
   if(((game->flags0D>>2)&1) && ((u32)((game->kind>>2)&0x3f)!=0x12 || game->state63!=0 || game->state64!=0)) data.extra=1;
   if(menu->player==0 && ((((game->kind>>2)&0x3f)==0x12U) || (((game->kind>>2)&0x3f)==9U)) && game->state63==0 && game->state64==0) data.rank=0;
   u32 kind=(game->kind>>2)&0x3f;
   if(kind==0 || kind==1 || kind==0x21) {
    data.rank=0;
    for(u32 i=0;i<objectIndex;++i) {
     if(*((u8*)game+i*0x5c+0x99)!=3) ++data.rank;
    }
   } else if(kind==0x0e || kind==0x18 || kind==0x1c) {
    data.rank=0;
    for(int i=0;i<4;++i) {
     if(*((u8*)game+i*0x5c+0x99)!=3 && *((u8*)game+i*0x5c+0x9a)<*((u8*)game+objectIndex*0x5c+0x9a)) ++data.rank;
    }
   }
   data.flag=((Bits0C*)((u8*)game+0xc))->b7!=0;
   if(((game->kind>>2)&0x3f)==7U && ((menu->flags1B>>2)&1)) data.type=2;
   u8* manager=(u8*)g_IfMngr;
   fn_800E08A0(*(void**)(manager+0x4c+menu->slot*4),&data,manager[0xa8]);
   if(((game->flags0B>>1)&1)==1U) {
    manager=(u8*)g_IfMngr;
    u8 slot=*(manager+menu->slot+0x68);
    fn_800E3684(*(void**)(manager+0x4c+slot*4),4);
   }
  }
  if(g_IfAdvMngr) {
   MenuInfo* menu=((gfTask*)arg0)->fn_27_23B5D8();
   MenuBits* bits=(MenuBits*)menu;
   DisplayData data;
   data.fighter=menu->kind; data.player=menu->player; data.color=menu->color;
   if(bits->f1D_4) data.status=3;
   else if(bits->f1B_4) data.status=2;
   else if(bits->f1B_3) data.status=1;
   else data.status=0;
   if(((menu->flags1C>>5)&1) && menu->player==1 && menu->value0B==0) data.flag2=1;
   data.index=objectIndex;
   if((menu->flags1C>>7)&1) {data.value=menu->value24;data.special=1;}
   else {data.value=menu->value22;data.special=0;}
   u8 value=(u8)menu->signedValue;
   data.level=(s8)(value & ~((s8)value>>31));
   data.value0B=menu->value0B;
   data.name=menu->name[0]?menu->name:0;
   fn_800E08A0(*(void**)((u8*)g_IfAdvMngr+0xe8+objectIndex*4),&data,0);
  }
 }
#undef objectIndex
#undef game
}
