#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>
#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on
inline void* operator new[](size_t, void* storage) { return storage; }
extern "C" {
void fn_27_1257EC(void*,long,int,int,void*);
void fn_125_8068(void*);
void fn_27_14B5F8(void*,void*);
void fn_125_83BC(void*,u32,u32,u8,void*);
void fn_125_8424(void*,void*,int,float,void*);
void fn_125_84AC(void*,void*,int);
void fn_125_8680(void*,void*,void*);
void fn_125_86F0(void*,void*,int);
void fn_27_3513C(void*,short,void*,void*);
void fn_125_7F9C(void*,int,void*);
void fn_125_8754(void*,void*,int,u8,void*);
void fn_125_8818(void*,void*,int,u8,void*);
void fn_125_88DC(void*,void*,int,u8);
void fn_125_89B0(void*,void*,int,u8);
void fn_125_8A84(void*,void*,int,u8,void*);
void fn_125_8B1C(void*,void*,void*);
void fn_27_64C8C(void*,void*,int);
void fn_27_65EE4(void*,void*);
void fn_27_154088(void*,void*);
void fn_27_693F4(void*,void*);
void fn_125_8B88(void*,void*,int);
void fn_125_8BE4(void*,void*,int,void*);
void fn_125_8C74(void*,void*);
void fn_27_5B248(void*,void*,int,int);
void fn_125_8CC8(void*,void*,short);
void fn_125_8D38(void*,void*,int,int,void*);
void fn_27_A1DA4(void*,void*,int);
void fn_125_8DA4(void*,short);
void fn_125_8DE8(void*,void*,int,int);
void fn_125_92A0(void*,void*);
void fn_125_9670(void*);
void fn_125_96D0(void*,void*);
void fn_125_9A64(void*,void*,int,int,int,int,void*);
void fn_27_14FBD8(void*,void*);
void fn_125_9B30(void*,void*,u8,void*);
void fn_125_9BC8(void*,void*,int);
void fn_27_ACAC4(void*,void*,int,int,u8,f32);
void fn_125_9C28(void*,void*,int);
void fn_27_BEBB4(void*,void*,int,int);
void fn_27_C20D8(void*,void*,int,int,int);
void fn_27_196664(void*,void*);
void fn_27_5BED0(void*,void*);
void fn_27_14CCEC(void*,void*);
void fn_27_C74BC(void*,void*,int);
void fn_27_1A60B8(void*,int);
void fn_27_D22D0(void*,int);
void fn_125_9CA4(void*,void*,void*,void*);
void fn_125_9EC0(void*,void*,int);
void fn_27_C7744(void*,void*,int);
void fn_27_1A079C(void*,int);
void fn_125_9F78(void*,int,void*);
void fn_27_14E0B8(void*,void*);
void fn_27_1404D4(void*,void*);
void fn_125_7F88(void*,int);
void fn_27_17437C(void*,void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_1A711C(void*,int,void*,int);
void fn_27_195B34(void*,void*,void*);
void fn_27_B62E4(void*,void*,float,int);
void fn_125_9CC0(void*,short,void*,int,int,float,signed char*);
void* fn_125_9E50();
void* fn_125_9F3C(void*,int);
void* __dynamic_cast(void*,long,const void*,const void*,short);
#define D(n) extern char n[];
D(lbl_125_data_62C) D(lbl_125_data_148) D(lbl_27_bss_3AC) D(lbl_27_bss_3CC) D(lbl_27_bss_4BC)
D(lbl_27_bss_46C0) D(lbl_27_bss_46D8) D(lbl_27_bss_5B0) D(lbl_27_bss_5D8) D(lbl_27_bss_69C)
D(lbl_27_bss_A48) D(lbl_27_bss_D8C) D(lbl_27_bss_8C4) D(lbl_125_data_22D8) D(lbl_125_data_2380)
D(lbl_125_data_2150) D(lbl_125_data_21D0)
D(lbl_27_data_2F9F8) D(lbl_27_data_2FAA0) D(lbl_27_data_2FB48) D(lbl_27_data_2FBF0)
D(lbl_27_data_2FC98) D(lbl_27_data_2FD40) D(lbl_27_data_2FDE8)
D(lbl_27_bss_7BEC) D(lbl_27_bss_7B1C) D(lbl_27_bss_7B2C) D(lbl_125_bss_1A0) D(lbl_27_bss_7B3C)
#undef D
}
class SlopeStorage {
public:
    SlopeStorage(void* acc, u8 initial, int count, f32 angle) {
        fn_27_ACAC4(this, acc, initial, count, initial, angle);
    }
};
class ShadowStorage {
public:
    ShadowStorage(void* acc, int mode, f32 opacity) {
        fn_27_B62E4(this, acc, opacity, mode);
    }
};
class ColorBlendStorage {
public:
    ColorBlendStorage(void* acc, int count, int enabled) {
        fn_27_BEBB4(this, acc, count, enabled);
    }
};
class JostleStorage {
public:
    JostleStorage(void* acc, int id, int count, int data) {
        fn_27_C20D8(this, acc, id, count, data);
    }
};
template <char* Table>
class ActionLeafStorage {
public:
    ActionLeafStorage(void* acc) {
        fn_27_17437C(this, acc);
        char* storage = (char*)this;
        *(char**)storage = Table;
        *(char**)(storage+4) = Table+0x40;
    }
};
static inline void* dcast(void* p, long off) { return __dynamic_cast(p, off, lbl_125_data_22D8, lbl_125_data_2380, (short)off); }
class V {
public:
#define M(n) virtual int m##n();
M(08) M(0c)
virtual u8 m10();
M(14) M(18) M(1c) M(20) M(24) M(28) M(2c) M(30) M(34) M(38) M(3c) M(40) M(44) M(48) M(4c)
virtual float m50();
M(54)
virtual u8 m58();
M(5c) M(60) M(64) M(68) M(6c) M(70) M(74) M(78) M(7c) M(80) M(84)
virtual float m88();
M(8c)
#undef M
virtual void* m90(int,int);
};
struct CommonDataStorage {
    char* data;
    bool flagA;
    bool flagB;
    char* statusList;
    char embeddedList[0xc];

    CommonDataStorage(char* common, void* storage)
        : data(common), flagA(false), flagB(false), statusList(embeddedList) {
        fn_27_1A711C(embeddedList,4,storage,0);
        ((V*)embeddedList)->m3c();
    }
};
class HV {
public:
virtual void h08(); virtual void h0c(); virtual void h10(); virtual void h14();
virtual void h18(); virtual void h1c(); virtual void h20();
virtual short h24();
};
class Calls {
public:
virtual int a08();
virtual void a0c(void*,void*);
virtual void a10();
virtual void a14(int,void*);
virtual void a18(); virtual void a1c(); virtual void a20();
virtual void a24(void*,int);
virtual void a28();
virtual void a2c(void*);
virtual void a30(); virtual void a34(); virtual void a38();
virtual void a3c(int,int,int);
virtual void a40(); virtual void a44(); virtual void a48(); virtual void a4c(); virtual void a50();
virtual void a54(int);
virtual void a58(); virtual void a5c(); virtual void a60(); virtual void a64(); virtual void a68();
virtual void a6c(int);
virtual void a70(); virtual void a74();
virtual void a78(void*,int);
virtual void a7c(); virtual void a80(); virtual void a84(); virtual void a88();
virtual void a8c(void*);
};
class Init1 {
public:
virtual void i08();
virtual void i0c(void*);
};
struct Off8Base { int a, b; };
class Off8 : public Off8Base {
public:
virtual void o08(); virtual void o0c(); virtual void o10(); virtual void o14();
virtual void o18(); virtual void o1c(); virtual void o20(); virtual void o24();
virtual void o28(); virtual void o2c(); virtual void o30(); virtual void o34();
virtual void o38(); virtual void o3c(); virtual void o40(); virtual void o44();
virtual void o48(); virtual void o4c(); virtual void o50();
virtual void o54(int);
virtual void o58(); virtual void o5c(); virtual void o60(); virtual void o64(); virtual void o68();
virtual void o6c(int);
};
struct Pair { void* a; void* b; };
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define C(p) ((Calls*)(p))
#define B(o) (base+(o))
#define ACC ((soModuleAccesser*)B(0x9d0))
#define MOD(o) P(P(base,0xaa8),o)
#define HEAPVAL() ((HV*)(MOD(0x80)+8))->h24()
#define VT(s,t) \
P(s,0x3c)=t; P(s,0x40)=t+0x64; P(s,0x48)=t+0x70; P(s,0x54)=t+0x84; \
P(s,0x64)=t+0xdc; P(s,0x70)=t+0xec; P(s,0x7c)=t+0xfc; P(s,0x88)=t+0x110; \
P(s,0x94)=t+0x128; P(s,0xa0)=t+0x140; P(s,0xac)=t+0x158; P(s,0xb8)=t+0x16c; \
P(s,0xc4)=t+0x180; P(s,0xd0)=t+0x190; P(s,0xdc)=t+0x1c4; P(s,0xe8)=t+0x1d4; \
P(s,0xf4)=t+0x1e8; P(s,0x100)=t+0x254;
#define a48 lbl_27_bss_A48
extern "C" void* fn_125_70(char* s,long entry,int heap,int modelHeap,int motionHeap) {
char* anim;
char* base;
int v; float scale;
char* q10; char* q8; char* q1; void* cast;
void* access; char* data;
signed char f10,f9,f8,f7,f6,f5,f4,f3,f2,f1,f0;
short v10,v9,v8,v7,v6,v5,v4,v3,v2,v1,v0;
Pair p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0;
char listStorage[16];
char temp[32];
struct Param { int a,b; float c,d,e,f; unsigned int bits; } param;
void* nulls[14];
char buildStorage[0x30];
#define bd ((V*)buildStorage)
fn_27_1257EC(s,entry,0x2c,heap,s+0xb64);
VT(s,lbl_125_data_62C)
new (buildStorage) ftFighterBuildData(entry,(ftKind)0x2c,(Heaps::HeapType)heap,(Heaps::HeapType)modelHeap,(Heaps::HeapType)motionHeap,0,(soModuleAccesser*)P(s,0x60),-1,s+0x1cc64,s+0x1cc6c);
base=s+0x194;
fn_125_8068(base);
new (B(0x9d0)) soModuleAccesser((StageObject*)s,
(soResourceModule*)B(0x1168),(soModelModule*)B(0x13dc),(soMotionModule*)B(0x16cc),(soPostureModule*)B(0x1878),(soGroundModule*)B(0x1940),(soSituationModule*)B(0x1998),
B(0x1a04),(soCollisionAttackModule*)B(0x2064),(soCollisionHitModule*)B(0x26b8),
(soCollisionShieldModule*)B(0x28e4),(soCollisionShieldModule*)B(0x323c),(soCollisionShieldModule*)lbl_27_bss_3AC,
B(0x3410),(soCollisionSearchModule*)lbl_27_bss_3CC,(soDamageModule*)B(0x35a4),
B(0x36a8),B(0x370c),(soStopModule*)B(0x3740),B(0x3764),B(0x3818),
(soSoundModule*)B(0x3848),(soLinkModule*)B(0x3a1c),(soVisibilityModule*)B(0x3a70),
(soControllerModule*)B(0x4058),(soCameraModule*)B(0x4214),(soWorkManageModule*)B(0x4238),
lbl_27_bss_4BC,(soAnimCmdModule*)B(0x426c),(soStatusModule*)B(0x5130),
lbl_27_bss_46C0,lbl_27_bss_46D8,(soKineticModule*)B(0x51e0),(soEventManageModule*)B(0xb8),
B(0x1a36c),(soEffectModule*)B(0x1a414),B(0x1a54c),(soAreaModule*)B(0x1a58c),
lbl_27_bss_5B0,lbl_27_bss_5D8,B(0x1a96c),B(0x1a9b4),
(soShadowModule*)B(0x1aa34),(soItemManageModule*)B(0x1ab20),(soColorBlendModule*)B(0x1ab8c),
B(0x1ace0),B(0x1ad2c),(soSlowModule*)B(0x1ad94),lbl_27_bss_69C,
B(0xab0),(soParamCustomizeModule*)B(0xac8),B(0x1add0));
long heapSlot = bd->m80();
q8 = (char*)bd->m7c();
q1 = (char*)bd->m78();
Heaps::HeapType instanceHeap = (Heaps::HeapType)bd->m74();
new (B(0xab0)) soHeapModuleImpl(instanceHeap,(Heaps::HeapType)(long)q1,(Heaps::HeapType)(long)q8,heapSlot);
fn_27_14B5F8(B(0xac8),ACC);
fn_125_83BC(B(0x115c),bd->m08(),bd->m0c(),bd->m10(),ACC);
v=bd->m68(); scale=bd->m50();
fn_125_8424(B(0x1180),ACC,v,scale,a48);
fn_125_84AC(B(0x14a8),ACC,bd->m18());
fn_125_8680(B(0x183c),ACC,a48);
fn_125_86F0(B(0x18f0),ACC,bd->m28());
fn_27_3513C(B(0x1998),HEAPVAL(),ACC,a48);
fn_125_7F9C(B(0x19d4),bd->m14(),ACC);
#define HIT(n,o) n(B(o),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),a48);
HIT(fn_125_8754,0x1a48) HIT(fn_125_8818,0x2104)
fn_125_88DC(B(0x2720),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_125_89B0(B(0x2938),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
HIT(fn_125_8A84,0x3294)
fn_125_8B1C(B(0x34f8),ACC,a48);
fn_27_64C8C(B(0x36a8),ACC,1);
fn_27_65EE4(B(0x370c),ACC); fn_27_154088(B(0x3740),ACC); fn_27_693F4(B(0x3764),ACC);
fn_125_8B88(B(0x379c),ACC,bd->m1c());
fn_125_8BE4(B(0x3834),ACC,bd->m84(),a48);
fn_125_8C74(B(0x38a4),ACC);
fn_27_5B248(B(0x3a70),ACC,bd->m20(),2);
fn_125_8CC8(B(0x3aa0),ACC,HEAPVAL());
fn_125_8D38(B(0x41c4),ACC,bd->m5c(),bd->m60(),a48);
fn_27_A1DA4(B(0x4238),ACC,bd->m54());
fn_125_8DA4(B(0x426c),HEAPVAL());
fn_125_8DE8(B(0x4360),ACC,bd->m24(),bd->m70());
fn_125_92A0(B(0x51e0),ACC); fn_125_9670(B(0x54e8)); fn_125_96D0(B(0x56cc),ACC);
fn_125_9A64(B(0x1a3a8),ACC,bd->m2c(),bd->m30(),bd->m34(),bd->m38(),a48);
fn_27_14FBD8(B(0x1a54c),ACC);
fn_125_9B30(B(0x1a57c),ACC,bd->m58(),a48);
bd->m40(); bd->m3c(); bd->m44();
fn_125_9BC8(B(0x1a8f0),ACC,bd->m48());
new (B(0x1a9b4)) SlopeStorage(ACC,0,1,bd->m88());
new (B(0x1aa34)) ShadowStorage(ACC,0,10.0f);
fn_125_9C28(B(0x1aa7c),ACC,bd->m64());
new (B(0x1ab8c)) ColorBlendStorage(ACC,10,1);
new (B(0x1ace0)) JostleStorage(ACC,0,8,bd->m6c());
fn_27_196664(B(0x1ad2c),ACC); fn_27_5BED0(B(0x1ad94),ACC); fn_27_14CCEC(B(0x1add0),ACC);
if (((V*)B(0x56a8))->m08()==0) C(MOD(0x64))->a14(1,B(0x56a8));
fn_27_C74BC(B(0x1af50),P(P(buildStorage,0xc),0x18),14);
anim=B(0x1af60);
fn_27_1A60B8(anim,0); fn_27_1A60B8(anim+0x48c,0); fn_27_D22D0(anim+0x91c,0);
fn_125_9CA4(anim+0x9c8,anim,anim+0x48c,fn_125_9E50());
f0=0;
fn_125_9CC0(anim+0x9e4,HEAPVAL(),anim+0x91c,0,1,1.0f,&f0);
fn_125_9EC0(anim,0,0x120); fn_125_9EC0(anim+0x48c,0,0x120); fn_125_9EC0(fn_125_9E50(),0,0);
v0=1; p0.a=anim+0x9e4; p0.b=anim+0x9c8; C(MOD(0x6c))->a0c(&p0,&v0);
#define THREAD(i,o,mask,num,declaration) \
 { bd->m90(i,2); bd->m90(i,1); void* t##i=bd->m90(i,0); \
declaration q##i=anim+o; fn_27_C7744(q##i,t##i,num); fn_27_D22D0(q##i+0x14,0); \
fn_125_9CA4(q##i+0xc0,q##i,lbl_27_bss_D8C,lbl_27_bss_D8C); \
f##i=0; fn_125_9CC0(q##i+0xdc,HEAPVAL(),q##i+0x14,i,1,1.0f,&f##i); \
v##i=mask; p##i.a=q##i+0xdc; p##i.b=q##i+0xc0; C(MOD(0x6c))->a0c(&p##i,&v##i); }
THREAD(1,0xa34,2,0x1ee,)
THREAD(2,0xb60,0x40,0x1ee,char*)
THREAD(3,0xc8c,0x40,0x1ee,char*)
THREAD(4,0xdb8,2,0x1ee,char*)
THREAD(5,0xee4,0x20,0x1ee,char*)
THREAD(6,0x1010,0x80,0x1ee,char*)
THREAD(7,0x113c,0x80,0x1ee,char*)
THREAD(8,0x1268,0x20,0x1ee,)
q8=anim+0x1394; f9=1;
fn_125_9CC0(q8,HEAPVAL(),q8+0x50,9,1,1.0f,&f9);
fn_27_1A079C(q8+0x50,0);
v9=4; p9.a=q8; p9.b=lbl_27_bss_8C4; C(MOD(0x6c))->a0c(&p9,&v9);
THREAD(10,0x14b8,0x10,0x29,)
q10=(char*)bd->m90(0,0); fn_125_9EC0(fn_125_9F3C(anim,0),q10,0x112);
q10=(char*)bd->m90(0,1); fn_125_9EC0(fn_125_9F3C(anim,1),q10,0x112);
fn_125_9EC0(fn_125_9F3C(anim,0),P(P(buildStorage,0xc),0x24),14);
fn_125_9EC0(fn_125_9F3C(anim,1),P(P(buildStorage,0xc),0x28),14);
fn_125_9F78(anim,0,((ftFighterBuildData*)bd)->getAnimCmdDisguiseList(false,0));
fn_125_9F78(anim,1,((ftFighterBuildData*)bd)->getAnimCmdDisguiseList(false,1));
C(MOD(0x70))->a8c(B(0x1af50));
q10=(char*)soValueAccesser::getConstantIndefinite(ACC,0xa805,0);
cast=dcast(MOD(0x90),0);
if(cast) fn_27_14E0B8(cast,q10);
C(MOD(0x90))->a2c(q10);
fn_27_1404D4(s+0x1c6d8,P(s,0x60));
q10=s+0x1c714; fn_125_7F88(q10,0); P(q10,0)=lbl_125_data_2150;
access=P(s,0x60); heap=(int)(s+0x1cbcc);
fn_125_7F88((char*)heap,0); P((char*)heap,0)=lbl_125_data_21D0;
#define EXT(o,n) new ((char*)heap+o) ActionLeafStorage<n>(access);
EXT(8,lbl_27_data_2F9F8) EXT(0x20,lbl_27_data_2FAA0) EXT(0x34,lbl_27_data_2FB48)
EXT(0x48,lbl_27_data_2FBF0) EXT(0x5c,lbl_27_data_2FC98) EXT(0x70,lbl_27_data_2FD40) EXT(0x84,lbl_27_data_2FDE8)
P(s,0x1cc64)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7f9,0);
*(int*)(s+0x1cc68)=1;
P(s,0x1cc6c)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7fc,0);
*(int*)(s+0x1cc70)=1;
fn_27_126470(s);
((Init1*)(s+0x1c6d8))->i0c(P(s,0x60));
VT(s,lbl_125_data_148)
fn_27_C749C(s+0x1cc74);
char* commonData = (char*)g_ftCommonDataAccesser.getData((ftKind)0x2c);
anim=s+0x1cc84;
new (anim) CommonDataStorage(commonData,listStorage);
typedef void* StatusPointer;
new (nulls) StatusPointer[14]();
nulls[0]=lbl_27_bss_7BEC; nulls[1]=lbl_27_bss_7B1C; nulls[2]=lbl_27_bss_7B2C; nulls[3]=lbl_125_bss_1A0;
nulls[5]=lbl_27_bss_7B2C; nulls[6]=lbl_27_bss_7B2C; nulls[7]=lbl_27_bss_7B2C;
nulls[8]=lbl_125_bss_1A0; nulls[9]=lbl_125_bss_1A0; nulls[10]=lbl_125_bss_1A0;
nulls[11]=lbl_27_bss_7B3C; nulls[12]=lbl_27_bss_7B3C; nulls[13]=lbl_27_bss_7B3C;
C(P(P(P(s,0x60),0xd8),0x70))->a78(nulls,14);
data=P(P(s,0x1cc84),0x90);
param.a=0; param.b=0; param.c=0.0f; param.d=0.0f; param.e=0.0f; param.f=0.0f; param.bits &= 0x7fffffff;
fn_27_195B34(data,temp,&param);
C(P(P(P(s,0x60),0xd8),0x28))->a24(&param,2);
C(P(P(P(s,0x60),0xd8),0x28))->a3c(0,0,2);
((Off8*)P(P(P(s,0x60),0xd8),0x9c))->o54(0);
((Off8*)P(P(P(s,0x60),0xd8),0x9c))->o6c(20);
return s;
}
