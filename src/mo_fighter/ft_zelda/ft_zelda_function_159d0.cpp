#pragma use_simple_stdpnew on
#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>
#pragma force_active on
inline void* operator new[](size_t, void* storage) { return storage; }

extern "C" {
void fn_27_1257EC(void*, long, int, int, void*);
void* fn_104_7938(void*);
void fn_27_14B5F8(void*, void*);
void fn_104_7C8C(void*, u32, u32, u8, void*);
void fn_104_7CF4(void*, void*, int, void*);
void fn_104_19BCC(void*, void*, int);
void fn_104_7F50(void*, void*, void*);
void fn_104_7FC0(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_104_786C(void*, int, void*);
void fn_104_8024(void*, void*, int, u8, void*);
void fn_104_80E8(void*, void*, int, u8, void*);
void fn_104_81AC(void*, void*, int, u8);
void fn_104_19D68(void*, void*, int, u8);
void fn_104_8354(void*, void*, int, u8, void*);
void fn_104_83EC(void*, void*, int, u8);
void fn_104_8488(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_104_84F4(void*, void*, int);
void fn_104_8550(void*, void*, int, void*);
void fn_104_19E3C(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_104_8634(void*, void*, short);
void fn_104_86A4(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_104_8710(void*, short);
void fn_104_19E90(void*, void*, int, int);
void fn_104_1A218(void*, void*);
void fn_104_8FDC(void*);
void fn_104_1A5E8(void*, void*);
void fn_104_93B0(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_104_947C(void*, void*, u8, void*);
void fn_104_9514(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_104_9574(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A5FB4(void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_D22D0(void*, int);
void* fn_104_979C();
void fn_104_95F0(void*, void*, void*, void*);
void fn_104_960C(void*, short, void*, int, int, float, signed char*);
void fn_104_980C(void*, void*, int);
void* fn_104_1AA6C(void*, int);
void fn_104_1AAA8(void*, int, void*);
void fn_27_1A079C(void*, int);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_104_7858(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
#define D(n) extern char n[];
D(lbl_104_data_8DF4) D(lbl_104_data_8A44) D(lbl_104_data_20CC) D(lbl_104_data_214C)
D(lbl_104_data_2254) D(lbl_104_data_22FC)
D(lbl_27_data_2F9F8) D(lbl_27_data_2FAA0) D(lbl_27_data_2FB48) D(lbl_27_data_2FBF0)
D(lbl_27_data_2FC98) D(lbl_27_data_2FD40) D(lbl_27_data_2FDE8)
D(lbl_27_bss_3AC) D(lbl_27_bss_4BC) D(lbl_27_bss_46C0) D(lbl_27_bss_46D8)
D(lbl_27_bss_5B0) D(lbl_27_bss_5D8) D(lbl_27_bss_69C) D(lbl_27_bss_A48) D(lbl_27_bss_D8C)
D(lbl_27_bss_8C4) D(lbl_27_bss_7E14) D(lbl_27_bss_7E24)
D(lbl_104_bss_4F4) D(lbl_104_bss_504) D(lbl_104_bss_514) D(lbl_104_bss_524)
D(lbl_104_bss_534) D(lbl_104_bss_544) D(lbl_104_bss_1E4)
extern const float lbl_104_rodata_D8;
extern const float lbl_104_rodata_DC;
#undef D
}

class V {
public:
virtual u32 m08(); virtual u32 m0c();
virtual u8 m10();
virtual int m14(); virtual int m18(); virtual int m1c(); virtual int m20();
virtual int m24(); virtual int m28(); virtual int m2c(); virtual int m30();
virtual int m34(); virtual int m38(); virtual int m3c(); virtual int m40();
virtual int m44(); virtual int m48(); virtual int m4c();
virtual float m50();
virtual int m54();
virtual u8 m58();
virtual int m5c(); virtual int m60(); virtual int m64(); virtual int m68();
virtual int m6c(); virtual int m70(); virtual int m74(); virtual int m78();
virtual int m7c(); virtual int m80(); virtual int m84();
virtual float m88();
virtual int m8c();
virtual void* m90(int, int);
};
class HV {
public:
virtual void h08(); virtual void h0c(); virtual void h10(); virtual void h14();
virtual void h18(); virtual void h1c(); virtual void h20();
virtual short h24();
};
class Nul { public: virtual int isNull(); };
class Init1 { public: virtual void i08(); virtual void i0c(void*); };
class Calls {
public:
virtual void a08();
virtual void a0c(void*, void*);
virtual void a10();
virtual void a14(int, void*);
virtual void a18(); virtual void a1c(); virtual void a20();
virtual void a24(void*, int);
virtual void a28();
virtual void a2c(void*);
virtual void a30(); virtual void a34(); virtual void a38();
virtual void a3c(int, int, int);
virtual void a40(); virtual void a44(); virtual void a48(); virtual void a4c(); virtual void a50();
virtual void a54(int);
virtual void a58(); virtual void a5c(); virtual void a60(); virtual void a64(); virtual void a68();
virtual void a6c(int);
virtual void a70(); virtual void a74();
virtual void a78(void*, int);
virtual void a7c(); virtual void a80(); virtual void a84(); virtual void a88();
virtual void a8c(void*);
};
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
static inline void* dcast(void* p, long off) {
    return __dynamic_cast(p, off, lbl_104_data_2254, lbl_104_data_22FC, (short)off);
}

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

extern "C" void* fn_104_159D0(char* s, long entry, int heap, int modelHeap, int motionHeap) {
char* anim;
char* base;
int v;
char* q10; char* q8; char* q1; void* cast;
void* access;
signed char f10,f9,f8,f7,f6,f5,f4,f3,f2,f1,f0;
short v10,v9,v8,v7,v6,v5,v4,v3,v2,v1,v0;
Pair p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0;
void* nulls[13];
char buildStorage[0x30];
#define bd ((V*)buildStorage)
fn_27_1257EC(s,entry,0xe,heap,s+0xb64);
VT(s,lbl_104_data_8DF4)
new (buildStorage) ftFighterBuildData(entry,(ftKind)0xe,(Heaps::HeapType)heap,(Heaps::HeapType)modelHeap,(Heaps::HeapType)motionHeap,0,(soModuleAccesser*)P(s,0x60),-1,s+0x1ff54,s+0x1ff5c);
base=s+0x194;
fn_104_7938(base);
new (B(0x9d0)) soModuleAccesser((StageObject*)s,
(soResourceModule*)B(0x1168),(soModelModule*)B(0x1374),(soMotionModule*)B(0x1664),(soPostureModule*)B(0x1810),(soGroundModule*)B(0x18d8),(soSituationModule*)B(0x1930),
B(0x199c),(soCollisionAttackModule*)B(0x233c),(soCollisionHitModule*)B(0x2cd0),
(soCollisionShieldModule*)B(0x2efc),(soCollisionShieldModule*)B(0x3964),(soCollisionShieldModule*)lbl_27_bss_3AC,
B(0x3b38),(soCollisionSearchModule*)B(0x3d0c),(soDamageModule*)B(0x3ec0),
B(0x3fc4),B(0x4028),(soStopModule*)B(0x405c),B(0x4080),B(0x4134),
(soSoundModule*)B(0x4164),(soLinkModule*)B(0x4338),(soVisibilityModule*)B(0x438c),
(soControllerModule*)B(0x4974),(soCameraModule*)B(0x4b30),(soWorkManageModule*)B(0x4b54),
lbl_27_bss_4BC,(soAnimCmdModule*)B(0x4b88),(soStatusModule*)B(0x5a88),
lbl_27_bss_46C0,lbl_27_bss_46D8,(soKineticModule*)B(0x5b38),(soEventManageModule*)B(0xb8),
B(0x1d664),(soEffectModule*)B(0x1d70c),B(0x1d844),(soAreaModule*)B(0x1d884),
lbl_27_bss_5B0,lbl_27_bss_5D8,B(0x1dc64),B(0x1dcac),
(soShadowModule*)B(0x1dd2c),(soItemManageModule*)B(0x1de18),(soColorBlendModule*)B(0x1de84),
B(0x1dfd8),B(0x1e024),(soSlowModule*)B(0x1e08c),lbl_27_bss_69C,
B(0xab0),(soParamCustomizeModule*)B(0xac8),B(0x1e0c8));
long heapSlot = bd->m80();
q8 = (char*)bd->m7c();
q1 = (char*)bd->m78();
Heaps::HeapType instanceHeap = (Heaps::HeapType)bd->m74();
new (B(0xab0)) soHeapModuleImpl(instanceHeap,(Heaps::HeapType)(long)q1,(Heaps::HeapType)(long)q8,heapSlot);
fn_27_14B5F8(B(0xac8),ACC);
fn_104_7C8C(B(0x115c),bd->m08(),bd->m0c(),bd->m10(),ACC);
v=bd->m68();
bd->m50();
fn_104_7CF4(B(0x1180),ACC,v,a48);
fn_104_19BCC(B(0x1440),ACC,bd->m18());
fn_104_7F50(B(0x17d4),ACC,a48);
fn_104_7FC0(B(0x1888),ACC,bd->m28());
fn_27_3513C(B(0x1930),HEAPVAL(),ACC,a48);
fn_104_786C(B(0x196c),bd->m14(),ACC);
#define HIT(n,o) n(B(o),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),a48);
HIT(fn_104_8024,0x19e0) HIT(fn_104_80E8,0x23dc)
fn_104_81AC(B(0x2d38),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_104_19D68(B(0x2f50),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
HIT(fn_104_8354,0x39bc)
fn_104_83EC(B(0x3c1c),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_104_8488(B(0x3e14),ACC,a48);
fn_27_64C8C(B(0x3fc4),ACC,1);
fn_27_65EE4(B(0x4028),ACC); fn_27_154088(B(0x405c),ACC); fn_27_693F4(B(0x4080),ACC);
fn_104_84F4(B(0x40b8),ACC,bd->m1c());
fn_104_8550(B(0x4150),ACC,bd->m84(),a48);
fn_104_19E3C(B(0x41c0),ACC);
fn_27_5B248(B(0x438c),ACC,bd->m20(),2);
fn_104_8634(B(0x43bc),ACC,HEAPVAL());
fn_104_86A4(B(0x4ae0),ACC,bd->m5c(),bd->m60(),a48);
fn_27_A1DA4(B(0x4b54),ACC,bd->m54());
fn_104_8710(B(0x4b88),HEAPVAL());
fn_104_19E90(B(0x4c7c),ACC,bd->m24(),bd->m70());
fn_104_1A218(B(0x5b38),ACC); fn_104_8FDC(B(0x5e40)); fn_104_1A5E8(B(0x6024),ACC);
fn_104_93B0(B(0x1d6a0),ACC,bd->m2c(),bd->m30(),bd->m34(),bd->m38(),a48);
fn_27_14FBD8(B(0x1d844),ACC);
fn_104_947C(B(0x1d874),ACC,bd->m58(),a48);
bd->m40(); bd->m3c(); bd->m44();
fn_104_9514(B(0x1dbe8),ACC,bd->m48());
new (B(0x1dcac)) SlopeStorage(ACC,0,1,bd->m88());
new (B(0x1dd2c)) ShadowStorage(ACC,0,lbl_104_rodata_D8);
fn_104_9574(B(0x1dd74),ACC,bd->m64());
new (B(0x1de84)) ColorBlendStorage(ACC,10,1);
new (B(0x1dfd8)) JostleStorage(ACC,0,8,bd->m6c());
fn_27_196664(B(0x1e024),ACC); fn_27_5BED0(B(0x1e08c),ACC); fn_27_14CCEC(B(0x1e0c8),ACC);
if (((Nul*)B(0x6000))->isNull()==0) C(MOD(0x64))->a14(1,B(0x6000));
fn_27_C74BC(B(0x1e248),P(P(buildStorage,0xc),0x18),0xd);
anim=B(0x1e258);
fn_27_1A5FB4(anim,0); fn_27_1A5FB4(anim+0x488,0); fn_27_D22D0(anim+0x914,0);
fn_104_95F0(anim+0x9c0,anim,anim+0x488,fn_104_979C());
f0=0;
fn_104_960C(anim+0x9dc,HEAPVAL(),anim+0x914,0,1,lbl_104_rodata_DC,&f0);
fn_104_980C(anim,0,0x11f); fn_104_980C(anim+0x488,0,0x11f); fn_104_980C(fn_104_979C(),0,0);
v0=1; p0.a=anim+0x9dc; p0.b=anim+0x9c0; C(MOD(0x6c))->a0c(&p0,&v0);
#define THREAD(i,o,mask,num,declaration) \
 { bd->m90(i,2); bd->m90(i,1); void* t##i=bd->m90(i,0); \
declaration q##i=anim+o; fn_27_C7744(q##i,t##i,num); fn_27_D22D0(q##i+0x14,0); \
fn_104_95F0(q##i+0xc0,q##i,lbl_27_bss_D8C,lbl_27_bss_D8C); \
f##i=0; fn_104_960C(q##i+0xdc,HEAPVAL(),q##i+0x14,i,1,lbl_104_rodata_DC,&f##i); \
v##i=mask; p##i.a=q##i+0xdc; p##i.b=q##i+0xc0; C(MOD(0x6c))->a0c(&p##i,&v##i); }
THREAD(1,0xa2c,2,0x1e6,)
THREAD(2,0xb58,0x40,0x1e6,char*)
THREAD(3,0xc84,0x40,0x1e6,char*)
THREAD(4,0xdb0,2,0x1e6,char*)
THREAD(5,0xedc,0x20,0x1e6,char*)
THREAD(6,0x1008,0x80,0x1e6,char*)
THREAD(7,0x1134,0x80,0x1e6,char*)
THREAD(8,0x1260,0x20,0x1e6,)
q8=anim+0x138c; f9=1;
fn_104_960C(q8,HEAPVAL(),q8+0x50,9,1,lbl_104_rodata_DC,&f9);
fn_27_1A079C(q8+0x50,0);
v9=4; p9.a=q8; p9.b=lbl_27_bss_8C4; C(MOD(0x6c))->a0c(&p9,&v9);
THREAD(10,0x14b0,0x10,0x29,)
q10=(char*)bd->m90(0,0); fn_104_980C(fn_104_1AA6C(anim,0),q10,0x112);
q10=(char*)bd->m90(0,1); fn_104_980C(fn_104_1AA6C(anim,1),q10,0x112);
fn_104_980C(fn_104_1AA6C(anim,0),P(P(buildStorage,0xc),0x24),0xd);
fn_104_980C(fn_104_1AA6C(anim,1),P(P(buildStorage,0xc),0x28),0xd);
fn_104_1AAA8(anim,0,((ftFighterBuildData*)buildStorage)->getAnimCmdDisguiseList(false,0));
fn_104_1AAA8(anim,1,((ftFighterBuildData*)buildStorage)->getAnimCmdDisguiseList(false,1));
C(MOD(0x70))->a8c(B(0x1e248));
q10=(char*)soValueAccesser::getConstantIndefinite(ACC,0xa805,0);
cast=dcast(MOD(0x90),0);
if(cast) fn_27_14E0B8(cast,q10);
C(MOD(0x90))->a2c(q10);
fn_27_1404D4(s+0x1f9c8,P(s,0x60));
q10=s+0x1fa04; fn_104_7858(q10,0); P(q10,0)=lbl_104_data_20CC;
access=P(s,0x60); heap=(int)(s+0x1febc);
fn_104_7858((char*)heap,0); P((char*)heap,0)=lbl_104_data_214C;
#define EXT(o,n) new ((char*)heap+o) ActionLeafStorage<n>(access);
EXT(8,lbl_27_data_2F9F8) EXT(0x20,lbl_27_data_2FAA0) EXT(0x34,lbl_27_data_2FB48)
EXT(0x48,lbl_27_data_2FBF0) EXT(0x5c,lbl_27_data_2FC98) EXT(0x70,lbl_27_data_2FD40)
EXT(0x84,lbl_27_data_2FDE8)
P(s,0x1ff54)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7f9,0);
*(int*)(s+0x1ff58)=1;
P(s,0x1ff5c)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7fc,0);
*(int*)(s+0x1ff60)=1;
fn_27_126470(s);
((Init1*)(s+0x1f9c8))->i0c(P(s,0x60));
VT(s,lbl_104_data_8A44)
fn_27_C749C(s+0x1ff64);
P(s,0x1ff74)=(char*)g_ftCommonDataAccesser.getData((ftKind)0xe);
typedef void* StatusPointer;
new (nulls) StatusPointer[13]();
nulls[0]=lbl_27_bss_7E14; nulls[1]=lbl_104_bss_4F4; nulls[2]=lbl_104_bss_514;
nulls[3]=lbl_104_bss_544; nulls[4]=lbl_104_bss_1E4; nulls[5]=lbl_27_bss_7E14;
nulls[6]=lbl_27_bss_7E24; nulls[7]=lbl_27_bss_7E14; nulls[8]=lbl_104_bss_504;
nulls[10]=lbl_104_bss_524; nulls[11]=lbl_104_bss_534; nulls[12]=lbl_104_bss_544;
C(P(P(P(s,0x60),0xd8),0x70))->a78(nulls,0xd);
return s;
}
