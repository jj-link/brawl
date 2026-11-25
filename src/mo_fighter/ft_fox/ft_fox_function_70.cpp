#include <types.h>
#pragma use_simple_stdpnew on
#include <new>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern char lbl_97_data_62C[], lbl_97_data_148[], lbl_97_data_229C[], lbl_97_data_2344[];
extern char lbl_97_data_2114[], lbl_97_data_2194[], lbl_97_bss_1A0[];
extern char lbl_27_bss_A48[], lbl_27_bss_D8C[], lbl_27_bss_8C4[], lbl_27_bss_3AC[];
extern char lbl_27_bss_3CC[], lbl_27_bss_4BC[], lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_69C[];
extern char lbl_27_bss_7BEC[], lbl_27_bss_7B1C[], lbl_27_bss_7B2C[], lbl_27_bss_7B3C[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[], lbl_27_data_2FB48[], lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[], lbl_27_data_2FD40[], lbl_27_data_2FDE8[];
extern const float lbl_97_rodata_0[];
void fn_27_1257EC(void*, int, int, int, void*);
void fn_97_8140(void*);
void fn_27_14B5F8(void*, void*);
void fn_97_8494(void*, int, int, u8, void*);
void fn_97_84FC(void*, void*, float, void*, void*);
void fn_97_8584(void*, void*, void*);
void fn_97_8758(void*, void*, void*);
void fn_97_87C8(void*, void*, void*);
void fn_27_3513C(void*, s16, void*, void*);
void fn_97_8074(void*, int, void*);
void fn_97_882C(void*, void*, int, u8, void*);
void fn_97_88F0(void*, void*, int, u8, void*);
void fn_97_89B4(void*, void*, int, u8);
void fn_97_8A88(void*, void*, int, u8);
void fn_97_8B5C(void*, void*, int, u8, void*);
void fn_97_8BF4(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_97_8C60(void*, void*, void*);
void fn_97_8CBC(void*, void*, void*, void*);
void fn_97_8D4C(void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_97_8DA0(void*, void*, s16);
void fn_97_8E10(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_97_8E7C(void*, s16);
void fn_97_8EC0(void*, void*, void*, void*);
void fn_97_9378(void*, void*);
void fn_97_9748(void*);
void fn_97_97A8(void*, void*);
void fn_97_9B3C(void*, void*, void*, void*, void*, void*, void*);
void fn_27_14FBD8(void*, void*);
void fn_97_9C08(void*, void*, u8, void*);
void fn_97_9CA0(void*, void*, void*);
void fn_27_ACAC4(void*, void*, int, int, bool, float);
void fn_27_B62E4(void*, void*, float, int);
void fn_97_9D00(void*, void*, void*);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A60B8(void*, int);
void fn_27_D22D0(void*, int);
void fn_97_9D7C(void*, void*, void*, void*);
void fn_97_9D98(void*, s16, void*, int, int, float, s8*);
void fn_97_9F98(void*, void*, int);
void fn_27_C7744(void*, void*, int);
void fn_27_1A079C(void*, int);
void fn_97_A050(void*, int, void*);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_97_8060(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);
void fn_27_1A6EF0(void*, int, void*, int);
void fn_27_195B34(void*, void*, void*);
void* fn_97_9F28();
void* fn_97_A014(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct BuildQueries : soModuleAccesserBuildData {
    virtual s32 getHeapSlotNo() const = 0;
    virtual void* getModelExtendNodeTable() const = 0;
    virtual float getModelScale() const = 0;
    virtual soSoundIdExchanger* getSoundIdExchanger() const = 0;
    virtual soPreCheckAnimCmdData* getPreCheckAnimCmdData() const = 0;
    virtual void* getEffectNodeData() const = 0;
    virtual soEffectScreenData* getEffectScreenData() const = 0;
    virtual s32* getTerritoryRect() const = 0;
    virtual void* getTerritoryParam() const = 0;
    virtual void* getTargetSearchParam() const = 0;
    virtual soIkData* getIkData() const = 0;
    virtual float getSlopeAngleLimit() const = 0;
};

struct WorkQueries {
    virtual int isNull() const;
};

struct SlopeStorage {
    SlopeStorage(soModuleAccesser* modules, int initial, float limit) {
        fn_27_ACAC4(this, modules, initial, 1, false, limit);
    }
};

struct ShadowStorage {
    ShadowStorage(soModuleAccesser* modules, const float* constants) {
        fn_27_B62E4(this, modules, constants[0], 0);
    }
};

struct ColorStorage {
    ColorStorage(soModuleAccesser* modules) {
        fn_27_BEBB4(this, modules, 10, 1);
    }
};

struct JostleStorage {
    JostleStorage(soModuleAccesser* modules, void* jostle) {
        fn_27_C20D8(this, modules, 0, 8, jostle);
    }
};

struct CmdRegistry {
    virtual bool isNull();
    virtual void put(void**, s16*);
};

struct FoxExtension {
    virtual void slot0();
    virtual void init(soModuleAccesser*);
};

struct FoxArray {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void clear();
};

struct FoxStatusStorage {
    bool flagA;
    bool flagB;
    char* list;
    char embeddedList[1];

    FoxStatusStorage(void* scratch)
        : flagA(false), flagB(false), list(embeddedList) {
        fn_27_1A6EF0(embeddedList, 4, scratch, 0);
        reinterpret_cast<FoxArray*>(embeddedList)->clear();
    }
};

struct PhysicsCalls {
    int prefix[2];
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19(int);
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(int);
};

struct FoxFrame {
    s8 flags[11];
    s16 masks[11];
    void* pairs[11][2];
    int scratch[4];
    union {
        soCollisionReflectorGroupData* alignment;
        char bytes[28];
    } reflector;
    char output[32];
    char buildData[sizeof(ftFighterBuildData)];
    void* processes[14];
};

#define FIELD(type, p, offset) (*reinterpret_cast<type*>(reinterpret_cast<char*>(p) + (offset)))
#define MOD(p) (reinterpret_cast<soModuleAccesser*>((p) + 0x9d0))
#define MODULES(p) (MOD(p)->m_enumerationStart)
#define ACCESS (FIELD(soModuleAccesser*, self, 0x60))
#define THREAD_ID (static_cast<soEventManager&>(*MODULES(m)->m_eventManageModule).getManageId())
#define REGISTRY (reinterpret_cast<CmdRegistry*>(MODULES(m)->m_animCmdModule))
#define INSTALL_TABLES(p, vt) \
    FIELD(void*, p, 0x3c) = vt + 0x0; \
    FIELD(void*, p, 0x40) = vt + 0x64; \
    FIELD(void*, p, 0x48) = vt + 0x70; \
    FIELD(void*, p, 0x54) = vt + 0x84; \
    FIELD(void*, p, 0x64) = vt + 0xdc; \
    FIELD(void*, p, 0x70) = vt + 0xec; \
    FIELD(void*, p, 0x7c) = vt + 0xfc; \
    FIELD(void*, p, 0x88) = vt + 0x110; \
    FIELD(void*, p, 0x94) = vt + 0x128; \
    FIELD(void*, p, 0xa0) = vt + 0x140; \
    FIELD(void*, p, 0xac) = vt + 0x158; \
    FIELD(void*, p, 0xb8) = vt + 0x16c; \
    FIELD(void*, p, 0xc4) = vt + 0x180; \
    FIELD(void*, p, 0xd0) = vt + 0x190; \
    FIELD(void*, p, 0xdc) = vt + 0x1c4; \
    FIELD(void*, p, 0xe8) = vt + 0x1d4; \
    FIELD(void*, p, 0xf4) = vt + 0x1e8; \
    FIELD(void*, p, 0x100) = vt + 0x254

#define REGISTER_THREAD(i, bits, interpreter, addresses) \
    frame.masks[i] = bits; \
    frame.pairs[i][0] = interpreter; \
    frame.pairs[i][1] = addresses; \
    REGISTRY->put(frame.pairs[i], &frame.masks[i])

#define INIT_THREAD_AT(binding, thread, i, offset, size, bits) do { \
    build->getAnimCmdData(i, 2); \
    build->getAnimCmdData(i, 1); \
    void* script = build->getAnimCmdData(i, 0); \
    binding = anim + offset; \
    fn_27_C7744(thread, script, size); \
    fn_27_D22D0(thread + 0x14, 0); \
    fn_97_9D7C(thread + 0xc0, thread, lbl_27_bss_D8C, lbl_27_bss_D8C); \
    frame.flags[i] = 0; \
    fn_97_9D98(thread + 0xdc, THREAD_ID, thread + 0x14, i, 1, rodata[1], &frame.flags[i]); \
    REGISTER_THREAD(i, bits, thread + 0xdc, thread + 0xc0); \
} while (0)

#define INIT_THREAD(i, offset, size, bits) \
    INIT_THREAD_AT(char* thread, thread, i, offset, size, bits)

struct PartStorage {
    char* table;
    char* secondaryTable;

    PartStorage(soModuleAccesser* access, char* vt) {
        fn_27_17437C(this, access);
        table = vt;
        secondaryTable = vt + 0x40;
    }
};

#define INIT_PART(offset, vt) new (parts + offset) PartStorage(access, vt)

extern "C" void* fn_97_70(char* self, s32 entry, Heaps::HeapType heap,
                          Heaps::HeapType modelHeap, Heaps::HeapType motionHeap) {
    const float* const rodata = lbl_97_rodata_0;
    char* parts;
    FoxFrame frame;
    fn_27_1257EC(self, entry, 6, heap, self + 0xb64);
    INSTALL_TABLES(self, lbl_97_data_62C);
    new (frame.buildData) ftFighterBuildData(entry, (ftKind)6, heap, modelHeap, motionHeap,
        0, ACCESS, -1, self + 0x1cd20, self + 0x1cd28);
    #define build ((BuildQueries*)frame.buildData)
    void* commands;
    soSet<soAreaData>* areas;
    char* extension;
    char* thread10;
    char* thread9;
    char* thread8;
    char* thread1;
    char* anim;
    char* m = self + 0x194;
    soModuleAccesser* access;
    fn_97_8140(m);
    new (m + 0x9d0) soModuleAccesser(
        (StageObject*)(self),
        (soResourceModule*)(m + 0x1168),
        (soModelModule*)(m + 0x13dc),
        (soMotionModule*)(m + 0x16cc),
        (soPostureModule*)(m + 0x1878),
        (soGroundModule*)(m + 0x1940),
        (soSituationModule*)(m + 0x1998),
        m + 0x1a04,
        (soCollisionAttackModule*)(m + 0x2064),
        (soCollisionHitModule*)(m + 0x2720),
        (soCollisionShieldModule*)(m + 0x294c),
        (soCollisionShieldModule*)(m + 0x3304),
        (soCollisionShieldModule*)(lbl_27_bss_3AC),
        m + 0x34d8,
        (soCollisionSearchModule*)(lbl_27_bss_3CC),
        (soDamageModule*)(m + 0x366c),
        m + 0x3770,
        m + 0x37d4,
        (soStopModule*)(m + 0x3808),
        m + 0x382c,
        m + 0x38e0,
        (soSoundModule*)(m + 0x3910),
        (soLinkModule*)(m + 0x3ae4),
        (soVisibilityModule*)(m + 0x3b38),
        (soControllerModule*)(m + 0x4120),
        (soCameraModule*)(m + 0x42dc),
        (soWorkManageModule*)(m + 0x4300),
        lbl_27_bss_4BC,
        (soAnimCmdModule*)(m + 0x4334),
        (soStatusModule*)(m + 0x51f8),
        lbl_27_bss_46C0,
        lbl_27_bss_46D8,
        (soKineticModule*)(m + 0x52a8),
        (soEventManageModule*)(m + 0xb8),
        m + 0x1a428,
        (soEffectModule*)(m + 0x1a4d0),
        m + 0x1a608,
        (soAreaModule*)(m + 0x1a648),
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        m + 0x1aa28,
        m + 0x1aa70,
        (soShadowModule*)(m + 0x1aaf0),
        (soItemManageModule*)(m + 0x1abdc),
        (soColorBlendModule*)(m + 0x1ac48),
        m + 0x1ad9c,
        m + 0x1ade8,
        (soSlowModule*)(m + 0x1ae50),
        lbl_27_bss_69C,
        m + 0xab0,
        (soParamCustomizeModule*)(m + 0xac8),
        m + 0x1ae8c);
    s32 slot = build->getHeapSlotNo();
    thread8 = (char*)(long)build->getNWMotionInstanceHeap();
    thread1 = (char*)(long)build->getNWModelInstanceHeap();
    Heaps::HeapType instance = build->getInstanceHeap();
    new (m + 0xab0) soHeapModuleImpl(instance,
        (Heaps::HeapType)(long)thread1, (Heaps::HeapType)(long)thread8, slot);
    fn_27_14B5F8(m + 0xac8, MOD(m));
    fn_97_8494(m + 0x115c, build->getMdlResId(), build->getAnmResId(), build->getResGroupNo(), MOD(m));
    thread8 = static_cast<char*>(build->getModelExtendNodeTable());
    fn_97_84FC(m + 0x1180, MOD(m), build->getModelScale(), thread8, lbl_27_bss_A48);
    fn_97_8584(m + 0x14a8, MOD(m), build->getMotionData());
    fn_97_8758(m + 0x183c, MOD(m), lbl_27_bss_A48);
    fn_97_87C8(m + 0x18f0, MOD(m), build->getGroundConditionChecker());
    fn_27_3513C(m + 0x1998, THREAD_ID, MOD(m), lbl_27_bss_A48);
    fn_97_8074(m + 0x19d4, build->getTeam(), MOD(m));
#define OWNER_ARGS FIELD(int, self, 0x28), (u8)(FIELD(u32, self, 0x2c) >> 7)
    fn_97_882C(m + 0x1a48, MOD(m), OWNER_ARGS, lbl_27_bss_A48);
    fn_97_88F0(m + 0x2104, MOD(m), OWNER_ARGS, lbl_27_bss_A48);
    fn_97_89B4(m + 0x2788, MOD(m), OWNER_ARGS);
    fn_97_8A88(m + 0x29a0, MOD(m), OWNER_ARGS);
    fn_97_8B5C(m + 0x335c, MOD(m), OWNER_ARGS, lbl_27_bss_A48);
    fn_97_8BF4(m + 0x35c0, MOD(m), lbl_27_bss_A48);
    fn_27_64C8C(m + 0x3770, MOD(m), 1);
    fn_27_65EE4(m + 0x37d4, MOD(m));
    fn_27_154088(m + 0x3808, MOD(m));
    fn_27_693F4(m + 0x382c, MOD(m));
    fn_97_8C60(m + 0x3864, MOD(m), build->getShakeData());
    fn_97_8CBC(m + 0x38fc, MOD(m), build->getSoundIdExchanger(), lbl_27_bss_A48);
    fn_97_8D4C(m + 0x396c, MOD(m));
    fn_27_5B248(m + 0x3b38, MOD(m), build->getVisibilityData(), 2);
    fn_97_8DA0(m + 0x3b68, MOD(m), THREAD_ID);
    fn_97_8E10(m + 0x428c, MOD(m), build->getCameraRangeSet(), build->getCameraClipSphereSet(), lbl_27_bss_A48);
    fn_27_A1DA4(m + 0x4300, MOD(m), build->getParamAccesser());
    fn_97_8E7C(m + 0x4334, THREAD_ID);
    fn_97_8EC0(m + 0x4428, MOD(m), build->getStatusData(), build->getPreCheckAnimCmdData());
    fn_97_9378(m + 0x52a8, MOD(m));
    fn_97_9748(m + 0x55b0);
    fn_97_97A8(m + 0x5794, MOD(m));
    fn_97_9B3C(m + 0x1a464, MOD(m), build->getEffectNodeData(), build->getEffectEmitData(),
        build->getEffectCommonData(), build->getEffectScreenData(), lbl_27_bss_A48);
    fn_27_14FBD8(m + 0x1a608, MOD(m));
    s32 category = build->getAreaCategory();
    fn_97_9C08(m + 0x1a638, MOD(m), category, lbl_27_bss_A48);
    build->getTerritoryRect();
    build->getTerritoryParam();
    build->getTargetSearchParam();
    fn_97_9CA0(m + 0x1a9ac, MOD(m), build->getIkData());
    new (m + 0x1aa70) SlopeStorage(MOD(m), 0, build->getSlopeAngleLimit());
    new (m + 0x1aaf0) ShadowStorage(MOD(m), rodata);
    fn_97_9D00(m + 0x1ab38, MOD(m), build->getItemNodeData());
    new (m + 0x1ac48) ColorStorage(MOD(m));
    new (m + 0x1ad9c) JostleStorage(MOD(m), build->getJostleData());
    fn_27_196664(m + 0x1ade8, MOD(m));
    fn_27_5BED0(m + 0x1ae50, MOD(m));
    fn_27_14CCEC(m + 0x1ae8c, MOD(m));
    if (!((WorkQueries*)(m + 0x5770))->isNull())
        MODULES(m)->m_workManageModule->setWork(1, (soGeneralWorkAbstract*)(m + 0x5770));
    fn_27_C74BC(m + 0x1b00c, FIELD(void*, FIELD(char*, frame.buildData, 0xc), 0x18), 14);

    anim = m + 0x1b01c;
    fn_27_1A60B8(anim, 0);
    fn_27_1A60B8(anim + 0x48c, 0);
    fn_27_D22D0(anim + 0x91c, 0);
    fn_97_9D7C(anim + 0x9c8, anim, anim + 0x48c, fn_97_9F28());
    frame.flags[0] = 0;
    fn_97_9D98(anim + 0x9e4, THREAD_ID, anim + 0x91c, 0, 1, rodata[1], &frame.flags[0]);
    fn_97_9F98(anim, 0, 0x120);
    fn_97_9F98(anim + 0x48c, 0, 0x120);
    fn_97_9F98(fn_97_9F28(), 0, 0);
    REGISTER_THREAD(0, 1, anim + 0x9e4, anim + 0x9c8);
    INIT_THREAD_AT(thread1, thread1, 1, 0xa34, 0x1f2, 2);
    INIT_THREAD(2, 0xb60, 0x1f2, 64);
    INIT_THREAD(3, 0xc8c, 0x1f2, 64);
    INIT_THREAD(4, 0xdb8, 0x1f2, 2);
    INIT_THREAD(5, 0xee4, 0x1f2, 32);
    INIT_THREAD(6, 0x1010, 0x1f2, 128);
    INIT_THREAD(7, 0x113c, 0x1f2, 128);
    INIT_THREAD_AT(thread8, thread8, 8, 0x1268, 0x1f2, 32);

    thread9 = anim + 0x1394;
    frame.flags[9] = 1;
    fn_97_9D98(thread9, THREAD_ID, thread9 + 0x50, 9, 1, rodata[1], &frame.flags[9]);
    fn_27_1A079C(thread9 + 0x50, 0);
    REGISTER_THREAD(9, 4, thread9, lbl_27_bss_8C4);
    INIT_THREAD_AT(thread10, thread10, 10, 0x14b8, 0x29, 16);

    commands = build->getAnimCmdData(0, 0);
    fn_97_9F98(fn_97_A014(anim, 0), commands, 0x112);
    commands = build->getAnimCmdData(0, 1);
    fn_97_9F98(fn_97_A014(anim, 1), commands, 0x112);
    void* list = fn_97_A014(anim, 0);
    fn_97_9F98(list, FIELD(void*, FIELD(char*, frame.buildData, 0xc), 0x24), 14);
    list = fn_97_A014(anim, 1);
    fn_97_9F98(list, FIELD(void*, FIELD(char*, frame.buildData, 0xc), 0x28), 14);
#define fighterBuild ((ftFighterBuildData*)frame.buildData)
    fn_97_A050(anim, 0, fighterBuild->getAnimCmdDisguiseList(false, 0));
    fn_97_A050(anim, 1, fighterBuild->getAnimCmdDisguiseList(false, 1));
    MODULES(m)->m_statusModule->connectStatusDataList(m + 0x1b00c);
    areas = (soSet<soAreaData>*)soValueAccesser::getConstantIndefinite(MOD(m), 0xa805, 0);
    void* areaImpl = __dynamic_cast(MODULES(m)->m_areaModule, 0, lbl_97_data_229C, lbl_97_data_2344, 0);
    if (areaImpl) fn_27_14E0B8(areaImpl, areas);
    MODULES(m)->m_areaModule->addArea(areas);

    fn_27_1404D4(self + 0x1c794, ACCESS);
    extension = self + 0x1c7d0;
    fn_97_8060(extension, 0);
    FIELD(void*, extension, 0) = lbl_97_data_2114;
    access = ACCESS;
    parts = self + 0x1cc88;
    fn_97_8060(parts, 0);
    FIELD(void*, parts, 0) = lbl_97_data_2194;
    INIT_PART(8, lbl_27_data_2F9F8);
    INIT_PART(0x20, lbl_27_data_2FAA0);
    INIT_PART(0x34, lbl_27_data_2FB48);
    INIT_PART(0x48, lbl_27_data_2FBF0);
    INIT_PART(0x5c, lbl_27_data_2FC98);
    INIT_PART(0x70, lbl_27_data_2FD40);
    INIT_PART(0x84, lbl_27_data_2FDE8);
    FIELD(void*, self, 0x1cd20) = soValueAccesser::getConstantIndefinite(ACCESS, 0xa7f9, 0);
    FIELD(int, self, 0x1cd24) = 1;
    FIELD(void*, self, 0x1cd28) = soValueAccesser::getConstantIndefinite(ACCESS, 0xa7fc, 0);
    FIELD(int, self, 0x1cd2c) = 1;
    fn_27_126470(self);
    ((FoxExtension*)(self + 0x1c794))->init(ACCESS);
    INSTALL_TABLES(self, lbl_97_data_148);
    ftData* common = g_ftCommonDataAccesser.getData((ftKind)6);
    {
        char* commonBase = self + 0x20000;
        FIELD(ftData*, commonBase, -0x32d0) = common;
        fn_27_C749C(self + 0x1cd34);
    }
    FIELD(bool, self + 0x20000, -0x32bc) = false;
    m = self + 0x20000;
    FIELD(bool, m, -0x32bb) = false;
    FIELD(char*, m, -0x32b8) = m - 0x32b4;
    fn_27_1A6EF0(m - 0x32b4, 4, frame.scratch, 0);
    reinterpret_cast<FoxArray*>(m - 0x32b4)->clear();

    struct StatusProcessList {
        void* entries[14];
        StatusProcessList() : entries() {}
    };
    new (frame.processes) StatusProcessList();
    frame.processes[0] = lbl_27_bss_7BEC;
    frame.processes[1] = lbl_27_bss_7B1C;
    frame.processes[2] = lbl_27_bss_7B2C;
    frame.processes[3] = lbl_97_bss_1A0;
    frame.processes[5] = lbl_27_bss_7B2C;
    frame.processes[6] = lbl_27_bss_7B2C;
    frame.processes[7] = lbl_27_bss_7B2C;
    frame.processes[8] = lbl_97_bss_1A0;
    frame.processes[9] = lbl_97_bss_1A0;
    frame.processes[10] = lbl_97_bss_1A0;
    frame.processes[11] = lbl_27_bss_7B3C;
    frame.processes[12] = lbl_27_bss_7B3C;
    frame.processes[13] = lbl_27_bss_7B3C;
    ACCESS->m_enumerationStart->m_statusModule->addRangeUniqProc((soStatusUniqProcess*)frame.processes, 14);

    void* params = FIELD(void*, FIELD(char*, self, 0x1cd30), 0x90);
#define data frame.reflector.bytes
    FIELD(int, data, 0) = 0;
    FIELD(int, data, 4) = 0;
    float zero = rodata[2];
    FIELD(float, data, 8) = zero;
    FIELD(float, data, 12) = zero;
    FIELD(float, data, 16) = zero;
    FIELD(float, data, 20) = zero;
    FIELD(u32, data, 24) &= 0x7fffffff;
    fn_27_195B34(params, frame.output, data);
    ACCESS->m_enumerationStart->m_collisionReflectorModule->add((soCollisionReflectorGroupData*)data, 2);
    ACCESS->m_enumerationStart->m_collisionReflectorModule->setStatus(0, 0, 2);
    ((PhysicsCalls*)ACCESS->m_enumerationStart->m_physicsModule)->v19(0);
    ((PhysicsCalls*)ACCESS->m_enumerationStart->m_physicsModule)->v25(0x15);
    return self;
}
