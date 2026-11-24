#pragma force_active on
#include <types.h>
#include <ft/fighter.h>
#include <so/model/so_model_module_simple.h>
#include <new>
#pragma use_simple_stdpnew on

inline void* operator new[](size_t, void* storage) {
 return storage;
}
#include <so/so_value_accesser.h>
#include <so/so_heap_module_impl.h>
#include <ft/ft_fighter_build_data.h>

extern "C" {
void __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv(ftFighterBuildData*,s32,ftKind,Heaps::HeapType,Heaps::HeapType,Heaps::HeapType,u8,soModuleAccesser*,s32,void*,void*);
void __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel(soHeapModuleImpl*,Heaps::HeapType,Heaps::HeapType,Heaps::HeapType,s32);
void __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(soModuleAccesser*,StageObject*,soResourceModule*,soModelModule*,soMotionModule*,soPostureModule*,soGroundModule*,soSituationModule*,void*,soCollisionAttackModule*,soCollisionHitModule*,soCollisionShieldModule*,soCollisionShieldModule*,soCollisionShieldModule*,void*,soCollisionSearchModule*,soDamageModule*,void*,void*,soStopModule*,void*,void*,soSoundModule*,soLinkModule*,soVisibilityModule*,soControllerModule*,soCameraModule*,soWorkManageModule*,void*,soAnimCmdModule*,soStatusModule*,void*,void*,soKineticModule*,soEventManageModule*,void*,soEffectModule*,void*,soAreaModule*,void*,void*,void*,void*,soShadowModule*,soItemManageModule*,soColorBlendModule*,void*,void*,soSlowModule*,void*,void*,soParamCustomizeModule*,void*);
void fn_27_1257EC(void*, s32, s32, s32, void*);
void fn_110_6E0C(void*);
void fn_27_14B5F8(void*, void*);
void fn_110_7160(void*, u32, u32, u8, void*);
void fn_110_71C8(void*, void*, f32, void*, void*);
void fn_110_7250(void*, void*, void*);
void fn_110_7424(void*, void*, void*);
void fn_110_7494(void*, void*, void*);
void fn_27_3513C(void*, s16, void*, void*);
void fn_110_6D40(void*, s32, void*);
void fn_110_74F8(void*, void*, s32, u8, void*);
void fn_110_75BC(void*, void*, s32, u8, void*);
void fn_110_7680(void*, void*, s32, u8);
void fn_110_7754(void*, void*, s32, u8);
void fn_110_7828(void*, void*, s32, u8, void*);
void fn_110_78C0(void*, void*, s32, u8);
void fn_110_795C(void*, void*, void*);
void fn_27_64C8C(void*, void*, s32);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_110_79C8(void*, void*, void*);
void fn_110_7A24(void*, void*, void*, void*);
void fn_110_7AB4(void*, void*);
void fn_27_5B248(void*, void*, void*, s32);
void fn_110_7B08(void*, void*, s16);
void fn_110_7B78(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_110_7BE4(void*, s16);
void fn_110_7C28(void*, void*, void*, void*);
void fn_110_80E0(void*, void*);
void fn_110_84B0(void*);
void fn_110_8510(void*, void*);
void fn_110_869C(void*, void*, void*, void*, void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_110_8768(void*, void*, u8, void*);
void fn_110_8800(void*, void*, void*);
void fn_27_ACAC4(void*, void*, bool, s32, bool);
void fn_27_B62E4(void*, void*, float, s32);
void fn_110_8860(void*, void*, void*);
void fn_27_BEBB4(void*, void*, s32, s32);
void fn_27_C20D8(void*, void*, s32, s32, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, s32);
void fn_27_1A69DC(void*, s32);
void fn_27_D22D0(void*, s32);
void* fn_110_8A88();
void fn_110_88DC(void*, void*, void*, void*);
void fn_110_88F8(void*, s16, void*, s32, s32, float, s8*);
void fn_110_8AF8(void*, s32, s32);
void* fn_110_8B74(void*, s32);
void fn_110_8BB0(void*, s32, void*);
void fn_27_1A079C(void*, s32);
void fn_27_1404D4(void*, void*);
void fn_110_6D2C(void*, s32);
void fn_27_17437C(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_1F980(void*);
u8 fn_27_1119B8(void*);
void fn_27_C7744(void*, void*, s32);
extern u8 lbl_110_data_600[];
extern u8 lbl_110_data_11C[];
extern u8 lbl_110_data_1354[];
extern u8 lbl_110_data_13D4[];
extern u8 lbl_110_data_14DC[];
extern u8 lbl_110_data_1584[];
extern u8 lbl_27_bss_3AC[];
extern u8 lbl_27_bss_4BC[];
extern u8 lbl_27_bss_46C0[];
extern u8 lbl_27_bss_46D8[];
extern u8 lbl_27_bss_5B0[];
extern u8 lbl_27_bss_5D8[];
extern u8 lbl_27_bss_69C[];
extern u8 lbl_27_bss_8C4[];
extern u8 lbl_27_bss_A48[];
extern u8 lbl_27_bss_D8C[];
extern u8 lbl_27_bss_8034[];
extern u8 lbl_27_bss_8044[];
extern u8 lbl_27_bss_8054[];
extern u8 lbl_27_bss_8064[];
extern u8 lbl_27_bss_8074[];
extern u8 lbl_110_bss_194[];
extern u8 lbl_110_bss_1A4[];
extern u8 lbl_110_bss_1B4[];
extern u8 lbl_110_bss_1C4[];
extern u8 lbl_110_bss_1D4[];
extern u8 lbl_110_bss_1E4[];
extern u8 lbl_110_bss_1F4[];
extern u8 lbl_110_bss_204[];
extern u8 lbl_110_bss_214[];
extern u8 lbl_110_bss_224[];
extern u8 lbl_27_data_2F9F8[];
extern u8 lbl_27_data_2FAA0[];
extern u8 lbl_27_data_2FB48[];
extern u8 lbl_27_data_2FBF0[];
extern u8 lbl_27_data_2FC98[];
extern u8 lbl_27_data_2FD40[];
extern u8 lbl_27_data_2FDE8[];
extern float lbl_110_rodata_0;
extern float lbl_110_rodata_4;
}

struct SlopeInit {
 explicit SlopeInit(void* accesser, bool initial) { fn_27_ACAC4(this,accesser,initial,1,initial); }
};
struct ShadowInit {
 ShadowInit(void* accesser, const float* scale) { fn_27_B62E4(this,accesser,*scale,0); }
};
struct ColorBlendInit {
 explicit ColorBlendInit(void* accesser) { fn_27_BEBB4(this,accesser,10,1); }
};
struct JostleInit {
 JostleInit(void* accesser, void* data) { fn_27_C20D8(this,accesser,0,8,data); }
};

template <u8* Table>
struct ActionListenerInit {
 explicit ActionListenerInit(void* accesser) {
  fn_27_17437C(this,accesser);
  *(void**)this=Table;
  *(void**)((char*)this+4)=Table+0x40;
 }
};

class BuildData : public soModuleAccesserBuildData {
public:
 virtual s32 getHeapSlotNo() const;
 virtual void* getModelExtendNodeTable() const;
 virtual float getModelScale() const;
 virtual soSoundIdExchanger* getSoundIdExchanger() const;
 virtual soPreCheckAnimCmdData* getPreCheckAnimCmdData() const;
 virtual soEffectScreenData* getEffectScreenData() const;
 virtual void* getEffectNodeData() const;
 virtual s32* getTerritoryRect() const;
 virtual void* getTerritoryParam() const;
 virtual void* getTargetSearchParam() const;
 virtual soIkData* getIkData() const;
 virtual float getSlopeAngleLimit() const;
};
class V80 {
public:
 virtual void* m0(); virtual void* m1(); virtual void* m2(); virtual void* m3();
 virtual void* m4(); virtual void* m5(); virtual void* m6(); virtual s32 m7();
};
struct Holder80 { char pad[8]; V80 obj; s32 m7() { return obj.m7(); } };
class V64 {
public: virtual void* m0(); virtual void* m1(); virtual void* m2(); virtual void* m3(s32, void*);
};
class V6C {
public: virtual void* m0(); virtual void* m1(void*, void*);
};
class V70 {
public:
 virtual void* m00();
 virtual void* m01();
 virtual void* m02();
 virtual void* m03();
 virtual void* m04();
 virtual void* m05();
 virtual void* m06();
 virtual void* m07();
 virtual void* m08();
 virtual void* m09();
 virtual void* m10();
 virtual void* m11();
 virtual void* m12();
 virtual void* m13();
 virtual void* m14();
 virtual void* m15();
 virtual void* m16();
 virtual void* m17();
 virtual void* m18();
 virtual void* m19();
 virtual void* m20();
 virtual void* m21();
 virtual void* m22();
 virtual void* m23();
 virtual void* m24();
 virtual void* m25();
 virtual void* m26();
 virtual void* m27();
 virtual void* m28(void*, s32);
 virtual void* m29();
 virtual void* m30();
 virtual void* m31();
 virtual void* m32();
 virtual void* m33(void*);
};
class V90 {
public:
 virtual void* m0(); virtual void* m1(); virtual void* m2(); virtual void* m3();
 virtual void* m4(); virtual void* m5(); virtual void* m6(); virtual void* m7();
 virtual void* m8(); virtual void* m9(void*);
};
class VCD { public: virtual void* m0(); virtual void* m1(void*); };
class V5D34 { public: virtual s32 m0(); };
struct Mods {
 void* pad0; soModelModule* p4; char pad8[0x5C];
 V64* p64; void* p68; V6C* p6C; V70* p70; char pad74[0xC]; Holder80* p80;
 char pad84[0xC]; V90* p90;
};
struct Bd {
 void* vtable; s32 entryId; s32 kind; void* ftData;
 u8 resGroupNo; u8 pad10[3]; s32 team; void* acc; void* camRange;
 void* camClip; s32 instHeap; s32 nwModelHeap; s32 nwMotionHeap;
};
struct Locals { s8 f[11]; u8 padf; s16 v[11]; u8 padv[2]; void* p[22]; };
#define MODS ((Mods*)*(void**)(p25 + 0xAA8))
#define SELFMODS ((Mods*)*(void**)(*(char**)(self + 0x60) + 0xD8))
#define BITS ((u8)((*(u32*)(self + 0x2C) >> 7) & 0xFF))
#define EVAL (*(s32*)(self + 0x28))
#define b ((BuildData*)&bd)
#define FTDATA ((char*)bd.ftData)
#define SETVT(ADDR, TABLE) \
 *(void**)((ADDR)+0x3C)=(TABLE); \
 *(void**)((ADDR)+0x40)=(TABLE)+0x64; \
 *(void**)((ADDR)+0x48)=(TABLE)+0x70; \
 *(void**)((ADDR)+0x54)=(TABLE)+0x84; \
 *(void**)((ADDR)+0x64)=(TABLE)+0xDC; \
 *(void**)((ADDR)+0x70)=(TABLE)+0xEC; \
 *(void**)((ADDR)+0x7C)=(TABLE)+0xFC; \
 *(void**)((ADDR)+0x88)=(TABLE)+0x110; \
 *(void**)((ADDR)+0x94)=(TABLE)+0x128; \
 *(void**)((ADDR)+0xA0)=(TABLE)+0x140; \
 *(void**)((ADDR)+0xAC)=(TABLE)+0x158; \
 *(void**)((ADDR)+0xB8)=(TABLE)+0x16C; \
 *(void**)((ADDR)+0xC4)=(TABLE)+0x180; \
 *(void**)((ADDR)+0xD0)=(TABLE)+0x190; \
 *(void**)((ADDR)+0xDC)=(TABLE)+0x1C4; \
 *(void**)((ADDR)+0xE8)=(TABLE)+0x1D4; \
 *(void**)((ADDR)+0xF4)=(TABLE)+0x1E8; \
 *(void**)((ADDR)+0x100)=(TABLE)+0x254

extern "C" void* fn_110_70(char* self, s32 a1, s32 a2, void* unused, s32 a4) {
 struct Frame { Locals loc; Bd bd; void* reg[30]; } frame;
#define loc frame.loc
#define bd frame.bd
#define reg frame.reg
 char* g;
 char* p25;
 fn_27_1257EC(self, a1, 0x15, a2, self + 0xB64);
 SETVT(self, lbl_110_data_600);
 __ct__18ftFighterBuildDataFl6ftKindQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypeUcP16soModuleAccesserlPvPv((ftFighterBuildData*)&bd,a1, (ftKind)0x15, (Heaps::HeapType)a2,
  (Heaps::HeapType)a2, (Heaps::HeapType)a4, 0, *(soModuleAccesser**)(self+0x60),
  -1, self+0xD2D8, self+0xD2E0);
 char* g10;
 char* g8;
 char* g1;
 p25=self+0x194;
 fn_110_6E0C(p25);
 __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv((soModuleAccesser*)(p25+0x9D0),
  (StageObject*)self,
  (soResourceModule*)(p25+0x1168), (soModelModule*)(p25+0x1374),
  (soMotionModule*)(p25+0x1668), (soPostureModule*)(p25+0x1814),
  (soGroundModule*)(p25+0x18DC), (soSituationModule*)(p25+0x1934),
  p25+0x19A0, (soCollisionAttackModule*)(p25+0x2000),
  (soCollisionHitModule*)(p25+0x2994), (soCollisionShieldModule*)(p25+0x2BC0),
  (soCollisionShieldModule*)(p25+0x3628), (soCollisionShieldModule*)lbl_27_bss_3AC,
  p25+0x37FC, (soCollisionSearchModule*)(p25+0x39D0),
  (soDamageModule*)(p25+0x3B84), p25+0x3C88, p25+0x3CEC,
  (soStopModule*)(p25+0x3D20), p25+0x3D44, p25+0x3DF8,
  (soSoundModule*)(p25+0x3E28), (soLinkModule*)(p25+0x4064),
  (soVisibilityModule*)(p25+0x40B8), (soControllerModule*)(p25+0x46A0),
  (soCameraModule*)(p25+0x485C), (soWorkManageModule*)(p25+0x4880),
  lbl_27_bss_4BC, (soAnimCmdModule*)(p25+0x48B4),
  (soStatusModule*)(p25+0x57BC), lbl_27_bss_46C0, lbl_27_bss_46D8,
  (soKineticModule*)(p25+0x586C), (soEventManageModule*)(p25+0xB8),
  p25+0xA8E4, (soEffectModule*)(p25+0xA98C), p25+0xAAC4,
  (soAreaModule*)(p25+0xAB04), lbl_27_bss_5B0, lbl_27_bss_5D8,
  p25+0xAF08, p25+0xAF50, (soShadowModule*)(p25+0xAFD0),
  (soItemManageModule*)(p25+0xB10C), (soColorBlendModule*)(p25+0xB178),
  p25+0xB2CC, p25+0xB318, (soSlowModule*)(p25+0xB380),
  lbl_27_bss_69C, p25+0xAB0, (soParamCustomizeModule*)(p25+0xAC8), p25+0xB3BC);
 {
  s32 t80=b->getHeapSlotNo();
  g8=(char*)b->getNWMotionInstanceHeap();
  g1=(char*)b->getNWModelInstanceHeap();
  Heaps::HeapType t74=b->getInstanceHeap();
  __ct__16soHeapModuleImplFQ25Heaps8HeapTypeQ25Heaps8HeapTypeQ25Heaps8HeapTypel((soHeapModuleImpl*)(p25+0xAB0),t74,(Heaps::HeapType)(s32)g1,(Heaps::HeapType)(s32)g8,t80);
 }
 fn_27_14B5F8(p25+0xAC8,p25+0x9D0);
 fn_110_7160(p25+0x115C,b->getMdlResId(),b->getAnmResId(),b->getResGroupNo(),p25+0x9D0);
 {
  g8=(char*)b->getModelExtendNodeTable();
  f32 scale=b->getModelScale();
  fn_110_71C8(p25+0x1180,p25+0x9D0,scale,g8,lbl_27_bss_A48);
 }
 fn_110_7250(p25+0x1444,p25+0x9D0,b->getMotionData());
 fn_110_7424(p25+0x17D8,p25+0x9D0,lbl_27_bss_A48);
 fn_110_7494(p25+0x188C,p25+0x9D0,b->getGroundConditionChecker());
 fn_27_3513C(p25+0x1934,(s16)MODS->p80->m7(),p25+0x9D0,lbl_27_bss_A48);
 fn_110_6D40(p25+0x1970,b->getTeam(),p25+0x9D0);
 fn_110_74F8(p25+0x19E4,p25+0x9D0,EVAL,BITS,lbl_27_bss_A48);
 fn_110_75BC(p25+0x20A0,p25+0x9D0,EVAL,BITS,lbl_27_bss_A48);
 fn_110_7680(p25+0x29FC,p25+0x9D0,EVAL,BITS);
 fn_110_7754(p25+0x2C14,p25+0x9D0,EVAL,BITS);
 fn_110_7828(p25+0x3680,p25+0x9D0,EVAL,BITS,lbl_27_bss_A48);
 fn_110_78C0(p25+0x38E0,p25+0x9D0,EVAL,BITS);
 fn_110_795C(p25+0x3AD8,p25+0x9D0,lbl_27_bss_A48);
 fn_27_64C8C(p25+0x3C88,p25+0x9D0,1);
 fn_27_65EE4(p25+0x3CEC,p25+0x9D0);
 fn_27_154088(p25+0x3D20,p25+0x9D0);
 fn_27_693F4(p25+0x3D44,p25+0x9D0);
 fn_110_79C8(p25+0x3D7C,p25+0x9D0,b->getShakeData());
 fn_110_7A24(p25+0x3E14,p25+0x9D0,b->getSoundIdExchanger(),lbl_27_bss_A48);
 fn_110_7AB4(p25+0x3E84,p25+0x9D0);
 fn_27_5B248(p25+0x40B8,p25+0x9D0,b->getVisibilityData(),2);
 fn_110_7B08(p25+0x40E8,p25+0x9D0,(s16)MODS->p80->m7());
 fn_110_7B78(p25+0x480C,p25+0x9D0,b->getCameraRangeSet(),b->getCameraClipSphereSet(),lbl_27_bss_A48);
 fn_27_A1DA4(p25+0x4880,p25+0x9D0,b->getParamAccesser());
 fn_110_7BE4(p25+0x48B4,(s16)MODS->p80->m7());
 fn_110_7C28(p25+0x49A8,p25+0x9D0,b->getStatusData(),b->getPreCheckAnimCmdData());
 fn_110_80E0(p25+0x586C,p25+0x9D0);
 fn_110_84B0(p25+0x5B74);
 fn_110_8510(p25+0x5D58,p25+0x9D0);
 fn_110_869C(p25+0xA920,p25+0x9D0,b->getEffectNodeData(),b->getEffectEmitData(),
 b->getEffectCommonData(),b->getEffectScreenData(),lbl_27_bss_A48);
 fn_27_14FBD8(p25+0xAAC4,p25+0x9D0);
 s32 areaCategory=b->getAreaCategory();
 fn_110_8768(p25+0xAAF4,p25+0x9D0,(u8)areaCategory,lbl_27_bss_A48);
 (void)b->getTerritoryRect();
 (void)b->getTerritoryParam();
 (void)b->getTargetSearchParam();
 fn_110_8800(p25+0xAE8C,p25+0x9D0,b->getIkData());
 (void)b->getSlopeAngleLimit();
 new (p25+0xAF50) SlopeInit(p25+0x9D0,false);
 new (p25+0xAFD0) ShadowInit(p25+0x9D0,&lbl_110_rodata_0);
 fn_110_8860(p25+0xB018,p25+0x9D0,b->getItemNodeData());
 new (p25+0xB178) ColorBlendInit(p25+0x9D0);
 new (p25+0xB2CC) JostleInit(p25+0x9D0,b->getJostleData());
 fn_27_196664(p25+0xB318,p25+0x9D0);
 fn_27_5BED0(p25+0xB380,p25+0x9D0);
 fn_27_14CCEC(p25+0xB3BC,p25+0x9D0);
 if (((V5D34*)(p25+0x5D34))->m0()==0) MODS->p64->m3(1,p25+0x5D34);
 fn_27_C74BC(p25+0xB53C,*(void**)(FTDATA+0x18),0x1F);
 g=p25+0xB54C;
 fn_27_1A69DC(g,0);
 fn_27_1A69DC(g+0x4D0,0);
 fn_27_D22D0(g+0x9A4,0);
 fn_110_88DC(g+0xA50,g,g+0x4D0,fn_110_8A88());
 loc.f[0]=0;
 fn_110_88F8(g+0xA6C,(s16)MODS->p80->m7(),g+0x9A4,0,1,lbl_110_rodata_4,&loc.f[0]);
 fn_110_8AF8(g,0,0x131);
 fn_110_8AF8(g+0x4D0,0,0x131);
 fn_110_8AF8(fn_110_8A88(),0,0);
 loc.v[0]=1; loc.p[0]=g+0xA6C; loc.p[1]=g+0xA50;
 MODS->p6C->m1(&loc.p[0],&loc.v[0]);
 {
  (void)b->getAnimCmdData(1,2);
  (void)b->getAnimCmdData(1,1);
  void* t=b->getAnimCmdData(1,0);
  g1=g+0xABC;
  fn_27_C7744(g1,t,0x213);
  fn_27_D22D0(g1+0x14,0);
  fn_110_88DC(g1+0xC0,g1,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[1]=0;
  fn_110_88F8(g1+0xDC,(s16)MODS->p80->m7(),g1+0x14,1,1,lbl_110_rodata_4,&loc.f[1]);
  loc.v[1]=0x2;
  loc.p[2]=g1+0xDC; loc.p[3]=g1+0xC0;
  MODS->p6C->m1(&loc.p[2],&loc.v[1]);
 }
 {
  (void)b->getAnimCmdData(2,2);
  (void)b->getAnimCmdData(2,1);
  void* t=b->getAnimCmdData(2,0);
  char* g2=g+0xBE8;
  fn_27_C7744(g2,t,0x213);
  fn_27_D22D0(g2+0x14,0);
  fn_110_88DC(g2+0xC0,g2,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[2]=0;
  fn_110_88F8(g2+0xDC,(s16)MODS->p80->m7(),g2+0x14,2,1,lbl_110_rodata_4,&loc.f[2]);
  loc.v[2]=0x40;
  loc.p[4]=g2+0xDC; loc.p[5]=g2+0xC0;
  MODS->p6C->m1(&loc.p[4],&loc.v[2]);
 }
 {
  (void)b->getAnimCmdData(3,2);
  (void)b->getAnimCmdData(3,1);
  void* t=b->getAnimCmdData(3,0);
  char* g3=g+0xD14;
  fn_27_C7744(g3,t,0x213);
  fn_27_D22D0(g3+0x14,0);
  fn_110_88DC(g3+0xC0,g3,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[3]=0;
  fn_110_88F8(g3+0xDC,(s16)MODS->p80->m7(),g3+0x14,3,1,lbl_110_rodata_4,&loc.f[3]);
  loc.v[3]=0x40;
  loc.p[6]=g3+0xDC; loc.p[7]=g3+0xC0;
  MODS->p6C->m1(&loc.p[6],&loc.v[3]);
 }
 {
  (void)b->getAnimCmdData(4,2);
  (void)b->getAnimCmdData(4,1);
  void* t=b->getAnimCmdData(4,0);
  char* g4=g+0xE40;
  fn_27_C7744(g4,t,0x213);
  fn_27_D22D0(g4+0x14,0);
  fn_110_88DC(g4+0xC0,g4,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[4]=0;
  fn_110_88F8(g4+0xDC,(s16)MODS->p80->m7(),g4+0x14,4,1,lbl_110_rodata_4,&loc.f[4]);
  loc.v[4]=0x2;
  loc.p[8]=g4+0xDC; loc.p[9]=g4+0xC0;
  MODS->p6C->m1(&loc.p[8],&loc.v[4]);
 }
 {
  (void)b->getAnimCmdData(5,2);
  (void)b->getAnimCmdData(5,1);
  void* t=b->getAnimCmdData(5,0);
  char* g5=g+0xF6C;
  fn_27_C7744(g5,t,0x213);
  fn_27_D22D0(g5+0x14,0);
  fn_110_88DC(g5+0xC0,g5,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[5]=0;
  fn_110_88F8(g5+0xDC,(s16)MODS->p80->m7(),g5+0x14,5,1,lbl_110_rodata_4,&loc.f[5]);
  loc.v[5]=0x20;
  loc.p[10]=g5+0xDC; loc.p[11]=g5+0xC0;
  MODS->p6C->m1(&loc.p[10],&loc.v[5]);
 }
 {
  (void)b->getAnimCmdData(6,2);
  (void)b->getAnimCmdData(6,1);
  void* t=b->getAnimCmdData(6,0);
  char* g6=g+0x1098;
  fn_27_C7744(g6,t,0x213);
  fn_27_D22D0(g6+0x14,0);
  fn_110_88DC(g6+0xC0,g6,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[6]=0;
  fn_110_88F8(g6+0xDC,(s16)MODS->p80->m7(),g6+0x14,6,1,lbl_110_rodata_4,&loc.f[6]);
  loc.v[6]=0x80;
  loc.p[12]=g6+0xDC; loc.p[13]=g6+0xC0;
  MODS->p6C->m1(&loc.p[12],&loc.v[6]);
 }
 {
  (void)b->getAnimCmdData(7,2);
  (void)b->getAnimCmdData(7,1);
  void* t=b->getAnimCmdData(7,0);
  char* g7=g+0x11C4;
  fn_27_C7744(g7,t,0x213);
  fn_27_D22D0(g7+0x14,0);
  fn_110_88DC(g7+0xC0,g7,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[7]=0;
  fn_110_88F8(g7+0xDC,(s16)MODS->p80->m7(),g7+0x14,7,1,lbl_110_rodata_4,&loc.f[7]);
  loc.v[7]=0x80;
  loc.p[14]=g7+0xDC; loc.p[15]=g7+0xC0;
  MODS->p6C->m1(&loc.p[14],&loc.v[7]);
 }
 {
  (void)b->getAnimCmdData(8,2);
  (void)b->getAnimCmdData(8,1);
  void* t=b->getAnimCmdData(8,0);
  g8=g+0x12F0;
  fn_27_C7744(g8,t,0x213);
  fn_27_D22D0(g8+0x14,0);
  fn_110_88DC(g8+0xC0,g8,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[8]=0;
  fn_110_88F8(g8+0xDC,(s16)MODS->p80->m7(),g8+0x14,8,1,lbl_110_rodata_4,&loc.f[8]);
  loc.v[8]=0x20;
  loc.p[16]=g8+0xDC; loc.p[17]=g8+0xC0;
  MODS->p6C->m1(&loc.p[16],&loc.v[8]);
 }
 {
  g8=g+0x141C;
  loc.f[9]=1;
  fn_110_88F8(g8,(s16)MODS->p80->m7(),g8+0x50,9,1,lbl_110_rodata_4,&loc.f[9]);
  fn_27_1A079C(g8+0x50,0);
  loc.v[9]=4; loc.p[18]=g8; loc.p[19]=lbl_27_bss_8C4;
  MODS->p6C->m1(&loc.p[18],&loc.v[9]);
 }
 {
  (void)b->getAnimCmdData(10,2);
  (void)b->getAnimCmdData(10,1);
  void* t=b->getAnimCmdData(10,0);
  g10=g+0x1540;
  fn_27_C7744(g10,t,0x29);
  fn_27_D22D0(g10+0x14,0);
  fn_110_88DC(g10+0xC0,g10,lbl_27_bss_D8C,lbl_27_bss_D8C);
  loc.f[10]=0;
  fn_110_88F8(g10+0xDC,(s16)MODS->p80->m7(),g10+0x14,10,1,lbl_110_rodata_4,&loc.f[10]);
  loc.v[10]=0x10;
  loc.p[20]=g10+0xDC; loc.p[21]=g10+0xC0;
  MODS->p6C->m1(&loc.p[20],&loc.v[10]);
 }
 {
  g10=(char*)b->getAnimCmdData(0,0);
  fn_110_8AF8(fn_110_8B74(g,0),(s32)g10,0x112);
  g10=(char*)b->getAnimCmdData(0,1);
  fn_110_8AF8(fn_110_8B74(g,1),(s32)g10,0x112);
  fn_110_8AF8(fn_110_8B74(g,0),*(s32*)(FTDATA+0x24),0x1F);
  fn_110_8AF8(fn_110_8B74(g,1),*(s32*)(FTDATA+0x28),0x1F);
 }
 fn_110_8BB0(g,0,((ftFighterBuildData*)&bd)->getAnimCmdDisguiseList(false,0));
 fn_110_8BB0(g,1,((ftFighterBuildData*)&bd)->getAnimCmdDisguiseList(false,1));
 MODS->p70->m33(p25+0xB53C);
 g10=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)(p25+0x9D0),0xA805,0);
 {
  void* cast=__dynamic_cast(MODS->p90,0,lbl_110_data_14DC,lbl_110_data_1584,0);
  if(cast!=0)fn_27_14E0B8(cast,g10);
 }
 MODS->p90->m9(g10);
 fn_27_1404D4(self+0xCD4C,*(void**)(self+0x60));
 {
  g10=self+0xCD88;
  fn_110_6D2C(g10,0); *(void**)g10=lbl_110_data_1354;
 }
 p25=*(char**)(self+0x60);
 a1=(s32)(self+0xD240);
 fn_110_6D2C((char*)a1,0);
 *(void**)a1=lbl_110_data_13D4;
 new ((char*)a1+0x8) ActionListenerInit<lbl_27_data_2F9F8>(p25);
 new ((char*)a1+0x20) ActionListenerInit<lbl_27_data_2FAA0>(p25);
 new ((char*)a1+0x34) ActionListenerInit<lbl_27_data_2FB48>(p25);
 new ((char*)a1+0x48) ActionListenerInit<lbl_27_data_2FBF0>(p25);
 new ((char*)a1+0x5C) ActionListenerInit<lbl_27_data_2FC98>(p25);
 new ((char*)a1+0x70) ActionListenerInit<lbl_27_data_2FD40>(p25);
 new ((char*)a1+0x84) ActionListenerInit<lbl_27_data_2FDE8>(p25);
 *(s32*)(self+0xD2D8)=(s32)soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self+0x60),0xA7F9,0);
 *(s32*)(self+0xD2DC)=1;
 *(s32*)(self+0xD2E0)=(s32)soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(self+0x60),0xA7FC,0);
 *(s32*)(self+0xD2E4)=1;
 fn_27_126470(self);
 ((VCD*)(self+0xCD4C))->m1(*(void**)(self+0x60));
 SETVT(self,lbl_110_data_11C);
 fn_27_C749C(self+0xD2E8);
 *(void**)(self+0xD2F8)=g_ftCommonDataAccesser.getData((ftKind)0x15);
 fn_27_1F980(self+0xD2FC);
 {
  typedef void* StatusPointer;
  new (reg) StatusPointer[30]();
  reg[0]=lbl_27_bss_8034; reg[1]=lbl_110_bss_194;
  reg[2]=lbl_110_bss_204; reg[3]=lbl_110_bss_224;
  reg[5]=lbl_27_bss_8034;
  reg[7]=lbl_27_bss_8044; reg[8]=lbl_27_bss_8044;
  reg[9]=lbl_27_bss_8054; reg[10]=lbl_27_bss_8074;
  reg[11]=lbl_27_bss_8064; reg[12]=lbl_27_bss_8064;
  reg[13]=lbl_27_bss_8064; reg[14]=lbl_27_bss_8064;
  reg[15]=lbl_110_bss_1B4; reg[17]=lbl_110_bss_1B4;
  reg[18]=lbl_110_bss_1C4; reg[19]=lbl_110_bss_1D4;
  reg[20]=lbl_110_bss_1A4; reg[21]=lbl_110_bss_1A4;
  reg[22]=lbl_110_bss_1A4; reg[23]=lbl_110_bss_1A4;
  reg[24]=lbl_110_bss_1A4; reg[25]=lbl_110_bss_1E4;
  reg[26]=lbl_110_bss_1F4; reg[27]=lbl_110_bss_1A4;
  reg[28]=lbl_110_bss_214;
  SELFMODS->p70->m28(reg,30);
 }
 SELFMODS->p90->m9(*(char**)(self+0xD2F8)+0x94);
 if(fn_27_1119B8(((Fighter*)self)->getOwner())>=6 &&
    fn_27_1119B8(((Fighter*)self)->getOwner())<=0xB){
  SELFMODS->p4->setNodeConvertData(*(u32***)(*(char**)(self+0xD2F8)+0x9C));
  SELFMODS->p4->setShadowNode(*(int*)(*(char**)(self+0xD2F8)+0xA0));
 }
 return self;
}
