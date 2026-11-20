#include <new>
#include <types.h>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>

#pragma use_simple_stdpnew on
#pragma force_active on

extern "C" {
void fn_27_1257EC(void*,long,int,int,void*);
void fn_105_8138(void*);
void fn_27_14B5F8(void*,void*);
void fn_105_848C(void*,u32,u32,u8,void*);
void* fn_105_84FC(void*,soModuleAccesser*,float,void*,soEventObserverRegistrationDesc*);
void fn_105_8584(void*,void*,void*);
void fn_105_8758(void*,void*,void*);
void fn_105_87C8(void*,void*,void*);
void fn_27_3513C(void*,short,void*,void*);
void fn_105_806C(void*,long,void*);
void fn_105_882C(void*,void*,long,u8,void*);
void fn_105_88F0(void*,void*,long,u8,void*);
void fn_105_89B4(void*,void*,long,u8);
void fn_105_8A88(void*,void*,long,u8);
void fn_105_8B5C(void*,void*,long,u8,void*);
void fn_105_8BF4(void*,void*,void*);
void fn_27_64C8C(void*,void*,int);
void fn_27_65EE4(void*,void*);
void fn_27_154088(void*,void*);
void fn_27_693F4(void*,void*);
void fn_105_8C60(void*,void*,void*);
void fn_105_8CBC(void*,void*,void*,void*);
void fn_105_8D4C(void*,void*);
void fn_27_5B248(void*,void*,void*,int);
void fn_105_8DA0(void*,void*,short);
void fn_105_8E10(void*,void*,void*,void*,void*);
void fn_27_A1DA4(void*,void*,void*);
void fn_105_8E7C(void*,short);
void fn_105_8EC0(void*,void*,void*,void*);
void fn_105_9378(void*,void*);
void fn_105_9748(void*);
void fn_105_97A8(void*,void*);
void fn_105_9BCC(void*,void*,void*,void*,void*,void*,void*);
void fn_27_14FBD8(void*,void*);
void fn_105_9C98(void*,void*,u8,void*);
void fn_105_9D30(void*,void*,void*);
void fn_27_ACAC4(void*,void*,int,int,bool,float);
void fn_27_B62E4(void*,void*,float,int);
void fn_105_9D90(void*,void*,void*);
void fn_27_BEBB4(void*,void*,int,int);
void fn_27_C20D8(void*,void*,int,int,void*);
void fn_27_196664(void*,void*);
void fn_27_5BED0(void*,void*);
void fn_27_14CCEC(void*,void*);
void fn_27_C74BC(void*,void*,int);
void fn_27_1A61BC(void*,int);
void fn_27_D22D0(void*,int);
void* fn_105_9FB8();
void fn_105_9E0C(void*,void*,void*,void*);
void fn_105_9E28(void*,short,void*,int,int,float,signed char*);
void fn_105_A028(void*,void*,int);
void fn_27_C7744(void*,void*,int);
void fn_27_1A079C(void*,int);
void* fn_105_A0A4(void*,int);
void fn_105_A0E0(void*,int,void*);
void* __dynamic_cast(void*,long,const void*,const void*,short);
void fn_27_14E0B8(void*,void*);
void fn_27_1404D4(void*,void*);
void fn_105_8058(void*,int);
void fn_27_17437C(void*,void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);

extern char lbl_105_data_6A0[];
extern char lbl_105_data_1B8[];
extern char lbl_105_data_292C[];
extern char lbl_105_data_29AC[];
extern char lbl_105_data_2AB4[];
extern char lbl_105_data_2C48[];
extern char lbl_105_bss_27C[];
extern char lbl_105_bss_28C[];
extern char lbl_105_bss_29C[];
extern char lbl_105_bss_2AC[];
extern char lbl_105_bss_2BC[];
extern char lbl_105_bss_2CC[];
extern char lbl_105_bss_2DC[];
extern char lbl_105_bss_2EC[];
extern char lbl_105_bss_2FC[];
extern char lbl_105_bss_30C[];
extern char lbl_105_bss_31C[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern float lbl_105_rodata_4, lbl_105_rodata_8;
}

class FinishCalls {
public:
    virtual void f08();
    virtual void f0C(void*);
};

class Calls {
public:
    virtual int f08();
    virtual void f0C(void**,short*);
    virtual int f10();
    virtual void f14(int,void*);
    virtual int f18();
    virtual int f1C();
    virtual int f20();
    virtual short f24();
    virtual int f28();
    virtual void f2C(void*);
    virtual int f30();
    virtual int f34();
    virtual int f38();
    virtual int f3C();
    virtual int f40();
    virtual int f44();
    virtual int f48();
    virtual int f4C();
    virtual int f50();
    virtual int f54();
    virtual int f58();
    virtual int f5C();
    virtual int f60();
    virtual int f64();
    virtual int f68();
    virtual int f6C();
    virtual int f70();
    virtual int f74();
    virtual void f78(void**,int);
    virtual int f7C();
    virtual int f80();
    virtual int f84();
    virtual int f88();
    virtual void f8C(void*);
    virtual int f90();
    virtual int f94();
    virtual void f98(int,void*);
};

static inline char*& ptr(void* p,int o) {
    return *(char**)((char*)p+o);
}

static inline Calls* obj(void* p) {
    return (Calls*)p;
}

#define MOD(m,o) ptr(ptr(m,0xAA8),o)
#define VALUE(m) obj(MOD(m,0x80)+8)->f24()
#define P(T,o) reinterpret_cast<T*>(m+(o))
#define SETVT(b) \
ptr(self,0x3c)=(b)+0x0; \
ptr(self,0x40)=(b)+0x64; \
ptr(self,0x48)=(b)+0x70; \
ptr(self,0x54)=(b)+0x84; \
ptr(self,0x64)=(b)+0xdc; \
ptr(self,0x70)=(b)+0xec; \
ptr(self,0x7c)=(b)+0xfc; \
ptr(self,0x88)=(b)+0x110; \
ptr(self,0x94)=(b)+0x128; \
ptr(self,0xa0)=(b)+0x140; \
ptr(self,0xac)=(b)+0x158; \
ptr(self,0xb8)=(b)+0x16c; \
ptr(self,0xc4)=(b)+0x180; \
ptr(self,0xd0)=(b)+0x190; \
ptr(self,0xdc)=(b)+0x1c4; \
ptr(self,0xe8)=(b)+0x1d4; \
ptr(self,0xf4)=(b)+0x1e8; \
ptr(self,0x100)=(b)+0x254;

class BuildCalls {
public:
    virtual u32 getMdlResId()=0;
    virtual u32 getAnmResId()=0;
    virtual u8 getResGroupNo()=0;
    virtual s32 getTeam()=0;
    virtual void* getMotionData()=0;
    virtual void* getShakeData()=0;
    virtual void* getVisibilityData()=0;
    virtual void* getStatusData()=0;
    virtual void* getGroundConditionChecker()=0;
    virtual void* getEffectNodeData()=0;
    virtual void* getEffectEmitData()=0;
    virtual void* getEffectCommonData()=0;
    virtual void* getEffectScreenData()=0;
    virtual void* getTerritoryParam()=0;
    virtual void* getTerritoryRect()=0;
    virtual void* getTargetSearchParam()=0;
    virtual void* getIkData()=0;
    virtual int getModelLayerType()=0;
    virtual float getModelScale()=0;
    virtual void* getParamAccesser()=0;
    virtual int getAreaCategory()=0;
    virtual void* getCameraRangeSet()=0;
    virtual void* getCameraClipSphereSet()=0;
    virtual void* getItemNodeData()=0;
    virtual void* getModelExtendNodeTable()=0;
    virtual void* getJostleData()=0;
    virtual void* getPreCheckAnimCmdData()=0;
    virtual Heaps::HeapType getInstanceHeap()=0;
    virtual Heaps::HeapType getNWModelInstanceHeap()=0;
    virtual Heaps::HeapType getNWMotionInstanceHeap()=0;
    virtual s32 getHeapSlotNo()=0;
    virtual void* getSoundIdExchanger()=0;
    virtual float getSlopeAngleLimit()=0;
    virtual void unused()=0;
    virtual void* getAnimCmdData(u32,int)=0;
};

class SlopeStorage {
public:
    SlopeStorage(void* modules,int first,int count,bool enabled,float angle) {
        fn_27_ACAC4(this,modules,first,count,enabled,angle);
    }
};

class ShadowStorage {
public:
    ShadowStorage(void* modules) {
        fn_27_B62E4(this,modules,lbl_105_rodata_4,0);
    }
};

class ColorStorage {
public:
    ColorStorage(void* modules,int count,int enabled) {
        fn_27_BEBB4(this,modules,count,enabled);
    }
};

class JostleStorage {
public:
    JostleStorage(void* modules,int mode,int count,void* data) {
        fn_27_C20D8(this,modules,mode,count,data);
    }
};

struct Local {
    signed char flags[11];
    char pad;
    short values[11];
    short pad2;
    void* pairs[22];
    char build[0x30];
    void* list[15];
};

extern "C" void* fn_105_70(char* self,long entry,char* heap,int modelHeap,char* motionHeap) {
    char *finalPart8, *finalPart20, *finalPart34, *finalPart48, *finalPart5C, *finalPart70, *finalPart84;
    char* finalPart;
    void* constant;
    char* part;
    Local l;
    fn_27_1257EC(self,entry,15,(int)heap,self+0xB64);
    SETVT(lbl_105_data_6A0)

    new(l.build) ftFighterBuildData(
        entry,(ftKind)15,(Heaps::HeapType)(long)heap,
        (Heaps::HeapType)modelHeap,(Heaps::HeapType)(long)motionHeap,
        0,(soModuleAccesser*)ptr(self,0x60),-1,
        self+0x1FE28,self+0x1FE30);

    motionHeap=self+0x194;
#define m motionHeap
    fn_105_8138(m);

    new(m+0x9D0) soModuleAccesser(
        (StageObject*)self,
        P(soResourceModule,0x116C),
        P(soModelModule,0x1378),
        P(soMotionModule,0x1668),
        P(soPostureModule,0x1814),
        P(soGroundModule,0x18DC),
        P(soSituationModule,0x1934),
        m+0x19A0,
        P(soCollisionAttackModule,0x2000),
        P(soCollisionHitModule,0x2994),
        P(soCollisionShieldModule,0x2BC0),
        P(soCollisionShieldModule,0x3628),
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        m+0x37FC,
        (soCollisionSearchModule*)lbl_27_bss_3CC,
        P(soDamageModule,0x3990),
        m+0x3A94,m+0x3AF8,
        P(soStopModule,0x3B2C),
        m+0x3B50,m+0x3C04,
        P(soSoundModule,0x3C34),
        P(soLinkModule,0x3E08),
        P(soVisibilityModule,0x3E5C),
        P(soControllerModule,0x4444),
        P(soCameraModule,0x4600),
        P(soWorkManageModule,0x4624),
        lbl_27_bss_4BC,
        P(soAnimCmdModule,0x4658),
        P(soStatusModule,0x5520),
        lbl_27_bss_46C0,lbl_27_bss_46D8,
        P(soKineticModule,0x55D0),
        P(soEventManageModule,0xB8),
        m+0x1D528,
        P(soEffectModule,0x1D5D0),
        m+0x1D708,
        P(soAreaModule,0x1D748),
        lbl_27_bss_5B0,lbl_27_bss_5D8,
        m+0x1DB28,m+0x1DB70,
        P(soShadowModule,0x1DBF0),
        P(soItemManageModule,0x1DCDC),
        P(soColorBlendModule,0x1DD48),
        m+0x1DE9C,m+0x1DEE8,
        P(soSlowModule,0x1DF50),
        lbl_27_bss_69C,m+0xAB0,
        P(soParamCustomizeModule,0xAC8),
        m+0x1DF8C);

    modelHeap=((BuildCalls*)l.build)->getHeapSlotNo();
    char* part8=(char*)((BuildCalls*)l.build)->getNWMotionInstanceHeap();
    char* part1=(char*)((BuildCalls*)l.build)->getNWModelInstanceHeap();
    Heaps::HeapType h0=((BuildCalls*)l.build)->getInstanceHeap();
    new(m+0xAB0) soHeapModuleImpl(h0,(Heaps::HeapType)(long)part1,(Heaps::HeapType)(long)part8,modelHeap);
    fn_27_14B5F8(m+0xAC8,m+0x9D0);

    fn_105_848C(m+0x115C,((BuildCalls*)l.build)->getMdlResId(),
        ((BuildCalls*)l.build)->getAnmResId(),
        ((BuildCalls*)l.build)->getResGroupNo(),m+0x9D0);

    heap=lbl_27_bss_A48;
    fn_105_84FC(m+0x1184,P(soModuleAccesser,0x9D0),
        ((BuildCalls*)l.build)->getModelScale(),
        ((BuildCalls*)l.build)->getModelExtendNodeTable(),
        (soEventObserverRegistrationDesc*)heap);
    fn_105_8584(m+0x1444,m+0x9D0,((BuildCalls*)l.build)->getMotionData());
    fn_105_8758(m+0x17D8,m+0x9D0,heap);
    fn_105_87C8(m+0x188C,m+0x9D0,((BuildCalls*)l.build)->getGroundConditionChecker());
    short value0=VALUE(m);
    fn_27_3513C(m+0x1934,value0,m+0x9D0,heap);
    fn_105_806C(m+0x1970,((BuildCalls*)l.build)->getTeam(),m+0x9D0);

    fn_105_882C(m+0x19E4,m+0x9D0,*(long*)(self+0x28),(u8)((*(u32*)(self+0x2C)>>7)&255),heap);
    fn_105_88F0(m+0x20A0,m+0x9D0,*(long*)(self+0x28),(u8)((*(u32*)(self+0x2C)>>7)&255),heap);
    fn_105_89B4(m+0x29FC,m+0x9D0,*(long*)(self+0x28),(u8)((*(u32*)(self+0x2C)>>7)&255));
    fn_105_8A88(m+0x2C14,m+0x9D0,*(long*)(self+0x28),(u8)((*(u32*)(self+0x2C)>>7)&255));
    fn_105_8B5C(m+0x3680,m+0x9D0,*(long*)(self+0x28),(u8)((*(u32*)(self+0x2C)>>7)&255),heap);
    fn_105_8BF4(m+0x38E4,m+0x9D0,heap);
    fn_27_64C8C(m+0x3A94,m+0x9D0,1);
    fn_27_65EE4(m+0x3AF8,m+0x9D0);
    fn_27_154088(m+0x3B2C,m+0x9D0);
    fn_27_693F4(m+0x3B50,m+0x9D0);
    fn_105_8C60(m+0x3B88,m+0x9D0,((BuildCalls*)l.build)->getShakeData());
    fn_105_8CBC(m+0x3C20,m+0x9D0,((BuildCalls*)l.build)->getSoundIdExchanger(),heap);
    fn_105_8D4C(m+0x3C90,m+0x9D0);
    fn_27_5B248(m+0x3E5C,m+0x9D0,((BuildCalls*)l.build)->getVisibilityData(),2);
    short value1=VALUE(m);
    fn_105_8DA0(m+0x3E8C,m+0x9D0,value1);

    fn_105_8E10(m+0x45B0,m+0x9D0,((BuildCalls*)l.build)->getCameraRangeSet(),
        ((BuildCalls*)l.build)->getCameraClipSphereSet(),heap);
    fn_27_A1DA4(m+0x4624,m+0x9D0,((BuildCalls*)l.build)->getParamAccesser());
    short value2=VALUE(m);
    fn_105_8E7C(m+0x4658,value2);

    fn_105_8EC0(m+0x474C,m+0x9D0,((BuildCalls*)l.build)->getStatusData(),
        ((BuildCalls*)l.build)->getPreCheckAnimCmdData());
    fn_105_9378(m+0x55D0,m+0x9D0);
    fn_105_9748(m+0x58D8);
    fn_105_97A8(m+0x5A98,m+0x9D0);

    fn_105_9BCC(m+0x1D564,m+0x9D0,((BuildCalls*)l.build)->getEffectNodeData(),
        ((BuildCalls*)l.build)->getEffectEmitData(),((BuildCalls*)l.build)->getEffectCommonData(),
        ((BuildCalls*)l.build)->getEffectScreenData(),heap);
    fn_27_14FBD8(m+0x1D708,m+0x9D0);
    s32 area=((BuildCalls*)l.build)->getAreaCategory();
    fn_105_9C98(m+0x1D738,m+0x9D0,(u8)area,heap);
    ((BuildCalls*)l.build)->getTerritoryRect();
    ((BuildCalls*)l.build)->getTerritoryParam();
    ((BuildCalls*)l.build)->getTargetSearchParam();
    fn_105_9D30(m+0x1DAAC,m+0x9D0,((BuildCalls*)l.build)->getIkData());
    new(m+0x1DB70) SlopeStorage(m+0x9D0,0,1,false,((BuildCalls*)l.build)->getSlopeAngleLimit());
    new(m+0x1DBF0) ShadowStorage(m+0x9D0);
    fn_105_9D90(m+0x1DC38,m+0x9D0,((BuildCalls*)l.build)->getItemNodeData());
    new(m+0x1DD48) ColorStorage(m+0x9D0,10,1);
    void* jostle=((BuildCalls*)l.build)->getJostleData();
    new(m+0x1DE9C) JostleStorage(m+0x9D0,0,8,jostle);
    fn_27_196664(m+0x1DEE8,m+0x9D0);
    fn_27_5BED0(m+0x1DF50,m+0x9D0);
    fn_27_14CCEC(m+0x1DF8C,m+0x9D0);

    if(obj(m+0x5A74)->f08()==0)
        obj(MOD(m,0x64))->f14(1,m+0x5A74);

    fn_27_C74BC(m+0x1E10C,*(void**)(*(char**)(l.build+0xC)+0x18),15);
    char* state=m+0x1E11C;
    fn_27_1A61BC(state,0);
    fn_27_1A61BC(state+0x490,0);
    fn_27_D22D0(state+0x924,0);
    fn_105_9E0C(state+0x9D0,state,state+0x490,fn_105_9FB8());

    l.flags[0]=0;
    short value3=VALUE(m);
    fn_105_9E28(state+0x9EC,value3,state+0x924,0,1,lbl_105_rodata_8,&l.flags[0]);
    fn_105_A028(state,0,0x121);
    fn_105_A028(state+0x490,0,0x121);
    fn_105_A028(fn_105_9FB8(),0,0);
    l.values[0]=1;
    l.pairs[0]=state+0x9EC;
    l.pairs[1]=state+0x9D0;
    obj(MOD(m,0x6C))->f0C(&l.pairs[0],&l.values[0]);

    ((BuildCalls*)l.build)->getAnimCmdData(1,2);
    ((BuildCalls*)l.build)->getAnimCmdData(1,1);
    void* cmd1=((BuildCalls*)l.build)->getAnimCmdData(1,0);
    {
        part1=state+0xA3C;
        fn_27_C7744(part1,cmd1,0x1F2);
        fn_27_D22D0(part1+0x14,0);
        fn_105_9E0C(part1+0xC0,part1,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[1]=0;
        short value4=VALUE(m);
        fn_105_9E28(part1+0xDC,value4,part1+0x14,1,1,lbl_105_rodata_8,&l.flags[1]);
        l.values[1]=2;
        l.pairs[2]=part1+0xDC;
        l.pairs[3]=part1+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[2],&l.values[1]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(2,2);
    ((BuildCalls*)l.build)->getAnimCmdData(2,1);
    void* cmd2=((BuildCalls*)l.build)->getAnimCmdData(2,0);
    {
        char* part=state+0xB68;
        fn_27_C7744(part,cmd2,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[2]=0;
        short value5=VALUE(m);
        fn_105_9E28(part+0xDC,value5,part+0x14,2,1,lbl_105_rodata_8,&l.flags[2]);
        l.values[2]=64;
        l.pairs[4]=part+0xDC;
        l.pairs[5]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[4],&l.values[2]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(3,2);
    ((BuildCalls*)l.build)->getAnimCmdData(3,1);
    void* cmd3=((BuildCalls*)l.build)->getAnimCmdData(3,0);
    {
        char* part=state+0xC94;
        fn_27_C7744(part,cmd3,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[3]=0;
        short value6=VALUE(m);
        fn_105_9E28(part+0xDC,value6,part+0x14,3,1,lbl_105_rodata_8,&l.flags[3]);
        l.values[3]=64;
        l.pairs[6]=part+0xDC;
        l.pairs[7]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[6],&l.values[3]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(4,2);
    ((BuildCalls*)l.build)->getAnimCmdData(4,1);
    void* cmd4=((BuildCalls*)l.build)->getAnimCmdData(4,0);
    {
        char* part=state+0xDC0;
        fn_27_C7744(part,cmd4,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[4]=0;
        short value7=VALUE(m);
        fn_105_9E28(part+0xDC,value7,part+0x14,4,1,lbl_105_rodata_8,&l.flags[4]);
        l.values[4]=2;
        l.pairs[8]=part+0xDC;
        l.pairs[9]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[8],&l.values[4]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(5,2);
    ((BuildCalls*)l.build)->getAnimCmdData(5,1);
    void* cmd5=((BuildCalls*)l.build)->getAnimCmdData(5,0);
    {
        char* part=state+0xEEC;
        fn_27_C7744(part,cmd5,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[5]=0;
        short value8=VALUE(m);
        fn_105_9E28(part+0xDC,value8,part+0x14,5,1,lbl_105_rodata_8,&l.flags[5]);
        l.values[5]=32;
        l.pairs[10]=part+0xDC;
        l.pairs[11]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[10],&l.values[5]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(6,2);
    ((BuildCalls*)l.build)->getAnimCmdData(6,1);
    void* cmd6=((BuildCalls*)l.build)->getAnimCmdData(6,0);
    {
        char* part=state+0x1018;
        fn_27_C7744(part,cmd6,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[6]=0;
        short value9=VALUE(m);
        fn_105_9E28(part+0xDC,value9,part+0x14,6,1,lbl_105_rodata_8,&l.flags[6]);
        l.values[6]=128;
        l.pairs[12]=part+0xDC;
        l.pairs[13]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[12],&l.values[6]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(7,2);
    ((BuildCalls*)l.build)->getAnimCmdData(7,1);
    void* cmd7=((BuildCalls*)l.build)->getAnimCmdData(7,0);
    {
        char* part=state+0x1144;
        fn_27_C7744(part,cmd7,0x1F2);
        fn_27_D22D0(part+0x14,0);
        fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[7]=0;
        short value10=VALUE(m);
        fn_105_9E28(part+0xDC,value10,part+0x14,7,1,lbl_105_rodata_8,&l.flags[7]);
        l.values[7]=128;
        l.pairs[14]=part+0xDC;
        l.pairs[15]=part+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[14],&l.values[7]);
    }

    ((BuildCalls*)l.build)->getAnimCmdData(8,2);
    ((BuildCalls*)l.build)->getAnimCmdData(8,1);
    void* cmd8=((BuildCalls*)l.build)->getAnimCmdData(8,0);
    {
        part8=state+0x1270;
        fn_27_C7744(part8,cmd8,0x1F2);
        fn_27_D22D0(part8+0x14,0);
        fn_105_9E0C(part8+0xC0,part8,lbl_27_bss_D8C,lbl_27_bss_D8C);
        l.flags[8]=0;
        short value11=VALUE(m);
        fn_105_9E28(part8+0xDC,value11,part8+0x14,8,1,lbl_105_rodata_8,&l.flags[8]);
        l.values[8]=32;
        l.pairs[16]=part8+0xDC;
        l.pairs[17]=part8+0xC0;
        obj(MOD(m,0x6C))->f0C(&l.pairs[16],&l.values[8]);
    }

    part=state+0x139C;
    l.flags[9]=1;
    short value12=VALUE(m);
    fn_105_9E28(part,value12,part+0x50,9,1,lbl_105_rodata_8,&l.flags[9]);
    fn_27_1A079C(part+0x50,0);
    l.values[9]=4;
    l.pairs[18]=part;
    l.pairs[19]=lbl_27_bss_8C4;
    obj(MOD(m,0x6C))->f0C(&l.pairs[18],&l.values[9]);

    ((BuildCalls*)l.build)->getAnimCmdData(10,2);
    ((BuildCalls*)l.build)->getAnimCmdData(10,1);
    void* cmd10=((BuildCalls*)l.build)->getAnimCmdData(10,0);
    part=state+0x14C0;
    fn_27_C7744(part,cmd10,0x29);
    fn_27_D22D0(part+0x14,0);
    fn_105_9E0C(part+0xC0,part,lbl_27_bss_D8C,lbl_27_bss_D8C);
    l.flags[10]=0;
    short value13=VALUE(m);
    fn_105_9E28(part+0xDC,value13,part+0x14,10,1,lbl_105_rodata_8,&l.flags[10]);
    l.values[10]=16;
    l.pairs[20]=part+0xDC;
    l.pairs[21]=part+0xC0;
    obj(MOD(m,0x6C))->f0C(&l.pairs[20],&l.values[10]);

    part=(char*)((BuildCalls*)l.build)->getAnimCmdData(0,0);
    fn_105_A028(fn_105_A0A4(state,0),part,0x112);
    part=(char*)((BuildCalls*)l.build)->getAnimCmdData(0,1);
    fn_105_A028(fn_105_A0A4(state,1),part,0x112);
    void* list0=fn_105_A0A4(state,0);
    fn_105_A028(list0,*(void**)(*(char**)(l.build+0xC)+0x24),15);
    void* list1=fn_105_A0A4(state,1);
    fn_105_A028(list1,*(void**)(*(char**)(l.build+0xC)+0x28),15);
    fn_105_A0E0(state,0,((ftFighterBuildData*)l.build)->getAnimCmdDisguiseList(false,0));
    fn_105_A0E0(state,1,((ftFighterBuildData*)l.build)->getAnimCmdDisguiseList(false,1));
    obj(MOD(m,0x70))->f8C(m+0x1E10C);

    constant=soValueAccesser::getConstantIndefinite((soModuleAccesser*)(m+0x9D0),0xA805,0);
    void* cast=__dynamic_cast(MOD(m,0x90),0,lbl_105_data_2AB4,lbl_105_data_2C48,0);
    if(cast)
        fn_27_14E0B8(cast,constant);
    obj(MOD(m,0x90))->f2C(constant);

    fn_27_1404D4(self+0x1F89C,ptr(self,0x60));
    finalPart=self+0x1F8D8;
    fn_105_8058(finalPart,0);
    ptr(finalPart,0)=lbl_105_data_292C;

    motionHeap=ptr(self,0x60);
#define access motionHeap
    heap=self+0x1FD90;
#define tail heap
    fn_105_8058(tail,0);
    ptr(tail,0)=lbl_105_data_29AC;

    {
        finalPart8=tail+0x8;
        fn_27_17437C(finalPart8,access);
        ptr(finalPart8,0)=lbl_27_data_2F9F8;
        ptr(finalPart8,4)=lbl_27_data_2F9F8+0x40;
    }
    {
        finalPart20=tail+0x20;
        fn_27_17437C(finalPart20,access);
        ptr(finalPart20,0)=lbl_27_data_2FAA0;
        ptr(finalPart20,4)=lbl_27_data_2FAA0+0x40;
    }
    {
        finalPart34=tail+0x34;
        fn_27_17437C(finalPart34,access);
        ptr(finalPart34,0)=lbl_27_data_2FB48;
        ptr(finalPart34,4)=lbl_27_data_2FB48+0x40;
    }
    {
        finalPart48=tail+0x48;
        fn_27_17437C(finalPart48,access);
        ptr(finalPart48,0)=lbl_27_data_2FBF0;
        ptr(finalPart48,4)=lbl_27_data_2FBF0+0x40;
    }
    {
        finalPart5C=tail+0x5C;
        fn_27_17437C(finalPart5C,access);
        ptr(finalPart5C,0)=lbl_27_data_2FC98;
        ptr(finalPart5C,4)=lbl_27_data_2FC98+0x40;
    }
    {
        finalPart70=tail+0x70;
        fn_27_17437C(finalPart70,access);
        ptr(finalPart70,0)=lbl_27_data_2FD40;
        ptr(finalPart70,4)=lbl_27_data_2FD40+0x40;
    }
    {
        finalPart84=tail+0x84;
        fn_27_17437C(finalPart84,access);
        ptr(finalPart84,0)=lbl_27_data_2FDE8;
        ptr(finalPart84,4)=lbl_27_data_2FDE8+0x40;
    }

    ptr(self,0x1FE28)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)ptr(self,0x60),0xA7F9,0);
    *(int*)(self+0x1FE2C)=1;
    ptr(self,0x1FE30)=(char*)soValueAccesser::getConstantIndefinite((soModuleAccesser*)ptr(self,0x60),0xA7FC,0);
    *(int*)(self+0x1FE34)=1;
    fn_27_126470(self);
    ((FinishCalls*)(self+0x1F89C))->f0C(ptr(self,0x60));

    SETVT(lbl_105_data_1B8)
    fn_27_C749C(self+0x1FE38);
    ptr(self,0x1FE48)=(char*)g_ftCommonDataAccesser.getData((ftKind)15);
    self[0x1FE4C]=0;

    struct List { void* slots[15]; List() : slots() {} };
    new(l.list) List;
    l.list[1]=lbl_105_bss_28C;
    l.list[2]=lbl_105_bss_2AC;
    l.list[3]=lbl_105_bss_2FC;
    l.list[4]=lbl_105_bss_2DC;
    l.list[5]=lbl_105_bss_29C;
    l.list[8]=lbl_105_bss_2BC;
    l.list[12]=lbl_105_bss_2CC;
    l.list[14]=lbl_105_bss_2EC;

    obj(ptr(ptr(ptr(self,0x60),0xD8),0x70))->f78(l.list,15);
    obj(ptr(ptr(ptr(self,0x60),0xD8),0x70))->f98(0x74,lbl_105_bss_27C);
    obj(ptr(ptr(ptr(self,0x60),0xD8),0x70))->f98(0x10E,lbl_105_bss_30C);
    obj(ptr(ptr(ptr(self,0x60),0xD8),0x70))->f98(0xBE,lbl_105_bss_31C);
    return self;
#undef m
}
