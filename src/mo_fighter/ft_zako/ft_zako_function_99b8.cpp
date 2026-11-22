// Compiler comparison is pending for this revision.

#include <types.h>
#include <new>
#pragma use_simple_stdpnew on
#include <ft/ft_fighter_build_data.h>
#include <ft/ft_cancel_module.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
void fn_27_1257EC(void*, int, int, int, void*);
void fn_126_51D0(void*);
void fn_126_50F0(void*, int);
void fn_126_5524(void*, u32, u32, u8, void*);
void fn_126_558C(void*, void*, float, void*, void*);
void fn_126_5614(void*, void*, void*);
void fn_126_57E8(void*, void*, void*);
void fn_126_5858(void*, void*, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_126_5104(void*, int, void*);
void fn_126_58BC(void*, void*, int, u8, void*);
void fn_126_5980(void*, void*, int, u8, void*);
void fn_126_5A44(void*, void*, int, u8);
void fn_126_5B18(void*, void*, int, u8);
void fn_126_5BEC(void*, void*, int, u8, void*);
void fn_126_5C84(void*, void*, void*);
void fn_126_5CF0(void*, void*, void*);
void fn_126_5D4C(void*, void*, void*, void*);
void fn_126_5DDC(void*, void*);
void fn_126_5E30(void*, void*, short);
void fn_126_5EA0(void*, void*, void*, void*, void*);
void fn_126_5F0C(void*, short);
void fn_126_5F50(void*, void*, void*, void*);
void fn_126_6408(void*, void*);
void fn_126_67D8(void*);
void fn_126_6838(void*, void*, void*, void*, void*, void*, void*);
void fn_126_6904(void*, void*, u8, void*);
void fn_126_69D0(void*, void*, void*);
void fn_126_6A30(void*, void*, void*, void*);
void fn_126_6A4C(void*, short, void*, int, int, float, signed char*);
void* fn_126_6BDC();
void fn_126_6C4C(void*, void*, int);
void* fn_126_6CC8(void*, int);
void fn_126_6D04(void*, int, void*);
void fn_27_14B5F8(void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_27_A1DA4(void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_27_ACAC4(void*, void*, bool, int, bool, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A599C(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_1A079C(void*, int);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);

extern char lbl_126_data_589C[];
extern char lbl_126_data_53B4[];
extern char lbl_126_data_B50[];
extern char lbl_126_data_BD0[];
extern char lbl_126_data_CD8[];
extern char lbl_126_data_D80[];
extern char lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[];
extern char lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[];
extern char lbl_27_bss_46D8[];
extern char lbl_27_bss_55C[];
extern char lbl_27_bss_5B0[];
extern char lbl_27_bss_5D8[];
extern char lbl_27_bss_628[];
extern char lbl_27_bss_69C[];
extern char lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[];
extern char lbl_27_bss_8C4[];
extern char lbl_27_data_2F9F8[];
extern char lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[];
extern char lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[];
extern char lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern float lbl_126_rodata_10, lbl_126_rodata_14;
}

struct BuildCalls {
    virtual u32 getMdlResId();
    virtual u32 getAnmResId();
    virtual u8 getResGroupNo();
    virtual s32 getTeam();
    virtual void* getMotionData();
    virtual void* getShakeData();
    virtual void* getVisibilityData();
    virtual void* getStatusData();
    virtual void* getGroundConditionChecker();
    virtual void* getEffectNodeData();
    virtual void* getEffectEmitData();
    virtual void* getEffectCommonData();
    virtual void* getEffectScreenData();
    virtual void* getTerritoryParam();
    virtual void* getTerritoryRect();
    virtual void* getTargetSearchParam();
    virtual void* getIkData();
    virtual s32 getModelLayerType();
    virtual float getModelScale();
    virtual void* getParamAccesser();
    virtual u8 getAreaCategory();
    virtual void* getCameraRangeSet();
    virtual void* getCameraClipSphereSet();
    virtual void* getItemNodeData();
    virtual void* getModelExtendNodeTable();
    virtual void* getJostleData();
    virtual void* getPreCheckAnimCmdData();
    virtual Heaps::HeapType getInstanceHeap();
    virtual Heaps::HeapType getNWModelInstanceHeap();
    virtual Heaps::HeapType getNWMotionInstanceHeap();
    virtual s32 getHeapSlotNo();
    virtual void* getSoundIdExchanger();
    virtual float getSlopeAngleLimit();
    virtual void* destroy();
    virtual void* getAnimCmdData(u32, int);
};

struct V {
    virtual int f08();
    virtual void f0c(void*, void*);
    virtual void f10();
    virtual void f14(int, void*);
    virtual void f18();
    virtual void f1c();
    virtual void f20();
    virtual short f24();
    virtual void f28();
    virtual void f2c(void*);
    virtual void f30();
    virtual void f34();
    virtual void f38();
    virtual void f3c();
    virtual void f40();
    virtual void f44();
    virtual void f48();
    virtual void f4c();
    virtual void f50();
    virtual void f54();
    virtual void f58();
    virtual void f5c();
    virtual void f60();
    virtual void f64();
    virtual void f68();
    virtual void f6c();
    virtual void f70();
    virtual void f74();
    virtual void f78();
    virtual void f7c();
    virtual void f80();
    virtual void f84();
    virtual void f88();
    virtual void f8c(void*);
};

struct ZakoStateStorage {
    char* table;
    ZakoStateStorage() {
        fn_126_50F0(this, 0);
        table = lbl_126_data_B50;
    }
};

template <char* Table>
struct ZakoActionLeafStorage {
    char* table;
    char* secondaryTable;
    explicit ZakoActionLeafStorage(void* accesser) {
        fn_27_17437C(this, accesser);
        table = Table;
        secondaryTable = Table+0x40;
    }
};

#define PTR(o,n) (*(void**)((char*)(o)+(n)))
#define EN(n) PTR(PTR(m,0xaa8),n)
#define HEAP() ((V*)((char*)EN(0x80)+8))->f24()
#define SETVT(t) \
    PTR(p,0x3c)=t; PTR(p,0x40)=t+0x64; PTR(p,0x48)=t+0x70; PTR(p,0x54)=t+0x84; \
    PTR(p,0x64)=t+0xdc; PTR(p,0x70)=t+0xec; PTR(p,0x7c)=t+0xfc; PTR(p,0x88)=t+0x110; \
    PTR(p,0x94)=t+0x128; PTR(p,0xa0)=t+0x140; PTR(p,0xac)=t+0x158; PTR(p,0xb8)=t+0x16c; \
    PTR(p,0xc4)=t+0x180; PTR(p,0xd0)=t+0x190; PTR(p,0xdc)=t+0x1c4; PTR(p,0xe8)=t+0x1d4; \
    PTR(p,0xf4)=t+0x1e8; PTR(p,0x100)=t+0x254;
#define M(T,n) reinterpret_cast<T*>(m+n)

extern "C" void* fn_126_99B8(char* p, int arg1, int arg2, int arg3, int arg4) {
    struct Locals {
        signed char flags[11];
        char pad;
        short values[11];
        char pad2[2];
        void* pairs[22];
        char build[sizeof(ftFighterBuildData)];
    } local;

#define rawBuild local.build
    fn_27_1257EC(p, arg1, 0x33, arg2, p+0xb64);
    SETVT(lbl_126_data_589C)
    new (rawBuild) ftFighterBuildData(
        arg1, (ftKind)0x33, (Heaps::HeapType)arg2, (Heaps::HeapType)arg3,
        (Heaps::HeapType)arg4, 0, (soModuleAccesser*)PTR(p,0x60),
        -1, p+0x811c, p+0x8124);
    char* t;
    char* a;
    void* cast;
    char* m = p+0x194;
    fn_126_51D0(m);

    new (m+0x9d0) soModuleAccesser(
        (StageObject*)p, M(soResourceModule,0x1168), M(soModelModule,0x1374),
        M(soMotionModule,0x1690), M(soPostureModule,0x183c), M(soGroundModule,0x1904),
        M(soSituationModule,0x195c), m+0x19c8, M(soCollisionAttackModule,0x2028),
        M(soCollisionHitModule,0x29bc), M(soCollisionShieldModule,0x2be8),
        M(soCollisionShieldModule,0x3650), (soCollisionShieldModule*)lbl_27_bss_3AC,
        m+0x3824, (soCollisionSearchModule*)lbl_27_bss_3CC,
        M(soDamageModule,0x39b8), m+0x3abc, m+0x3b20, M(soStopModule,0x3b54),
        m+0x3b78, m+0x3c2c, M(soSoundModule,0x3c5c), M(soLinkModule,0x3dfc),
        M(soVisibilityModule,0x3e50), M(soControllerModule,0x4438),
        M(soCameraModule,0x45f4), M(soWorkManageModule,0x4618), lbl_27_bss_4BC,
        M(soAnimCmdModule,0x464c), M(soStatusModule,0x54f0),
        lbl_27_bss_46C0, lbl_27_bss_46D8, M(soKineticModule,0x55a0),
        M(soEventManageModule,0xb8), lbl_27_bss_55C, M(soEffectModule,0x5afc),
        m+0x5c34, M(soAreaModule,0x5c68), lbl_27_bss_5B0, lbl_27_bss_5D8,
        m+0x5f70, m+0x5fb8, M(soShadowModule,0x6038),
        (soItemManageModule*)lbl_27_bss_628, M(soColorBlendModule,0x6084),
        m+0x61d8, m+0x6224, M(soSlowModule,0x628c), lbl_27_bss_69C,
        m+0xab0, M(soParamCustomizeModule,0xac8), m+0x62c8);

#define b ((BuildCalls*)rawBuild)
    char* motionHeap;
    s32 heapSlot;
    char* modelHeap;
    heapSlot = b->getHeapSlotNo();
    motionHeap = reinterpret_cast<char*>(b->getNWMotionInstanceHeap());
    modelHeap = reinterpret_cast<char*>(b->getNWModelInstanceHeap());
    new (m+0xab0) soHeapModuleImpl(
        b->getInstanceHeap(), (Heaps::HeapType)(s32)modelHeap,
        (Heaps::HeapType)(s32)motionHeap, heapSlot);
    fn_27_14B5F8(m+0xac8, m+0x9d0);
    fn_126_5524(m+0x115c, b->getMdlResId(), b->getAnmResId(),
                b->getResGroupNo(), m+0x9d0);
    fn_126_558C(m+0x1180, m+0x9d0, b->getModelScale(),
                b->getModelExtendNodeTable(), lbl_27_bss_A48);
    fn_126_5614(m+0x1440, m+0x9d0, b->getMotionData());
    fn_126_57E8(m+0x1800, m+0x9d0, lbl_27_bss_A48);
    fn_126_5858(m+0x18b4, m+0x9d0, b->getGroundConditionChecker());
    fn_27_3513C(m+0x195c, HEAP(), m+0x9d0, lbl_27_bss_A48);
    fn_126_5104(m+0x1998, b->getTeam(), m+0x9d0);

#define ID (*(int*)(p+0x28))
#define GROUP ((u8)(*(u32*)(p+0x2c)>>7))
    fn_126_58BC(m+0x1a0c, m+0x9d0, ID, GROUP, lbl_27_bss_A48);
    fn_126_5980(m+0x20c8, m+0x9d0, ID, GROUP, lbl_27_bss_A48);
    fn_126_5A44(m+0x2a24, m+0x9d0, ID, GROUP);
    fn_126_5B18(m+0x2c3c, m+0x9d0, ID, GROUP);
    fn_126_5BEC(m+0x36a8, m+0x9d0, ID, GROUP, lbl_27_bss_A48);
    fn_126_5C84(m+0x390c, m+0x9d0, lbl_27_bss_A48);
    fn_27_64C8C(m+0x3abc, m+0x9d0, 1);
    fn_27_65EE4(m+0x3b20, m+0x9d0);
    fn_27_154088(m+0x3b54, m+0x9d0);
    fn_27_693F4(m+0x3b78, m+0x9d0);
    fn_126_5CF0(m+0x3bb0, m+0x9d0, b->getShakeData());
    fn_126_5D4C(m+0x3c48, m+0x9d0, b->getSoundIdExchanger(), lbl_27_bss_A48);
    fn_126_5DDC(m+0x3cb8, m+0x9d0);
    fn_27_5B248(m+0x3e50, m+0x9d0, b->getVisibilityData(), 2);
    fn_126_5E30(m+0x3e80, m+0x9d0, HEAP());
    fn_126_5EA0(m+0x45a4, m+0x9d0, b->getCameraRangeSet(),
                b->getCameraClipSphereSet(), lbl_27_bss_A48);
    fn_27_A1DA4(m+0x4618, m+0x9d0, b->getParamAccesser());
    fn_126_5F0C(m+0x464c, HEAP());
    fn_126_5F50(m+0x4740, m+0x9d0, b->getStatusData(), b->getPreCheckAnimCmdData());
    fn_126_6408(m+0x55a0, m+0x9d0);
    fn_126_67D8(m+0x58a8);
    fn_126_6838(m+0x5a90, m+0x9d0, b->getEffectNodeData(),
                b->getEffectEmitData(), b->getEffectCommonData(),
                b->getEffectScreenData(), lbl_27_bss_A48);
    fn_27_14FBD8(m+0x5c34, m+0x9d0);
    fn_126_6904(m+0x5c64, m+0x9d0, b->getAreaCategory(), lbl_27_bss_A48);
    b->getTerritoryRect();
    b->getTerritoryParam();
    b->getTargetSearchParam();
    fn_126_69D0(m+0x5ef4, m+0x9d0, b->getIkData());
    fn_27_ACAC4(m+0x5fb8, m+0x9d0, false, 1, false, b->getSlopeAngleLimit());
    fn_27_B62E4(m+0x6038, m+0x9d0, lbl_126_rodata_10, 0);
    b->getItemNodeData();
    fn_27_BEBB4(m+0x6084, m+0x9d0, 10, 1);
    fn_27_C20D8(m+0x61d8, m+0x9d0, 0, 8, b->getJostleData());
    fn_27_196664(m+0x6224, m+0x9d0);
    fn_27_5BED0(m+0x628c, m+0x9d0);
    fn_27_14CCEC(m+0x62c8, m+0x9d0);
    if (((V*)(m+0x5a68))->f08() == 0)
        ((V*)EN(0x64))->f14(1, m+0x5a68);

    fn_27_C74BC(m+0x6448, PTR(PTR(rawBuild,0xc),0x18), 6);
    a = m+0x6458;
    fn_27_1A599C(a, 0);
    fn_27_1A599C(a+0x46c, 0);
    fn_27_D22D0(a+0x8dc, 0);
    fn_126_6A30(a+0x988, a, a+0x46c, fn_126_6BDC());
    local.flags[0] = 0;
    fn_126_6A4C(a+0x9a4, HEAP(), a+0x8dc, 0, 1, lbl_126_rodata_14, &local.flags[0]);
    fn_126_6C4C(a, 0, 0x118);
    fn_126_6C4C(a+0x46c, 0, 0x118);
    fn_126_6C4C(fn_126_6BDC(), 0, 0);
    local.values[0] = 1;
    local.pairs[0] = a+0x9a4;
    local.pairs[1] = a+0x988;
    ((V*)EN(0x6c))->f0c(&local.pairs[0], &local.values[0]);

#define THREAD_IMPL(i,off,mask,size,declaration,q) \
    { \
        b->getAnimCmdData(i,2); \
        b->getAnimCmdData(i,1); \
        void* data=b->getAnimCmdData(i,0); \
        declaration q=a+off; \
        fn_27_C7744(q,data,size); \
        fn_27_D22D0(q+0x14,0); \
        fn_126_6A30(q+0xc0,q,lbl_27_bss_D8C,lbl_27_bss_D8C); \
        local.flags[i]=0; \
        fn_126_6A4C(q+0xdc,HEAP(),q+0x14,i,1,lbl_126_rodata_14,&local.flags[i]); \
        local.values[i]=mask; \
        local.pairs[2*i]=q+0xdc; \
        local.pairs[2*i+1]=q+0xc0; \
        ((V*)EN(0x6c))->f0c(&local.pairs[2*i],&local.values[i]); \
    }
#define THREAD(i,off,mask,size) THREAD_IMPL(i,off,mask,size,char*,q)
    THREAD_IMPL(1,0x9f4,2,0x1cf,,modelHeap)
    THREAD(2,0xb20,0x40,0x1cf)
    THREAD(3,0xc4c,0x40,0x1cf)
    THREAD(4,0xd78,2,0x1cf)
    THREAD(5,0xea4,0x20,0x1cf)
    THREAD(6,0xfd0,0x80,0x1cf)
    THREAD(7,0x10fc,0x80,0x1cf)
    THREAD_IMPL(8,0x1228,0x20,0x1cf,,motionHeap)
    {
        motionHeap = a+0x1354;
        local.flags[9] = 1;
        fn_126_6A4C(motionHeap, HEAP(), motionHeap+0x50, 9, 1,
                    lbl_126_rodata_14, &local.flags[9]);
        fn_27_1A079C(motionHeap+0x50, 0);
        local.values[9] = 4;
        local.pairs[18] = motionHeap;
        local.pairs[19] = lbl_27_bss_8C4;
        ((V*)EN(0x6c))->f0c(&local.pairs[18], &local.values[9]);
    }
    THREAD_IMPL(10,0x1478,0x10,0x29,,t)

    t = static_cast<char*>(b->getAnimCmdData(0, 0));
    fn_126_6C4C(fn_126_6CC8(a, 0), t, 0x112);
    t = static_cast<char*>(b->getAnimCmdData(0, 1));
    fn_126_6C4C(fn_126_6CC8(a, 1), t, 0x112);
    fn_126_6C4C(fn_126_6CC8(a, 0), PTR(PTR(rawBuild,0xc),0x24), 6);
    fn_126_6C4C(fn_126_6CC8(a, 1), PTR(PTR(rawBuild,0xc),0x28), 6);
    fn_126_6D04(a, 0, ((ftFighterBuildData*)rawBuild)->getAnimCmdDisguiseList(false, 0));
    fn_126_6D04(a, 1, ((ftFighterBuildData*)rawBuild)->getAnimCmdDisguiseList(false, 1));
    ((V*)EN(0x70))->f8c(m+0x6448);
    t = static_cast<char*>(soValueAccesser::getConstantIndefinite(
        M(soModuleAccesser,0x9d0), 0xa805, 0));
    cast = __dynamic_cast(EN(0x90), 0, lbl_126_data_CD8, lbl_126_data_D80, 0);
    if (cast)
        fn_27_14E0B8(cast, t);
    ((V*)EN(0x90))->f2c(t);

    fn_27_1404D4(p+0x7b90, PTR(p,0x60));
    new (p+0x7bcc) ZakoStateStorage();
    m = static_cast<char*>(PTR(p,0x60));
    arg2 = reinterpret_cast<int>(p+0x8084);
    fn_126_50F0(reinterpret_cast<char*>(arg2), 0);
    PTR(reinterpret_cast<char*>(arg2),0) = lbl_126_data_BD0;

    new (reinterpret_cast<char*>(arg2)+0x8) ZakoActionLeafStorage<lbl_27_data_2F9F8>(m);
    new (reinterpret_cast<char*>(arg2)+0x20) ZakoActionLeafStorage<lbl_27_data_2FAA0>(m);
    new (reinterpret_cast<char*>(arg2)+0x34) ZakoActionLeafStorage<lbl_27_data_2FB48>(m);
    new (reinterpret_cast<char*>(arg2)+0x48) ZakoActionLeafStorage<lbl_27_data_2FBF0>(m);
    new (reinterpret_cast<char*>(arg2)+0x5c) ZakoActionLeafStorage<lbl_27_data_2FC98>(m);
    new (reinterpret_cast<char*>(arg2)+0x70) ZakoActionLeafStorage<lbl_27_data_2FD40>(m);
    new (reinterpret_cast<char*>(arg2)+0x84) ZakoActionLeafStorage<lbl_27_data_2FDE8>(m);

    PTR(p,0x811c) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(p,0x60), 0xa7f9, 0);
    *(int*)(p+0x8120) = 1;
    PTR(p,0x8124) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(p,0x60), 0xa7fc, 0);
    *(int*)(p+0x8128) = 1;
    fn_27_126470(p);
    reinterpret_cast<ftCancelModule*>(p+0x7b90)->postInitialize((soModuleAccesser*)PTR(p,0x60));
    SETVT(lbl_126_data_53B4)
    fn_27_C749C(p+0x812c);
    PTR(p,0x813c) = g_ftCommonDataAccesser.getData((ftKind)0x33);
    return p;
}

#undef THREAD
#undef THREAD_IMPL
#undef GROUP
#undef ID
#undef b
#undef rawBuild
#undef M
#undef SETVT
#undef HEAP
#undef EN
#undef PTR