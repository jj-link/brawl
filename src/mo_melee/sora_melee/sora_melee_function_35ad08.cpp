#include <types.h>
#include <new>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/so_value_accesser.h>

#pragma force_active on
#pragma use_simple_stdpnew on
#pragma always_inline on
#pragma inline_depth(8)

typedef soArrayVector<soInstanceUnit<soEventUnit*>, 19> EventStore;
typedef soInstanceManagerSimpleEntity<soEventUnit*, EventStore> EventManager;
template<> class soInstanceManagerSimpleEntity<soEventUnit*, EventStore> {
public:
    soInstanceManagerSimpleEntity();
};

#define EVENT_CTOR(Observer, N) \
    template<> class soEventUnitWithWorkArea<Observer, N> { \
    public: soEventUnitWithWorkArea(s16, s16); \
    }
EVENT_CTOR(soDamageEventObserver, 4);
EVENT_CTOR(soSituationEventObserver, 4);
EVENT_CTOR(soCollisionHitEventObserver, 4);
EVENT_CTOR(soCollisionAttackEventObserver, 4);
EVENT_CTOR(soModelEventObserver, 4);
EVENT_CTOR(soCaptureEventObserver, 4);
EVENT_CTOR(soCollisionShieldEventObserver, 4);
EVENT_CTOR(soCollisionReflectorEventObserver, 4);
EVENT_CTOR(soCollisionAbsorberEventObserver, 4);
EVENT_CTOR(soCollisionSearchEventObserver, 4);
EVENT_CTOR(soItemManageEventObserver, 1);
EVENT_CTOR(soMotionEventObserver, 1);
#undef EVENT_CTOR

class ArticleSetup {
public:
    virtual u32 slot08();
    virtual u32 slot0C();
    virtual u32 slot10();
    virtual u32 slot14();
    virtual u32 slot18();
    virtual u32 slot1C();
    virtual u32 slot20();
    virtual u32 slot24();
    virtual u32 slot28();
    virtual u32 slot2C();
    virtual u32 slot30();
    virtual u32 slot34();
    virtual u32 slot38();
    virtual u32 slot3C();
    virtual u32 slot40();
    virtual u32 slot44();
    virtual u32 slot48();
    virtual u32 slot4C();
    virtual f32 slot50();
    virtual u32 slot54();
    virtual u32 slot58();
    virtual u32 slot5C();
    virtual u32 slot60();
    virtual u32 slot64();
    virtual u32 slot68();
    virtual u32 slot6C();
    virtual u32 slot70();
    virtual u32 slot74();
    virtual u32 slot78();
    virtual u32 slot7C();
    virtual u32 slot80();
    virtual u32 slot84();
    virtual u32 slot88();
    virtual u32 slot8C();
    virtual void slot90(int, int);

    u32 data[15];
};

class MotionArray {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void append(void*);
};

class EventObserverInterface {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual u32 slot24();
};

struct WorkHeader {
    char* nullableVtable;
    u8 isNull;
};

class WorkInitialization : public WorkHeader {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    virtual void slot58();
    virtual void slot5C();
    virtual void slot60();
    virtual void slot64();
    virtual void slot68();
    virtual void slot6C();
};

class WorkRegistration {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14(int, void*);
};

extern "C" {
extern char lbl_27_data_8FA58[], lbl_27_data_8FCD0[], lbl_27_data_8FA64[];
extern char lbl_27_data_2BEE8[], lbl_27_data_465C0[], lbl_27_data_46568[], lbl_27_data_8E80[];
extern char lbl_27_data_8FA60[], __vt__19soGeneralWorkSimple[];
extern const f32 lbl_27_rodata_7A00, lbl_27_rodata_7A04;

extern char lbl_27_bss_170[], lbl_27_bss_188[], lbl_27_bss_344[], lbl_27_bss_35C[];
extern char lbl_27_bss_384[], lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[];
extern char lbl_27_bss_3CC[], lbl_27_bss_3DC[], lbl_27_bss_3F4[], lbl_27_bss_404[];
extern char lbl_27_bss_424[], lbl_27_bss_47C[], lbl_27_bss_48C[], lbl_27_bss_4BC[];
extern char lbl_27_bss_4D0[], lbl_27_bss_4E8[], lbl_27_bss_530[], lbl_27_bss_55C[];
extern char lbl_27_bss_584[], lbl_27_bss_598[], lbl_27_bss_5B0[], lbl_27_bss_5D8[];
extern char lbl_27_bss_5EC[], lbl_27_bss_604[], lbl_27_bss_628[], lbl_27_bss_654[];
extern char lbl_27_bss_66C[], lbl_27_bss_6E8[], lbl_27_bss_9BC[], lbl_27_bss_A48[], lbl_27_bss_DBC[];
extern char lbl_27_bss_51FC[], lbl_27_bss_5204[], lbl_27_bss_520C[], lbl_27_bss_5214[];
extern char lbl_27_bss_521C[], lbl_27_bss_5270[], lbl_27_bss_80D8[], lbl_27_bss_80E4[];
extern char lbl_27_bss_80F0[], lbl_27_bss_80FC[], lbl_27_bss_8108[], lbl_27_bss_8114[];
extern s8 lbl_27_bss_51F8, lbl_27_bss_5200, lbl_27_bss_5208;
extern s8 lbl_27_bss_5210, lbl_27_bss_5218, lbl_27_bss_526C;

void fn_27_1DC5E8(void*, int, const void*, u32, u32, u32, u8, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, const char*, u32, u32, int, void*, void*, int);
void fn_27_1A9430(void*, s16, s16);
void fn_27_1AA1F4(void*, s16, s16);
void fn_27_D5878(void*, s16, s16);
void fn_27_1AA878(void*, s16, s16);
void fn_27_CBD88(void*, int, int);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, int);
void fn_27_C9630(void*, int, int);
void fn_27_C7470(void*, u32, int);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, s16, int, void*);
void fn_27_2520C(void*, void*, void*, void*);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_687F8(void*, void*, void*, u32);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, u32, int, int, void*);
void fn_27_CBAA0(void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, u32, int);
void fn_27_A1DA4(void*, void*, u32);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, u32, void*, void*, u32, void*, u32, int, u32, void*);
void fn_27_B62E4(void*, void*, f32, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
void fn_27_197C78(void*);
void fn_27_197C28(void*);
void fn_27_C94E0(void*);
void fn_27_197C9C(void*);
void fn_27_197C18(void*);
void fn_27_C948C(void*);
void fn_27_82A94(void*, s16);
void fn_27_82794(void*, s16);
void fn_27_82A14(void*, s16);
void fn_27_82714(void*, s16);
void fn_27_82B14(void*, s16);
void fn_27_82C54(void*, s16);
void __register_global_object(void*, void (*)(void*, s16), void*);
}

template <class T> static inline T& field(void* object, int offset) {
    return *reinterpret_cast<T*>(static_cast<u8*>(object) + offset);
}

static inline void installArticleTables(u8* article, char* table) {
    field<char*>(article, 0x3C) = table;
    field<char*>(article, 0x40) = table + 0x64;
    field<char*>(article, 0x48) = table + 0x70;
    field<char*>(article, 0x54) = table + 0x84;
    field<char*>(article, 0x64) = table + 0xDC;
    field<char*>(article, 0x70) = table + 0xEC;
    field<char*>(article, 0x7C) = table + 0x100;
    field<char*>(article, 0x88) = table + 0x118;
    field<char*>(article, 0x90) = table + 0x124;
}

struct TeamResource {
    char* vtable;
    bool isNull;
    u32 data;
    int index;
};
struct TeamStorage {
    TeamResource primary;
    TeamResource secondary;
    u8 module[1];
};

static inline s16 eventId(u8* modules) {
    u8* enumeration = field<u8*>(modules, 0x8D0);
    u8* manager = field<u8*>(enumeration, 0x80);
    return reinterpret_cast<EventObserverInterface*>(manager + 8)->slot24();
}

extern "C" u8* fn_27_35AD08(u8* self, int owner, void* resource, const int* params) {
    struct {
        u32 motionEntry[6];
        u32 descriptor[16];
    } locals;
    u32 resourceSlot18;
    u32 resourceSlot1C;
    ArticleSetup* ids = field<ArticleSetup*>(resource, 4);
    resourceSlot1C = ids->slot1C();
    resourceSlot18 = ids->slot18();
    u32 resourceSlot10 = ids->slot10();
    int articleId = params[0];
    fn_27_1DC5E8(reinterpret_cast<ArticleSetup*>(locals.descriptor), 0x5A, params, resourceSlot10, resourceSlot18, resourceSlot1C,
                 static_cast<u8>(articleId), -1, &g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);
    fn_27_1D7EF0(self, lbl_27_data_8FA58, reinterpret_cast<ArticleSetup*>(locals.descriptor)->data[0], reinterpret_cast<ArticleSetup*>(locals.descriptor)->data[1], owner, resource, self + 0x8C4, 1);
    installArticleTables(self, lbl_27_data_8FCD0);

    u8* modules = self + 0xCC;
    new (modules) EventManager;
    new (modules + 0xB8) soEventManageModuleImpl(modules);
    fn_27_1A9430(modules + 0xCC, reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 4);
    fn_27_1AA1F4(modules + 0x1B8, reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 5);
    new (modules + 0x364) soEventUnitWithWorkArea<soDamageEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 6);
    fn_27_D5878(modules + 0x3C0, reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 7);
    new (modules + 0x404) soEventUnitWithWorkArea<soSituationEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 8);
    new (modules + 0x460) soEventUnitWithWorkArea<soCollisionHitEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 0);
    new (modules + 0x4BC) soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 1);
    new (modules + 0x518) soEventUnitWithWorkArea<soModelEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 9);
    fn_27_1AA878(modules + 0x574, reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 11);
    new (modules + 0x5B8) soEventUnitWithWorkArea<soCaptureEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 13);
    new (modules + 0x614) soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 14);
    new (modules + 0x670) soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 15);
    new (modules + 0x6CC) soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 16);
    new (modules + 0x728) soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 17);
    new (modules + 0x784) soEventUnitWithWorkArea<soItemManageEventObserver, 1>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 12);
    new (modules + 0x7BC) soEventUnitWithWorkArea<soMotionEventObserver, 1>(reinterpret_cast<soEventManageModuleImpl*>(modules + 0xB8)->getManageId(), 10);

    new (modules + 0x7F8) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(modules + 0x918),
        reinterpret_cast<soModelModule*>(modules + 0xA44),
        reinterpret_cast<soMotionModule*>(modules + 0xBE8),
        reinterpret_cast<soPostureModule*>(modules + 0xD5C),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(lbl_27_bss_35C),
        modules + 0xDC4,
        reinterpret_cast<soCollisionAttackModule*>(lbl_27_bss_384),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4, lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(modules + 0xE14),
        lbl_27_bss_424, modules + 0xE40,
        reinterpret_cast<soSoundModule*>(modules + 0xE54),
        reinterpret_cast<soLinkModule*>(modules + 0xFC0),
        reinterpret_cast<soVisibilityModule*>(modules + 0x1014),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(modules + 0x102C),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(lbl_27_bss_4D0),
        reinterpret_cast<soStatusModule*>(lbl_27_bss_4E8),
        lbl_27_bss_170, lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(lbl_27_bss_530),
        reinterpret_cast<soEventManageModule*>(modules + 0xB8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(modules + 0x1120),
        lbl_27_bss_584,
        reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0, lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(modules + 0x1260),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(modules + 0x12AC),
        lbl_27_bss_654, lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(modules + 0x1404), modules + 0x141C, modules + 0x8D8,
        reinterpret_cast<soParamCustomizeModule*>(modules + 0x8F0), lbl_27_bss_6E8);
    u32 heapSize = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot80();
    Heaps::HeapType heapC = static_cast<Heaps::HeapType>(reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot7C());
    Heaps::HeapType heapB = static_cast<Heaps::HeapType>(reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot78());
    Heaps::HeapType heapA = static_cast<Heaps::HeapType>(reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot74());
    new (modules + 0x8D8) soHeapModuleImpl(heapA, heapB, heapC, heapSize);

    modules[0x8F4] = 0;
    field<char*>(modules, 0x8F0) = lbl_27_data_2BEE8;
    field<f32>(modules, 0x8F8) = lbl_27_rodata_7A00;
    field<f32>(modules, 0x8FC) = lbl_27_rodata_7A00;

    u32 resourceFlag = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot10();
    u32 resourceSet = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot0C();
    u32 resourceKind = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot08();
    u8* resourceIds = modules + 0x900;
    resourceIds[4] = 0;
    field<char*>(resourceIds, 0) = lbl_27_data_465C0;
    field<u32>(resourceIds, 8) = resourceKind;
    field<u32>(resourceIds, 0xC) = resourceKind;
    field<u32>(resourceIds, 0x10) = resourceSet;
    field<s16>(resourceIds, 0x14) = 0;
    field<s16>(resourceIds, 0x16) = 0;
    new (resourceIds + 0x18) soResourceModuleImpl(0, reinterpret_cast<soResourceIdAccesser*>(resourceIds),
                                                static_cast<u8>(resourceFlag));

    u32 modelData = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot68();
    f32 modelScale = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot50();
    u8* model = modules + 0x930;
    fn_27_CBD88(model, 5, 0);
    if (lbl_27_bss_51F8 == 0) {
        fn_27_197C78(lbl_27_bss_51FC);
        __register_global_object(lbl_27_bss_51FC, fn_27_82A94, lbl_27_bss_80D8);
        lbl_27_bss_51F8 = 1;
    }
    new (model + 0x114) soModelModuleImpl(
        reinterpret_cast<soModuleAccesser*>(modules + 0x7F8),
        reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale, reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_27_bss_51FC),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

    u32 motionResource = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot18();
    u8* const& motion = modules + 0xB10;
    fn_27_CD8C8(motion, 0);
    fn_27_D2A38(motion + 0x20, 0);
    field<u8*>(motion, 0x70) = motion;
    field<char*>(motion, 0x6C) = lbl_27_data_8E80;
    field<int>(motion, 0x74) = 0;
    field<int>(motion, 0x80) = 0;
    field<int>(motion, 0x78) = -1;
    field<int>(motion, 0x7C) = -1;
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(locals.motionEntry, i == 0 ? motion + 0x20 : 0);
        reinterpret_cast<MotionArray*>(motion)->append(locals.motionEntry);
        fn_27_AB18C(locals.motionEntry, -1);
    }
    fn_27_C9630(motion + 0x88, 1, 0);
    fn_27_C7470(motion + 0xC4, motionResource, 0x10);

    if (lbl_27_bss_5208 == 0) {
        fn_27_197C28(lbl_27_bss_520C);
        __register_global_object(lbl_27_bss_520C, fn_27_82794, lbl_27_bss_80F0);
        lbl_27_bss_5208 = 1;
    }
    void* motionList = lbl_27_bss_520C;
    if (lbl_27_bss_5200 == 0) {
        fn_27_C94E0(lbl_27_bss_5204);
        __register_global_object(lbl_27_bss_5204, fn_27_82A14, lbl_27_bss_80E4);
        lbl_27_bss_5200 = 1;
    }
    u8* motionKinds = motion + 0x88;
    u8* motionSwitcher = motion + 0x6C;
    s16 motionId;
    for (int i = 0; i < 1; ++i) {
        motionId = eventId(modules);
    }
    fn_27_13844(motion + 0xD8, modules + 0x7F8, motion + 0xC4, motionSwitcher,
                motionList, motionKinds, lbl_27_bss_9BC, lbl_27_bss_5204,
                motionId, 0, lbl_27_bss_DBC);
    reinterpret_cast<ArticleSetup*>(field<void*>(field<void*>(modules, 0x8D0), 4))->slot08();
    if (lbl_27_bss_5210 == 0) {
        fn_27_197C9C(lbl_27_bss_5214);
        __register_global_object(lbl_27_bss_5214, fn_27_82714, lbl_27_bss_80FC);
        lbl_27_bss_5210 = 1;
    }
    fn_27_2520C(modules + 0xD5C, modules + 0x7F8, lbl_27_bss_5214, lbl_27_bss_A48);
    reinterpret_cast<ArticleSetup*>(modules + 0xD5C)->slot38();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot28();
    eventId(modules);

    u32 transitionData = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot14();
    TeamStorage* team = reinterpret_cast<TeamStorage*>(modules + 0xDA4);
    team->primary.isNull = false;
    team->primary.vtable = lbl_27_data_46568;
    team->primary.data = transitionData;
    team->secondary.data = transitionData;
    team->primary.index = -1;
    TeamResource* other = &team->secondary;
    other->isNull = false;
    other->vtable = lbl_27_data_46568;
    other->index = -1;
    fn_27_B5048(team->module, &team->primary, other, &team->primary, modules + 0x7F8, lbl_27_bss_A48);
    new (modules + 0xE14) soStopModuleImpl(reinterpret_cast<soModuleAccesser*>(modules + 0x7F8));

    u32 hitData = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot1C();
    if (lbl_27_bss_5218 == 0) {
        fn_27_197C18(lbl_27_bss_521C);
        __register_global_object(lbl_27_bss_521C, fn_27_82B14, lbl_27_bss_8108);
        lbl_27_bss_5218 = 1;
    }
    fn_27_687F8(modules + 0xE40, modules + 0x7F8, lbl_27_bss_521C, hitData);
    u32 soundData = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot84();
    u8* sound = modules + 0xE48;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 0xC, modules + 0x7F8, sound, soundData, 1, 0, lbl_27_bss_A48);
    u8* link = modules + 0xEB0;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, modules + 0x7F8, link);
    fn_27_5AD88(modules + 0x1014, modules + 0x7F8, reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot20(), 1);

    eventId(modules);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot60();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot5C();
    fn_27_A1DA4(modules + 0x102C, modules + 0x7F8, reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot54());
    eventId(modules);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot70();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot24();

    u8* work = modules + 0x1068;
    work[0x3C] = 0;
    field<char*>(work, 0x40) = __vt__19soGeneralWorkSimple;
    field<char*>(work, 0x38) = __vt__19soGeneralWorkSimple + 8;
    soGeneralWorkSimple* generalWork = reinterpret_cast<soGeneralWorkSimple*>(work + 0x38);
    generalWork->m_intWorks = reinterpret_cast<s32*>(work);
    generalWork->m_intWorkSize = 7;
    generalWork->m_floatWorks = reinterpret_cast<f32*>(work + 0x1C);
    generalWork->m_floatWorkSize = 6;
    generalWork->m_flagWorks = reinterpret_cast<u32*>(work + 0x34);
    generalWork->m_flagWorkSize = 1;
    reinterpret_cast<WorkInitialization*>(generalWork)->slot6C();

    u32 effectD = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot38();
    u32 effectC = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot34();
    u32 effectB = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot30();
    u32 effectA = reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot2C();
    u8* effect = modules + 0x10C8;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3C, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_27_data_8FA60, 0);
    if (lbl_27_bss_526C == 0) {
        fn_27_C948C(lbl_27_bss_5270);
        __register_global_object(lbl_27_bss_5270, fn_27_82C54, lbl_27_bss_8114);
        lbl_27_bss_526C = 1;
    }
    fn_27_9747C(effect + 0x58, modules + 0x7F8, effect, effectA,
                effect + 0x48, lbl_27_bss_5270, effectB, lbl_27_bss_A48,
                effectC, -1, effectD, effect + 0x3C);

    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot58();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot40();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot3C();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot44();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot48();
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot88();
    fn_27_B62E4(modules + 0x1260, modules + 0x7F8, lbl_27_rodata_7A04, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot64();
    fn_27_BEBB4(modules + 0x12AC, modules + 0x7F8, -1, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot6C();
    fn_27_5C600(modules + 0x1404, modules + 0x7F8);
    fn_27_63B94(modules + 0x141C, modules + 0x7F8, 0);

    if (reinterpret_cast<ArticleSetup*>(modules + 0x10A0)->slot08() == 0) {
        void* module = field<void*>(field<void*>(modules, 0x8D0), 0x64);
        reinterpret_cast<WorkRegistration*>(module)->slot14(1, modules + 0x10A0);
    }
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(0, 2);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(0, 1);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(0, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(1, 2);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(1, 1);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(1, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(2, 2);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(2, 1);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(2, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(3, 2);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(3, 1);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(3, 0);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(5, 2);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(5, 1);
    reinterpret_cast<ArticleSetup*>(locals.descriptor)->slot90(5, 0);
    fn_27_1D90FC(self);
    installArticleTables(self, lbl_27_data_8FA64);
    fn_27_1D8FC8(self, 0);
    return self;
}
