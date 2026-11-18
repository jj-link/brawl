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
void fn_95_8010(void*);
void fn_27_14B5F8(void*, void*);
void fn_95_8364(void*, u32, u32, u8, void*);
void fn_95_83CC(void*, void*, int, float, void*);
void fn_95_8454(void*, void*, int);
void fn_95_8628(void*, void*, void*);
void fn_95_8698(void*, void*, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_95_7F44(void*, int, void*);
void fn_95_86FC(void*, void*, int, u8, void*);
void fn_95_87C0(void*, void*, int, u8, void*);
void fn_95_8884(void*, void*, int, u8);
void fn_95_8958(void*, void*, int, u8);
void fn_95_8A2C(void*, void*, int, u8, void*);
void fn_95_8AC4(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_95_8B30(void*, void*, int);
void fn_95_8B8C(void*, void*, int, void*);
void fn_95_8C1C(void*, void*);
void fn_27_5B248(void*, void*, int, int);
void fn_95_8C70(void*, void*, short);
void fn_95_8CE0(void*, void*, int, int, void*);
void fn_27_A1DA4(void*, void*, int);
void fn_95_8D4C(void*, short);
void fn_95_8D90(void*, void*, int, int);
void fn_95_9248(void*, void*);
void fn_95_9618(void*);
void fn_95_9678(void*, void*);
void fn_95_9B44(void*, void*, int, int, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_95_9C10(void*, void*, u8, void*);
void fn_95_9CA8(void*, void*, int);
void fn_27_ACAC4(void*, void*, int, int, u8, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_95_9D08(void*, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, int);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A65CC(void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_D22D0(void*, int);
void* fn_95_9F30();
void fn_95_9D84(void*, void*, void*, void*);
void fn_95_9DA0(void*, short, void*, int, int, float, signed char*);
void fn_95_9FA0(void*, void*, int);
void* fn_95_A01C(void*, int);
void fn_95_A058(void*, int, void*);
void fn_27_1A079C(void*, int);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_95_7F30(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_1F980(void*, void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
#define D(n) extern char n[];
D(lbl_95_data_600) D(lbl_95_data_11C) D(lbl_95_data_2900) D(lbl_95_data_2980)
D(lbl_95_data_2A88) D(lbl_95_data_2B30)
D(lbl_27_data_2F9F8) D(lbl_27_data_2FAA0) D(lbl_27_data_2FB48) D(lbl_27_data_2FBF0)
D(lbl_27_data_2FC98) D(lbl_27_data_2FD40) D(lbl_27_data_2FDE8)
D(lbl_27_bss_3AC) D(lbl_27_bss_3CC) D(lbl_27_bss_4BC) D(lbl_27_bss_46C0) D(lbl_27_bss_46D8)
D(lbl_27_bss_5B0) D(lbl_27_bss_5D8) D(lbl_27_bss_69C) D(lbl_27_bss_A48) D(lbl_27_bss_D8C)
D(lbl_27_bss_8C4) D(lbl_27_bss_7704) D(lbl_27_bss_502C) D(lbl_27_bss_503C)
D(lbl_95_bss_3AC) D(lbl_95_bss_3BC) D(lbl_95_bss_3CC) D(lbl_95_bss_3DC) D(lbl_95_bss_3EC)
D(lbl_95_bss_3FC) D(lbl_95_bss_40C) D(lbl_95_bss_41C) D(lbl_95_bss_42C) D(lbl_95_bss_43C)
D(lbl_95_bss_44C) D(lbl_95_bss_45C) D(lbl_95_bss_354) D(lbl_95_bss_36C) D(lbl_95_bss_384)
D(lbl_95_bss_39C)
extern const float lbl_95_rodata_0;
extern const float lbl_95_rodata_4;
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
virtual void a90(); virtual void a94();
virtual void a98(int, void*);
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
static inline void* dcast(void* p, long off) { return __dynamic_cast(p, off, lbl_95_data_2A88, lbl_95_data_2B30, (short)off); }

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

extern "C" void* fn_95_70(char* s, long entry, int heap, int modelHeap, int motionHeap) {
char* anim;
char* base;
int v; float scale;
char* q10; char* q8; char* q1; void* cast;
void* access;
signed char f10,f9,f8,f7,f6,f5,f4,f3,f2,f1,f0;
short v10,v9,v8,v7,v6,v5,v4,v3,v2,v1,v0;
Pair p10,p9,p8,p7,p6,p5,p4,p3,p2,p1,p0;
void* nulls[19];
char buildStorage[0x30];
#define bd ((V*)buildStorage)
fn_27_1257EC(s,entry,4,heap,s+0xb64);
VT(s,lbl_95_data_600)
new (buildStorage) ftFighterBuildData(entry,(ftKind)4,(Heaps::HeapType)heap,(Heaps::HeapType)modelHeap,(Heaps::HeapType)motionHeap,0,(soModuleAccesser*)P(s,0x60),-1,s+0x22264,s+0x2226c);
base=s+0x194;
fn_95_8010(base);
new (B(0x9d0)) soModuleAccesser((StageObject*)s,
(soResourceModule*)B(0x1168),(soModelModule*)B(0x1374),(soMotionModule*)B(0x16f4),(soPostureModule*)B(0x18a0),(soGroundModule*)B(0x1968),(soSituationModule*)B(0x19c0),
B(0x1a2c),(soCollisionAttackModule*)B(0x208c),(soCollisionHitModule*)B(0x2a20),
(soCollisionShieldModule*)B(0x2c4c),(soCollisionShieldModule*)B(0x36b4),(soCollisionShieldModule*)lbl_27_bss_3AC,
B(0x3888),(soCollisionSearchModule*)lbl_27_bss_3CC,(soDamageModule*)B(0x3a1c),
B(0x3b20),B(0x3b84),(soStopModule*)B(0x3bb8),B(0x3bdc),B(0x3c90),
(soSoundModule*)B(0x3cc0),(soLinkModule*)B(0x3e60),(soVisibilityModule*)B(0x3eb4),
(soControllerModule*)B(0x449c),(soCameraModule*)B(0x4658),(soWorkManageModule*)B(0x467c),
lbl_27_bss_4BC,(soAnimCmdModule*)B(0x46b0),(soStatusModule*)B(0x5588),
lbl_27_bss_46C0,lbl_27_bss_46D8,(soKineticModule*)B(0x5638),(soEventManageModule*)B(0xb8),
B(0x1f944),(soEffectModule*)B(0x1f9ec),B(0x1fb24),(soAreaModule*)B(0x1fb64),
lbl_27_bss_5B0,lbl_27_bss_5D8,B(0x1ff44),B(0x1ff8c),
(soShadowModule*)B(0x2000c),(soItemManageModule*)B(0x200f8),(soColorBlendModule*)B(0x20164),
B(0x202b8),B(0x20304),(soSlowModule*)B(0x2036c),lbl_27_bss_69C,
B(0xab0),(soParamCustomizeModule*)B(0xac8),B(0x203a8));
long heapSlot = bd->m80();
q8 = (char*)bd->m7c();
q1 = (char*)bd->m78();
Heaps::HeapType instanceHeap = (Heaps::HeapType)bd->m74();
new (B(0xab0)) soHeapModuleImpl(instanceHeap,(Heaps::HeapType)(long)q1,(Heaps::HeapType)(long)q8,heapSlot);
fn_27_14B5F8(B(0xac8),ACC);
fn_95_8364(B(0x115c),bd->m08(),bd->m0c(),bd->m10(),ACC);
v=bd->m68(); scale=bd->m50();
fn_95_83CC(B(0x1180),ACC,v,scale,a48);
fn_95_8454(B(0x1440),ACC,bd->m18());
fn_95_8628(B(0x1864),ACC,a48);
fn_95_8698(B(0x1918),ACC,bd->m28());
fn_27_3513C(B(0x19c0),HEAPVAL(),ACC,a48);
fn_95_7F44(B(0x19fc),bd->m14(),ACC);
#define HIT(n,o) n(B(o),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7),a48);
HIT(fn_95_86FC,0x1a70) HIT(fn_95_87C0,0x212c)
fn_95_8884(B(0x2a88),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
fn_95_8958(B(0x2ca0),ACC,*(int*)(s+0x28),(u8)(*(u32*)(s+0x2c)>>7));
HIT(fn_95_8A2C,0x370c)
fn_95_8AC4(B(0x3970),ACC,a48);
fn_27_64C8C(B(0x3b20),ACC,1);
fn_27_65EE4(B(0x3b84),ACC); fn_27_154088(B(0x3bb8),ACC); fn_27_693F4(B(0x3bdc),ACC);
fn_95_8B30(B(0x3c14),ACC,bd->m1c());
fn_95_8B8C(B(0x3cac),ACC,bd->m84(),a48);
fn_95_8C1C(B(0x3d1c),ACC);
fn_27_5B248(B(0x3eb4),ACC,bd->m20(),2);
fn_95_8C70(B(0x3ee4),ACC,HEAPVAL());
fn_95_8CE0(B(0x4608),ACC,bd->m5c(),bd->m60(),a48);
fn_27_A1DA4(B(0x467c),ACC,bd->m54());
fn_95_8D4C(B(0x46b0),HEAPVAL());
fn_95_8D90(B(0x47a4),ACC,bd->m24(),bd->m70());
fn_95_9248(B(0x5638),ACC); fn_95_9618(B(0x5940)); fn_95_9678(B(0x5b24),ACC);
fn_95_9B44(B(0x1f980),ACC,bd->m2c(),bd->m30(),bd->m34(),bd->m38(),a48);
fn_27_14FBD8(B(0x1fb24),ACC);
fn_95_9C10(B(0x1fb54),ACC,bd->m58(),a48);
bd->m40(); bd->m3c(); bd->m44();
fn_95_9CA8(B(0x1fec8),ACC,bd->m48());
new (B(0x1ff8c)) SlopeStorage(ACC,0,1,bd->m88());
new (B(0x2000c)) ShadowStorage(ACC,0,lbl_95_rodata_0);
fn_95_9D08(B(0x20054),ACC,bd->m64());
new (B(0x20164)) ColorBlendStorage(ACC,10,1);
new (B(0x202b8)) JostleStorage(ACC,0,8,bd->m6c());
fn_27_196664(B(0x20304),ACC); fn_27_5BED0(B(0x2036c),ACC); fn_27_14CCEC(B(0x203a8),ACC);
if (((Nul*)B(0x5b00))->isNull()==0) C(MOD(0x64))->a14(1,B(0x5b00));
fn_27_C74BC(B(0x20528),P(P(buildStorage,0xc),0x18),0x13);
anim=B(0x20538);
fn_27_1A65CC(anim,0); fn_27_1A65CC(anim+0x4a0,0); fn_27_D22D0(anim+0x944,0);
fn_95_9D84(anim+0x9f0,anim,anim+0x4a0,fn_95_9F30());
f0=0;
fn_95_9DA0(anim+0xa0c,HEAPVAL(),anim+0x944,0,1,lbl_95_rodata_4,&f0);
fn_95_9FA0(anim,0,0x125); fn_95_9FA0(anim+0x4a0,0,0x125); fn_95_9FA0(fn_95_9F30(),0,0);
v0=1; p0.a=anim+0xa0c; p0.b=anim+0x9f0; C(MOD(0x6c))->a0c(&p0,&v0);
#define THREAD(i,o,mask,num,declaration) \
 { bd->m90(i,2); bd->m90(i,1); void* t##i=bd->m90(i,0); \
declaration q##i=anim+o; fn_27_C7744(q##i,t##i,num); fn_27_D22D0(q##i+0x14,0); \
fn_95_9D84(q##i+0xc0,q##i,lbl_27_bss_D8C,lbl_27_bss_D8C); \
f##i=0; fn_95_9DA0(q##i+0xdc,HEAPVAL(),q##i+0x14,i,1,lbl_95_rodata_4,&f##i); \
v##i=mask; p##i.a=q##i+0xdc; p##i.b=q##i+0xc0; C(MOD(0x6c))->a0c(&p##i,&v##i); }
THREAD(1,0xa5c,2,0x1e8,)
THREAD(2,0xb88,0x40,0x1e8,char*)
THREAD(3,0xcb4,0x40,0x1e8,char*)
THREAD(4,0xde0,2,0x1e8,char*)
THREAD(5,0xf0c,0x20,0x1e8,char*)
THREAD(6,0x1038,0x80,0x1e8,char*)
THREAD(7,0x1164,0x80,0x1e8,char*)
THREAD(8,0x1290,0x20,0x1e8,)
q8=anim+0x13bc; f9=1;
fn_95_9DA0(q8,HEAPVAL(),q8+0x50,9,1,lbl_95_rodata_4,&f9);
fn_27_1A079C(q8+0x50,0);
v9=4; p9.a=q8; p9.b=lbl_27_bss_8C4; C(MOD(0x6c))->a0c(&p9,&v9);
THREAD(10,0x14e0,0x10,0x29,)
q10=(char*)bd->m90(0,0); fn_95_9FA0(fn_95_A01C(anim,0),q10,0x112);
q10=(char*)bd->m90(0,1); fn_95_9FA0(fn_95_A01C(anim,1),q10,0x112);
fn_95_9FA0(fn_95_A01C(anim,0),P(P(buildStorage,0xc),0x24),0x13);
fn_95_9FA0(fn_95_A01C(anim,1),P(P(buildStorage,0xc),0x28),0x13);
fn_95_A058(anim,0,((ftFighterBuildData*)buildStorage)->getAnimCmdDisguiseList(false,0));
fn_95_A058(anim,1,((ftFighterBuildData*)buildStorage)->getAnimCmdDisguiseList(false,1));
C(MOD(0x70))->a8c(B(0x20528));
q10=(char*)soValueAccesser::getConstantIndefinite(ACC,0xa805,0);
cast=dcast(MOD(0x90),0);
if(cast) fn_27_14E0B8(cast,q10);
C(MOD(0x90))->a2c(q10);
fn_27_1404D4(s+0x21cd8,P(s,0x60));
q10=s+0x21d14; fn_95_7F30(q10,0); P(q10,0)=lbl_95_data_2900;
access=P(s,0x60); heap=(int)(s+0x221cc);
fn_95_7F30((char*)heap,0); P((char*)heap,0)=lbl_95_data_2980;
#define EXT(o,n) new ((char*)heap+o) ActionLeafStorage<n>(access);
EXT(8,lbl_27_data_2F9F8) EXT(0x20,lbl_27_data_2FAA0) EXT(0x34,lbl_27_data_2FB48)
EXT(0x48,lbl_27_data_2FBF0) EXT(0x5c,lbl_27_data_2FC98) EXT(0x70,lbl_27_data_2FD40)
EXT(0x84,lbl_27_data_2FDE8)
P(s,0x22264)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7f9,0);
*(int*)(s+0x22268)=1;
P(s,0x2226c)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)P(s,0x60),0xa7fc,0);
*(int*)(s+0x22270)=1;
fn_27_126470(s);
((Init1*)(s+0x21cd8))->i0c(P(s,0x60));
VT(s,lbl_95_data_11C)
fn_27_C749C(s+0x22274);
P(s,0x22284)=(char*)g_ftCommonDataAccesser.getData((ftKind)4);
fn_27_1F980(s+0x22288,s+0x20000);
typedef void* StatusPointer;
new (nulls) StatusPointer[19]();
nulls[1]=lbl_95_bss_3CC; nulls[2]=lbl_95_bss_41C; nulls[3]=lbl_95_bss_42C;
nulls[4]=lbl_95_bss_45C; nulls[5]=lbl_27_bss_7704; nulls[6]=lbl_27_bss_7704;
nulls[7]=lbl_95_bss_3DC; nulls[8]=lbl_95_bss_3EC; nulls[9]=lbl_95_bss_3FC;
nulls[10]=lbl_95_bss_40C; nulls[11]=lbl_95_bss_43C; nulls[12]=lbl_95_bss_43C;
nulls[14]=lbl_95_bss_44C; nulls[15]=lbl_95_bss_44C; nulls[16]=lbl_95_bss_44C;
nulls[17]=lbl_95_bss_44C; nulls[18]=lbl_95_bss_44C;
C(P(P(P(s,0x60),0xd8),0x70))->a78(nulls,0x13);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x1a,lbl_95_bss_354);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x1b,lbl_95_bss_36C);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x1d,lbl_95_bss_384);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x1f,lbl_95_bss_39C);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x20,lbl_95_bss_39C);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0xc,lbl_95_bss_3AC);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x33,lbl_27_bss_502C);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x21,lbl_27_bss_503C);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x35,lbl_95_bss_3BC);
C(P(P(P(s,0x60),0xd8),0x70))->a98(0x37,lbl_95_bss_3BC);
return s;
}
