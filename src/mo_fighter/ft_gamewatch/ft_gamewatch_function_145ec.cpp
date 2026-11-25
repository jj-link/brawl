#include <new>
#pragma use_simple_stdpnew on
#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on
template <> class soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > {
public: soInstanceManagerSimpleEntity();
private: unsigned long storage[46];
};
template <> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[23];
};
template <> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[14];
};
template <> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public: soEventUnitWithWorkArea(s16, s16);
private: unsigned long storage[15];
};
class ExternalGeneralWork : public soGeneralWorkAbstract {
public: virtual void clearWorkAll();
};
typedef unsigned char Byte;
typedef unsigned long Word;
class GameWatchVirtualInterface {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual Word slot14() = 0;
    virtual Word slot18() = 0;
    virtual Word slot1C() = 0;
    virtual Word slot20() = 0;
    virtual Word slot24() = 0;
    virtual Word slot28() = 0;
    virtual Word slot2C() = 0;
    virtual Word slot30() = 0;
    virtual Word slot34() = 0;
    virtual Word slot38() = 0;
    virtual Word slot3C() = 0;
    virtual Word slot40() = 0;
    virtual Word slot44() = 0;
    virtual Word slot48() = 0;
    virtual Word slot4C() = 0;
    virtual float slot50() = 0;
    virtual Word slot54() = 0;
    virtual Word slot58() = 0;
    virtual Word slot5C() = 0;
    virtual Word slot60() = 0;
    virtual Word slot64() = 0;
    virtual Word slot68() = 0;
    virtual Word slot6C() = 0;
    virtual Word slot70() = 0;
    virtual Word slot74() = 0;
    virtual Word slot78() = 0;
    virtual Word slot7C() = 0;
    virtual Word slot80() = 0;
    virtual Word slot84() = 0;
    virtual Word slot88() = 0;
    virtual Word slot8C() = 0;
    virtual Word slot90(int, int) = 0;
};
class GameWatchPairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};
class GameWatchListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};
class GameWatchArrayRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(int, void*) = 0;
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual Word slot2();
    virtual void slot3();
    virtual Word slot4();
    virtual Word slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10(void*);
};
struct ArticleResource {
    Word unk0;
    Object_vptr_0* ids;
};
struct AbsoluteAttackRecord {
    Word header[9];
    float position[3];
    Word middle[2];
    unsigned int reserved : 27;
    unsigned int category : 5;
    Word tail[11];
    inline void initialize(float zero) {
        position[0] = zero;
        position[1] = zero;
        position[2] = zero;
        category = 0;
    }
};
#pragma always_inline on
#pragma inline_depth(4)
static inline Word& word(void* p, int offset) { return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset); }
static inline Byte* pointer(void* p, int offset) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset); }
static inline float& scalar(void* p, int offset) { return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset); }
static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x7F8);
}
static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x8D0), 0x80) + 8;
    return reinterpret_cast<GameWatchVirtualInterface*>(events)->slot24();
}
struct GameWatchConstants {
    float zero, followingFirst, followingSecond;
};
extern "C" {
extern const GameWatchConstants lbl_107_rodata_D0;
extern Byte lbl_107_data_9690[];
extern Byte lbl_107_data_9914[];
extern Byte lbl_27_bss_398[];
extern Byte lbl_27_bss_3AC[];
extern Byte lbl_27_bss_3BC[];
extern Byte lbl_27_bss_3CC[];
extern Byte lbl_27_bss_3DC[];
extern Byte lbl_27_bss_3F4[];
extern Byte lbl_27_bss_404[];
extern Byte lbl_27_bss_424[];
extern Byte lbl_27_bss_48C[];
extern Byte lbl_27_bss_4BC[];
extern Byte lbl_27_bss_170[];
extern Byte lbl_27_bss_188[];
extern Byte lbl_27_bss_584[];
extern Byte lbl_27_bss_598[];
extern Byte lbl_27_bss_5B0[];
extern Byte lbl_27_bss_5D8[];
extern Byte lbl_27_bss_5EC[];
extern Byte lbl_27_bss_604[];
extern Byte lbl_27_bss_614[];
extern Byte lbl_27_bss_628[];
extern Byte lbl_27_bss_654[];
extern Byte lbl_27_bss_66C[];
extern Byte lbl_107_data_9C34[];
extern Byte lbl_107_data_9E0C[];
extern Byte lbl_107_bss_2B0[];
extern Byte lbl_107_bss_258[];
extern Byte lbl_27_bss_A48[];
extern Byte lbl_107_bss_2C0[];
extern Byte lbl_107_bss_270[];
extern Byte lbl_107_bss_2B8[];
extern Byte lbl_107_bss_264[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern Byte lbl_107_bss_2C8[];
extern Byte lbl_107_bss_27C[];
extern Byte lbl_107_data_96A0[];
extern Byte lbl_107_data_9D60[];
extern Byte lbl_107_data_96A4[];
extern Byte lbl_107_bss_2D0[];
extern Byte lbl_107_bss_288[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_107_data_96A8[];
extern Byte lbl_107_data_9B80[];
extern Byte lbl_27_bss_47C[];
extern Byte lbl_27_bss_6E8[];
extern Byte lbl_27_bss_344[];
extern Byte lbl_27_bss_55C[];
extern signed char lbl_107_bss_2AC;
extern signed char lbl_107_bss_2BC;
extern signed char lbl_107_bss_2B4;
extern signed char lbl_107_bss_2C4;
extern signed char lbl_107_bss_2CC;
void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_107_8648(void*, int);
void fn_27_CBD88(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_107_8D08(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C7470(void*, Word, int);
void fn_27_197C28(void*);
void fn_27_82794(void*, short);
void fn_27_C94E0(void*);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
void fn_27_C9630(void*, int, int);
void fn_27_CBAA0(void*, int, int);
void fn_27_1F980(void*);
void fn_27_19FF5C(void*, int, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_107_161E8(void*, Word);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19C940(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_107_16240(void*, short);
void fn_27_197C18(void*);
void fn_27_82B14(void*, short);
void fn_27_687F8(void*, void*, void*, Word);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, Word, int, int, void*);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, Word, int);
void fn_27_A1DA4(void*, void*, Word);
void fn_27_711E4(void*, short, void*);
void fn_27_1AC390(void*, int);
void fn_27_C74BC(void*, Word, int);
void fn_107_9904(void*, void*, int, void*, int, void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A2CEC(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
void fn_27_1DBE08(void*, void*, void*, void*);
void fn_27_1AEB6C(void*, int);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_C948C(void*);
void fn_27_82C54(void*, short);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_C7744(void*, Word, int);
void fn_27_D22D0(void*, int);
void fn_107_A540(void*, void*, void*, void*);
void fn_107_A55C(void*, short, void*, int, int, float, Byte*);
void fn_27_1DBA64(void*);
void fn_107_B444(void*, float, float, float);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}
struct MotionEventStorage {
    Word storage[59];
    inline MotionEventStorage(Word id) { fn_27_1A9430(this, static_cast<short>(id), 4); }
};
struct StatusEventStorage {
    Word storage[107];
    inline StatusEventStorage(Word id) { fn_27_1AA1F4(this, static_cast<short>(id), 5); }
};
struct LinkEventStorage {
    Word storage[17];
    inline LinkEventStorage(Word id) { fn_27_D5878(this, static_cast<short>(id), 7); }
};
struct ArticleEventStorage {
    Word storage[17];
    inline ArticleEventStorage(Word id) { fn_27_1AA878(this, static_cast<short>(id), 11); }
};
struct Events {
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    MotionEventStorage motion;
    StatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    LinkEventStorage link;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    ArticleEventStorage article;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;
    inline Word id() { return reinterpret_cast<GameWatchVirtualInterface*>(&events)->slot54(); }
    inline Events() :
        manager(), events(this), motion(id()), status(id()), damage(id(), 6),
        link(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
        model(id(), 9), article(id()), capture(id(), 13), shield(id(), 14),
        reflector(id(), 15), absorber(id(), 16), search(id(), 17), item(id(), 12),
        motion1(id(), 10) { }
};
struct GameWatchFollowingVector { Word components[3]; };
static inline void buildDescriptor(Byte* descriptor, Byte* article, ArticleResource* resource, Byte* parameters) {
    Object_vptr_0* const resourceIds = resource->ids;
    Word resourceC = resourceIds->slot5();
    Word resourceB = resourceIds->slot4();
    Word resourceA = resourceIds->slot2();
    fn_27_1DC5E8(descriptor, 0x76, parameters, resourceA, resourceB, resourceC,
        static_cast<unsigned char>(word(parameters, 0)), -1,
        article + 0x208C, 0, 0, 0, 0, 0, 0, 0);
}
static inline Byte* getMotionTranslation(Byte* motion) {
    return motion + 0x88;
}
static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}
static inline Byte* rescueName() {
    return lbl_107_data_9690;
}
static inline void initBase(Byte* article, Byte* descriptor, int owner, ArticleResource* resource) {
    Byte* const& name = rescueName();
    fn_27_1D7EF0(article, name, word(descriptor, 4), word(descriptor, 8),
        owner, resource, article + 0x8C4, 1);
}
class GameWatchRescue {
public:
    inline GameWatchRescue(int owner, ArticleResource* resource, Byte* parameters) {
    Byte* article = reinterpret_cast<Byte*>(this);
    Byte* commands;
    Byte* following;
    const GameWatchConstants* const constants = &lbl_107_rodata_D0;
    Byte descriptor[64];
    Object_vptr_0* resourceIds = resource->ids;
    fn_27_1DC5E8(descriptor, 0x76, parameters,
        resourceIds->slot2(), resourceIds->slot4(), resourceIds->slot5(),
        static_cast<unsigned char>(word(parameters, 0)), -1,
        article + 0x208C, 0, 0, 0, 0, 0, 0, 0);
    Byte* const& name = rescueName();
    fn_27_1D7EF0(article, name, word(descriptor, 4), word(descriptor, 8),
        owner, resource, article + 0x8C4, 1);
    word(article, 0x3C) = reinterpret_cast<Word>(lbl_107_data_9914);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_107_data_9914 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_107_data_9914 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_107_data_9914 + 0x124);
    Events* const eventStorage = reinterpret_cast<Events*>(article + 0xCC);
    new (eventStorage) Events;
    Byte* modules = reinterpret_cast<Byte*>(eventStorage);
    new (modules + 0x7F8) soModuleAccesser(
        reinterpret_cast<StageObject*>(article),
        reinterpret_cast<soResourceModule*>(modules + 0x918),
        reinterpret_cast<soModelModule*>(modules + 0xA44),
        reinterpret_cast<soMotionModule*>(modules + 0xBE8),
        reinterpret_cast<soPostureModule*>(modules + 0xD94),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(modules + 0xE10),
        modules + 0xE6C,
        reinterpret_cast<soCollisionAttackModule*>(modules + 0xFD4),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4, lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(modules + 0x1080),
        lbl_27_bss_424, modules + 0x10AC,
        reinterpret_cast<soSoundModule*>(modules + 0x10C0),
        reinterpret_cast<soLinkModule*>(modules + 0x122C),
        reinterpret_cast<soVisibilityModule*>(modules + 0x1280),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(modules + 0x1298),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(modules + 0x12CC),
        reinterpret_cast<soStatusModule*>(modules + 0x1480),
        lbl_27_bss_170, lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(modules + 0x1530),
        reinterpret_cast<soEventManageModule*>(modules + 0xB8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(modules + 0x169C),
        lbl_27_bss_584,
        reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0, lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(modules + 0x17DC),
        lbl_27_bss_654, lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(modules + 0x1934),
        modules + 0x194C, modules + 0x8D8,
        reinterpret_cast<soParamCustomizeModule*>(modules + 0x8F0),
        lbl_27_bss_6E8);
    Heaps::HeapType heapA, heapB, heapC;
    Word heapSize;
    heapSize = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot80();
    heapC = static_cast<Heaps::HeapType>(reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot7C());
    heapB = static_cast<Heaps::HeapType>(reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot78());
    heapA = static_cast<Heaps::HeapType>(reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot74());
    new (modules + 0x8D8) soHeapModuleImpl(heapA, heapB, heapC, heapSize);
    Byte* customization = modules + 0x8F0;
    fn_107_8648(customization, 0);
    word(customization, 0) = reinterpret_cast<Word>(lbl_107_data_9C34);
    scalar(customization, 8) = constants->zero;
    scalar(customization, 12) = constants->zero;
    Word resourceFlag = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot10();
    Word resourceSet = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot0C();
    Word resourceKind = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot08();
    Byte* ids = modules + 0x900;
    fn_107_8648(ids, 0);
    word(ids, 0) = reinterpret_cast<Word>(lbl_107_data_9E0C);
    word(ids, 8) = resourceKind;
    word(ids, 12) = resourceKind;
    word(ids, 16) = resourceSet;
    *reinterpret_cast<short*>(ids + 20) = 0;
    *reinterpret_cast<short*>(ids + 22) = 0;
    new (ids + 24) soResourceModuleImpl(0, reinterpret_cast<soResourceIdAccesser*>(ids),
        static_cast<unsigned char>(resourceFlag));
    Byte* model;
    Word modelData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot68();
    float modelScale = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot50();
    model = modules + 0x930;
    fn_27_CBD88(model, 5, 0);
    if (lbl_107_bss_2AC == 0) {
        fn_27_197C78(lbl_107_bss_2B0);
        __register_global_object(lbl_107_bss_2B0, reinterpret_cast<void*>(fn_27_82A94), lbl_107_bss_258);
        lbl_107_bss_2AC = 1;
    }
    new (model + 0x114) soModelModuleImpl(articleAccesser(modules), reinterpret_cast<soArray<soModelNodeSetUp>*>(model),
        modelScale, reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_107_bss_2B0),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    Word motionEntry[5], statusEntry[5];
    Word motionResource = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot18();
    Byte* motion = modules + 0xB10;
    fn_27_CD8C8(motion, 0);
    fn_27_D2A38(motion + 0x20, 0);
    fn_107_8D08(motion + 0x6C, motion);
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
        reinterpret_cast<Object_vptr_0*>(motion)->slot10(motionEntry);
        fn_27_AB18C(motionEntry, -1);
    }
    fn_27_C9630(motion + 0x88, 1, 0);
    fn_27_C7470(motion + 0xC4, motionResource, 3);
    if (lbl_107_bss_2BC == 0) {
        fn_27_197C28(lbl_107_bss_2C0);
        __register_global_object(lbl_107_bss_2C0, reinterpret_cast<void*>(fn_27_82794), lbl_107_bss_270);
        lbl_107_bss_2BC = 1;
    }
    Byte* motionA = lbl_107_bss_2C0;
    if (lbl_107_bss_2B4 == 0) {
        fn_27_C94E0(lbl_107_bss_2B8);
        __register_global_object(lbl_107_bss_2B8, reinterpret_cast<void*>(fn_27_82A14), lbl_107_bss_264);
        lbl_107_bss_2B4 = 1;
    }
    Byte* motionTranslation = getMotionTranslation(motion);
    Byte* motionInstances = getMotionInstances(motion);
    fn_27_13844(motion + 0xD8, articleAccesser(modules), motion + 0xC4, motionInstances,
        motionA, motionTranslation, lbl_27_bss_9BC, lbl_107_bss_2B8, eventId(modules), 0, lbl_27_bss_DBC);
    reinterpret_cast<GameWatchVirtualInterface*>(pointer(pointer(modules, 0x8D0), 4))->slot08();
    Byte* posture = modules + 0xD58;
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<GameWatchVirtualInterface*>(posture + 0x3C)->slot38();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot28();
    fn_27_3513C(modules + 0xE10, eventId(modules), articleAccesser(modules), lbl_27_bss_A48);
    Byte* transition;
    Word transitionData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot14();
    transition = modules + 0xE4C;
    fn_107_161E8(transition, transitionData);
    fn_107_161E8(transition + 0x10, transitionData);
    fn_27_B5048(transition + 0x20, transition, transition + 0x10,
        transition, articleAccesser(modules), lbl_27_bss_A48);
    int taskId;
    Byte* attack;
    unsigned char taskCategory = static_cast<unsigned char>(word(article, 0x2C) >> 7);
    taskId = word(article, 0x28);
    attack = modules + 0xEB0;
    Byte attackPart[144];
    new (attackPart) soCollisionAttackPart(static_cast<soCollision::Category>(0), false);
    fn_27_19C940(attack, 1, attackPart, 0);
    reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
    fn_27_CB6E0(attack + 0x9C, 1, 0);
    AbsoluteAttackRecord absolute;
    absolute.initialize(constants->zero);
    fn_27_C94AC(attack + 0x120, 0, &absolute);
    fn_107_16240(&absolute, -1);
    new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules), taskId,
        static_cast<gfTask::Category>(taskCategory), reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
        reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
    new (modules + 0x1080) soStopModuleImpl(articleAccesser(modules));
    Word hitData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot1C();
    if (lbl_107_bss_2C4 == 0) {
        fn_27_197C18(lbl_107_bss_2C8);
        __register_global_object(lbl_107_bss_2C8, reinterpret_cast<void*>(fn_27_82B14), lbl_107_bss_27C);
        lbl_107_bss_2C4 = 1;
    }
    fn_27_687F8(modules + 0x10AC, articleAccesser(modules), lbl_107_bss_2C8, hitData);
    Byte* sound;
    Word soundData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot84();
    sound = modules + 0x10B4;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData, 1, 0, lbl_27_bss_A48);
    Byte* link = modules + 0x111C;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, articleAccesser(modules), link);
    Word visibilityData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot20();
    fn_27_5AD88(modules + 0x1280, articleAccesser(modules), visibilityData, 1);
    eventId(modules);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot60();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot5C();
    Word workData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot54();
    fn_27_A1DA4(modules + 0x1298, articleAccesser(modules), workData);
    Word animEvent = eventId(modules);
    Byte* animCommand = modules + 0x12CC;
    fn_27_711E4(animCommand, animEvent, animCommand + 0x24);
    fn_27_1AC390(animCommand + 0x24, 0);
    Byte* status;
    Word statusData = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot70();
    Word statusResource = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot24();
    status = modules + 0x1370;
    fn_27_C74BC(status, statusResource, 1);
    Byte* statusWork = status + 0x10;
    fn_107_9904(statusWork + 0x14, statusWork, 2, statusWork + 0x8, 2, statusWork + 0x10, 1);
    reinterpret_cast<ExternalGeneralWork*>(statusWork + 0x14)->clearWorkAll();
    int statusIndex;
    Byte* statusArray = status + 0x48;
    fn_27_CD8C8(statusArray, 0);
    fn_27_1A1E04(statusArray + 0x20, 0);
    fn_107_8D08(statusArray + 0x8C, statusArray);
    for (statusIndex = 0; statusIndex < 1; ++statusIndex) {
        fn_27_AB15C(statusEntry, statusIndex == 0 ? statusArray + 0x20 : 0);
        reinterpret_cast<Object_vptr_0*>(statusArray)->slot10(statusEntry);
        fn_27_AB18C(statusEntry, -1);
    }
    fn_27_1A2CEC(status + 0xEC, 0);
    word(status, 0xFC) = reinterpret_cast<Word>(status + 0x100);
    fn_27_1A29F0(status + 0x100, 1, lbl_107_data_96A0, 0);
    reinterpret_cast<GameWatchVirtualInterface*>(status + 0x100)->slot3C();
    fn_27_73930(status + 0x110, articleAccesser(modules), status, status + 0xEC,
        status + 0x24, status + 0xD4, status + 0xFC, statusData, 1, 1);
    Byte* kinetic = modules + 0x1530;
    fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0xB0);
    fn_27_1AEB6C(kinetic + 0x30, 0);
    word(kinetic, 0xB0) = reinterpret_cast<Word>(lbl_107_data_9D60);
    Byte* kineticWork = modules + 0x15E4;
    fn_107_9904(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6, kineticWork + 0x34, 1);
    reinterpret_cast<ExternalGeneralWork*>(kineticWork + 0x38)->clearWorkAll();
    Word effectD = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot38();
    Word effectC = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot34();
    Byte* parameterAccesser;
    Byte* command1;
    Byte* command2;
    Byte* command3;
    Byte* command4;
    Byte* effect;
    Word effectA;
    Word effectB = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot30();
    effectA = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot2C();
    effect = modules + 0x1644;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3C, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_107_data_96A4, 0);
    if (lbl_107_bss_2CC == 0) {
        fn_27_C948C(lbl_107_bss_2D0);
        __register_global_object(lbl_107_bss_2D0, reinterpret_cast<void*>(fn_27_82C54), lbl_107_bss_288);
        lbl_107_bss_2CC = 1;
    }
    fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA, effect + 0x48,
        lbl_107_bss_2D0, effectB, lbl_27_bss_A48, effectC, -1, effectD, effect + 0x3C);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot58();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot40();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot3C();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot44();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot48();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot88();
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot64();
    fn_27_BEBB4(modules + 0x17DC, articleAccesser(modules), -1, 0);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot6C();
    fn_27_5C600(modules + 0x1934, articleAccesser(modules));
    fn_27_63B94(modules + 0x194C, articleAccesser(modules), 0);
    if (reinterpret_cast<GameWatchVirtualInterface*>(modules + 0x161C)->slot08() == 0) {
        Byte* work = pointer(pointer(modules, 0x8D0), 0x64);
        reinterpret_cast<GameWatchArrayRegistry*>(work)->add(1, modules + 0x161C);
    }
    Byte commandFlag0, commandFlag1, commandFlag2, commandFlag3, commandFlag4;
    short listenerId0, listenerId1;
    short commandId0, commandId1, commandId2, commandId3, commandId4;
    void* commandPair0[2];
    void* commandPair1[2];
    void* commandPair2[2];
    void* commandPair3[2];
    void* commandPair4[2];
    commands = modules + 0x1990;
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(0, 2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(0, 1);
    Word commandData0 = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(0, 0);
    fn_27_C7744(commands, commandData0, 1);
    fn_27_D22D0(commands + 0x14, 0);
    fn_107_A540(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag0 = 0;
    fn_107_A55C(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
        constants->zero, &commandFlag0);
    commandId0 = 1;
    commandPair0[0] = commands + 0xDC;
    commandPair0[1] = commands + 0xC0;
    Byte* commandRegistry0 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<GameWatchPairRegistry*>(commandRegistry0)->add(commandPair0, &commandId0);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(1, 2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(1, 1);
    Word commandData1 = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(1, 0);
    command1 = commands + 0x12C;
    fn_27_C7744(command1, commandData1, 3);
    fn_27_D22D0(command1 + 0x14, 0);
    fn_107_A540(command1 + 0xC0, command1, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag1 = 0;
    fn_107_A55C(command1 + 0xDC, eventId(modules), command1 + 0x14, 1, 1,
        constants->zero, &commandFlag1);
    commandId1 = 2;
    commandPair1[0] = command1 + 0xDC;
    commandPair1[1] = command1 + 0xC0;
    Byte* commandRegistry1 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<GameWatchPairRegistry*>(commandRegistry1)->add(commandPair1, &commandId1);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(2, 2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(2, 1);
    Word commandData2 = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(2, 0);
    command2 = commands + 0x258;
    fn_27_C7744(command2, commandData2, 3);
    fn_27_D22D0(command2 + 0x14, 0);
    fn_107_A540(command2 + 0xC0, command2, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag2 = 0;
    fn_107_A55C(command2 + 0xDC, eventId(modules), command2 + 0x14, 2, 1,
        constants->zero, &commandFlag2);
    commandId2 = 2;
    commandPair2[0] = command2 + 0xDC;
    commandPair2[1] = command2 + 0xC0;
    Byte* commandRegistry2 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<GameWatchPairRegistry*>(commandRegistry2)->add(commandPair2, &commandId2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(3, 2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(3, 1);
    Word commandData3 = reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(3, 0);
    command3 = commands + 0x384;
    fn_27_C7744(command3, commandData3, 3);
    fn_27_D22D0(command3 + 0x14, 0);
    fn_107_A540(command3 + 0xC0, command3, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag3 = 0;
    fn_107_A55C(command3 + 0xDC, eventId(modules), command3 + 0x14, 3, 1,
        constants->zero, &commandFlag3);
    commandId3 = 2;
    commandPair3[0] = command3 + 0xDC;
    commandPair3[1] = command3 + 0xC0;
    Byte* commandRegistry3 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<GameWatchPairRegistry*>(commandRegistry3)->add(commandPair3, &commandId3);
    command4 = commands + 0x4B0;
    commandFlag4 = 1;
    fn_107_A55C(command4, eventId(modules), command4 + 0x50, 4, 1,
        constants->zero, &commandFlag4);
    fn_27_D22D0(command4 + 0x50, 0);
    commandId4 = 4;
    commandPair4[0] = command4;
    commandPair4[1] = lbl_27_bss_8C4;
    Byte* commandRegistry4 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<GameWatchPairRegistry*>(commandRegistry4)->add(commandPair4, &commandId4);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(5, 2);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(5, 1);
    reinterpret_cast<GameWatchVirtualInterface*>(descriptor)->slot90(5, 0);
    fn_27_1DBA64(article + 0x200C);
    GameWatchFollowingVector vector0, vector1, vector2, vector3, vector4;
    fn_107_B444(&vector4, constants->followingFirst, constants->followingFirst, constants->followingFirst);
    fn_107_B444(&vector3, constants->followingSecond, constants->followingSecond, constants->followingSecond);
    fn_107_B444(&vector2, constants->followingFirst, constants->followingFirst, constants->followingFirst);
    fn_107_B444(&vector1, constants->followingSecond, constants->followingSecond, constants->followingSecond);
    fn_107_B444(&vector0, constants->followingSecond, constants->followingSecond, constants->followingSecond);
    following = article + 0x2044;
    fn_107_8648(following, 0);
    following[5] |= 0x80;
    following[6] = 0;
    word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
    *reinterpret_cast<GameWatchFollowingVector*>(following + 8) = vector0;
    *reinterpret_cast<GameWatchFollowingVector*>(following + 20) = vector1;
    *reinterpret_cast<GameWatchFollowingVector*>(following + 32) = vector2;
    *reinterpret_cast<GameWatchFollowingVector*>(following + 44) = vector3;
    *reinterpret_cast<GameWatchFollowingVector*>(following + 56) = vector4;
    fn_27_1D90FC(article);
    listenerId0 = 1;
    Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<GameWatchListenerRegistry*>(listeners0)->add(article + 0x200C, 0, &listenerId0, -1);
    listenerId1 = 1;
    Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<GameWatchListenerRegistry*>(listeners1)->add(following, 1, &listenerId1, -1);
    word(article, 0x3C) = reinterpret_cast<Word>(lbl_107_data_96A8);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_107_data_96A8 + 0x124);
    Byte* const& parameterData = pointer(parameters, 0x34);
    word(article, 0x2088) = reinterpret_cast<Word>(parameterData);
    parameterAccesser = article + 0x208C;
    fn_107_8648(parameterAccesser, 0);
    word(parameterAccesser, 12) = 0x76;
    word(parameterAccesser, 16) = 3999;
    word(parameterAccesser, 20) = 23999;
    word(parameterAccesser, 24) = 0;
    word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_107_data_9B80);
    word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_107_data_9B80 + 8);
    word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
    fn_27_1F980(article + 0x20B8);
    fn_27_1D8FC8(article, 0);
    }
};

extern "C" void* fn_107_145EC(Byte* article, int owner, ArticleResource* resource, Byte* parameters) {
    new (article) GameWatchRescue(owner, resource, parameters);
    return article;
}
