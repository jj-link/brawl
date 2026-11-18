#include <types.h>
#include <new>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <ac/ac_cmd_interpreter.h>
#include <so/event/so_event_system.h>
#pragma force_active on
#pragma use_simple_stdpnew on
class Object_vptr_0 {
public:
 virtual s32 slot0(); virtual void slot1(void*,void*); virtual void* slot2();
 virtual void slot3(s32,void*); virtual void slot4(); virtual void slot5();
 virtual void slot6(); virtual s32 slot7(); virtual void slot8();
};
class DataIfc {
public:
 virtual void s0(); virtual void s1(); virtual void* s2();
 virtual void s3(); virtual void* s4(); virtual void* s5();
 virtual void s6(); virtual void s7(); virtual void s8();
};
class Acc {
public:
 virtual void* m0(); virtual void* m1(); virtual s32 m2();
 virtual void* m3(); virtual void* m4(); virtual void* m5();
 virtual void* m6(); virtual void m7(); virtual void m8();
 virtual void* m9(); virtual void* m10(); virtual void* m11();
 virtual void* m12(); virtual void m13(); virtual void m14();
 virtual void m15(); virtual void* m16(); virtual void m17();
 virtual f32 m18(); virtual void* m19(); virtual void m20();
 virtual void m21(); virtual void m22(); virtual void m23();
 virtual void* m24(); virtual void m25(); virtual void m26();
 virtual s32 m27(); virtual s32 m28(); virtual s32 m29();
 virtual s32 m30(); virtual void m31(); virtual void m32();
 virtual void m33(); virtual s32 m34(s32,s32);
};
struct ResetMode { u8 value; char padding[3]; };
struct CommandKind { s16 value; char padding[2]; };
struct StackHeader {
 void* vt; void* calc;
 u32 flags:8; u32 state:8; u32 preserved:16;
 acCmdInterpreterStackData entries[8];
};
struct EventPack { void* vt; s16 id,unit; s32 result; };
extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_2BEE8[];
extern char lbl_27_data_15218[];
extern char lbl_27_data_20878[];
extern char lbl_27_data_4605C[];
extern char lbl_27_data_4606C[];
extern char lbl_27_data_462D8[];
extern char lbl_27_data_46658[];
extern char lbl_27_data_466B8[];
extern char lbl_27_data_81A0[];
extern char lbl_27_data_128[];
extern char lbl_27_bss_170[];
extern char lbl_27_bss_188[];
extern char lbl_27_bss_344[];
extern char lbl_27_bss_35C[];
extern char lbl_27_bss_384[];
extern char lbl_27_bss_398[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3BC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_3DC[];
extern char lbl_27_bss_3F4[];
extern char lbl_27_bss_404[];
extern char lbl_27_bss_414[];
extern char lbl_27_bss_424[];
extern char lbl_27_bss_444[];
extern char lbl_27_bss_47C[];
extern char lbl_27_bss_48C[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_4E8[];
extern char lbl_27_bss_530[];
extern char lbl_27_bss_55C[];
extern char lbl_27_bss_584[];
extern char lbl_27_bss_598[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_604[];
extern char lbl_27_bss_628[];
extern char lbl_27_bss_654[];
extern char lbl_27_bss_66C[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_6E8[];
extern char lbl_27_bss_8B4[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char __RTTI__11soEventUnit[];
extern const char lbl_27_rodata_2B60[];
void fn_27_1DC5E8(void*,s32,void*,void*,void*,void*,u8,s32,void*,s32,s32,s32,s32,s32,s32,s32);
void fn_27_1D7EF0(void*,void*,s32,s32,s32,void*,void*,s32);
void fn_27_1E0D84(void*);
void fn_27_1E107C(void*,void*,void*,u8,void*);
void fn_27_1E10E0(void*,void*,void*,void*,f32);
void fn_27_1E11CC(void*,void*,void*);
void fn_27_1E146C(void*,void*,void*);
void fn_27_1E1524(void*,void*,void*);
void fn_27_1E15A4(void*,void*,void*);
void fn_27_1E1648(void*,void*);
void fn_27_1E16CC(void*,s16);
void fn_27_1E1774(void*);
void fn_27_1E1800(void*,void*,void*,void*,void*,void*,void*);
void fn_27_1E1A6C(void*,void*,void*);
void fn_27_5AD88(void*,void*,void*,s32);
void fn_27_5C600(void*,void*);
void fn_27_A1DA4(void*,void*,void*);
void fn_27_B62E4(void*,void*,s32,f32);
void fn_27_BEBB4(void*,void*,s32,s32);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*,s32);
void* __dynamic_cast(void*,long,const void*,const void*,s16);
}
inline s32& word(char* p,s32 o) { return *(s32*)(p+o); }
inline void*& ptr(char* p,s32 o) { return *(void**)(p+o); }
inline s32 eventId(char* p) {
 return ((Object_vptr_0*)((char*)*(void**)((char*)ptr(p,0x8dc)+0x80)+8))->slot7();
}
extern "C" char* fn_27_1DF5F8(char* self,s32 owner,void* resource,void* common,u8 flag) {
 const f32* rp=(const f32*)lbl_27_rodata_2B60;
 char descriptor[64];
 void* b;
 void* c;
 DataIfc* di=*(DataIfc**)((char*)resource+4);
 c=di->s5();
 b=di->s4();
 void* a=di->s2();
 fn_27_1DC5E8(descriptor,0x85,common,a,b,c,0,-1,g_soParamAccesserNull,0,0,0,0,0,0,0);
 fn_27_1D7EF0(self,lbl_27_data_4605C,word(descriptor,4),word(descriptor,8),owner,resource,self+0x8d0,1);
 char* so=self+0xcc;
 char* base=lbl_27_data_462D8;
 ptr(self,0x3c)=base;
 ptr(self,0x40)=base+0x64;
 ptr(self,0x48)=base+0x70;
 ptr(self,0x54)=base+0x84;
 ptr(self,0x64)=base+0xdc;
 ptr(self,0x70)=base+0xec;
 ptr(self,0x7c)=base+0x100;
 ptr(self,0x88)=base+0x118;
 ptr(self,0x90)=base+0x124;
 fn_27_1E0D84(so);
 new (so+0x804) soModuleAccesser(
 (StageObject*)self,
 (soResourceModule*)(so+0x924),
 (soModelModule*)(so+0xa50),
 (soMotionModule*)(so+0xbf4),
 (soPostureModule*)(so+0xd68),
 (soGroundModule*)lbl_27_bss_344,
 (soSituationModule*)lbl_27_bss_35C,
 so+0xdd0,
 (soCollisionAttackModule*)lbl_27_bss_384,
 (soCollisionHitModule*)lbl_27_bss_398,
 (soCollisionShieldModule*)lbl_27_bss_3AC,
 (soCollisionShieldModule*)lbl_27_bss_3AC,
 (soCollisionShieldModule*)lbl_27_bss_3AC,
 lbl_27_bss_3BC,
 (soCollisionSearchModule*)lbl_27_bss_3CC,
 (soDamageModule*)lbl_27_bss_3DC,
 lbl_27_bss_3F4,lbl_27_bss_404,
 (soStopModule*)lbl_27_bss_414,
 lbl_27_bss_424,so+0xe24,
 (soSoundModule*)lbl_27_bss_444,
 (soLinkModule*)(so+0xf40),
 (soVisibilityModule*)(so+0xf94),
 (soControllerModule*)lbl_27_bss_47C,
 (soCameraModule*)lbl_27_bss_48C,
 (soWorkManageModule*)(so+0xfac),
 lbl_27_bss_4BC,
 (soAnimCmdModule*)(so+0xfe0),
 (soStatusModule*)lbl_27_bss_4E8,
 lbl_27_bss_170,lbl_27_bss_188,
 (soKineticModule*)lbl_27_bss_530,
 (soEventManageModule*)(so+0xb8),
 lbl_27_bss_55C,
 (soEffectModule*)(so+0x114c),
 lbl_27_bss_584,
 (soAreaModule*)lbl_27_bss_598,
 lbl_27_bss_5B0,lbl_27_bss_5D8,so+0x128c,lbl_27_bss_604,
 (soShadowModule*)(so+0x12d8),
 (soItemManageModule*)lbl_27_bss_628,
 (soColorBlendModule*)(so+0x1324),
 lbl_27_bss_654,lbl_27_bss_66C,
 (soSlowModule*)(so+0x147c),lbl_27_bss_69C,
 so+0x8e4,(soParamCustomizeModule*)(so+0x8fc),lbl_27_bss_6E8);
 Heaps::HeapType hb;
 Heaps::HeapType hc;
 s32 heapSize=((Acc*)descriptor)->m30();
 hc=(Heaps::HeapType)((Acc*)descriptor)->m29();
 hb=(Heaps::HeapType)((Acc*)descriptor)->m28();
 Heaps::HeapType ha=(Heaps::HeapType)((Acc*)descriptor)->m27();
 new (so+0x8e4) soHeapModuleImpl(ha,hb,hc,heapSize);
 so[0x900]=0; ptr(so,0x8fc)=lbl_27_data_2BEE8;
 *(f32*)(so+0x904)=rp[0]; *(f32*)(so+0x908)=rp[0];
 s32 resourceFlags=((Acc*)descriptor)->m2();
 fn_27_1E107C(so+0x90c,((Acc*)descriptor)->m0(),((Acc*)descriptor)->m1(),(u8)resourceFlags,so+0x804);
 void* md=((Acc*)descriptor)->m24(); f32 scale=((Acc*)descriptor)->m18();
 fn_27_1E10E0(so+0x93c,so+0x804,md,lbl_27_bss_A48,scale);
 fn_27_1E11CC(so+0xb1c,so+0x804,((Acc*)descriptor)->m4());
 fn_27_1E146C(so+0xd64,so+0x804,lbl_27_bss_A48);
 ((Acc*)descriptor)->m8(); eventId(so);
 fn_27_1E1524(so+0xdb0,((Acc*)descriptor)->m3(),so+0x804);
 fn_27_1E15A4(so+0xe20,so+0x804,((Acc*)descriptor)->m5());
 ((Acc*)descriptor)->m31(); fn_27_1E1648(so+0xe30,so+0x804);
 fn_27_5AD88(so+0xf94,so+0x804,((Acc*)descriptor)->m6(),1);
 eventId(so);
 ((Acc*)descriptor)->m22(); ((Acc*)descriptor)->m21();
 fn_27_A1DA4(so+0xfac,so+0x804,((Acc*)descriptor)->m19());
 fn_27_1E16CC(so+0xfe0,(s16)eventId(so));
 ((Acc*)descriptor)->m26(); ((Acc*)descriptor)->m7(); fn_27_1E1774(so+0x1088);
 fn_27_1E1800(so+0x10e8,so+0x804,((Acc*)descriptor)->m9(),((Acc*)descriptor)->m10(),((Acc*)descriptor)->m11(),((Acc*)descriptor)->m12(),lbl_27_bss_A48);
 ((Acc*)descriptor)->m20(); ((Acc*)descriptor)->m14(); ((Acc*)descriptor)->m13(); ((Acc*)descriptor)->m15();
 fn_27_1E1A6C(so+0x1288,so+0x804,((Acc*)descriptor)->m16());
 ((Acc*)descriptor)->m32(); fn_27_B62E4(so+0x12d8,so+0x804,0,rp[1]);
 ((Acc*)descriptor)->m23(); fn_27_BEBB4(so+0x1324,so+0x804,-1,0);
 ((Acc*)descriptor)->m25(); fn_27_5C600(so+0x147c,so+0x804);
 if (((Object_vptr_0*)(so+0x10c0))->slot0()==0) {
  ((Object_vptr_0*)*(void**)((char*)ptr(so,0x8dc)+0x64))->slot3(1,so+0x10c0);
 }
 ((Acc*)descriptor)->m34(0,2); ((Acc*)descriptor)->m34(0,1); ((Acc*)descriptor)->m34(0,0);
 ((Acc*)descriptor)->m34(1,2); ((Acc*)descriptor)->m34(1,1); ((Acc*)descriptor)->m34(1,0);
 ((Acc*)descriptor)->m34(2,2); ((Acc*)descriptor)->m34(2,1); s32 ret=((Acc*)descriptor)->m34(2,0);
 char* arr=so+0x149c;
 word(arr,4)=0; ptr(arr,0)=lbl_27_data_20878; word(arr,8)=ret; word(arr,12)=2;
 if (ret==0) word(arr,12)=0;
 StackHeader* header=(StackHeader*)(arr+0x14);
 header->vt=lbl_27_data_15218;
 header->calc=lbl_27_data_15218+0x48;
 header->flags=0;
 header->state=0;
 acCmdInterpreterStackData* p=header->entries;
 do {
  new (p) acCmdInterpreterStackData(acCmdInterpreterStackData::Invalid,0,false,0,rp[2]);
  ++p;
 } while (p<header->entries+8);
 ptr(arr,0xd0)=arr; ptr(arr,0xc0)=lbl_27_data_46658;
 CommandKind kind;
 char* interp;
 int result=0;
 soArrayVector<acCmdInterpreterStackData,8>* stack=(soArrayVector<acCmdInterpreterStackData,8>*)(arr+0x14);
 ptr((char*)stack,0xc0)=lbl_27_bss_D8C; ptr((char*)stack,0xc4)=lbl_27_bss_D8C;
 ResetMode reset; reset.value=0;
 s32 id=eventId(so);
 interp=arr+0xdc;
 new (interp) acCmdInterpreter(stack,1,0,&reset.value,rp[0]);
 EventPack* pack=(EventPack*)(interp+0x34);
 pack->vt=lbl_27_data_466B8;
 pack->id=id; pack->unit=5; pack->result=result;
 s32 eid=(s16)id;
 if(eid>0 && eid>-1) {
  if(soEventSystem::getInstance()->getInstanceManager().isContain(eid)) {
   if(soEventSystem::getInstance()->getManager(pack->id)->getObserverCapacity(pack->unit)==0)
    pack->result=result;
   else {
    soEventManager* m;
    s16 unit;
    unit=pack->unit;
    m=soEventSystem::getInstance()->getManager(pack->id);
    if (m->getObserverCapacity(unit)==0) {
     result=0;
    } else {
     void* p=m->getEventUnit(unit);
     Object_vptr_0* u=(Object_vptr_0*)__dynamic_cast(p,0,lbl_27_data_128,__RTTI__11soEventUnit,0);
     if (u==0) {
      result=0;
     } else {
      result=u->slot7();
     }
    }
    pack->result=result;
   }
  }
 }
 ptr(interp,0)=lbl_27_data_81A0;
 ptr(interp,0x34)=lbl_27_data_81A0+0x20;
 word(interp,0x40)=2; word(interp,0x44)=0; word(interp,0x48)=0; word(interp,0x4c)=0;
 kind.value=2; void* pair[2]={arr+0xdc,arr+0xc0};
 ((Object_vptr_0*)*(void**)((char*)ptr(so,0x8dc)+0x6c))->slot1(pair,&kind.value);
 ((Acc*)descriptor)->m34(3,2); ((Acc*)descriptor)->m34(3,1); ((Acc*)descriptor)->m34(3,0);
 ((Acc*)descriptor)->m34(5,2); ((Acc*)descriptor)->m34(5,1); ((Acc*)descriptor)->m34(5,0);
 fn_27_1D90FC(self);
 base=lbl_27_data_4606C;
 ptr(self,0x3c)=base; ptr(self,0x40)=base+0x64;
 ptr(self,0x48)=base+0x70; ptr(self,0x54)=base+0x84;
 ptr(self,0x64)=base+0xdc; ptr(self,0x70)=base+0xec;
 ptr(self,0x7c)=base+0x100; ptr(self,0x88)=base+0x118;
 ptr(self,0x90)=base+0x124;
 self[0x169a]=flag;
 char* tail=self+0x169c;
 word(tail,4)=0; ptr(tail,0)=lbl_27_data_20878;
 word(tail,8)=0; word(tail,12)=0;
 ptr(tail,0x10)=lbl_27_data_46658;
 ptr(tail,0x20)=tail; ptr(tail,0x24)=lbl_27_bss_8B4; ptr(tail,0x28)=lbl_27_bss_8B4;
 fn_27_1D8FC8(self,0);
 return self;
}
