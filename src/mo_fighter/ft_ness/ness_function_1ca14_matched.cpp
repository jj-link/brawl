#include <new>
#pragma use_simple_stdpnew on

#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on

typedef unsigned char Byte;
typedef unsigned long Word;

template<>
class soInstanceManagerSimpleEntity<
    soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> >
    : public soInstanceManagerSimple<soEventUnit*> {
public:
    soInstanceManagerFixedSimple<
        soEventUnit*, soInstanceUnit<soEventUnit*>,
        soArray<soInstanceUnit<soEventUnit*> > > m_fixedSimple;
    soArrayVector<soInstanceUnit<soEventUnit*>, 19> m_arrayVector;

    soInstanceManagerSimpleEntity();
    ~soInstanceManagerSimpleEntity();
};

#define DECLARE_EVENT_UNIT(Observer, Count)                                 \
    template<> class soEventUnitWithWorkArea<Observer, Count>               \
        : public soEventUnitImpl<Observer> {                                \
        soInstanceManagerFullPropertyVector<Observer*, Count> m_observerList; \
    public:                                                                 \
        soEventUnitWithWorkArea(s16, s16);                                  \
        virtual ~soEventUnitWithWorkArea();                                 \
        virtual u32 getObserverNum() const;                                 \
    }

DECLARE_EVENT_UNIT(soDamageEventObserver, 4);
DECLARE_EVENT_UNIT(soSituationEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionAttackEventObserver, 4);
DECLARE_EVENT_UNIT(soModelEventObserver, 4);

#undef DECLARE_EVENT_UNIT

class NessWorkInterface {
    Byte storage[8];

public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void initialize();
};

class NessVirtualInterface {
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

class NessPairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};

class NessListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};

class NessArrayRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(int, void*) = 0;
};

class Object_vptr_0 {
public:
    virtual Word slot0() = 0;
    virtual Word slot1() = 0;
    virtual Word slot2() = 0;
    virtual Word slot3() = 0;
    virtual Word fn_101_11338() = 0;
    virtual Word fn_101_11334() = 0;
    virtual Word fn_101_11330() = 0;
    virtual Word slot7() = 0;
    virtual Word fn_101_1132C() = 0;
    virtual Word fn_101_11324() = 0;
    virtual void fn_101_11320(void*) = 0;
};

struct NessAbsoluteAttackRecord {
    Word header[9];
    float position[3];
    Word middle[2];
    unsigned int reserved : 27;
    unsigned int category : 5;
    Word tail[11];

    inline void initialize(float value) {
        position[0] = value;
        position[1] = value;
        position[2] = value;
        category = 0;
    }
};

#pragma always_inline on
#pragma inline_depth(8)

static inline Word& word(void* p, int offset) {
    return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset);
}

static inline Byte* pointer(void* p, int offset) {
    return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset);
}

static inline float& scalar(void* p, int offset) {
    return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset);
}

static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x5BC);
}

static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x694), 0x80) + 8;
    return reinterpret_cast<NessVirtualInterface*>(events)->slot24();
}

struct NessConstants {
    float one, negativeOne, zero;
};

extern "C" {
extern const NessConstants lbl_101_rodata_130;

extern Byte lbl_101_data_B028[], lbl_101_data_B2AC[], lbl_101_data_B040[];
extern Byte lbl_101_data_B518[], lbl_101_data_93C8[], lbl_101_data_974C[];
extern Byte lbl_101_data_B038[], lbl_101_data_94F4[], lbl_101_data_B03C[];
extern Byte lbl_27_data_13730[];

extern Byte lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[];
extern Byte lbl_27_bss_3CC[], lbl_27_bss_3DC[], lbl_27_bss_3F4[];
extern Byte lbl_27_bss_404[], lbl_27_bss_424[], lbl_27_bss_48C[];
extern Byte lbl_27_bss_4BC[], lbl_27_bss_170[], lbl_27_bss_188[];
extern Byte lbl_27_bss_584[], lbl_27_bss_598[], lbl_27_bss_5B0[];
extern Byte lbl_27_bss_5D8[], lbl_27_bss_5EC[], lbl_27_bss_604[];
extern Byte lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[];
extern Byte lbl_27_bss_654[], lbl_27_bss_66C[], lbl_27_bss_A48[];
extern Byte lbl_27_bss_DBC[], lbl_27_bss_9BC[], lbl_27_bss_47C[];
extern Byte lbl_27_bss_344[], lbl_27_bss_55C[], lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[], lbl_27_bss_6E8[];

extern signed char lbl_101_bss_2F8, lbl_101_bss_310, lbl_101_bss_308;
extern signed char lbl_101_bss_300, lbl_101_bss_328, lbl_101_bss_330;
extern Byte lbl_101_bss_2FC[], lbl_101_bss_44C[], lbl_101_bss_314[];
extern Byte lbl_101_bss_470[], lbl_101_bss_30C[], lbl_101_bss_464[];
extern Byte lbl_101_bss_304[], lbl_101_bss_458[], lbl_101_bss_32C[];
extern Byte lbl_101_bss_47C[], lbl_101_bss_334[], lbl_101_bss_488[];

void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA024(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_D7CB8(void*, short, short);
void fn_27_1A8A0C(void*, short, short);
void fn_27_19A55C(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C7470(void*, Word, int);
void fn_27_197C28(void*);
void fn_27_82794(void*, short);
void fn_27_197C08(void*);
void fn_27_82754(void*, short);
void fn_27_C94E0(void*);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
void fn_27_19FF5C(void*, int, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19C940(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_27_197C18(void*);
void fn_27_82B14(void*, short);
void fn_27_687F8(void*, void*, void*, Word);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, Word, int, int, void*);
void fn_27_CBAA0(void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, Word, int);
void fn_27_A1DA4(void*, void*, Word);
void fn_27_711E4(void*, short, void*);
void fn_27_1AC390(void*, int);
void fn_27_C74BC(void*, Word, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A2CEC(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
void fn_27_1DBE08(void*, void*, void*, void*);
void fn_27_1AD79C(void*, int);
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
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, bool);
void fn_101_9210(void*, int);
void fn_101_98D0(void*, void*);
void fn_101_156C4(void*, Word);
void fn_101_1571C(void*, short);
void fn_101_1303C(void*, float, float, float);
void fn_101_A4CC(void*, void*, int, void*, int, void*, int);
void fn_101_B2BC(void*, void*, void*, void*);
void fn_101_B2D8(void*, short, void*, int, int, float, Byte*);
}

struct NessMotionEventStorage {
    Word storage[59];
    inline NessMotionEventStorage(Word id) {
        fn_27_1A9430(this, static_cast<short>(id), 4);
    }
};

struct NessStatusEventStorage {
    Word storage[83];
    inline NessStatusEventStorage(Word id) {
        fn_27_1AA024(this, static_cast<short>(id), 5);
    }
};

struct NessUnknownEventStorage {
    Word storage[17];
    inline NessUnknownEventStorage(Word id) {
        fn_27_D5878(this, static_cast<short>(id), 7);
    }
};

struct NessUnknownEventStorage11 {
    Word storage[18];
    inline NessUnknownEventStorage11(Word id) {
        fn_27_1AA878(this, static_cast<short>(id), 11);
    }
};

struct NessShieldEventStorage {
    Word storage[16];
    inline NessShieldEventStorage(Word id) {
        fn_27_D7CB8(this, static_cast<short>(id), 14);
    }
};

struct NessEffectEventStorage {
    Word storage[30];
    inline NessEffectEventStorage(Word id) {
        fn_27_1A8A0C(this, static_cast<short>(id), 18);
    }
};

struct NessSituationEventStorage {
    Byte storage[96];
    inline NessSituationEventStorage(Word id) {
        new (this) soEventUnitWithWorkArea<soSituationEventObserver, 4>(id, 8);
    }
};

struct NessEventStorage {
    soInstanceManagerSimpleEntity<
        soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    NessMotionEventStorage motion;
    NessStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    NessUnknownEventStorage unknown;
    NessSituationEventStorage situation;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    NessUnknownEventStorage11 unknown11;
    NessShieldEventStorage shield;
    NessEffectEventStorage effect;

    inline Word id() {
        return reinterpret_cast<NessVirtualInterface*>(&events)->slot54();
    }

    inline NessEventStorage()
        : manager(), events(this), motion(id()), status(id()), damage(id(), 6),
          unknown(id()), situation(id()), attack(id(), 1),
          model(id(), 9), unknown11(id()), shield(id()), effect(id()) {}
};

struct NessFollowingVector {
    Word components[3];
};

#define INSTALL_ARTICLE_TABLE(table)                                      \
    word(article, 0x3C) = reinterpret_cast<Word>(table);                  \
    word(article, 0x40) = reinterpret_cast<Word>(table + 0x64);           \
    word(article, 0x48) = reinterpret_cast<Word>(table + 0x70);           \
    word(article, 0x54) = reinterpret_cast<Word>(table + 0x84);           \
    word(article, 0x64) = reinterpret_cast<Word>(table + 0xDC);           \
    word(article, 0x70) = reinterpret_cast<Word>(table + 0xEC);           \
    word(article, 0x7C) = reinterpret_cast<Word>(table + 0x100);          \
    word(article, 0x88) = reinterpret_cast<Word>(table + 0x118);          \
    word(article, 0x90) = reinterpret_cast<Word>(table + 0x124)

#define INITIALIZE_GLOBAL(guard, object, construct, destroy, record)      \
    if (guard == 0) {                                                     \
        construct(object);                                                \
        __register_global_object(object, reinterpret_cast<void*>(destroy), record); \
        guard = 1;                                                        \
    }

#define DESCRIPTOR reinterpret_cast<NessVirtualInterface*>(descriptor)

static inline Byte* starStormName() {
    return lbl_101_data_B028;
}

static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}

static inline void buildDescriptor(Byte* descriptor, Byte* article, void* resource, Byte* parameters) {
    Byte* resourceIds = pointer(resource, 4);
    Word resourceC = reinterpret_cast<NessVirtualInterface*>(resourceIds)->slot1C();
    Word resourceA = reinterpret_cast<NessVirtualInterface*>(resourceIds)->slot10();
    fn_27_1DC5E8(descriptor, 0x6A, parameters, resourceA, 31, resourceC,
        static_cast<unsigned char>(word(parameters, 0)), -1,
        article + 0x1BDC, 0, 0, 0, 0, 0, 0, 0);
}

class NessArticleStorage {
public:
    inline NessArticleStorage(int owner, void* resource, Byte* parameters) {
        Byte* article = reinterpret_cast<Byte*>(this);
        Byte* commands;
        Byte* following;
        const NessConstants* const constants = &lbl_101_rodata_130;
        Byte descriptor[64];
        buildDescriptor(descriptor, article, resource, parameters);
        Byte* const& articleName = starStormName();
        fn_27_1D7EF0(article, articleName, word(descriptor, 4), word(descriptor, 8),
            owner, resource, article + 0x688, 1);
        INSTALL_ARTICLE_TABLE(lbl_101_data_B2AC);

        Byte* modules = article + 0xCC;
        new (modules) NessEventStorage;
        new (modules + 0x5BC) soModuleAccesser(
            reinterpret_cast<StageObject*>(article),
            reinterpret_cast<soResourceModule*>(modules + 0x6DC),
            reinterpret_cast<soModelModule*>(modules + 0x76C),
            reinterpret_cast<soMotionModule*>(modules + 0x8D4),
            reinterpret_cast<soPostureModule*>(modules + 0xA80),
            reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
            reinterpret_cast<soSituationModule*>(modules + 0xAFC),
            modules + 0xB58,
            reinterpret_cast<soCollisionAttackModule*>(modules + 0xCC0),
            reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            lbl_27_bss_3BC,
            reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
            reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
            lbl_27_bss_3F4, lbl_27_bss_404,
            reinterpret_cast<soStopModule*>(modules + 0xD6C),
            lbl_27_bss_424, modules + 0xD98,
            reinterpret_cast<soSoundModule*>(modules + 0xDAC),
            reinterpret_cast<soLinkModule*>(modules + 0xF18),
            reinterpret_cast<soVisibilityModule*>(modules + 0xF6C),
            reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
            reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
            reinterpret_cast<soWorkManageModule*>(modules + 0xF84),
            lbl_27_bss_4BC,
            reinterpret_cast<soAnimCmdModule*>(modules + 0xFB8),
            reinterpret_cast<soStatusModule*>(modules + 0x116C),
            lbl_27_bss_170, lbl_27_bss_188,
            reinterpret_cast<soKineticModule*>(modules + 0x121C),
            reinterpret_cast<soEventManageModule*>(modules + 0xB8),
            lbl_27_bss_55C,
            reinterpret_cast<soEffectModule*>(modules + 0x1340),
            lbl_27_bss_584,
            reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
            lbl_27_bss_5B0, lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604,
            reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
            reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
            reinterpret_cast<soColorBlendModule*>(lbl_27_bss_640),
            lbl_27_bss_654, lbl_27_bss_66C,
            reinterpret_cast<soSlowModule*>(modules + 0x1484),
            modules + 0x149C, modules + 0x69C,
            reinterpret_cast<soParamCustomizeModule*>(modules + 0x6B4),
            lbl_27_bss_6E8);

        Heaps::HeapType heapA, heapB, heapC;
        Word heapSize;
        heapSize = DESCRIPTOR->slot80();
        heapC = static_cast<Heaps::HeapType>(DESCRIPTOR->slot7C());
        heapB = static_cast<Heaps::HeapType>(DESCRIPTOR->slot78());
        heapA = static_cast<Heaps::HeapType>(DESCRIPTOR->slot74());
        new (modules + 0x69C) soHeapModuleImpl(heapA, heapB, heapC, heapSize);

        Byte* customization = modules + 0x6B4;
        fn_101_9210(customization, 0);
        word(customization, 0) = reinterpret_cast<Word>(lbl_101_data_93C8);
        scalar(customization, 8) = constants->one;
        scalar(customization, 12) = constants->one;
        Word resourceFlag = DESCRIPTOR->slot10();
        Word resourceSet = DESCRIPTOR->slot0C();
        Word resourceKind = DESCRIPTOR->slot08();
        Byte* ids = modules + 0x6C4;
        fn_101_9210(ids, 0);
        word(ids, 0) = reinterpret_cast<Word>(lbl_101_data_974C);
        word(ids, 8) = resourceKind;
        word(ids, 12) = resourceKind;
        word(ids, 16) = resourceSet;
        *reinterpret_cast<short*>(ids + 20) = 0;
        *reinterpret_cast<short*>(ids + 22) = 0;
        new (ids + 24) soResourceModuleImpl(0,
            reinterpret_cast<soResourceIdAccesser*>(ids),
            static_cast<unsigned char>(resourceFlag));

        Byte* model;
        Word modelData = DESCRIPTOR->slot68();
        float modelScale = DESCRIPTOR->slot50();
        model = modules + 0x6F4;
        fn_27_19A55C(model, 2, 0);
        INITIALIZE_GLOBAL(lbl_101_bss_2F8, lbl_101_bss_2FC,
            fn_27_197C78, fn_27_82A94, lbl_101_bss_44C);
        new (model + 0x78) soModelModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale,
            reinterpret_cast<void*>(modelData),
            reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_101_bss_2FC),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

        Word motionEntry[5], statusEntry[5];
        Word motionResource = DESCRIPTOR->slot18();
        Byte* motion = modules + 0x838;
        fn_27_CD8C8(motion, 0);
        fn_27_D2A38(motion + 0x20, 0);
        fn_101_98D0(motion + 0x6C, motion);
        for (int i = 0; i < 1; ++i) {
            fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
            reinterpret_cast<Object_vptr_0*>(motion)->fn_101_11320(motionEntry);
            fn_27_AB18C(motionEntry, -1);
        }
        fn_27_C7470(motion + 0x88, motionResource, 1);
        INITIALIZE_GLOBAL(lbl_101_bss_310, lbl_101_bss_314,
            fn_27_197C28, fn_27_82794, lbl_101_bss_470);
        Byte* motionA = lbl_101_bss_314;
        INITIALIZE_GLOBAL(lbl_101_bss_308, lbl_101_bss_30C,
            fn_27_197C08, fn_27_82754, lbl_101_bss_464);
        Byte* motionInstances;
        Byte* motionB = lbl_101_bss_30C;
        INITIALIZE_GLOBAL(lbl_101_bss_300, lbl_101_bss_304,
            fn_27_C94E0, fn_27_82A14, lbl_101_bss_458);
        motionInstances = getMotionInstances(motion);
        fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88,
            motionInstances, motionA, motionB, lbl_27_bss_9BC, lbl_101_bss_304,
            eventId(modules), 0, lbl_27_bss_DBC);
        reinterpret_cast<NessVirtualInterface*>(
            pointer(pointer(modules, 0x694), 4))->slot08();

        Byte* posture = modules + 0xA44;
        fn_27_19FF5C(posture, 1, 0);
        new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
        reinterpret_cast<NessVirtualInterface*>(posture + 0x3C)->slot38();
        DESCRIPTOR->slot28();
        fn_27_3513C(modules + 0xAFC, eventId(modules),
            articleAccesser(modules), lbl_27_bss_A48);

        Byte* transition;
        Word transitionData = DESCRIPTOR->slot14();
        transition = modules + 0xB38;
        fn_101_156C4(transition, transitionData);
        fn_101_156C4(transition + 0x10, transitionData);
        fn_27_B5048(transition + 0x20, transition, transition + 0x10,
            transition, articleAccesser(modules), lbl_27_bss_A48);

        int taskId;
        Byte* attack;
        unsigned char taskCategory = static_cast<unsigned char>(word(article, 0x2C) >> 7);
        taskId = word(article, 0x28);
        attack = modules + 0xB9C;
        Byte attackPart[144];
        new (attackPart) soCollisionAttackPart(static_cast<soCollision::Category>(0), false);
        fn_27_19C940(attack, 1, attackPart, 0);
        reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
        fn_27_CB6E0(attack + 0x9C, 1, 0);
        NessAbsoluteAttackRecord absolute;
        absolute.initialize(constants->one);
        fn_27_C94AC(attack + 0x120, 0, &absolute);
        fn_101_1571C(&absolute, -1);
        new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules),
            taskId, static_cast<gfTask::Category>(taskCategory),
            reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
            reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
            reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
        new (modules + 0xD6C) soStopModuleImpl(articleAccesser(modules));

        Word hitData = DESCRIPTOR->slot1C();
        INITIALIZE_GLOBAL(lbl_101_bss_328, lbl_101_bss_32C,
            fn_27_197C18, fn_27_82B14, lbl_101_bss_47C);
        fn_27_687F8(modules + 0xD98, articleAccesser(modules), lbl_101_bss_32C, hitData);
        Byte* sound;
        Word soundData = DESCRIPTOR->slot84();
        sound = modules + 0xDA0;
        fn_27_57FC8(sound);
        fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData, 1, 0, lbl_27_bss_A48);
        Byte* link = modules + 0xE08;
        fn_27_CBAA0(link, 5, 0);
        fn_27_6A244(link + 0x110, articleAccesser(modules), link);
        Word visibilityData = DESCRIPTOR->slot20();
        fn_27_5AD88(modules + 0xF6C, articleAccesser(modules), visibilityData, 1);

        eventId(modules);
        DESCRIPTOR->slot60();
        DESCRIPTOR->slot5C();
        Word workData = DESCRIPTOR->slot54();
        fn_27_A1DA4(modules + 0xF84, articleAccesser(modules), workData);
        Word animEvent = eventId(modules);
        Byte* animCommand = modules + 0xFB8;
        fn_27_711E4(animCommand, animEvent, animCommand + 0x24);
        fn_27_1AC390(animCommand + 0x24, 0);

        Byte* status;
        Word statusData = DESCRIPTOR->slot70();
        Word statusResource = DESCRIPTOR->slot24();
        status = modules + 0x105C;
        fn_27_C74BC(status, statusResource, 1);
        Byte* statusWork = status + 0x10;
        fn_101_A4CC(statusWork + 0x14, statusWork, 2, statusWork + 8, 2,
            statusWork + 0x10, 1);
        reinterpret_cast<NessWorkInterface*>(statusWork + 0x14)->initialize();
        int i;
        Byte* statusArray = status + 0x48;
        fn_27_CD8C8(statusArray, 0);
        fn_27_1A1E04(statusArray + 0x20, 0);
        fn_101_98D0(statusArray + 0x8C, statusArray);
        for (i = 0; i < 1; ++i) {
            fn_27_AB15C(statusEntry, i == 0 ? statusArray + 0x20 : 0);
            reinterpret_cast<Object_vptr_0*>(statusArray)->fn_101_11320(statusEntry);
            fn_27_AB18C(statusEntry, -1);
        }
        fn_27_1A2CEC(status + 0xEC, 0);
        word(status, 0xFC) = reinterpret_cast<Word>(status + 0x100);
        fn_27_1A29F0(status + 0x100, 1, lbl_101_data_B038, 0);
        reinterpret_cast<NessVirtualInterface*>(status + 0x100)->slot3C();
        fn_27_73930(status + 0x110, articleAccesser(modules), status,
            status + 0xEC, status + 0x24, status + 0xD4, status + 0xFC, statusData, 1, 1);

        Byte* kinetic = modules + 0x121C;
        fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0x68);
        fn_27_1AD79C(kinetic + 0x30, 0);
        word(kinetic, 0x68) = reinterpret_cast<Word>(lbl_101_data_94F4);
        Byte* kineticWork = modules + 0x1288;
        fn_101_A4CC(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6,
            kineticWork + 0x34, 1);
        reinterpret_cast<NessWorkInterface*>(kineticWork + 0x38)->initialize();

        Word effectD = DESCRIPTOR->slot38();
        Word effectC = DESCRIPTOR->slot34();
        Byte* parameterAccesser;
        Byte* command1;
        Byte* command2;
        Byte* command3;
        Byte* command4;
        Byte* effect;
        Word effectA;
        Word effectB = DESCRIPTOR->slot30();
        effectA = DESCRIPTOR->slot2C();
        effect = modules + 0x12E8;
        fn_27_CBEC8(effect, 1, 0);
        fn_27_C9FE4(effect + 0x3C, 1, 0);
        fn_27_D37BC(effect + 0x48, 1, lbl_101_data_B03C, 0);
        INITIALIZE_GLOBAL(lbl_101_bss_330, lbl_101_bss_334,
            fn_27_C948C, fn_27_82C54, lbl_101_bss_488);
        fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA,
            effect + 0x48, lbl_101_bss_334, effectB, lbl_27_bss_A48,
            effectC, -1, effectD, effect + 0x3C);

        DESCRIPTOR->slot58();
        DESCRIPTOR->slot40();
        DESCRIPTOR->slot3C();
        DESCRIPTOR->slot44();
        DESCRIPTOR->slot48();
        DESCRIPTOR->slot88();
        DESCRIPTOR->slot64();
        DESCRIPTOR->slot6C();
        fn_27_5C600(modules + 0x1484, articleAccesser(modules));
        fn_27_63B94(modules + 0x149C, articleAccesser(modules), 0);
        if (reinterpret_cast<NessVirtualInterface*>(modules + 0x12C0)->slot08() == 0) {
            Byte* work = pointer(pointer(modules, 0x694), 0x64);
            reinterpret_cast<NessArrayRegistry*>(work)->add(1, modules + 0x12C0);
        }

        Byte commandFlag0, commandFlag1, commandFlag2, commandFlag3, commandFlag4;
        short listenerId0, listenerId1;
        short commandId0, commandId1, commandId2, commandId3, commandId4;
        void* commandPair0[2];
        void* commandPair1[2];
        void* commandPair2[2];
        void* commandPair3[2];
        void* commandPair4[2];
        commands = modules + 0x14E0;

        DESCRIPTOR->slot90(0, 2);
        DESCRIPTOR->slot90(0, 1);
        Word commandData0 = DESCRIPTOR->slot90(0, 0);
        fn_27_C7744(commands, commandData0, 1);
        fn_27_D22D0(commands + 0x14, 0);
        fn_101_B2BC(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
        commandFlag0 = 0;
        fn_101_B2D8(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
            constants->one, &commandFlag0);
        commandId0 = 1;
        commandPair0[0] = commands + 0xDC;
        commandPair0[1] = commands + 0xC0;
        Byte* commandRegistry0 = pointer(pointer(modules, 0x694), 0x6C);
        reinterpret_cast<NessPairRegistry*>(commandRegistry0)->add(commandPair0, &commandId0);

#define INITIALIZE_COMMAND(index, offset)                                              \
        DESCRIPTOR->slot90(index, 2);                                                   \
        DESCRIPTOR->slot90(index, 1);                                                   \
        Word commandData##index = DESCRIPTOR->slot90(index, 0);                         \
        command##index = commands + offset;                                       \
        fn_27_C7744(command##index, commandData##index, 1);                             \
        fn_27_D22D0(command##index + 0x14, 0);                                          \
        fn_101_B2BC(command##index + 0xC0, command##index, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        commandFlag##index = 0;                                                         \
        fn_101_B2D8(command##index + 0xDC, eventId(modules), command##index + 0x14,     \
            index, 1, constants->one, &commandFlag##index);                             \
        commandId##index = 2;                                                           \
        commandPair##index[0] = command##index + 0xDC;                                  \
        commandPair##index[1] = command##index + 0xC0;                                  \
        Byte* commandRegistry##index = pointer(pointer(modules, 0x694), 0x6C);           \
        reinterpret_cast<NessPairRegistry*>(commandRegistry##index)->add(              \
            commandPair##index, &commandId##index)

        INITIALIZE_COMMAND(1, 0x12C);
        INITIALIZE_COMMAND(2, 0x258);
        INITIALIZE_COMMAND(3, 0x384);
#undef INITIALIZE_COMMAND

        command4 = commands + 0x4B0;
        commandFlag4 = 1;
        fn_101_B2D8(command4, eventId(modules), command4 + 0x50, 4, 1,
            constants->one, &commandFlag4);
        fn_27_D22D0(command4 + 0x50, 0);
        commandId4 = 4;
        commandPair4[0] = command4;
        commandPair4[1] = lbl_27_bss_8C4;
        Byte* commandRegistry4 = pointer(pointer(modules, 0x694), 0x6C);
        reinterpret_cast<NessPairRegistry*>(commandRegistry4)->add(commandPair4, &commandId4);
        DESCRIPTOR->slot90(5, 2);
        DESCRIPTOR->slot90(5, 1);
        DESCRIPTOR->slot90(5, 0);

        fn_27_1DBA64(article + 0x1B5C);
        NessFollowingVector vector0, vector1, vector2, vector3, vector4;
        fn_101_1303C(&vector4, constants->negativeOne, constants->negativeOne, constants->negativeOne);
        fn_101_1303C(&vector3, constants->zero, constants->zero, constants->zero);
        fn_101_1303C(&vector2, constants->negativeOne, constants->negativeOne, constants->negativeOne);
        fn_101_1303C(&vector1, constants->zero, constants->zero, constants->zero);
        fn_101_1303C(&vector0, constants->zero, constants->zero, constants->zero);
        following = article + 0x1B94;
        fn_101_9210(following, 0);
        following[5] |= 0x80;
        following[6] = 0;
        word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
        *reinterpret_cast<NessFollowingVector*>(following + 8) = vector0;
        *reinterpret_cast<NessFollowingVector*>(following + 20) = vector1;
        *reinterpret_cast<NessFollowingVector*>(following + 32) = vector2;
        *reinterpret_cast<NessFollowingVector*>(following + 44) = vector3;
        *reinterpret_cast<NessFollowingVector*>(following + 56) = vector4;
        fn_27_1D90FC(article);

        listenerId0 = 1;
        Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<NessListenerRegistry*>(listeners0)->add(
            article + 0x1B5C, 0, &listenerId0, -1);
        listenerId1 = 1;
        Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<NessListenerRegistry*>(listeners1)->add(
            following, 1, &listenerId1, -1);

        INSTALL_ARTICLE_TABLE(lbl_101_data_B040);
        Byte* const& parameterData = pointer(parameters, 0x34);
        word(article, 0x1BD8) = reinterpret_cast<Word>(parameterData);
        parameterAccesser = article + 0x1BDC;
        fn_101_9210(parameterAccesser, 0);
        word(parameterAccesser, 12) = 0x6A;
        word(parameterAccesser, 16) = 3999;
        word(parameterAccesser, 20) = 23999;
        word(parameterAccesser, 24) = 0;
        word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_101_data_B518);
        word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_101_data_B518 + 8);
        word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
        word(parameterAccesser, 32) = reinterpret_cast<Word>(parameterData + 4);
        word(parameterAccesser, 40) = reinterpret_cast<Word>(parameterData + 8);
        fn_27_1D8FC8(article, false);
    }
};

#undef DESCRIPTOR
#undef INITIALIZE_GLOBAL
#undef INSTALL_ARTICLE_TABLE

extern "C" void* fn_101_1CA14(Byte* article, int owner, void* resource, Byte* parameters) {
    new (article) NessArticleStorage(owner, resource, parameters);
    return article;
}
