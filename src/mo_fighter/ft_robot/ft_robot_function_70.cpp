#include <types.h>
#include <new>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on
#pragma always_inline on
inline void* operator new[](size_t,void* storage) { return storage; }
#pragma always_inline reset
extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_120_data_608[];
extern char lbl_120_data_120[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[];
extern char lbl_120_data_2058[];
extern char lbl_120_data_2100[];
extern char lbl_120_data_1ED0[];
extern char lbl_120_data_1F50[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern char lbl_120_bss_2B4[];
extern char lbl_120_bss_2C4[];
extern char lbl_120_bss_2D4[];
extern char lbl_120_bss_2E4[];
extern char lbl_120_bss_304[];
extern char lbl_120_bss_314[];
extern char lbl_27_bss_8A54[];
extern float lbl_120_rodata_0, lbl_120_rodata_4;
void fn_27_1257EC(void*, int, int, int, void*);
void fn_120_5CB8(void*);
void fn_27_126470(void*);
void fn_27_1404D4(void*, void*);
void fn_27_C749C(void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_14B5F8(void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_27_1A079C(void*, int);
void fn_120_68C4(void*, void*);
void fn_120_6EF0(void*, void*);
void fn_120_72C0(void*);
void fn_120_7320(void*, void*);
void fn_120_62D0(void*, void*, void*);
void fn_120_63A4(void*, void*, int, unsigned char, void*);
void fn_120_6468(void*, void*, int, unsigned char, void*);
void fn_120_652C(void*, void*, int, unsigned char);
void fn_120_6600(void*, void*, int, unsigned char);
void fn_120_66D4(void*, void*, int, unsigned char, void*);
void fn_120_676C(void*, void*, void*);
void fn_120_600C(void*, u32, u32, unsigned char, void*);
void* fn_120_6074(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_120_60FC(void*, void*, void*);
void fn_120_6340(void*, void*, void*);
void fn_120_5BEC(void*, int, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_120_6918(void*, void*, short);
void fn_120_69F4(void*, short);
void fn_120_67D8(void*, void*, void*);
void fn_120_6834(void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_120_6988(void*, void*, void*, void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_120_6A38(void*, void*, void*, void*);
void fn_120_7600(void*, void*, void*, void*, void*, void*, void*);
void fn_120_76CC(void*, void*, unsigned char, void*);
void fn_120_7764(void*, void*, void*);
void fn_120_77F8(void*, void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A5EB0(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void fn_120_7874(void*, void*, void*, void*);
void fn_120_7890(void*, short, void*, int, int, float, signed char*);
void fn_120_7A90(void*, void*, int);
void fn_120_7B48(void*, int, void*);
void fn_27_14E0B8(void*, void*);
void fn_120_5BD8(void*, int);
void fn_27_17437C(void*, void*);
void* fn_120_7A20(); void* fn_120_7B0C(void*,int);
}
class SlopeStorage {
public:
 SlopeStorage(void* accesser, u8 initial, int count, float angle) {
  fn_27_ACAC4(this,accesser,initial,count,initial,angle);
 }
};
class ShadowStorage {
public:
 ShadowStorage(void* accesser, int mode, const float& scale) {
  fn_27_B62E4(this,accesser,scale,mode);
 }
};
class ColorBlendStorage {
public:
 ColorBlendStorage(void* accesser, int count, int enabled) {
  fn_27_BEBB4(this,accesser,count,enabled);
 }
};
class JostleStorage {
public:
 JostleStorage(void* accesser, int id, int count, void* data) {
  fn_27_C20D8(this,accesser,id,count,data);
 }
};
class FighterStateStorage {
public:
 FighterStateStorage() {
  fn_120_5BD8(this,0);
  *reinterpret_cast<void**>(this)=lbl_120_data_1ED0;
 }
};
template<char* Table>
class ActionLeafStorage {
public:
 ActionLeafStorage(void* accesser) {
  fn_27_17437C(this,accesser);
  char* storage=reinterpret_cast<char*>(this);
  *reinterpret_cast<char**>(storage)=Table;
  *reinterpret_cast<char**>(storage+4)=Table+0x40;
 }
};
struct V {
virtual int v0();
virtual void v1(void**, short*);
virtual void v2();
virtual void v3(int,void*);
virtual void v4();
virtual void v5(void*, int);
virtual void v6();
virtual short v7();
virtual void v8(int);
virtual void v9(int);
virtual void v10();
virtual void v11();
virtual void v12();
virtual void v13(int, int, int);
virtual void v14();
virtual void v15();
virtual void v16();
virtual void v17(void*);
virtual void v18();
virtual void v19(int);
virtual void v20();
virtual void v21();
virtual void v22();
virtual void v23();
virtual void v24();
virtual void v25();
virtual void v26();
virtual void v27();
virtual void v28(void*,int);
virtual void v29(void*, int);
virtual void v30();
virtual void v31();
virtual void v32();
virtual void v33(void*);
virtual void v34();
};
struct SearchModuleStorage { char prefix[8]; };
struct SearchModuleView : SearchModuleStorage {
 virtual void slot0();
 virtual void slot1();
 virtual void slot2();
 virtual void slot3();
 virtual void slot4();
 virtual void slot5();
 virtual void slot6();
 virtual void slot7();
 virtual void slot8();
 virtual void slot9();
 virtual void slot10();
 virtual void slot11();
 virtual void slot12();
 virtual void slot13();
 virtual void slot14();
 virtual void slot15();
 virtual void slot16();
 virtual void slot17();
 virtual void slot18();
 virtual void set(int);
};
struct ItemV { virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual void x4(); virtual void x5(); virtual void x6(); virtual void set(int); virtual void set2(int); };
struct SetV { virtual void x0(); virtual void x1(); virtual void x2(); virtual void x3(); virtual void x4(); virtual void x5(); virtual void x6(); virtual void set(void*,int); };
struct InitV { virtual void x(); virtual void init(void*); };
struct H { char pad[8]; V obj; };
struct E { char pad[0x64]; V* v64; char pad2[4]; V* v6c; V* v70; char pad3[0xc]; H* h80; char pad4[0xc]; V* v90; };
struct Locals { signed char flags[12]; short values[11]; void* ptrs[22]; };
class BuildCalls : public soModuleAccesserBuildData {
public:
 virtual void* getEffectNodeData() const = 0;
 virtual soEffectScreenData* getEffectScreenData() const = 0;
 virtual void* getTerritoryParam() const = 0;
 virtual s32* getTerritoryRect() const = 0;
 virtual void* getTargetSearchParam() const = 0;
 virtual soIkData* getIkData() const = 0;
 virtual float getModelScale() const = 0;
 virtual void* getModelExtendNodeTable() const = 0;
 virtual soPreCheckAnimCmdData* getPreCheckAnimCmdData() const = 0;
 virtual s32 getHeapSlotNo() const = 0;
 virtual soSoundIdExchanger* getSoundIdExchanger() const = 0;
 virtual float getSlopeAngleLimit() const = 0;
};
#define data (*(BuildCalls*)buf)
#define en (*(E**)(m+0xaa8))
#define HEAP (en->h80->obj.v7())
#define VT(S,O) (*(V**)((char*)(S)+(O)))

#define SLOT_WITH_BASE(I,OFF,VAL,C,qq) \
 data.getAnimCmdData(I,2); data.getAnimCmdData(I,1); \
 { void* t=data.getAnimCmdData(I,0); qq=q+OFF; \
 fn_27_C7744(qq,t,C); fn_27_D22D0(qq+0x14,0); \
 fn_120_7874(qq+0xc0,qq,lbl_27_bss_D8C,lbl_27_bss_D8C); \
 local.flags[I]=0; fn_120_7890(qq+0xdc,HEAP,qq+0x14,I,1,lbl_120_rodata_4,&local.flags[I]); \
 local.values[I]=VAL; local.ptrs[2*I]=qq+0xdc; local.ptrs[2*I+1]=qq+0xc0; \
 en->v6c->v1(&local.ptrs[2*I],&local.values[I]); }
#define SLOT(I,OFF,VAL,C) { char* base; SLOT_WITH_BASE(I,OFF,VAL,C,base) }
extern "C" void* fn_120_70(char* self,int heap,int a2,int a3,int a4) {
 char* s=self;
 char* q;
 char* extraCommandBase;
 void* ac;
 void* val;
 struct Frame { Locals local; char buf[0x30]; void* arr[12]; } frame;
#define buf frame.buf
#define local frame.local
#define arr frame.arr
 fn_27_1257EC(s,heap,0x23,a2,s+0xb64);
 { char* tables=lbl_120_data_608;
*(void**)(s+0x3c)=tables+0x0;
*(void**)(s+0x40)=tables+0x64;
*(void**)(s+0x48)=tables+0x70;
*(void**)(s+0x54)=tables+0x84;
*(void**)(s+0x64)=tables+0xdc;
*(void**)(s+0x70)=tables+0xec;
*(void**)(s+0x7c)=tables+0xfc;
*(void**)(s+0x88)=tables+0x110;
*(void**)(s+0x94)=tables+0x128;
*(void**)(s+0xa0)=tables+0x140;
*(void**)(s+0xac)=tables+0x158;
*(void**)(s+0xb8)=tables+0x16c;
*(void**)(s+0xc4)=tables+0x180;
*(void**)(s+0xd0)=tables+0x190;
*(void**)(s+0xdc)=tables+0x1c4;
*(void**)(s+0xe8)=tables+0x1d4;
*(void**)(s+0xf4)=tables+0x1e8;
*(void**)(s+0x100)=tables+0x254;
}
new(buf) ftFighterBuildData(heap,(ftKind)0x23,(Heaps::HeapType)a2,(Heaps::HeapType)a3,(Heaps::HeapType)a4,0,*(soModuleAccesser**)(s+0x60),-1,s+0x12280,s+0x12288);
 char* m=s+0x194;
 fn_120_5CB8(m);
 new(m+0x9d0) soModuleAccesser(
 (StageObject*)s,
(soResourceModule*)(m+0x1168),
(soModelModule*)(m+0x1374),
(soMotionModule*)(m+0x16ac),
(soPostureModule*)(m+0x1858),
(soGroundModule*)(m+0x1920),
(soSituationModule*)(m+0x1978),
(void*)(m+0x19e4),
(soCollisionAttackModule*)(m+0x2044),
(soCollisionHitModule*)(m+0x29d8),
(soCollisionShieldModule*)(m+0x2c04),
(soCollisionShieldModule*)(m+0x367c),
(soCollisionShieldModule*)(lbl_27_bss_3AC),
(void*)(m+0x3850),
(soCollisionSearchModule*)(lbl_27_bss_3CC),
(soDamageModule*)(m+0x39e4),
(void*)(m+0x3ae8),
(void*)(m+0x3b4c),
(soStopModule*)(m+0x3b80),
(void*)(m+0x3ba4),
(void*)(m+0x3c58),
(soSoundModule*)(m+0x3c88),
(soLinkModule*)(m+0x3e28),
(soVisibilityModule*)(m+0x3e7c),
(soControllerModule*)(m+0x4464),
(soCameraModule*)(m+0x4620),
(soWorkManageModule*)(m+0x4644),
(void*)(lbl_27_bss_4BC),
(soAnimCmdModule*)(m+0x4678),
(soStatusModule*)(m+0x554c),
(void*)(lbl_27_bss_46C0),
(void*)(lbl_27_bss_46D8),
(soKineticModule*)(m+0x55fc),
(soEventManageModule*)(m+0xb8),
(void*)(m+0xfa10),
(soEffectModule*)(m+0xfab8),
(void*)(m+0xfbf0),
(soAreaModule*)(m+0xfc30),
(void*)(lbl_27_bss_5B0),
(void*)(lbl_27_bss_5D8),
(void*)(m+0xff98),
(void*)(m+0xffe0),
(soShadowModule*)(m+0x10060),
(soItemManageModule*)(m+0x1014c),
(soColorBlendModule*)(m+0x101b8),
(void*)(m+0x1030c),
(void*)(m+0x10358),
(soSlowModule*)(m+0x103c0),
(void*)(lbl_27_bss_69C),
(void*)(m+0xab0),
(soParamCustomizeModule*)(m+0xac8),
(void*)(m+0x103fc));

 char* motionBase;
 s32 slot;
 char* modelBase;
 slot = data.getHeapSlotNo();
 motionBase = reinterpret_cast<char*>(data.getNWMotionInstanceHeap());
 modelBase = reinterpret_cast<char*>(data.getNWModelInstanceHeap());
 new(m+0xab0) soHeapModuleImpl(data.getInstanceHeap(),
  static_cast<Heaps::HeapType>(reinterpret_cast<s32>(modelBase)),
  static_cast<Heaps::HeapType>(reinterpret_cast<s32>(motionBase)),slot);
 fn_27_14B5F8(m+0xac8,m+0x9d0);
 fn_120_600C(m+0x115c,data.getMdlResId(),data.getAnmResId(),data.getResGroupNo(),m+0x9d0);
 fn_120_6074(m+0x1180,(soModuleAccesser*)(m+0x9d0),data.getModelScale(),data.getModelExtendNodeTable(),(soEventObserverRegistrationDesc*)lbl_27_bss_A48);
 fn_120_60FC(m+0x1440,m+0x9d0,data.getMotionData());
 fn_120_62D0(m+0x181c,m+0x9d0,lbl_27_bss_A48);
 fn_120_6340(m+0x18d0,m+0x9d0,data.getGroundConditionChecker());
 fn_27_3513C(m+0x1978,HEAP,m+0x9d0,lbl_27_bss_A48);
 fn_120_5BEC(m+0x19b4,data.getTeam(),m+0x9d0);
fn_120_63A4(m+0x1a28,m+0x9d0,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),lbl_27_bss_A48);
fn_120_6468(m+0x20e4,m+0x9d0,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),lbl_27_bss_A48);
fn_120_652C(m+0x2a40,m+0x9d0,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_120_6600(m+0x2c58,m+0x9d0,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_120_66D4(m+0x36d4,m+0x9d0,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),lbl_27_bss_A48);

 fn_120_676C(m+0x3938,m+0x9d0,lbl_27_bss_A48);
 fn_27_64C8C(m+0x3ae8,m+0x9d0,1);
 fn_27_65EE4(m+0x3b4c,m+0x9d0);
 fn_27_154088(m+0x3b80,m+0x9d0);
 fn_27_693F4(m+0x3ba4,m+0x9d0);
 fn_120_67D8(m+0x3bdc,m+0x9d0,data.getShakeData());
 fn_120_6834(m+0x3c74,m+0x9d0,data.getSoundIdExchanger(),lbl_27_bss_A48);
 fn_120_68C4(m+0x3ce4,m+0x9d0);
 fn_27_5B248(m+0x3e7c,m+0x9d0,data.getVisibilityData(),2);
 fn_120_6918(m+0x3eac,m+0x9d0,HEAP);
 fn_120_6988(m+0x45d0,m+0x9d0,data.getCameraRangeSet(),data.getCameraClipSphereSet(),lbl_27_bss_A48);
 fn_27_A1DA4(m+0x4644,m+0x9d0,data.getParamAccesser());
 fn_120_69F4(m+0x4678,HEAP);
 fn_120_6A38(m+0x476c,m+0x9d0,data.getStatusData(),data.getPreCheckAnimCmdData());
 fn_120_6EF0(m+0x55fc,m+0x9d0); fn_120_72C0(m+0x5904); fn_120_7320(m+0x5ae8,m+0x9d0);
 fn_120_7600(m+0xfa4c,m+0x9d0,data.getEffectNodeData(),data.getEffectEmitData(),data.getEffectCommonData(),data.getEffectScreenData(),lbl_27_bss_A48);
 fn_27_14FBD8(m+0xfbf0,m+0x9d0);
 s32 areaCategory = data.getAreaCategory();
 fn_120_76CC(m+0xfc20,m+0x9d0,static_cast<u8>(areaCategory),lbl_27_bss_A48);
 data.getTerritoryRect(); data.getTerritoryParam(); data.getTargetSearchParam();
 fn_120_7764(m+0xff94,m+0x9d0,data.getIkData());
 new(m+0xffe0) SlopeStorage(m+0x9d0,0,1,data.getSlopeAngleLimit());
 new(m+0x10060) ShadowStorage(m+0x9d0,0,lbl_120_rodata_0);
 fn_120_77F8(m+0x100a8,m+0x9d0,data.getItemNodeData());
 new(m+0x101b8) ColorBlendStorage(m+0x9d0,10,1);
 new(m+0x1030c) JostleStorage(m+0x9d0,0,8,data.getJostleData());
 fn_27_196664(m+0x10358,m+0x9d0); fn_27_5BED0(m+0x103c0,m+0x9d0); fn_27_14CCEC(m+0x103fc,m+0x9d0);
 if(((V*)(m+0x5ac4))->v0()==0) en->v64->v3(1,m+0x5ac4);
 fn_27_C74BC(m+0x1057c,(*(void***)(buf+0xc))[6],12);
 q=m+0x1058c;
 fn_27_1A5EB0(q,0); fn_27_1A5EB0(q+0x484,0); fn_27_D22D0(q+0x90c,0);
 void* r7=fn_120_7A20(); fn_120_7874(q+0x9b8,q,q+0x484,r7);
 local.flags[0]=0; fn_120_7890(q+0x9d4,HEAP,q+0x90c,0,1,lbl_120_rodata_4,&local.flags[0]);
 fn_120_7A90(q,0,0x11e); fn_120_7A90(q+0x484,0,0x11e); fn_120_7A90(fn_120_7A20(),0,0);
 local.values[0]=1; local.ptrs[0]=q+0x9d4; local.ptrs[1]=q+0x9b8;
 en->v6c->v1(&local.ptrs[0],&local.values[0]);
 SLOT_WITH_BASE(1,0xa24,2,0x1e7,modelBase)
 SLOT(2,0xb50,0x40,0x1e7)
 SLOT(3,0xc7c,0x40,0x1e7)
 SLOT(4,0xda8,2,0x1e7)
 SLOT(5,0xed4,0x20,0x1e7)
 SLOT(6,0x1000,0x80,0x1e7)
 SLOT(7,0x112c,0x80,0x1e7)
 SLOT_WITH_BASE(8,0x1258,0x20,0x1e7,motionBase)
 motionBase=q+0x1384;
 { char* r=motionBase;
 local.flags[9]=1; fn_120_7890(r,HEAP,r+0x50,9,1,lbl_120_rodata_4,&local.flags[9]);
 fn_27_1A079C(r+0x50,0); local.values[9]=4; local.ptrs[18]=r; local.ptrs[19]=lbl_27_bss_8C4;
 en->v6c->v1(&local.ptrs[18],&local.values[9]); }
 SLOT_WITH_BASE(10,0x14a8,0x10,0x29,extraCommandBase)
 ac=data.getAnimCmdData(0,0); fn_120_7A90(fn_120_7B0C(q,0),ac,0x112);
 ac=data.getAnimCmdData(0,1); fn_120_7A90(fn_120_7B0C(q,1),ac,0x112);
 fn_120_7A90(fn_120_7B0C(q,0),(*(void***)(buf+0xc))[9],12);
 fn_120_7A90(fn_120_7B0C(q,1),(*(void***)(buf+0xc))[10],12);
 fn_120_7B48(q,0,((ftFighterBuildData*)buf)->getAnimCmdDisguiseList(false,0));
 fn_120_7B48(q,1,((ftFighterBuildData*)buf)->getAnimCmdDisguiseList(false,1));
 en->v70->v33(m+0x1057c);
 val=soValueAccesser::getConstantIndefinite((soModuleAccesser*)(m+0x9d0),0xa805,0);
 void* cast=__dynamic_cast(en->v90,0,lbl_120_data_2058,lbl_120_data_2100,0);
 if(cast) fn_27_14E0B8(cast,val);
 en->v90->v9((int)val);
 fn_27_1404D4(s+0x11cf4,*(void**)(s+0x60));
 new(s+0x11d30) FighterStateStorage();
 m=*(char**)(s+0x60);
 a2=reinterpret_cast<int>(s+0x121e8);
 fn_120_5BD8(reinterpret_cast<char*>(a2),0);
 *reinterpret_cast<void**>(a2)=lbl_120_data_1F50;
 new(reinterpret_cast<char*>(a2)+0x8) ActionLeafStorage<lbl_27_data_2F9F8>(m);
 new(reinterpret_cast<char*>(a2)+0x20) ActionLeafStorage<lbl_27_data_2FAA0>(m);
 new(reinterpret_cast<char*>(a2)+0x34) ActionLeafStorage<lbl_27_data_2FB48>(m);
 new(reinterpret_cast<char*>(a2)+0x48) ActionLeafStorage<lbl_27_data_2FBF0>(m);
 new(reinterpret_cast<char*>(a2)+0x5c) ActionLeafStorage<lbl_27_data_2FC98>(m);
 new(reinterpret_cast<char*>(a2)+0x70) ActionLeafStorage<lbl_27_data_2FD40>(m);
 new(reinterpret_cast<char*>(a2)+0x84) ActionLeafStorage<lbl_27_data_2FDE8>(m);

 *(void**)(s+0x12280)=soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(s+0x60),0xa7f9,0);
 *(int*)(s+0x12284)=1;
 *(void**)(s+0x12288)=soValueAccesser::getConstantIndefinite(*(soModuleAccesser**)(s+0x60),0xa7fc,0);
 *(int*)(s+0x1228c)=1;
 fn_27_126470(s);
 ((InitV*)(s+0x11cf4))->init(*(void**)(s+0x60));
 { char* tables=lbl_120_data_120;
*(void**)(s+0x3c)=tables+0x0;
*(void**)(s+0x40)=tables+0x64;
*(void**)(s+0x48)=tables+0x70;
*(void**)(s+0x54)=tables+0x84;
*(void**)(s+0x64)=tables+0xdc;
*(void**)(s+0x70)=tables+0xec;
*(void**)(s+0x7c)=tables+0xfc;
*(void**)(s+0x88)=tables+0x110;
*(void**)(s+0x94)=tables+0x128;
*(void**)(s+0xa0)=tables+0x140;
*(void**)(s+0xac)=tables+0x158;
*(void**)(s+0xb8)=tables+0x16c;
*(void**)(s+0xc4)=tables+0x180;
*(void**)(s+0xd0)=tables+0x190;
*(void**)(s+0xdc)=tables+0x1c4;
*(void**)(s+0xe8)=tables+0x1d4;
*(void**)(s+0xf4)=tables+0x1e8;
*(void**)(s+0x100)=tables+0x254;
}

 fn_27_C749C(s+0x12290);
 *(void**)(s+0x122a0)=g_ftCommonDataAccesser.getData((ftKind)0x23);
 new(arr) void*[12]();
 arr[0]=lbl_27_bss_8A54; arr[1]=lbl_120_bss_2B4; arr[2]=lbl_120_bss_2E4;
 arr[3]=lbl_120_bss_304; arr[4]=lbl_120_bss_314; arr[5]=lbl_120_bss_2B4;
 arr[7]=lbl_120_bss_2C4; arr[8]=lbl_120_bss_2D4; arr[9]=lbl_120_bss_304; arr[10]=lbl_120_bss_304; arr[11]=lbl_120_bss_304;
 VT(*(char**)(*(char**)(s+0x60)+0xd8),0x70)->v28(arr,12);
 ((SetV*)VT(*(char**)(*(char**)(s+0x60)+0xd8),0x28))->set(*(void**)(*(char**)(s+0x122a0)+0xb0),2);
 VT(*(char**)(*(char**)(s+0x60)+0xd8),0x28)->v13(0,0,2);
 (*(SearchModuleView**)(*(char**)(*(char**)(s+0x60)+0xd8)+0x9c))->set(0);
 ((ItemV*)VT(*(char**)(*(char**)(s+0x60)+0xd8),0xa0))->set(0x5d);
 ((ItemV*)VT(*(char**)(*(char**)(s+0x60)+0xd8),0xa0))->set2(6);
 return self;
}
