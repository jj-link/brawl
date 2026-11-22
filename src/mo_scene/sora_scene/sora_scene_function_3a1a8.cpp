#pragma force_active on
#include <types.h>
#include <gm/gm_global.h>
#include <mu/wifi/mu_wifi_interface.h>
struct Flags { u8 top:2; u8 enabled:1; u8 bottom:5; };
struct Player { u8 character,state,playerId,playerNo; s8 stock; u8 colorFile,color,controller,startPoint,pad9[2],team; u16 name[6]; u8 nameIndex,pad19[3]; Flags flags; u8 pad1D[0x3F]; };
struct Mode { u8 pad0[9]; u8 flagTop:3; u8 count:3; u8 flagLow:2; u8 flagATop:7; u8 flagALow:1; u8 padB[0x8D]; Player players[4]; };
extern "C" {
u8 fn_800CB0D8(muWifiInterfaceTask*,int);
int fn_800CB4AC(muWifiInterfaceTask*,int);
u8 fn_800CB568(muWifiInterfaceTask*,int);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(unsigned int);
int getFighterColorFileNo__6muMenuFiii(int,int);
int fn_800CB8F0(muWifiInterfaceTask*,int);
int fn_800CB250(muWifiInterfaceTask*,int);
void fn_800D3270(muWifiInterfaceTask*,int,u16*,u8*);
u8 fn_800D81AC(muWifiInterfaceTask*,int,int*);
void fn_800D2C50(muWifiInterfaceTask*,u8,u16*);
void fn_1_3A1A8() {
int color;
Mode* mode = (Mode*)g_GameGlobal->m_modeMelee;
Mode* cursor = mode;
u8* nameIndex = &mode->players[0].nameIndex;
u16* name = mode->players[0].name;
Flags* flags = &mode->players[0].flags;
muWifiInterfaceTask* wifi = g_muWifiInterfaceTask;
int tmp;
for (int i = 0; i < 4; i++) {
cursor->players[0].state=fn_800CB0D8(wifi,i);
if (cursor->players[0].state==0) {
cursor->players[0].character=fn_800CB4AC(wifi,i);
cursor->players[0].team=0;
color=fn_800CB568(wifi,i);
int kind=exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(cursor->players[0].character);
int file;
if(kind==0x28) file=0; else file=getFighterColorFileNo__6muMenuFiii(kind,color);
cursor->players[0].colorFile=file;
cursor->players[0].color=fn_800CB568(wifi,i);
cursor->players[0].playerId=fn_800CB8F0(wifi,i);
cursor->players[0].startPoint=i;
cursor->players[0].controller=fn_800CB250(wifi,i);
cursor->players[0].stock=-1;
fn_800D3270(wifi,fn_800CB8F0(wifi,i),name,nameIndex);
if(cursor->players[0].name[0]==0) { u8 index=fn_800D81AC(wifi,fn_800CB8F0(wifi,i),&tmp); fn_800D2C50(wifi,index,name); }
if(cursor->players[0].name[0]==0) flags->enabled=0; else flags->enabled=1;
} else cursor->players[0].startPoint=0;
cursor=(Mode*)((u8*)cursor+sizeof(Player)); nameIndex+=sizeof(Player); name=(u16*)((u8*)name+sizeof(Player)); flags=(Flags*)((u8*)flags+sizeof(Player));
}
mode->flagALow = 0; mode->count=3;
}
}