#pragma force_active on
#include <types.h>
#pragma force_active off
#include <new>
#pragma use_simple_stdpnew on
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_module_accesser.h>
#include <so/model/so_model_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/event/so_event_manage_module_impl.h>
#include <so/so_heap_module_impl.h>
#include <so/resource/so_resource_module_impl.h>
#pragma force_active on

class Interface {
public:
    virtual u32 m08();
    virtual u32 m0c();
    virtual u32 m10();
    virtual u32 m14();
    virtual u32 m18();
    virtual u32 m1c();
};

class DescriptorInterface {
public:
    virtual u32 v8();
    virtual u32 vc();
    virtual u32 v10();
    virtual u32 v14();
    virtual u32 v18();
    virtual u32 v1c();
    virtual u32 v20();
    virtual u32 v24();
    virtual u32 v28();
    virtual u32 v2c();
    virtual u32 v30();
    virtual u32 v34();
    virtual u32 v38();
    virtual u32 v3c();
    virtual u32 v40();
    virtual u32 v44();
    virtual u32 v48();
    virtual u32 v4c();
    virtual float v50();
    virtual u32 v54();
    virtual u32 v58();
    virtual u32 v5c();
    virtual u32 v60();
    virtual u32 v64();
    virtual u32 v68();
    virtual u32 v6c();
    virtual u32 v70();
    virtual u32 v74();
    virtual u32 v78();
    virtual u32 v7c();
    virtual u32 v80();
    virtual u32 v84();
    virtual u32 v88();
    virtual u32 v8c();
    virtual u32 getCommand(int, int);
};

typedef soEventManager EventNumber;
class PairRegistry {
public:
    virtual void v08();
    virtual void add(void**, short*);
};

class StatusWorkPrefix {
public:
    u32 header[2];
};
class EmbeddedStatusWork : public StatusWorkPrefix {
public:
    virtual void m08(); virtual void m0c(); virtual void m10(); virtual void m14();
    virtual void m18(); virtual void m1c(); virtual void m20(); virtual void m24();
    virtual void m28(); virtual void m2c(); virtual void m30(); virtual void m34();
    virtual void m38(); virtual void m3c(); virtual void m40(); virtual void m44();
    virtual void m48(); virtual void m4c(); virtual void m50(); virtual void m54();
    virtual void m58(); virtual void m5c(); virtual void m60(); virtual void m64();
    virtual void m68(); virtual void m6c();
};
class AppendArray {
public:
    virtual void m08(); virtual void m0c(); virtual void m10(); virtual void m14();
    virtual void m18(); virtual void m1c(); virtual void m20(); virtual void m24();
    virtual void m28(); virtual void m2c(); virtual void append(void*);
};
class StatusArray {
public:
    virtual void m08(); virtual void m0c(); virtual void m10(); virtual void m14();
    virtual void m18(); virtual void m1c(); virtual void m20(); virtual void m24();
    virtual void m28(); virtual void m2c(); virtual void m30(); virtual void m34();
    virtual void m38(); virtual void m3c();
};

class StatusStorage {
public:
    virtual void m08(); virtual void m0c(); virtual void m10();
    virtual void m14(); virtual void m18(); virtual void m1c();
    virtual void m20(); virtual void m24(); virtual void m28();
    virtual void m2c(); virtual void m30(); virtual void m34();
    virtual void m38(); virtual void m3c(); virtual void m40();
    virtual void m44(); virtual void m48(); virtual void m4c();
    virtual void m50(); virtual void m54(); virtual void m58();
    virtual void m5c(); virtual void m60(); virtual void m64();
    virtual void m68(); virtual void m6c(); virtual void m70();
    virtual void m74(); virtual void add(void**, int);
};
class WorkArray {
public:
    virtual void m08(); virtual void m0c(); virtual void m10();
    virtual void add(int, void*);
};
extern "C" {
void fn_27_1DC5E8(void*, int, void*, u32, u32, u32, u8, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, u32, u32, int, void*, void*, int);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
void fn_94_6C20(void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_197C18(void*);
void fn_27_82B14(void*, short);
void fn_27_687F8(void*, void*, void*, u32);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, u32, int, int, void*);
void fn_27_CBAA0(void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, u32, int);
void fn_27_A1DA4(void*, void*, u32);
void fn_27_711E4(void*, short, void*);
void fn_27_1AC390(void*, int);
void fn_27_19FF5C(void*, int, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_27_C7470(void*, u32, int);
void fn_27_197C28(void*);
void fn_27_82794(void*, short);
void fn_27_197C08(void*);
void fn_27_82754(void*, short);
void fn_27_C94E0(void*);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
void fn_27_CBD88(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void fn_94_1CD74(void*, u32);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19CDD0(void*, int, const soCollisionAttackPart&, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_94_1CDCC(void*, short);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_C948C(void*);
void fn_27_82C54(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_9747C(void*, void*, void*, u32, void*, void*, u32, void*, u32, int, u32, void*);
void fn_27_197C68(void*);
void fn_27_82B94(void*, short);
void fn_27_10158(void*, void*, u32, void*, int);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_C319C(void*, void*);
void fn_27_C7744(void*, u32, int);
void fn_27_1A0A94(void*, int);
void fn_94_8C70(void*, void*, void*, void*);
void fn_94_8C8C(void*, short, void*, int, int, float, signed char*);
void fn_27_C74BC(void*, u32, int);
void fn_94_7E08(void*, void*, int, void*, int, void*, int);
void fn_27_CD8C8(void*, int);
void fn_27_1A1B1C(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_1A4D6C(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, u32, int, int);

extern char lbl_27_bss_512C[], lbl_27_bss_514C[], lbl_27_bss_50EC[];
extern char lbl_27_bss_515C[], lbl_27_bss_510C[], lbl_27_bss_511C[];
extern char lbl_27_bss_513C[], lbl_27_bss_516C[];
extern char lbl_27_bss_D7C[], lbl_27_bss_9BC[], lbl_27_bss_DBC[];
extern char lbl_27_bss_344[], lbl_27_bss_398[], lbl_27_bss_3AC[];
extern char lbl_27_bss_3BC[], lbl_27_bss_3CC[], lbl_27_bss_3DC[];
extern char lbl_27_bss_3F4[], lbl_27_bss_404[], lbl_27_bss_424[];
extern char lbl_27_bss_47C[], lbl_27_bss_48C[], lbl_27_bss_4BC[];
extern char lbl_27_bss_170[], lbl_27_bss_188[], lbl_27_bss_530[];
extern char lbl_27_bss_55C[], lbl_27_bss_584[], lbl_27_bss_598[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_604[];
extern char lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[];
extern char lbl_27_bss_654[], lbl_27_bss_66C[], lbl_27_bss_A48[];
extern char lbl_27_bss_D8C[], lbl_27_bss_8C4[], lbl_27_data_8E80[];

extern signed char lbl_94_bss_3D4, lbl_94_bss_3DC, lbl_94_bss_3E4, lbl_94_bss_3EC;
extern signed char lbl_94_bss_3F4, lbl_94_bss_3FC, lbl_94_bss_404;
extern char lbl_94_bss_3D8[], lbl_94_bss_368[];
extern char lbl_94_bss_3E0[], lbl_94_bss_374[];
extern char lbl_94_bss_3E8[], lbl_94_bss_380[];
extern char lbl_94_bss_3F0[], lbl_94_bss_38C[];
extern char lbl_94_bss_3F8[], lbl_94_bss_398[];
extern char lbl_94_bss_400[], lbl_94_bss_3A4[];
extern char lbl_94_bss_408[], lbl_94_bss_3B0[];
extern char lbl_94_data_C85C[], lbl_94_data_C86C[], lbl_94_data_C870[];
extern char lbl_94_data_CAE0[], lbl_94_data_C874[];
extern char lbl_94_data_CE00[], lbl_94_data_CF80[], lbl_94_data_CD4C[];
extern const float lbl_94_rodata_88;
}

class soDamageEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
typedef soArrayVector<soInstanceUnit<soEventUnit*>, 19> WhipEventVector;
template <>
class soInstanceManagerSimpleEntity<soEventUnit*, WhipEventVector> {
    u32 storage[0xb8 / 4];
public:
    soInstanceManagerSimpleEntity();
};
template <>
class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soModelEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
    u32 storage[0x5c / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
    u32 storage[0x38 / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};
template <>
class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
    u32 storage[0x38 / 4];
public:
    soEventUnitWithWorkArea(s16, s16);
};

namespace {
template <int Size, int EventId, void (*Construct)(void*, short, short)>
struct WhipEventStorage {
    u8 storage[Size];
    WhipEventStorage(u32 id) { Construct(this, static_cast<short>(id), EventId); }
};

struct WhipEvents {
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > units;
    soEventManageModuleImpl manager;
    WhipEventStorage<0xec, 4, fn_27_1A9430> status;
    WhipEventStorage<0x1ac, 5, fn_27_1AA1F4> animCmd;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    WhipEventStorage<0x44, 7, fn_27_D5878> link;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    WhipEventStorage<0x44, 11, fn_27_1AA878> article;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion;
    char padding[4];
    soModuleAccesser accesser;

    char* storage() { return reinterpret_cast<char*>(this); }

    s16 id() { return static_cast<soEventManageModule&>(manager).getManageId(); }

    WhipEvents(char* self)
      : units(), manager(this), status(id()), animCmd(id()), damage(id(), 6),
        link(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
        model(id(), 9), article(id()), capture(id(), 13), shield(id(), 14),
        reflector(id(), 15), absorber(id(), 16), search(id(), 17),
        item(id(), 12), motion(id(), 10),
        accesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(storage() + 0x918),
        reinterpret_cast<soModelModule*>(storage() + 0xa44),
        reinterpret_cast<soMotionModule*>(storage() + 0xb2c),
        reinterpret_cast<soPostureModule*>(storage() + 0xcd8),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(storage() + 0xd54),
        storage() + 0xdb0,
        reinterpret_cast<soCollisionAttackModule*>(storage() + 0x10c8),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4, lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(storage() + 0x1174),
        lbl_27_bss_424, storage() + 0x11a0,
        reinterpret_cast<soSoundModule*>(storage() + 0x11b4),
        reinterpret_cast<soLinkModule*>(storage() + 0x1320),
        reinterpret_cast<soVisibilityModule*>(storage() + 0x1374),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(storage() + 0x138c),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(storage() + 0x13c0),
        reinterpret_cast<soStatusModule*>(storage() + 0x155c),
        lbl_27_bss_170, lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(lbl_27_bss_530),
        reinterpret_cast<soEventManageModule*>(storage() + 0xb8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(storage() + 0x16ec),
        lbl_27_bss_584,
        reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0, lbl_27_bss_5D8, storage() + 0x182c,
        lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(lbl_27_bss_640),
        lbl_27_bss_654, lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(storage() + 0x187c),
        storage() + 0x1894, storage() + 0x8d8,
        reinterpret_cast<soParamCustomizeModule*>(storage() + 0x8f0),
        storage() + 0x18d4) {}
};
}

static inline char* whipName() { return lbl_94_data_C85C; }

template <signed char& Guard, char* Object, void (*Construct)(void*),
          void (*Destroy)(void*, short), char* Registration>
static inline char* getMotionArray() {
    if (Guard == 0) {
        Construct(Object);
        __register_global_object(Object, reinterpret_cast<void*>(Destroy), Registration);
        Guard = 1;
    }
    return Object;
}

struct WhipArticle {
    void initialize(int owner, char* resource, char* parameters);
};

inline void WhipArticle::initialize(int owner, char* resource, char* parameters) {
    char* self = reinterpret_cast<char*>(this);
    struct CommandLocals {
        signed char flags[5];
        short ids[5];
        int statusDefault;
    } commandLocals;
    struct CommandEntries {
        void* pairs[10];
        u32 statusEntry[5];
    } commandEntries;
    u32 descriptor[16];
    Interface* ids = *reinterpret_cast<Interface**>(resource + 4);
    fn_27_1DC5E8(descriptor, 0x41, parameters, ids->m10(), ids->m18(), ids->m1c(),
                  static_cast<u8>(*reinterpret_cast<u32*>(parameters)), -1,
                  self + 0x1d1c, 0, 0, 0, 0, 0, 0, 0);
    char* const& name = whipName();
    fn_27_1D7EF0(self, name,
        descriptor[1], descriptor[2],
        owner, resource, self + 0x8c4, 1);
    *reinterpret_cast<char**>(self + 0x3c) = lbl_94_data_CAE0;
    *reinterpret_cast<char**>(self + 0x40) = lbl_94_data_CAE0 + 0x64;
    *reinterpret_cast<char**>(self + 0x48) = lbl_94_data_CAE0 + 0x70;
    *reinterpret_cast<char**>(self + 0x54) = lbl_94_data_CAE0 + 0x84;
    *reinterpret_cast<char**>(self + 0x64) = lbl_94_data_CAE0 + 0xdc;
    *reinterpret_cast<char**>(self + 0x70) = lbl_94_data_CAE0 + 0xec;
    *reinterpret_cast<char**>(self + 0x7c) = lbl_94_data_CAE0 + 0x100;
    *reinterpret_cast<char**>(self + 0x88) = lbl_94_data_CAE0 + 0x118;
    *reinterpret_cast<char**>(self + 0x90) = lbl_94_data_CAE0 + 0x124;

    char* commandModules = self + 0xcc;
    new (commandModules) WhipEvents(self);

#define config (reinterpret_cast<DescriptorInterface*>(descriptor))
    Heaps::HeapType heapA, heapB, heapC;
    u32 heapSize;
    heapSize = config->v80();
    heapC = static_cast<Heaps::HeapType>(config->v7c());
    heapB = static_cast<Heaps::HeapType>(config->v78());
    heapA = static_cast<Heaps::HeapType>(config->v74());
    new (commandModules + 0x8d8) soHeapModuleImpl(heapA, heapB, heapC, heapSize);
    char* customization = commandModules + 0x8f0;
    fn_94_6C20(customization, 0);
    *reinterpret_cast<char**>(customization) = lbl_94_data_CE00;
    *reinterpret_cast<float*>(customization + 8) = lbl_94_rodata_88;
    *reinterpret_cast<float*>(customization + 12) = lbl_94_rodata_88;
    u32 resourceFlag = config->v10();
    u32 resourceSet = config->vc();
    u32 resourceKind = config->v8();
    char* resourceIds = commandModules + 0x900;
    fn_94_6C20(resourceIds, 0);
    *reinterpret_cast<char**>(resourceIds) = lbl_94_data_CF80;
    *reinterpret_cast<u32*>(resourceIds + 8) = resourceKind;
    *reinterpret_cast<u32*>(resourceIds + 12) = resourceKind;
    *reinterpret_cast<u32*>(resourceIds + 16) = resourceSet;
    *reinterpret_cast<short*>(resourceIds + 20) = 0;
    *reinterpret_cast<short*>(resourceIds + 22) = 0;
    new (resourceIds + 24) soResourceModuleImpl(0,
        reinterpret_cast<soResourceIdAccesser*>(resourceIds),
        static_cast<u8>(resourceFlag));

    char* model;
    u32 modelData = config->v68();
    float modelScale = config->v50();
    model = commandModules + 0x930;
    fn_27_CBD88(model, 5, 0);
    if (lbl_94_bss_3D4 == 0) {
        fn_27_197C78(lbl_94_bss_3D8);
        __register_global_object(lbl_94_bss_3D8,
            reinterpret_cast<void*>(fn_27_82A94), lbl_94_bss_368);
        lbl_94_bss_3D4 = 1;
    }
    new (model + 0x114) soModelModuleImpl(
        reinterpret_cast<soModuleAccesser*>(commandModules + 0x7f8),
        reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale,
        reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_94_bss_3D8),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

    u32 motionData = config->v18();
    fn_27_C7470(commandModules + 0xb18, motionData, 15);
    char* motionA = getMotionArray<lbl_94_bss_3EC, lbl_94_bss_3F0,
        fn_27_197C28, fn_27_82794, lbl_94_bss_38C>();
    if (lbl_94_bss_3E4 == 0) {
        fn_27_197C08(lbl_94_bss_3E8);
        __register_global_object(lbl_94_bss_3E8,
            reinterpret_cast<void*>(fn_27_82754), lbl_94_bss_380);
        lbl_94_bss_3E4 = 1;
    }
    char* motionB = lbl_94_bss_3E8;
    char* motionC = getMotionArray<lbl_94_bss_3DC, lbl_94_bss_3E0,
        fn_27_C94E0, fn_27_82A14, lbl_94_bss_374>();
    short motionId = reinterpret_cast<EventNumber*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(commandModules + 0x8d0)
        + 0x80) + 8)->getManageId();
    fn_27_13844(commandModules + 0xb2c, commandModules + 0x7f8,
        commandModules + 0xb18, lbl_27_bss_D7C, motionA, motionB,
        lbl_27_bss_9BC, motionC, motionId, 0, lbl_27_bss_DBC);
    reinterpret_cast<Interface*>(*reinterpret_cast<char**>(
        *reinterpret_cast<char**>(commandModules + 0x8d0) + 4))->m08();

    char* posture = commandModules + 0x0c9c;
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3c) soPostureModuleImpl(
        reinterpret_cast<soModuleAccesser*>(commandModules + 0x7f8),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<StatusArray*>(posture + 0x3c)->m38();
    config->v28();
    short situationId = reinterpret_cast<EventNumber*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(commandModules + 0x8d0)
        + 0x80) + 8)->getManageId();
    fn_27_3513C(commandModules + 0x0d54, situationId,
        commandModules + 0x7f8, lbl_27_bss_A48);

    char* transition;
    u32 transitionData = config->v14();
    transition = commandModules + 0x0d90;
    fn_94_1CD74(transition, transitionData);
    fn_94_1CD74(transition + 0x10, transitionData);
    fn_27_B5048(transition + 0x20, transition, transition + 0x10,
        transition, commandModules + 0x7f8, lbl_27_bss_A48);

    int taskId;
    char* attack;
    u8 taskCategory = static_cast<u8>(*reinterpret_cast<u32*>(self + 0x2c) >> 7);
    taskId = *reinterpret_cast<int*>(self + 0x28);
    attack = commandModules + 0xdf4;
    fn_27_19CDD0(attack, 4,
        soCollisionAttackPart(static_cast<soCollision::Category>(0), false), 0);
    fn_27_CB6E0(attack + 0x24c, 1, 0);
    u32 absolute[26];
    *reinterpret_cast<float*>(&absolute[9]) = lbl_94_rodata_88;
    *reinterpret_cast<float*>(&absolute[10]) = lbl_94_rodata_88;
    *reinterpret_cast<float*>(&absolute[11]) = lbl_94_rodata_88;
    absolute[14] &= ~31UL;
    fn_27_C94AC(attack + 0x2d0, 0, absolute);
    fn_94_1CDCC(absolute, -1);
    new (attack + 0x2d4) soCollisionAttackModuleImpl(
        reinterpret_cast<soModuleAccesser*>(commandModules + 0x7f8),
        taskId, static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
        reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x24c),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x2d0),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);

    new (commandModules + 0x1174) soStopModuleImpl(
        reinterpret_cast<soModuleAccesser*>(commandModules + 0x7f8));
    u32 hitData = config->v1c();
    if (lbl_94_bss_3F4 == 0) {
        fn_27_197C18(lbl_94_bss_3F8);
        __register_global_object(lbl_94_bss_3F8,
            reinterpret_cast<void*>(fn_27_82B14), lbl_94_bss_398);
        lbl_94_bss_3F4 = 1;
    }
    fn_27_687F8(commandModules + 0x11a0, commandModules + 0x7f8,
                 lbl_94_bss_3F8, hitData);
    char* sound;
    u32 soundData = config->v84();
    sound = commandModules + 0x11a8;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 0x0c, commandModules + 0x7f8, sound, soundData,
                 1, 0, lbl_27_bss_A48);
    char* link = commandModules + 0x1210;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, commandModules + 0x7f8, link);
    u32 visibilityData = config->v20();
    fn_27_5AD88(commandModules + 0x1374, commandModules + 0x7f8,
                 visibilityData, 1);
    reinterpret_cast<EventNumber*>(*reinterpret_cast<char**>(
        *reinterpret_cast<char**>(commandModules + 0x8d0) + 0x80) + 8)->getManageId();
    config->v60();
    config->v5c();
    u32 workData = config->v54();
    fn_27_A1DA4(commandModules + 0x138c, commandModules + 0x7f8, workData);
    short animId = reinterpret_cast<EventNumber*>(
        *reinterpret_cast<char**>(*reinterpret_cast<char**>(commandModules + 0x8d0)
        + 0x80) + 8)->getManageId();
    char* anim = commandModules + 0x13c0;
    fn_27_711E4(anim, animId, anim + 0x24);
    fn_27_1AC390(anim + 0x24, 0);

    char* status;
    u32 statusData = config->v70();
    u32 statusResource = config->v24();
    status = commandModules + 0x1464;
    fn_27_C74BC(status, statusResource, 9);
    {
    char* statusWork = status + 0x10;
    fn_94_7E08(statusWork + 0x1c, statusWork, 3, statusWork + 0x0c,
                3, statusWork + 0x18, 1);
    reinterpret_cast<EmbeddedStatusWork*>(statusWork + 0x1c)->m6c();
    }
    int statusIndex;
    char* statusArray = status + 0x50;
    fn_27_CD8C8(statusArray, 0);
    fn_27_1A1B1C(statusArray + 0x20, 0);
    *reinterpret_cast<char**>(statusArray + 0x4c) = lbl_27_data_8E80;
    *reinterpret_cast<char**>(statusArray + 0x50) = statusArray;
    *reinterpret_cast<u32*>(statusArray + 0x54) = 0;
    commandLocals.statusDefault = 0;
    *reinterpret_cast<int*>(statusArray + 0x58) = -1;
    *reinterpret_cast<int*>(statusArray + 0x5c) = -1;
    *reinterpret_cast<u32*>(statusArray + 0x60) = 0;
    for (statusIndex = 0; statusIndex < 1; ++statusIndex) {
        fn_27_AB15C(commandEntries.statusEntry, statusIndex == 0 ? statusArray + 0x20 : 0);
        reinterpret_cast<AppendArray*>(statusArray)->append(commandEntries.statusEntry);
        fn_27_AB18C(commandEntries.statusEntry, -1);
    }
    fn_27_1A4D6C(status + 0xb4, 0);
    *reinterpret_cast<char**>(status + 0xe4) = status + 0xe8;
    fn_27_1A29F0(status + 0xe8, 1, lbl_94_data_C86C, 0);
    reinterpret_cast<StatusArray*>(status + 0xe8)->m3c();
    fn_27_73930(status + 0xf8, commandModules + 0x7f8, status,
        status + 0xb4, status + 0x2c, status + 0x9c, status + 0xe4,
        statusData, 0, 1);

    char* kineticWork = commandModules + 0x160c;
    fn_94_7E08(kineticWork + 0x60, kineticWork, 14, kineticWork + 0x38,
                9, kineticWork + 0x5c, 1);
    reinterpret_cast<EmbeddedStatusWork*>(kineticWork + 0x60)->m6c();
    u32 effectD = config->v38();
    u32 effectC = config->v34();
    char* accesser;
    char* command0;
    char* command1;
    char* command2;
    char* command3;
    char* command4;
    char* effect;
    u32 effectA;
    u32 effectB;
    effectB = config->v30();
    effectA = config->v2c();
    effect = commandModules + 0x1694;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3c, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_94_data_C870, 0);
    if (lbl_94_bss_3FC == 0) {
        fn_27_C948C(lbl_94_bss_400);
        __register_global_object(lbl_94_bss_400,
            reinterpret_cast<void*>(fn_27_82C54), lbl_94_bss_3A4);
        lbl_94_bss_3FC = 1;
    }
    fn_27_9747C(effect + 0x58, commandModules + 0x7f8, effect,
        effectA, effect + 0x48, lbl_94_bss_400, effectB, lbl_27_bss_A48,
        effectC, -1, effectD, effect + 0x3c);
    config->v58();
    config->v40();
    config->v3c();
    config->v44();
    u32 areaData = config->v48();
    if (lbl_94_bss_404 == 0) {
        fn_27_197C68(lbl_94_bss_408);
        __register_global_object(lbl_94_bss_408,
            reinterpret_cast<void*>(fn_27_82B94), lbl_94_bss_3B0);
        lbl_94_bss_404 = 1;
    }
    fn_27_10158(commandModules + 0x182c, commandModules + 0x7f8,
        areaData, lbl_94_bss_408, 1);
    config->v88();
    config->v64();
    config->v6c();
    fn_27_5C600(commandModules + 0x187c, commandModules + 0x7f8);
    fn_27_63B94(commandModules + 0x1894, commandModules + 0x7f8, 0);
    fn_27_C319C(commandModules + 0x18d4, commandModules + 0x7f8);
    if (reinterpret_cast<Interface*>(commandModules + 0x166c)->m08() == 0) {
        char* work = *reinterpret_cast<char**>(
            *reinterpret_cast<char**>(commandModules + 0x8d0) + 0x64);
        reinterpret_cast<WorkArray*>(work)->add(1, commandModules + 0x166c);
    }

    char* commandBase = commandModules + 0x18f0;
#define commandFlags (commandLocals.flags)
#define commandIds (commandLocals.ids)
#define commandPairs (commandEntries.pairs)
#define EVENT_VALUE() (reinterpret_cast<EventNumber*>(*reinterpret_cast<char**>(*reinterpret_cast<char**>(commandModules + 0x8d0) + 0x80) + 8)->getManageId())
#define PAIR_REGISTRY() (*reinterpret_cast<PairRegistry**>(*reinterpret_cast<char**>(commandModules + 0x8d0) + 0x6c))
#define BUILD_COMMAND(N, OFFSET, CAP, ID, KIND) \
    { \
        config->getCommand(N, 2); \
        config->getCommand(N, 1); \
        u32 data = config->getCommand(N, 0); \
        command##N = commandBase + OFFSET; \
        fn_27_C7744(command##N, data, CAP); \
        fn_27_1A0A94(command##N + 0x14, 0); \
        fn_94_8C70(command##N + 0x48, command##N, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        commandFlags[N] = 0; \
        const s16 eventId = EVENT_VALUE(); \
        fn_94_8C8C(command##N + 0x64, eventId, \
                    command##N + 0x14, N, KIND, lbl_94_rodata_88, &commandFlags[N]); \
        commandIds[N] = ID; \
        commandPairs[(N) * 2] = command##N + 0x64; \
        commandPairs[(N) * 2 + 1] = command##N + 0x48; \
        PAIR_REGISTRY()->add(&commandPairs[(N) * 2], &commandIds[N]); \
    }
    BUILD_COMMAND(0, 0x000, 9, 1, 0)
    BUILD_COMMAND(1, 0x0b4, 15, 2, 1)
    BUILD_COMMAND(2, 0x168, 15, 2, 1)
    BUILD_COMMAND(3, 0x21c, 15, 2, 1)
#undef BUILD_COMMAND
    command4 = commandBase + 0x2d0;
    commandFlags[4] = 1;
    const s16 command4EventId = EVENT_VALUE();
    fn_94_8C8C(command4, command4EventId, command4 + 0x50,
                4, 1, lbl_94_rodata_88, &commandFlags[4]);
    fn_27_1A0A94(command4 + 0x50, 0);
    commandIds[4] = 4;
    commandPairs[8] = command4;
    commandPairs[9] = lbl_27_bss_8C4;
    PAIR_REGISTRY()->add(&commandPairs[8], &commandIds[4]);
    config->getCommand(5, 2);
    config->getCommand(5, 1);
    config->getCommand(5, 0);
#undef EVENT_VALUE
#undef PAIR_REGISTRY
#undef commandFlags
#undef commandIds
#undef commandPairs

    fn_27_1D90FC(self);
    *reinterpret_cast<char**>(self + 0x3c) = lbl_94_data_C874;
    *reinterpret_cast<char**>(self + 0x40) = lbl_94_data_C874 + 0x64;
    *reinterpret_cast<char**>(self + 0x48) = lbl_94_data_C874 + 0x70;
    *reinterpret_cast<char**>(self + 0x54) = lbl_94_data_C874 + 0x84;
    *reinterpret_cast<char**>(self + 0x64) = lbl_94_data_C874 + 0xdc;
    *reinterpret_cast<char**>(self + 0x70) = lbl_94_data_C874 + 0xec;
    *reinterpret_cast<char**>(self + 0x7c) = lbl_94_data_C874 + 0x100;
    *reinterpret_cast<char**>(self + 0x88) = lbl_94_data_C874 + 0x118;
    *reinterpret_cast<char**>(self + 0x90) = lbl_94_data_C874 + 0x124;

    parameters = *reinterpret_cast<char**>(parameters + 0x34);
    *reinterpret_cast<char**>(self + 0x1d18) = parameters;
    accesser = self + 0x1d1c;
    fn_94_6C20(accesser, 0);
    *reinterpret_cast<u32*>(accesser + 0x0c) = 0x41;
    *reinterpret_cast<u32*>(accesser + 0x10) = 0x0f9f;
    *reinterpret_cast<u32*>(accesser + 0x14) = 0x5dbf;
    *reinterpret_cast<u32*>(accesser + 0x18) = 0;
    *reinterpret_cast<char**>(accesser + 0x08) = lbl_94_data_CD4C;
    *reinterpret_cast<char**>(accesser) = lbl_94_data_CD4C + 8;
    *reinterpret_cast<char**>(accesser + 0x1c) = parameters;
    *reinterpret_cast<char**>(accesser + 0x20) = parameters + 4;
    *reinterpret_cast<char**>(accesser + 0x24) = parameters + 8;

    void* process[9] = { 0 };
    process[1] = lbl_27_bss_512C;
    process[2] = lbl_27_bss_514C;
    process[3] = lbl_27_bss_50EC;
    process[4] = lbl_27_bss_515C;
    process[5] = lbl_27_bss_510C;
    process[6] = lbl_27_bss_511C;
    process[7] = lbl_27_bss_513C;
    process[8] = lbl_27_bss_516C;
    char* root = *reinterpret_cast<char**>(self + 0x60);
    char* modules = *reinterpret_cast<char**>(root + 0xd8);
    (*reinterpret_cast<StatusStorage**>(modules + 0x70))->add(process, 9);
    soModuleAccesser* articleAccesser = *reinterpret_cast<soModuleAccesser**>(self + 0x60);
    articleAccesser->getWorkManageModule().setInt(-1, 0x10000007);
    fn_27_1D8FC8(self, 0);
}

extern "C" void* fn_94_1AB4C(char* self, int owner, char* resource, char* parameters) {
    reinterpret_cast<WhipArticle*>(self)->initialize(owner, resource, parameters);
    return self;
}
