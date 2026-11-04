#include <gf/gf_task.h>
#include <so/event/so_event_system.h>
#include <string.h>
#pragma force_active on
extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*,const char*,gfTask::Category,int,int,bool);
void __construct_array(void*,void (*)(void*),void (*)(void*),unsigned long,int);
void* __dynamic_cast(void*,long,const void*,const void*,short);
void fn_27_2ADF38(void*); void fn_27_2ADF54(void*);
void fn_27_2ADF94(void*); void fn_27_2ADFB0(void*);
void fn_27_2ADFF0(void*); void fn_27_2AE00C(void*);
void fn_27_2AE04C(void*); void fn_27_2AE068(void*);
extern char lbl_27_data_73558[],lbl_27_data_264B8[],lbl_27_data_73A68[];
extern char lbl_27_data_748E8[],lbl_27_data_74718[],lbl_27_data_74550[],lbl_27_data_74368[];
extern char lbl_27_data_16390[],__RTTI__11soEventUnit[];
extern int lbl_27_data_74198,lbl_27_data_7419C;
extern const float lbl_27_rodata_5D5C;
extern char* g_soDisposeInstanceManager;
}
class DisposeObserver { public: virtual void addObserver(s16,s8); };
class Class_19CF0 {
public:
virtual void fn_27_DC378(); virtual void fn_27_DBD1C();
virtual void fn_27_DBD2C(); virtual void fn_27_D3664();
virtual void fn_27_D3684(); virtual void fn_27_D35A4();
virtual s16 fn_27_DBE30(void*,s8);
virtual void fn_27_DBFE0(); virtual void fn_27_DC330();
};
class DisposeManagerPart {
public:
virtual void slot0(); virtual void slot1(); virtual void slot2();
virtual void slot3(); virtual void slot4(); virtual void slot5();
virtual void slot6(); virtual void slot7(); virtual void slot8();
virtual void slot9(); virtual void slot10(); virtual void slot11();
virtual void slot12(); virtual void slot13(); virtual void slot14();
virtual void slot15(); virtual void slot16(); virtual void slot17();
virtual void slot18(); virtual s32 slot19();
};
struct Self { char data[0x14c0]; };
struct List128Flags { s32 a:9; s32 b:9; s32 c:9; s32 d:9; };
struct List64Flags { s32 a:8; s32 b:8; s32 c:8; s32 d:8; };
struct List12Flags { s32 a:5; s32 b:5; s32 c:5; s32 d:5; };
struct List3Flags { s32 a:3; s32 b:3; s32 c:3; s32 d:3; };
struct ObserverSelf { void* vt; s16 a,b,c; };
#define I(o) (*(int*)(self->data+(o)))
#define P(o) (*(void**)(self->data+(o)))
#define H(o) (*(s16*)(self->data+(o)))
#define B(o) (*(u8*)(self->data+(o)))
#define A(o) (self->data+(o))
static inline void initObserver(void* ptr) {
ObserverSelf* p=(ObserverSelf*)ptr;
p->a=-1; p->b=0; p->c=-1; p->vt=lbl_27_data_264B8;
((DisposeObserver*)p)->addObserver(-1,-1);
}
static inline void init128(void* ptr) {
char* p=(char*)ptr; *(void**)p=lbl_27_data_748E8;
List128Flags* f=(List128Flags*)(p+4);
f->a=-1; f->b=-1; f->c=-1;
__construct_array(p+12,fn_27_2ADF38,fn_27_2ADF54,12,128);
((soArrayContractible<void*>*)p)->clear();
}
static inline void init64(void* ptr) {
char* p=(char*)ptr; *(void**)p=lbl_27_data_74718;
List64Flags* f=(List64Flags*)(p+4);
f->a=-1; f->b=-1; f->c=-1;
__construct_array(p+8,fn_27_2ADF94,fn_27_2ADFB0,12,64);
((soArrayContractible<void*>*)p)->clear();
}
static inline void init12(void* ptr) {
char* p=(char*)ptr; *(void**)p=lbl_27_data_74550;
List12Flags* f=(List12Flags*)(p+4);
f->a=-1; f->b=-1; f->c=-1;
__construct_array(p+8,fn_27_2ADFF0,fn_27_2AE00C,12,12);
((soArrayContractible<void*>*)p)->clear();
}
static inline void init3(void* ptr) {
char* p=(char*)ptr; *(void**)p=lbl_27_data_74368;
List3Flags* f=(List3Flags*)(p+4);
f->a=-1; f->b=-1; f->c=-1;
__construct_array(p+8,fn_27_2AE04C,fn_27_2AE068,12,3);
((soArrayContractible<void*>*)p)->clear();
}
static inline bool isValid(ObserverSelf* p) {
    if(p->a<0) return false;
    if(p->b<0) return false;
    return true;
}
extern "C" Self* fn_27_2A1724(Self* self) {
__ct__6gfTaskFPCcQ26gfTask8Categoryiib(self,lbl_27_data_73558,gfTask::Category_Item,8,4,true);
initObserver(A(0x40));
P(0x3c)=lbl_27_data_73A68;
P(0x40)=lbl_27_data_73A68+0x64;
I(0x4c)=0; I(0x50)=0; I(0x54)=255;
B(0xbc)=1; B(0xbd)=0; I(0xc0)=0; I(0xc4)=0;
init128(A(0xc8));
B(0x6d4)=0;
init64(A(0x6d8)); init64(A(0x9e0)); init64(A(0xce8));
I(0xff0)=0; B(0xff4)=0; B(0xff5)=0; B(0x1008)=0;
I(0x10bc)=-1; I(0x10c0)=0; I(0x10c4)=0;
init12(A(0x10c8));
I(0x1160)=0; I(0x1164)=0; I(0x1168)=0; I(0x116c)=0;
init3(A(0x1170));
I(0x119c)=lbl_27_data_74198; I(0x11a0)=lbl_27_data_74198;
I(0x11a4)=lbl_27_data_74198; I(0x11a8)=lbl_27_data_74198;
I(0x11ac)=lbl_27_data_74198; I(0x11b0)=lbl_27_data_74198;
I(0x119c)=lbl_27_data_7419C; I(0x11a0)=lbl_27_data_7419C;
I(0x11a4)=lbl_27_data_7419C; I(0x11a8)=lbl_27_data_7419C;
I(0x11ac)=lbl_27_data_7419C; I(0x11b0)=lbl_27_data_7419C;
I(0x147c)=0; I(0x1480)=-1;
*(float*)A(0x1484)=lbl_27_rodata_5D5C;
I(0x1488)=0; I(0x148c)=-1; I(0x1490)=-1;
I(0x1494)=0; I(0x1498)=0;
B(0x149c)=0; B(0x149d)=0; B(0x149e)=1; B(0x149f)=1;
B(0x14a0)=1; B(0x14a1)=1; B(0x14a2)=1; B(0x14a3)=0;
I(0x14a4)=-1; I(0x14a8)=0; B(0x14ac)=0;
I(0x14b0)=0; B(0x14b4)=0; B(0x14b5)=0;
I(0x14b8)=0; I(0x14bc)=0;
s32 manageId=((DisposeManagerPart*)(g_soDisposeInstanceManager+0x60))->slot19();
u32 check4=0;
s32 check3=0;
s32 checkID=H(0x44);
bool check2=false;
bool check1=false;
if(checkID<0) goto valid_done;
if(H(0x46)<0) goto valid_done;
check1=true;
valid_done:
if(check1 && H(0x48)>-1) check2=true;
if(check2!=0) {
if(soEventSystem::getInstance()->getInstanceManager().isContain(checkID)==1) check3=1;
}
if(check3!=0) {
if(soEventSystem::getInstance()->getManager(H(0x44))->getObserverCapacity(H(0x46))==1) check4=1;
}
if(check4==1) {
s32 removeID=H(0x44);
if(soEventSystem::getInstance()->getInstanceManager().isContain(removeID)==1)
soEventSystem::getInstance()->getManager(H(0x44))->eraseObserver(H(0x46),H(0x48));
H(0x48)=-1; H(0x44)=-1;
}
if((s16)manageId>-1 && H(0x46)>-1) {
if(soEventSystem::getInstance()->getInstanceManager().isContain((s16)manageId)!=0) {
if(soEventSystem::getInstance()->getManager((s16)manageId)->isNullUnit(H(0x46))!=1) {
soEventManager* mgr=soEventSystem::getInstance()->getManager((s16)manageId);
s16 ret;
if(mgr->getObserverCapacity(H(0x46))==0) ret=-1;
else {
Class_19CF0* unit=(Class_19CF0*)__dynamic_cast(mgr->getEventUnit(H(0x46)),0,lbl_27_data_16390,__RTTI__11soEventUnit,0);
if(unit==0) ret=-1;
else ret=unit->fn_27_DBE30(A(0x40),-1);
}
H(0x48)=ret;
if(ret>-1 && ret>-1) H(0x44)=(s16)manageId;
}
}
}
I(0x119c)=-1; I(0x11a0)=-1; I(0x11a4)=-1;
I(0x11a8)=-1; I(0x11ac)=-1; I(0x11b0)=-1;
I(0x11b0)&=0x3ffff;
memset(A(0xff8),0,16);
memset(A(0x1009),0,0xb2);
memset(A(0x11b4),0,0x2c8);
return self;
}
