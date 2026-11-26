#include <types.h>
#include <new>
#include <ft/ft_fighter_build_data.h>
#include <so/so_heap_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <ft/ft_common_data_accesser.h>

#pragma use_simple_stdpnew on
#pragma force_active on

inline void* operator new[](size_t, void* storage) { return storage; }

class BuildCalls {
public:
    virtual u32 getMdlResId();
    virtual u32 getAnmResId();
    virtual int getResGroupNo();
    virtual int getTeam();
    virtual void* getMotionData();
    virtual void* getShakeData();
    virtual void* getVisibilityData();
    virtual void* getStatusData();
    virtual void* getGroundConditionChecker();
    virtual void* getEffectNodeData();
    virtual void* getEffectEmitData();
    virtual int getEffectCommonData();
    virtual int getEffectScreenData();
    virtual void* getTerritoryParam();
    virtual void* getTerritoryRect();
    virtual void* getTargetSearchParam();
    virtual void* getIkData();
    virtual int getModelLayerType();
    virtual float getModelScale();
    virtual void* getParamAccesser();
    virtual int getAreaCategory();
    virtual void* getCameraRangeSet();
    virtual void* getCameraClipSphereSet();
    virtual void* getItemNodeData();
    virtual void* getModelExtendNodeTable();
    virtual void* getJostleData();
    virtual void* getPreCheckAnimCmdData();
    virtual Heaps::HeapType getInstanceHeap();
    virtual Heaps::HeapType getNWModelInstanceHeap();
    virtual Heaps::HeapType getNWMotionInstanceHeap();
    virtual int getHeapSlotNo();
    virtual void* getSoundIdExchanger();
    virtual float getSlopeAngleLimit();
    virtual void unused();
    virtual void* getAnimCmdData(u32, int);
};

class Calls {
public:
    virtual int f01();
    virtual void* f02(int);
    virtual void f03();
    virtual int f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual int f08();
    virtual void f09();
    virtual void f10(void*);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27(int);
    virtual void f28();
    virtual void f29(void*, int);
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34(void*);
};

class RegisterCalls {
public:
    virtual void f01();
    virtual void f02(void**, short*);
    virtual void f03();
    virtual void f04(int, void*);
};

class UpdateCalls {
public:
    virtual void f01();
    virtual void f02(void*);
};

struct LastBase {
    int a, b;
};

class LastCalls : public LastBase {
public:
    virtual void f01();
    virtual void f02();
    virtual void f03();
    virtual void f04();
    virtual void f05();
    virtual void f06();
    virtual void f07();
    virtual void f08();
    virtual void f09();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26(int);
};

struct LastObject {
    LastCalls calls;
};

struct Locals {
    signed char flags[11];
    char pad0;
    short masks[11];
    char pad1[2];
    void* pairs[22];
    char build[0x30];
    void* extras[21];
};

extern "C" {
void fn_27_1257EC(void*, int, int, int, void*);
void fn_123_6E10(void*);
void fn_27_14B5F8(void*, void*);
void fn_123_7164(void*, u32, u32, u8, void*);
void* fn_123_71CC(void*, soModuleAccesser*, float, void*, soEventObserverRegistrationDesc*);
void fn_123_7254(void*, void*, void*);
void fn_123_7428(void*, void*, void*);
void fn_123_7498(void*, void*, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_123_6D44(void*, int, void*);
void fn_123_74FC(void*, void*, int, int, void*);
void fn_123_75C0(void*, void*, int, int, void*);
void fn_123_7684(void*, void*, int, int);
void fn_123_7758(void*, void*, int, int);
void fn_123_782C(void*, void*, int, int, void*);
void fn_123_78C4(void*, void*, int, int);
void fn_123_7960(void*, void*, void*);
void fn_27_64C8C(void*, void*, int);
void fn_27_65EE4(void*, void*);
void fn_27_154088(void*, void*);
void fn_27_693F4(void*, void*);
void fn_123_79CC(void*, void*, void*);
void fn_123_7A28(void*, void*, void*, void*);
void fn_123_7AB8(void*, void*);
void fn_27_5B248(void*, void*, void*, int);
void fn_123_7B0C(void*, void*, short);
void fn_123_7B7C(void*, void*, void*, void*, void*);
void fn_27_A1DA4(void*, void*, void*);
void fn_123_7BE8(void*, short);
void fn_123_7C2C(void*, void*, void*, void*);
void fn_123_80E4(void*, void*);
void fn_123_84B4(void*);
void fn_123_8514(void*, void*);
void fn_123_86A0(void*, void*, void*, void*, int, int, void*);
void fn_27_14FBD8(void*, void*);
void fn_123_876C(void*, void*, u8, void*);
void fn_123_8804(void*, void*, void*);
void fn_27_ACAC4(void*, void*, int, int, u8);
void fn_27_B62E4(void*, void*, float, int);
void fn_123_8864(void*, void*, void*);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_C20D8(void*, void*, int, int, void*);
void fn_27_196664(void*, void*);
void fn_27_5BED0(void*, void*);
void fn_27_14CCEC(void*, void*);
void fn_27_C74BC(void*, void*, int);
void fn_27_1A66D0(void*, int);
void fn_27_D22D0(void*, int);
void fn_27_C7744(void*, void*, int);
void fn_123_88E0(void*, void*, void*, void*);
void fn_123_88FC(void*, short, void*, int, int, float, signed char*);
void fn_123_8AFC(void*, void*, int);
void* fn_123_8A8C();
void* fn_123_8B78(void*, int);
void fn_123_8BB4(void*, int, void*);
void fn_27_1A079C(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_14E0B8(void*, void*);
void fn_27_1404D4(void*, void*);
void fn_123_6D30(void*, int);
void fn_27_17437C(void*, void*);
void fn_27_126470(void*);
void fn_27_C749C(void*);

extern char lbl_123_data_608[], lbl_123_data_120[];
extern char lbl_123_data_1388[], lbl_123_data_1408[];
extern char lbl_27_bss_3AC[], lbl_27_bss_4BC[];
extern char lbl_27_bss_46C0[], lbl_27_bss_46D8[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[];
extern char lbl_27_bss_69C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[];
extern char lbl_123_data_156C[], lbl_123_data_1614[];
extern char lbl_27_data_2F9F8[], lbl_27_data_2FAA0[];
extern char lbl_27_data_2FB48[], lbl_27_data_2FBF0[];
extern char lbl_27_data_2FC98[], lbl_27_data_2FD40[];
extern char lbl_27_data_2FDE8[];
extern char lbl_123_bss_304[], lbl_123_bss_314[];
extern char lbl_123_bss_324[], lbl_123_bss_334[];
extern const float lbl_123_rodata_0, lbl_123_rodata_4;
}

#define PTR(p, o) (*(void**)((char*)(p) + (o)))
#define INT(p, o) (*(int*)((char*)(p) + (o)))
#define UINT(p, o) (*(unsigned int*)((char*)(p) + (o)))
#define OB(p, o) ((Calls*)((char*)(p) + (o)))
#define ENUM(m) PTR(m, 0xaa8)

inline int eventId(char* m) {
    return OB(PTR(ENUM(m), 0x80), 8)->f08();
}

#define setTables(s, t) do { \
    PTR(s, 0x3c) = t; PTR(s, 0x40) = t + 0x64; \
    PTR(s, 0x48) = t + 0x70; PTR(s, 0x54) = t + 0x84; \
    PTR(s, 0x64) = t + 0xdc; PTR(s, 0x70) = t + 0xec; \
    PTR(s, 0x7c) = t + 0xfc; PTR(s, 0x88) = t + 0x110; \
    PTR(s, 0x94) = t + 0x128; PTR(s, 0xa0) = t + 0x140; \
    PTR(s, 0xac) = t + 0x158; PTR(s, 0xb8) = t + 0x16c; \
    PTR(s, 0xc4) = t + 0x180; PTR(s, 0xd0) = t + 0x190; \
    PTR(s, 0xdc) = t + 0x1c4; PTR(s, 0xe8) = t + 0x1d4; \
    PTR(s, 0xf4) = t + 0x1e8; PTR(s, 0x100) = t + 0x254; \
} while (0)

class SlopeInit {
public:
    inline SlopeInit(void* access) {
        fn_27_ACAC4(this, access, 0, 1, 0);
    }
};

class ShadowInit {
public:
    inline ShadowInit(void* access, float value) {
        fn_27_B62E4(this, access, value, 0);
    }
};

class ColorBlendInit {
public:
    inline ColorBlendInit(void* access) {
        fn_27_BEBB4(this, access, 10, 1);
    }
};

class JostleInit {
public:
    inline JostleInit(void* access, void* params) {
        fn_27_C20D8(this, access, 0, 8, params);
    }
};

template<char* table>
class SonicActionLeaf {
public:
    SonicActionLeaf(void* accesser) {
        fn_27_17437C(this, accesser);
        PTR(this, 0) = table;
        PTR(this, 4) = table + 0x40;
    }
};
#define SETUP_LISTENER(offset, label) new (listeners + offset) SonicActionLeaf<label>(m);

#define data ((BuildCalls*)l.build)

#define PAIR(i, a, b, k) \
    l.masks[i] = (k); \
    l.pairs[2 * (i)] = (a); \
    l.pairs[2 * (i) + 1] = (b); \
    ((RegisterCalls*)PTR(ENUM(m), 0x6c))->f02(&l.pairs[2 * (i)], &l.masks[i])

#define SETUP_SCRIPT(i, offset, count, kind, declaration, target) \
    data->getAnimCmdData(i, 2); \
    data->getAnimCmdData(i, 1); \
    void* scriptData##i = data->getAnimCmdData(i, 0); \
    { \
        declaration target = ac + offset; \
        fn_27_C7744(target, scriptData##i, count); \
        fn_27_D22D0(target + 0x14, 0); \
        fn_123_88E0(target + 0xc0, target, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        l.flags[i] = 0; \
        fn_123_88FC(target + 0xdc, eventId(m), target + 0x14, i, 1, \
                    lbl_123_rodata_4, &l.flags[i]); \
        PAIR(i, target + 0xdc, target + 0xc0, kind); \
    }

extern "C" void* fn_123_70(char* s, int a, int b, int c, int d) {
    char* part;
    Locals l;
    fn_27_1257EC(s, a, 0x2f, b, s + 0xb64);
    setTables(s, lbl_123_data_608);

    new (l.build) ftFighterBuildData(
        a, (ftKind)0x2f, (Heaps::HeapType)b, (Heaps::HeapType)c,
        (Heaps::HeapType)d, 0, (soModuleAccesser*)PTR(s, 0x60),
        -1, s + 0xd5b4, s + 0xd5bc);

    char* extraCommand;
    char* finalCommand;
    void* main0;
    void* main1;
    void* constant;
    char* listeners;
    char* ac;
    char* m = s + 0x194;
    fn_123_6E10(m);

    new (m + 0x9d0) soModuleAccesser(
        (StageObject*)s,
        (soResourceModule*)(m + 0x1168),
        (soModelModule*)(m + 0x1374),
        (soMotionModule*)(m + 0x1664),
        (soPostureModule*)(m + 0x1810),
        (soGroundModule*)(m + 0x18d8),
        (soSituationModule*)(m + 0x1930),
        m + 0x199c,
        (soCollisionAttackModule*)(m + 0x1ffc),
        (soCollisionHitModule*)(m + 0x2990),
        (soCollisionShieldModule*)(m + 0x2bbc),
        (soCollisionShieldModule*)(m + 0x3624),
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        m + 0x37f8,
        (soCollisionSearchModule*)(m + 0x39cc),
        (soDamageModule*)(m + 0x3b80),
        m + 0x3c84, m + 0x3ce8,
        (soStopModule*)(m + 0x3d1c),
        m + 0x3d40, m + 0x3df4,
        (soSoundModule*)(m + 0x3e24),
        (soLinkModule*)(m + 0x3ff8),
        (soVisibilityModule*)(m + 0x404c),
        (soControllerModule*)(m + 0x4634),
        (soCameraModule*)(m + 0x47f0),
        (soWorkManageModule*)(m + 0x4814),
        lbl_27_bss_4BC,
        (soAnimCmdModule*)(m + 0x4848),
        (soStatusModule*)(m + 0x5728),
        lbl_27_bss_46C0, lbl_27_bss_46D8,
        (soKineticModule*)(m + 0x57d8),
        (soEventManageModule*)(m + 0xb8),
        m + 0xac84,
        (soEffectModule*)(m + 0xad2c),
        m + 0xae64,
        (soAreaModule*)(m + 0xaea4),
        lbl_27_bss_5B0, lbl_27_bss_5D8,
        m + 0xb284, m + 0xb2cc,
        (soShadowModule*)(m + 0xb34c),
        (soItemManageModule*)(m + 0xb438),
        (soColorBlendModule*)(m + 0xb4a4),
        m + 0xb5f8, m + 0xb644,
        (soSlowModule*)(m + 0xb6ac),
        lbl_27_bss_69C, m + 0xab0,
        (soParamCustomizeModule*)(m + 0xac8),
        m + 0xb6e8);

    c = data->getHeapSlotNo();
    char* motionCommand = (char*)data->getNWMotionInstanceHeap();
    char* command = (char*)data->getNWModelInstanceHeap();
    Heaps::HeapType instanceHeap = data->getInstanceHeap();
    new (m + 0xab0) soHeapModuleImpl(instanceHeap, (Heaps::HeapType)(long)command,
        (Heaps::HeapType)(long)motionCommand, c);

    fn_27_14B5F8(m + 0xac8, m + 0x9d0);
    c = data->getResGroupNo();
    fn_123_7164(m + 0x115c, data->getMdlResId(), data->getAnmResId(),
                (u8)c, m + 0x9d0);

    motionCommand = (char*)data->getModelExtendNodeTable();
    float modelScale = data->getModelScale();
    fn_123_71CC(m + 0x1180, (soModuleAccesser*)(m + 0x9d0), modelScale,
                motionCommand, (soEventObserverRegistrationDesc*)lbl_27_bss_A48);
    fn_123_7254(m + 0x1440, m + 0x9d0, data->getMotionData());
    fn_123_7428(m + 0x17d4, m + 0x9d0, lbl_27_bss_A48);
    fn_123_7498(m + 0x1888, m + 0x9d0, data->getGroundConditionChecker());
    fn_27_3513C(m + 0x1930, eventId(m), m + 0x9d0, lbl_27_bss_A48);
    fn_123_6D44(m + 0x196c, data->getTeam(), m + 0x9d0);
    fn_123_74FC(m + 0x19e0, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff, lbl_27_bss_A48);
    fn_123_75C0(m + 0x209c, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff, lbl_27_bss_A48);
    fn_123_7684(m + 0x29f8, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff);
    fn_123_7758(m + 0x2c10, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff);
    fn_123_782C(m + 0x367c, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff, lbl_27_bss_A48);
    fn_123_78C4(m + 0x38dc, m + 0x9d0, INT(s, 0x28),
                (UINT(s, 0x2c) >> 7) & 0xff);
    fn_123_7960(m + 0x3ad4, m + 0x9d0, lbl_27_bss_A48);
    fn_27_64C8C(m + 0x3c84, m + 0x9d0, 1);
    fn_27_65EE4(m + 0x3ce8, m + 0x9d0);
    fn_27_154088(m + 0x3d1c, m + 0x9d0);
    fn_27_693F4(m + 0x3d40, m + 0x9d0);
    fn_123_79CC(m + 0x3d78, m + 0x9d0, data->getShakeData());
    fn_123_7A28(m + 0x3e10, m + 0x9d0, data->getSoundIdExchanger(),
                lbl_27_bss_A48);
    fn_123_7AB8(m + 0x3e80, m + 0x9d0);
    fn_27_5B248(m + 0x404c, m + 0x9d0, data->getVisibilityData(), 2);
    fn_123_7B0C(m + 0x407c, m + 0x9d0, eventId(m));

    motionCommand = (char*)data->getCameraClipSphereSet();
    void* range = data->getCameraRangeSet();
    fn_123_7B7C(m + 0x47a0, m + 0x9d0, range, motionCommand, lbl_27_bss_A48);
    fn_27_A1DA4(m + 0x4814, m + 0x9d0, data->getParamAccesser());
    fn_123_7BE8(m + 0x4848, eventId(m));

    motionCommand = (char*)data->getPreCheckAnimCmdData();
    void* status = data->getStatusData();
    fn_123_7C2C(m + 0x493c, m + 0x9d0, status, motionCommand);
    fn_123_80E4(m + 0x57d8, m + 0x9d0);
    fn_123_84B4(m + 0x5ae0);
    fn_123_8514(m + 0x5cc4, m + 0x9d0);

    a = data->getEffectScreenData();
    c = data->getEffectCommonData();
    motionCommand = (char*)data->getEffectEmitData();
    void* effNode = data->getEffectNodeData();
    fn_123_86A0(m + 0xacc0, m + 0x9d0, effNode, motionCommand, c, a,
                lbl_27_bss_A48);
    fn_27_14FBD8(m + 0xae64, m + 0x9d0);

    int areaCategory = data->getAreaCategory();
    fn_123_876C(m + 0xae94, m + 0x9d0, (u8)areaCategory, lbl_27_bss_A48);
    data->getTerritoryRect();
    data->getTerritoryParam();
    data->getTargetSearchParam();
    fn_123_8804(m + 0xb208, m + 0x9d0, data->getIkData());
    data->getSlopeAngleLimit();
    new (m + 0xb2cc) SlopeInit(m + 0x9d0);
    new (m + 0xb34c) ShadowInit(m + 0x9d0, lbl_123_rodata_0);
    fn_123_8864(m + 0xb394, m + 0x9d0, data->getItemNodeData());
    new (m + 0xb4a4) ColorBlendInit(m + 0x9d0);
    new (m + 0xb5f8) JostleInit(m + 0x9d0, data->getJostleData());
    fn_27_196664(m + 0xb644, m + 0x9d0);
    fn_27_5BED0(m + 0xb6ac, m + 0x9d0);
    fn_27_14CCEC(m + 0xb6e8, m + 0x9d0);

    if (OB(m, 0x5ca0)->f01() == 0)
        ((RegisterCalls*)PTR(ENUM(m), 0x64))->f04(1, m + 0x5ca0);

    fn_27_C74BC(m + 0xb868, PTR(PTR(l.build, 0xc), 0x18), 0x15);
    ac = m + 0xb878;
    fn_27_1A66D0(ac, 0);
    fn_27_1A66D0(ac + 0x4a8, 0);
    fn_27_D22D0(ac + 0x954, 0);
    fn_123_88E0(ac + 0xa00, ac, ac + 0x4a8, fn_123_8A8C());
    l.flags[0] = 0;
    fn_123_88FC(ac + 0xa1c, eventId(m), ac + 0x954, 0, 1,
                lbl_123_rodata_4, &l.flags[0]);
    fn_123_8AFC(ac, 0, 0x127);
    fn_123_8AFC(ac + 0x4a8, 0, 0x127);
    fn_123_8AFC(fn_123_8A8C(), 0, 0);
    PAIR(0, ac + 0xa1c, ac + 0xa00, 1);

    SETUP_SCRIPT(1, 0xa6c, 0x1f1, 0x2, char*, command)
    SETUP_SCRIPT(2, 0xb98, 0x1f1, 0x40, , command)
    SETUP_SCRIPT(3, 0xcc4, 0x1f1, 0x40, char*, command)
    SETUP_SCRIPT(4, 0xdf0, 0x1f1, 0x2, char*, command)
    SETUP_SCRIPT(5, 0xf1c, 0x1f1, 0x20, char*, command)
    SETUP_SCRIPT(6, 0x1048, 0x1f1, 0x80, char*, command)
    SETUP_SCRIPT(7, 0x1174, 0x1f1, 0x80, char*, command)
    SETUP_SCRIPT(8, 0x12a0, 0x1f1, 0x20, , motionCommand)
    {
        extraCommand = ac + 0x13cc;
        char* command = extraCommand;
        l.flags[9] = 1;
        fn_123_88FC(command, eventId(m), command + 0x50, 9, 1,
                    lbl_123_rodata_4, &l.flags[9]);
        fn_27_1A079C(command + 0x50, 0);
        PAIR(9, command, lbl_27_bss_8C4, 4);
    }
    SETUP_SCRIPT(10, 0x14f0, 0x29, 0x10, , finalCommand)

    main0 = data->getAnimCmdData(0, 0);
    fn_123_8AFC(fn_123_8B78(ac, 0), main0, 0x112);
    main1 = data->getAnimCmdData(0, 1);
    fn_123_8AFC(fn_123_8B78(ac, 1), main1, 0x112);
    fn_123_8AFC(fn_123_8B78(ac, 0), PTR(PTR(l.build, 0xc), 0x24), 0x15);
    fn_123_8AFC(fn_123_8B78(ac, 1), PTR(PTR(l.build, 0xc), 0x28), 0x15);
    void* disguise0 = ((ftFighterBuildData*)l.build)->getAnimCmdDisguiseList(false, 0);
    fn_123_8BB4(ac, 0, disguise0);
    void* disguise1 = ((ftFighterBuildData*)l.build)->getAnimCmdDisguiseList(false, 1);
    fn_123_8BB4(ac, 1, disguise1);
    OB(PTR(ENUM(m), 0x70), 0)->f34(m + 0xb868);

    constant = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)(m + 0x9d0), 0xa805, 0);
    void* param = __dynamic_cast(PTR(ENUM(m), 0x90), 0,
                                 lbl_123_data_156C, lbl_123_data_1614, 0);
    if (param)
        fn_27_14E0B8(param, constant);
    OB(PTR(ENUM(m), 0x90), 0)->f10(constant);

    fn_27_1404D4(s + 0xd028, PTR(s, 0x60));
    {
        part = s + 0xd064;
        fn_123_6D30(part, 0);
        PTR(part, 0) = lbl_123_data_1388;
    }
    m = (char*)PTR(s, 0x60);
    listeners = s + 0xd51c;
    fn_123_6D30(listeners, 0);
    PTR(listeners, 0) = lbl_123_data_1408;
    SETUP_LISTENER(0x08, lbl_27_data_2F9F8)
    SETUP_LISTENER(0x20, lbl_27_data_2FAA0)
    SETUP_LISTENER(0x34, lbl_27_data_2FB48)
    SETUP_LISTENER(0x48, lbl_27_data_2FBF0)
    SETUP_LISTENER(0x5C, lbl_27_data_2FC98)
    SETUP_LISTENER(0x70, lbl_27_data_2FD40)
    SETUP_LISTENER(0x84, lbl_27_data_2FDE8)

    PTR(s, 0xd5b4) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(s, 0x60), 0xa7f9, 0);
    INT(s, 0xd5b8) = 1;
    PTR(s, 0xd5bc) = soValueAccesser::getConstantIndefinite(
        (soModuleAccesser*)PTR(s, 0x60), 0xa7fc, 0);
    INT(s, 0xd5c0) = 1;
    fn_27_126470(s);
    ((UpdateCalls*)(s + 0xd028))->f02(PTR(s, 0x60));
    setTables(s, lbl_123_data_120);
    fn_27_C749C(s + 0xd5c4);
    PTR(s, 0xd5d4) = g_ftCommonDataAccesser.getData((ftKind)0x2f);

    typedef void* StatusPointer;
    new (l.extras) StatusPointer[21]();
    l.extras[12] = lbl_123_bss_304;
    l.extras[15] = lbl_123_bss_334;
    l.extras[18] = lbl_123_bss_314;
    l.extras[20] = lbl_123_bss_324;
    OB(PTR(PTR(PTR(s, 0x60), 0xd8), 0x70), 0)->f29(l.extras, 0x15);
    ((LastObject*)PTR(PTR(PTR(s, 0x60), 0xd8), 0x9c))->calls.f26(0x32);
    return s;
}
