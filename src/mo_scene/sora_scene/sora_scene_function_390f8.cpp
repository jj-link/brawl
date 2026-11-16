#include <types.h>
#include <gm/gm_global.h>
#pragma force_active on

struct FlagsA {
    u8 f8 : 6; u8 f8low : 2;
    u8 f9top : 3; u8 f9mid : 3; u8 f9x : 1; u8 f9last : 1;
    u8 fa0 : 1; u8 fa1 : 5; u8 fa6 : 1; u8 fa7 : 1;
    u8 fb0 : 5; u8 fb5 : 1; u8 fb6 : 2;
    u8 fc0 : 1; u8 fc1 : 6; u8 fc7 : 1;
};
struct Mode {
    u8 pad[8];
    FlagsA flags;
    u8 pad0d[6];
    u8 f13;
    u8 f14;
    u8 pad15;
    u8 f16;
    u8 pad17[3];
    u16 f1a;
    u8 f1c[4];
    int f20;
};
struct Corps { u8 a,b,c,d,e; u8 f0:1; u8 f1:1; u8 f2:6; };
struct FlagByte { u8 a:1; u8 b:1; u8 c:6; };
struct PlayerFlag { u8 a:2; u8 b:1; u8 c:5; };
struct HighFlag { u8 a:1; u8 b:7; };
struct Pair { u32 a, b; };
extern "C" {
extern int g_muWifiInterfaceTask;
extern char lbl_1_data_8FB8[], lbl_1_data_8FD8[];
void fn_8005033C(void*);
int fn_800CB82C(int);
u8* fn_800D89DC(int, u8*);
int fn_800CBC4C(int);
u64 fn_800D9964(int);
u8* fn_800CB834(int);
u8 fn_800CB0D8(int,int);
int fn_800CB8F0(int,int);
u8 fn_800CB4AC(int,int);
int fn_800CB568(int,int);
u8 fn_800CB250(int,int);
void fn_800D3270(int,int,u16*,u8*);
void fn_800D2C50(int,u8,u16*);
u8 fn_800D81AC(int,int,u8*);
void OSReport(const char*, ...);
int exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(int);
int getFighterColorFileNo__6muMenuFiii(int,int);
void fn_8010F960(u16,void*,void*,int);
void fn_1_32F8();
void fn_1_3D2D8();
}
static inline void setMode(Mode* mode, int kind, int time, bool flag1, bool flag2) {
    mode->f14 = kind;
    mode->f20 = time;
    mode->flags.fa0 = flag1;
    mode->flags.fa6 = flag2;
    mode->flags.f9last = flag2;
    mode->flags.fb5 = 0;
    mode->flags.fc0 = 0;
    mode->flags.fc7 = 0;
}
extern "C" void fn_1_390F8() {
    int var0;
    u8 buf[2];
    Mode* mode = (Mode*)g_GameGlobal->m_modeMelee;
    Corps* corps = (Corps*)g_GameGlobal->m_corps;
    u8* cursor;
    HighFlag* p24;
    u8* p23;
    u16* p22;
    PlayerFlag* p21;
    int var20;
    fn_8005033C(mode);
    int rule = fn_800CB82C(g_muWifiInterfaceTask);
    var0 = 0;
    switch (rule) {
    case 0: setMode(mode,5,0,1,1); var0 = 10; var20 = 0x27ed; break;
    case 1: setMode(mode,6,0,1,1); var0 = 100; var20 = 0x27ee; break;
    case 2: setMode(mode,7,0x2a30,1,0); var20 = 0x26fc; break;
    case 3: setMode(mode,8,0xd2f0,1,0); var20 = 0x27ee; break;
    case 4: setMode(mode,9,0,0,0); var20 = 0x26fc; break;
    case 5: setMode(mode,10,0,0,0); var20 = 0x2709; break;
    }
    mode->flags.f8 = 0x10;
    mode->flags.f9top = 1;
    mode->f13 = 1;
    mode->flags.f9mid = 2;
    mode->f1a = 1;
    corps->a = 2;
    corps->b = 0;
    corps->c = 5;
    corps->d = var0;
    corps->e = 2;
    corps->f0 = 0;
    corps->f1 = 1;
    u8* base = (u8*)mode;
    u8* info = fn_800D89DC(g_muWifiInterfaceTask, &buf[1]);
    *(int*)(base+0x38) = *(int*)(info+8);
    *(int*)(base+0x3c) = *(int*)(info+12);
    *(u64*)(base+0x30) = *(u64*)info;
    ((FlagByte*)(base+0x62))->b = fn_800CBC4C(g_muWifiInterfaceTask);
    ((FlagByte*)(base+0x62))->a = 1;
    mode->f16 = 2;
    u64 t = fn_800D9964(g_muWifiInterfaceTask);
    *(u32*)(base+0x44) = (u32)t;
    *(u32*)(base+0x40) = (u32)(t >> 32);
    info = fn_800CB834(g_muWifiInterfaceTask);
    base[0x60] = info[0x20];
    base[0x61] = info[0x21];
    cursor = base;
    p24 = (HighFlag*)(base+0xb3);
    p23 = base+0xb0;
    p22 = (u16*)(base+0xa4);
    p21 = (PlayerFlag*)(base+0xb4);
    int task = g_muWifiInterfaceTask;
    for (int i=0;i<7;i++) {
        if (i<2) {
            u8 v=fn_800CB0D8(task,i);
            cursor[0x99]=v;
            if (v==5) {
                OSReport(lbl_1_data_8FB8,i,v);
                cursor[0x99]=3;
            } else if (v==3) {
                OSReport(lbl_1_data_8FB8,i,v);
            } else {
                OSReport(lbl_1_data_8FD8,i,cursor[0x99],fn_800CB8F0(task,i));
                cursor[0x98]=fn_800CB4AC(task,i);
                u8 color=fn_800CB568(task,i);
                int kind=exchangeGmCharacterKind2MuSelchkind__6muMenuFiii(cursor[0x98]);
                int file;
                if (kind==0x28) file=0;
                else file=getFighterColorFileNo__6muMenuFiii(kind,color);
                cursor[0x9d]=file;
                cursor[0x9e]=fn_800CB568(task,i);
                cursor[0x9a]=fn_800CB8F0(task,i);
                cursor[0xa0]=i;
                cursor[0x9f]=fn_800CB250(task,i);
                cursor[0x9c]=1;
                cursor[0xa3]=0;
                p24->a = 0;
                fn_800D3270(task,fn_800CB8F0(task,i),p22,p23);
                if (*(u16*)(cursor+0xa4)==0)
                    fn_800D2C50(task,fn_800D81AC(task,fn_800CB8F0(task,i),buf),p22);
                if (*(u16*)(cursor+0xa4)==0) p21->b=0;
                else p21->b=1;
            }
        } else {
            cursor[0x99]=3;
            cursor[0x9c]=0;
            p24->a = 1;
            cursor[0xa0]=0;
        }
        cursor+=0x5c;
        p24=(HighFlag*)((u8*)p24+0x5c); p23+=0x5c; p22=(u16*)((u8*)p22+0x5c);
        p21=(PlayerFlag*)((u8*)p21+0x5c);
    }
    mode->flags.f9mid=2;
    fn_8010F960(mode->f1a,base+0x1c,base+0x5c,var20);
    fn_1_32F8();
    fn_1_3D2D8();
}