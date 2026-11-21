#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <new>
#pragma use_simple_stdpnew on
#pragma force_active on

class Obj {
public:
virtual int slot0();
virtual int slot1(void*);
virtual int slot2();
virtual int slot3(int,void*);
virtual int slot4(int);
virtual int slot5();
virtual int slot6(void*,int);
virtual int slot7();
virtual int slot8(int);
virtual int slot9(void*);
virtual int slot10();
virtual int slot11();
virtual int slot12();
virtual int slot13();
virtual int slot14();
virtual int slot15();
virtual int slot16();
virtual int slot17();
virtual float slot18();
virtual int slot19();
virtual int slot20();
virtual int slot21();
virtual int slot22();
virtual int slot23();
virtual int slot24();
virtual int slot25(int);
virtual int slot26();
virtual int slot27();
virtual int slot28(void*,int);
virtual int slot29();
virtual int slot30();
virtual int slot31();
virtual int slot32();
virtual int slot33(void*);
};
class Reg {
public:
virtual int slot0();
virtual void add(void*, short*);
};
struct Obj8 { int a, b; };
struct ObjOff : Obj8 {
virtual int s0(); virtual int s1(); virtual int s2(); virtual int s3(); virtual int s4();
virtual int s5(); virtual int s6(); virtual int s7(); virtual int s8(); virtual int s9();
virtual int s10(); virtual int s11(); virtual int s12(); virtual int s13(); virtual int s14();
virtual int s15(); virtual int s16(); virtual int s17(); virtual int s18(); virtual int s19();
virtual int s20(); virtual int s21(); virtual int s22(); virtual int s23(); virtual int s24();
virtual void s25(int);
};
class BuildCalls {
public:
virtual int slot0();
virtual int slot1();
virtual u8 slot2();
virtual int slot3();
virtual int slot4();
virtual int slot5();
virtual int slot6();
virtual int slot7();
virtual int slot8();
virtual int slot9();
virtual int slot10();
virtual int slot11();
virtual int slot12();
virtual int slot13();
virtual int slot14();
virtual int slot15();
virtual int slot16();
virtual int slot17();
virtual float slot18();
virtual int slot19();
virtual u8 slot20();
virtual int slot21();
virtual int slot22();
virtual int slot23();
virtual int slot24();
virtual int slot25();
virtual int slot26();
virtual int slot27();
virtual int slot28();
virtual int slot29();
virtual int slot30();
virtual int slot31();
virtual float slot32();
virtual int slot33();
virtual void* slot34(int,int);
};
extern "C" {
soModuleAccesser* __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(soModuleAccesser*,StageObject*,soResourceModule*,soModelModule*,soMotionModule*,soPostureModule*,soGroundModule*,soSituationModule*,void*,soCollisionAttackModule*,soCollisionHitModule*,soCollisionShieldModule*,soCollisionShieldModule*,soCollisionShieldModule*,void*,soCollisionSearchModule*,soDamageModule*,void*,void*,soStopModule*,void*,void*,soSoundModule*,soLinkModule*,soVisibilityModule*,soControllerModule*,soCameraModule*,soWorkManageModule*,void*,soAnimCmdModule*,soStatusModule*,void*,void*,soKineticModule*,soEventManageModule*,void*,soEffectModule*,void*,soAreaModule*,void*,void*,void*,void*,soShadowModule*,soItemManageModule*,soColorBlendModule*,void*,void*,soSlowModule*,void*,void*,soParamCustomizeModule*,void*);
void* __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(void*,Heaps::HeapType,Heaps::HeapType,Heaps::HeapType,s32);
ftFighterBuildData* __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(ftFighterBuildData*,s32,ftKind,Heaps::HeapType,Heaps::HeapType,Heaps::HeapType,u8,soModuleAccesser*,s32,void*,void*);
extern char lbl_118_data_608[];
extern char lbl_118_data_120[];
extern char lbl_118_data_1478[];
extern char lbl_118_data_14F8[];
extern char lbl_118_data_1600[];
extern char lbl_118_data_16A8[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_897C[];
extern char lbl_118_bss_254[];
extern char lbl_118_bss_264[];
extern char lbl_118_bss_274[];
extern char lbl_118_bss_284[];
extern char lbl_118_bss_294[];
extern char lbl_118_bss_2A4[];
extern char lbl_118_bss_2B4[];
extern char lbl_118_bss_2C4[];
extern char lbl_118_bss_2D4[];
extern char lbl_118_bss_2E4[];
extern char lbl_118_bss_2F4[];
extern char lbl_118_bss_304[];
extern char lbl_118_bss_314[];
extern char lbl_118_bss_324[];
extern const float lbl_118_rodata_0;
extern const float lbl_118_rodata_4;
void fn_27_1257EC(void*,int,int,int,void*);
void fn_118_6D0C(void*);
void fn_118_D5B0(void*,void*);
void fn_118_7060(void*,int,int,u8,void*);
void* fn_118_70C8(void*,soModuleAccesser*,float,void*,soEventObserverRegistrationDesc*);
void fn_118_7150(void*,void*,int);
void fn_118_7324(void*,void*,void*);
void fn_118_7394(void*,void*,int);
void fn_27_3513C(void*,short,void*,void*);
void fn_118_6C40(void*,int,void*);
void fn_118_73F8(void*,void*,int,u8,void*);
void fn_118_74BC(void*,void*,int,u8,void*);
void fn_118_7580(void*,void*,int,u8);
void fn_118_7654(void*,void*,int,u8);
void fn_118_7728(void*,void*,int,u8,void*);
void fn_118_77C0(void*,void*,void*);
void fn_27_64C8C(void*,void*,int);
void fn_27_65EE4(void*,void*);
void fn_27_154088(void*,void*);
void fn_27_693F4(void*,void*);
void fn_118_782C(void*,void*,int);
void fn_118_7888(void*,void*,int,void*);
void fn_118_7918(void*,void*);
void fn_27_5B248(void*,void*,int,int);
void fn_118_796C(void*,void*,short);
void fn_118_79DC(void*,void*,int,int,void*);
void fn_27_A1DA4(void*,void*,int);
void fn_118_7A48(void*,short);
void fn_118_7A8C(void*,void*,int,int);
void fn_118_7F44(void*,void*);
void fn_118_8314(void*);
void fn_118_8374(void*,void*);
void fn_118_8570(void*,void*,int,int,int,int,void*);
void fn_27_14FBD8(void*,void*);
void fn_118_863C(void*,void*,u8,void*);
void fn_118_86D4(void*,void*,int);
void fn_27_ACAC4(void*,void*,int,int,u8,float);
void fn_27_B62E4(void*,void*,float,int);
void fn_118_8734(void*,void*,int);
void fn_27_BEBB4(void*,void*,int,int);
void fn_27_C20D8(void*,void*,int,int,int);
void fn_27_196664(void*,void*);
void fn_27_5BED0(void*,void*);
void fn_27_14CCEC(void*,void*);
void fn_27_C74BC(void*,int,int);
void fn_27_1A65CC(void*,int);
void fn_27_D22D0(void*,int);
void* fn_118_895C();
void fn_118_87B0(void*,void*,void*,void*);
void fn_118_87CC(void*,short,void*,int,int,float,signed char*);
void fn_118_89CC(void*,void*,int);
void fn_27_C7744(void*,void*,int);
void fn_27_1A079C(void*,int);
void* fn_118_8A48(void*,int);
void fn_118_8A84(void*,int,void*);
void* __dynamic_cast(void*,long,const void*,const void*,short);
void fn_27_14E0B8(void*,void*);
void fn_27_1404D4(void*,void*);
void fn_118_6C2C(void*,int);
void fn_27_17437C(void*,void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
}
#define PTR(p,o) (*(void**)((char*)(p)+(o)))
#define INT(p,o) (*(int*)((char*)(p)+(o)))
#define UINT(p,o) (*(u32*)((char*)(p)+(o)))
#define OBJ(p,o) ((Obj*)((char*)(p)+(o)))
inline int eventId(char* m) {
 return OBJ(PTR(PTR(m,0xaa8),0x80),8)->slot7();
}
struct SlopeStorage {
 SlopeStorage(void* accesser, u8 initial, int count, float angle) {
  fn_27_ACAC4(this,accesser,initial,count,initial,angle);
 }
};
struct ShadowStorage {
 ShadowStorage(void* accesser,int mode,const float* opacity) {
  fn_27_B62E4(this,accesser,*opacity,mode);
 }
};
struct ColorStorage {
 ColorStorage(void* accesser,int count,int enabled) {
  fn_27_BEBB4(this,accesser,count,enabled);
 }
};
struct JostleStorage {
 JostleStorage(void* accesser,int id,int count,int data) {
  fn_27_C20D8(this,accesser,id,count,data);
 }
};
inline void setAnim(void* anim, int i, void* v, int flag) {
 fn_118_89CC(fn_118_8A48(anim, i), v, flag);
}
template <char* Table>
struct ActionLeafStorage {
 ActionLeafStorage(soModuleAccesser* accesser) {
  fn_27_17437C(this,accesser);
  PTR(this,0)=Table;
  PTR(this,4)=Table+0x40;
 }
};
#define REG ((Reg*)PTR(PTR(m,0xaa8),0x6c))
#define PART(i,off,kind,val,part,decl) { \
 b->slot34(i,2); b->slot34(i,1); \
 decl; \
 fn_27_C7744(part=anim+off,b->slot34(i,0),kind); \
 fn_27_D22D0(part+0x14,0); \
 fn_118_87B0(part+0xc0,part,lbl_27_bss_D8C,lbl_27_bss_D8C); \
 flag##i=0; \
 fn_118_87CC(part+0xdc,eventId(m),part+0x14,i,1,lbl_118_rodata_4,&flag##i); \
 value##i=val; pair##i[0]=part+0xdc; pair##i[1]=part+0xc0; \
 REG->add(pair##i,&value##i); }
extern "C" void* fn_118_70(char* s,int entry,int heap,int modelHeap,int motionHeap) {
 char* listeners;
 char* g;
 void* constant;
 char* extraCommand;
 char* anim;
 fn_27_1257EC(s,entry,0x21,heap,s+0xb64);
 PTR(s,0x3c)=lbl_118_data_608+0x0;
 PTR(s,0x40)=lbl_118_data_608+0x64;
 PTR(s,0x48)=lbl_118_data_608+0x70;
 PTR(s,0x54)=lbl_118_data_608+0x84;
 PTR(s,0x64)=lbl_118_data_608+0xdc;
 PTR(s,0x70)=lbl_118_data_608+0xec;
 PTR(s,0x7c)=lbl_118_data_608+0xfc;
 PTR(s,0x88)=lbl_118_data_608+0x110;
 PTR(s,0x94)=lbl_118_data_608+0x128;
 PTR(s,0xa0)=lbl_118_data_608+0x140;
 PTR(s,0xac)=lbl_118_data_608+0x158;
 PTR(s,0xb8)=lbl_118_data_608+0x16c;
 PTR(s,0xc4)=lbl_118_data_608+0x180;
 PTR(s,0xd0)=lbl_118_data_608+0x190;
 PTR(s,0xdc)=lbl_118_data_608+0x1c4;
 PTR(s,0xe8)=lbl_118_data_608+0x1d4;
 PTR(s,0xf4)=lbl_118_data_608+0x1e8;
 PTR(s,0x100)=lbl_118_data_608+0x254;
 char buildStorage[sizeof(ftFighterBuildData)];
 __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv((ftFighterBuildData*)buildStorage,entry,(ftKind)0x21,(Heaps::HeapType)heap,(Heaps::HeapType)modelHeap,(Heaps::HeapType)motionHeap,0,(soModuleAccesser*)PTR(s,0x60),-1,s+0x10524,s+0x1052c);
#define build ((ftFighterBuildData*)buildStorage)
#define b ((BuildCalls*)buildStorage)
 char* m=s+0x194;
 fn_118_6D0C(m);
 __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv((soModuleAccesser*)(m+0x9d0),(StageObject*)s,
 (soResourceModule*)(m+0x1168),
 (soModelModule*)(m+0x1374),
 (soMotionModule*)(m+0x1664),
 (soPostureModule*)(m+0x1810),
 (soGroundModule*)(m+0x18d8),
 (soSituationModule*)(m+0x1930),
 (m+0x199c),
 (soCollisionAttackModule*)(m+0x1ffc),
 (soCollisionHitModule*)(m+0x2990),
 (soCollisionShieldModule*)(m+0x2d4c),
 (soCollisionShieldModule*)(m+0x37b4),
 (soCollisionShieldModule*)(lbl_27_bss_3AC),
 (m+0x3988),
 (soCollisionSearchModule*)(lbl_27_bss_3CC),
 (soDamageModule*)(m+0x3b1c),
 (m+0x3c20),
 (m+0x3c84),
 (soStopModule*)(m+0x3cb8),
 (m+0x3cdc),
 (m+0x3d90),
 (soSoundModule*)(m+0x3dc0),
 (soLinkModule*)(m+0x3f60),
 (soVisibilityModule*)(m+0x3fb4),
 (soControllerModule*)(m+0x459c),
 (soCameraModule*)(m+0x4758),
 (soWorkManageModule*)(m+0x477c),
 (lbl_27_bss_4BC),
 (soAnimCmdModule*)(m+0x47b0),
 (soStatusModule*)(m+0x5688),
 (lbl_27_bss_46C0),
 (lbl_27_bss_46D8),
 (soKineticModule*)(m+0x5738),
 (soEventManageModule*)(m+0xb8),
 (m+0xdc04),
 (soEffectModule*)(m+0xdcac),
 (m+0xdde4),
 (soAreaModule*)(m+0xde24),
 (lbl_27_bss_5B0),
 (lbl_27_bss_5D8),
 (m+0xe204),
 (m+0xe24c),
 (soShadowModule*)(m+0xe2cc),
 (soItemManageModule*)(m+0xe3b8),
 (soColorBlendModule*)(m+0xe424),
 (m+0xe578),
 (m+0xe5c4),
 (soSlowModule*)(m+0xe62c),
 (lbl_27_bss_69C),
 (m+0xab0),
 (soParamCustomizeModule*)(m+0xac8),
 (m+0xe668));
 modelHeap=b->slot30();
 char* partEight=(char*)b->slot29();
 char* partOne=(char*)b->slot28();
 Heaps::HeapType inst=(Heaps::HeapType)b->slot27();
 __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(m+0xab0,inst,(Heaps::HeapType)(long)partOne,(Heaps::HeapType)(long)partEight,modelHeap);
 fn_118_D5B0(m+0xac8,m+0x9d0);
 fn_118_7060(m+0x115c,b->slot0(),b->slot1(),b->slot2(),m+0x9d0);
 partEight=(char*)b->slot24();
 float scale=b->slot18();
 fn_118_70C8(m+0x1180,(soModuleAccesser*)(m+0x9d0),scale,partEight,(soEventObserverRegistrationDesc*)lbl_27_bss_A48);
 fn_118_7150(m+0x1440,m+0x9d0,b->slot4());
 fn_118_7324(m+0x17d4,m+0x9d0,lbl_27_bss_A48);
 fn_118_7394(m+0x1888,m+0x9d0,b->slot8());
 fn_27_3513C(m+0x1930,eventId(m),m+0x9d0,lbl_27_bss_A48);
 fn_118_6C40(m+0x196c,b->slot3(),m+0x9d0);
 fn_118_73F8(m+0x19e0,m+0x9d0,INT(s,0x28),(u8)(UINT(s,0x2c)>>7),lbl_27_bss_A48);
 fn_118_74BC(m+0x209c,m+0x9d0,INT(s,0x28),(u8)(UINT(s,0x2c)>>7),lbl_27_bss_A48);
 fn_118_7580(m+0x29f8,m+0x9d0,INT(s,0x28),(u8)(UINT(s,0x2c)>>7));
 fn_118_7654(m+0x2da0,m+0x9d0,INT(s,0x28),(u8)(UINT(s,0x2c)>>7));
 fn_118_7728(m+0x380c,m+0x9d0,INT(s,0x28),(u8)(UINT(s,0x2c)>>7),lbl_27_bss_A48);
 fn_118_77C0(m+0x3a70,m+0x9d0,lbl_27_bss_A48);
 fn_27_64C8C(m+0x3c20,m+0x9d0,1);
 fn_27_65EE4(m+0x3c84,m+0x9d0);
 fn_27_154088(m+0x3cb8,m+0x9d0);
 fn_27_693F4(m+0x3cdc,m+0x9d0);
 fn_118_782C(m+0x3d14,m+0x9d0,b->slot5());
 fn_118_7888(m+0x3dac,m+0x9d0,b->slot31(),lbl_27_bss_A48);
 fn_118_7918(m+0x3e1c,m+0x9d0);
 fn_27_5B248(m+0x3fb4,m+0x9d0,b->slot6(),2);
 fn_118_796C(m+0x3fe4,m+0x9d0,eventId(m));
 fn_118_79DC(m+0x4708,m+0x9d0,b->slot21(),b->slot22(),lbl_27_bss_A48);
 fn_27_A1DA4(m+0x477c,m+0x9d0,b->slot19());
 fn_118_7A48(m+0x47b0,eventId(m));
 fn_118_7A8C(m+0x48a4,m+0x9d0,b->slot7(),b->slot26());
 fn_118_7F44(m+0x5738,m+0x9d0);
 fn_118_8314(m+0x5a40);
 fn_118_8374(m+0x5c24,m+0x9d0);
 fn_118_8570(m+0xdc40,m+0x9d0,b->slot9(),b->slot10(),b->slot11(),b->slot12(),lbl_27_bss_A48);
 fn_27_14FBD8(m+0xdde4,m+0x9d0);
 fn_118_863C(m+0xde14,m+0x9d0,b->slot20(),lbl_27_bss_A48);
 b->slot14(); b->slot13(); b->slot15();
 fn_118_86D4(m+0xe188,m+0x9d0,b->slot16());
 new (m+0xe24c) SlopeStorage(m+0x9d0,0,1,b->slot32());
 new (m+0xe2cc) ShadowStorage(m+0x9d0,0,&lbl_118_rodata_0);
 fn_118_8734(m+0xe314,m+0x9d0,b->slot23());
 new (m+0xe424) ColorStorage(m+0x9d0,10,1);
 new (m+0xe578) JostleStorage(m+0x9d0,0,8,b->slot25());
 fn_27_196664(m+0xe5c4,m+0x9d0);
 fn_27_5BED0(m+0xe62c,m+0x9d0);
 fn_27_14CCEC(m+0xe668,m+0x9d0);
 if(OBJ(m,0x5c00)->slot0()==0)
  OBJ(PTR(PTR(m,0xaa8),0x64),0)->slot3(1,m+0x5c00);
 fn_27_C74BC(m+0xe7e8,INT(PTR(buildStorage,0xc),0x18),0x13);
 anim=m+0xe7f8;
 fn_27_1A65CC(anim,0);
 fn_27_1A65CC(anim+0x4a0,0);
 fn_27_D22D0(anim+0x944,0);
 fn_118_87B0(anim+0x9f0,anim,anim+0x4a0,fn_118_895C());
 signed char flag10,flag9,flag8,flag7,flag6,flag5,flag4,flag3,flag2,flag1,flag0;
 short value10,value9,value8,value7,value6,value5,value4,value3,value2,value1,value0;
 void* pair10[2]; void* pair9[2]; void* pair8[2]; void* pair7[2]; void* pair6[2]; void* pair5[2]; void* pair4[2]; void* pair3[2]; void* pair2[2]; void* pair1[2]; void* pair0[2];
 {
 flag0=0;
 fn_118_87CC(anim+0xa0c,eventId(m),anim+0x944,0,1,lbl_118_rodata_4,&flag0);
 fn_118_89CC(anim,0,0x125);
 fn_118_89CC(anim+0x4a0,0,0x125);
 fn_118_89CC(fn_118_895C(),0,0);
 value0=1; pair0[0]=anim+0xa0c; pair0[1]=anim+0x9f0;
 REG->add(pair0,&value0);
 }
 PART(1,0xa5c,0x1eb,2,partOne,)
 PART(2,0xb88,0x1eb,0x40,part,char* part)
 PART(3,0xcb4,0x1eb,0x40,part,char* part)
 PART(4,0xde0,0x1eb,2,part,char* part)
 PART(5,0xf0c,0x1eb,0x20,part,char* part)
 PART(6,0x1038,0x1eb,0x80,part,char* part)
 PART(7,0x1164,0x1eb,0x80,part,char* part)
 PART(8,0x1290,0x1eb,0x20,partEight,)
 {
 extraCommand=anim+0x13bc;
 char* part=extraCommand;
 flag9=1;
 int value=eventId(m);
 fn_118_87CC(part,(short)value,part+0x50,9,1,lbl_118_rodata_4,&flag9);
 fn_27_1A079C(part+0x50,0);
 value9=4; pair9[0]=part; pair9[1]=lbl_27_bss_8C4;
 REG->add(pair9,&value9);
 }
 PART(10,0x14e0,0x29,0x10,extraCommand,)
 setAnim(anim,0,b->slot34(0,0),0x112);
 setAnim(anim,1,b->slot34(0,1),0x112);
 setAnim(anim,0,PTR(PTR(buildStorage,0xc),0x24),0x13);
 setAnim(anim,1,PTR(PTR(buildStorage,0xc),0x28),0x13);
 fn_118_8A84(anim,0,build->getAnimCmdDisguiseList(false,0));
 fn_118_8A84(anim,1,build->getAnimCmdDisguiseList(false,1));
 OBJ(PTR(PTR(m,0xaa8),0x70),0)->slot33(m+0xe7e8);
 constant = soValueAccesser::getConstantIndefinite((soModuleAccesser*)(m+0x9d0),0xa805,0);
 void* param=__dynamic_cast(PTR(PTR(m,0xaa8),0x90),0,lbl_118_data_1600,lbl_118_data_16A8,0);
 if(param) fn_27_14E0B8(param,constant);
 OBJ(PTR(PTR(m,0xaa8),0x90),0)->slot9(constant);
 fn_27_1404D4(s+0xff98,PTR(s,0x60));
 g = s+0xffd4;
 fn_118_6C2C(g,0);
 PTR(g,0)=lbl_118_data_1478;
 m=(char*)PTR(s,0x60);
 heap=(int)(s+0x1048c);
 listeners = (char*)heap;
 fn_118_6C2C(listeners,0);
 PTR(listeners,0)=lbl_118_data_14F8;
 new (listeners+0x8) ActionLeafStorage<lbl_27_data_2F9F8>((soModuleAccesser*)m);
 new (listeners+0x20) ActionLeafStorage<lbl_27_data_2FAA0>((soModuleAccesser*)m);
 new (listeners+0x34) ActionLeafStorage<lbl_27_data_2FB48>((soModuleAccesser*)m);
 new (listeners+0x48) ActionLeafStorage<lbl_27_data_2FBF0>((soModuleAccesser*)m);
 new (listeners+0x5c) ActionLeafStorage<lbl_27_data_2FC98>((soModuleAccesser*)m);
 new (listeners+0x70) ActionLeafStorage<lbl_27_data_2FD40>((soModuleAccesser*)m);
 new (listeners+0x84) ActionLeafStorage<lbl_27_data_2FDE8>((soModuleAccesser*)m);
 PTR(s,0x10524)=soValueAccesser::getConstantIndefinite((soModuleAccesser*)PTR(s,0x60),0xa7f9,0);
 INT(s,0x10528)=1;
 PTR(s,0x1052c)=soValueAccesser::getConstantIndefinite((soModuleAccesser*)PTR(s,0x60),0xa7fc,0);
 INT(s,0x10530)=1;
 fn_27_126470(s);
 OBJ(s,0xff98)->slot1(PTR(s,0x60));
 PTR(s,0x3c)=lbl_118_data_120+0x0;
 PTR(s,0x40)=lbl_118_data_120+0x64;
 PTR(s,0x48)=lbl_118_data_120+0x70;
 PTR(s,0x54)=lbl_118_data_120+0x84;
 PTR(s,0x64)=lbl_118_data_120+0xdc;
 PTR(s,0x70)=lbl_118_data_120+0xec;
 PTR(s,0x7c)=lbl_118_data_120+0xfc;
 PTR(s,0x88)=lbl_118_data_120+0x110;
 PTR(s,0x94)=lbl_118_data_120+0x128;
 PTR(s,0xa0)=lbl_118_data_120+0x140;
 PTR(s,0xac)=lbl_118_data_120+0x158;
 PTR(s,0xb8)=lbl_118_data_120+0x16c;
 PTR(s,0xc4)=lbl_118_data_120+0x180;
 PTR(s,0xd0)=lbl_118_data_120+0x190;
 PTR(s,0xdc)=lbl_118_data_120+0x1c4;
 PTR(s,0xe8)=lbl_118_data_120+0x1d4;
 PTR(s,0xf4)=lbl_118_data_120+0x1e8;
 PTR(s,0x100)=lbl_118_data_120+0x254;
 fn_27_C749C(s+0x10534);
 PTR(s,0x10544)=g_ftCommonDataAccesser.getData((ftKind)0x21);
 void* list[19]={0};
 list[0]=lbl_27_bss_897C;
 list[1]=lbl_118_bss_254;
 list[2]=lbl_118_bss_274;
 list[3]=lbl_118_bss_2B4;
 list[4]=lbl_118_bss_2E4;
 list[5]=lbl_27_bss_897C;
 list[6]=lbl_27_bss_897C;
 list[7]=lbl_27_bss_897C;
 list[8]=lbl_118_bss_264;
 list[9]=lbl_118_bss_284;
 list[10]=lbl_118_bss_294;
 list[11]=lbl_118_bss_2A4;
 list[12]=lbl_118_bss_2C4;
 list[13]=lbl_118_bss_2D4;
 list[15]=lbl_118_bss_2F4;
 list[16]=lbl_118_bss_304;
 list[17]=lbl_118_bss_314;
 list[18]=lbl_118_bss_324;
 OBJ(PTR(PTR(PTR(s,0x60),0xd8),0x70),0)->slot28(list,0x13);
 OBJ(PTR(PTR(PTR(s,0x60),0xd8),0x24),0)->slot6(PTR(*(void**)((unsigned long)s+0x10544),0x9c),1);
 ((ObjOff*)PTR(PTR(PTR(s,0x60),0xd8),0x9c))->s25(0x13);
 return s;
}
