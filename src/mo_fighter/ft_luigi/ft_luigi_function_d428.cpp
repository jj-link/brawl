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
DECLARE_EVENT_UNIT(soCollisionHitEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionAttackEventObserver, 4);
DECLARE_EVENT_UNIT(soModelEventObserver, 4);
DECLARE_EVENT_UNIT(soCaptureEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionShieldEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionReflectorEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionAbsorberEventObserver, 4);
DECLARE_EVENT_UNIT(soCollisionSearchEventObserver, 4);
DECLARE_EVENT_UNIT(soItemManageEventObserver, 1);
DECLARE_EVENT_UNIT(soMotionEventObserver, 1);

#undef DECLARE_EVENT_UNIT

class LuigiWorkInterface {
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

class LuigiVirtualInterface {
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

class LuigiPairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};

class LuigiListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};

class LuigiParamRegistry {
public:
    virtual void slot08(); virtual void slot0C(); virtual void slot10();
    virtual void slot14(); virtual void slot18(); virtual void slot1C();
    virtual void slot20(); virtual void slot24(); virtual void slot28();
    virtual void slot2C(); virtual void slot30(); virtual void slot34();
    virtual void slot38(); virtual void slot3C(); virtual void slot40();
    virtual void slot44(); virtual void slot48(); virtual void slot4C();
    virtual void slot50(); virtual void slot54(); virtual void slot58();
    virtual void slot5C(); virtual void slot60(); virtual void slot64();
    virtual void slot68(); virtual void slot6C(); virtual void slot70();
    virtual void slot74(); virtual void add(void**, int);
};

class LuigiArrayRegistry {
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
    virtual Word slot4() = 0;
    virtual Word slot5() = 0;
    virtual Word slot6() = 0;
    virtual Word slot7() = 0;
    virtual Word slot8() = 0;
    virtual Word slot9() = 0;
    virtual void slot10(void*) = 0;
};

struct LuigiAbsoluteAttackRecord {
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
    return reinterpret_cast<soModuleAccesser*>(modules + 0x7F8);
}

static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x8D0), 0x80) + 8;
    return reinterpret_cast<LuigiVirtualInterface*>(events)->slot24();
}

struct LuigiConstants {
    float one, negativeOne, zero;
};

extern "C" {
extern const LuigiConstants lbl_99_rodata_58;

extern Byte lbl_99_data_6580[], lbl_99_data_6808[], lbl_99_data_659C[];
extern Byte lbl_99_data_6A74[], lbl_99_data_6B30[], lbl_99_data_6D08[];
extern Byte lbl_99_data_6594[], lbl_99_data_6C5C[], lbl_99_data_6598[];
extern Byte lbl_27_data_13730[];

extern Byte lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[];
extern Byte lbl_27_bss_3CC[], lbl_27_bss_3DC[], lbl_27_bss_3F4[];
extern Byte lbl_27_bss_404[], lbl_27_bss_424[], lbl_27_bss_48C[];
extern Byte lbl_27_bss_4BC[], lbl_27_bss_170[], lbl_27_bss_188[];
extern Byte lbl_27_bss_584[], lbl_27_bss_5B0[];
extern Byte lbl_27_bss_5D8[], lbl_27_bss_5EC[], lbl_27_bss_604[];
extern Byte lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[];
extern Byte lbl_27_bss_654[], lbl_27_bss_66C[], lbl_27_bss_A48[];
extern Byte lbl_27_bss_DBC[], lbl_27_bss_9BC[], lbl_27_bss_47C[];
extern Byte lbl_27_bss_344[], lbl_27_bss_55C[], lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];

extern signed char lbl_99_bss_274, lbl_99_bss_28C, lbl_99_bss_284;
extern signed char lbl_99_bss_27C, lbl_99_bss_294, lbl_99_bss_29C;
extern Byte lbl_99_bss_278[], lbl_99_bss_208[], lbl_99_bss_290[];
extern Byte lbl_99_bss_22C[], lbl_99_bss_288[], lbl_99_bss_220[];
extern Byte lbl_99_bss_280[], lbl_99_bss_214[], lbl_99_bss_298[];
extern Byte lbl_99_bss_238[], lbl_99_bss_2A0[], lbl_99_bss_244[];
extern signed char lbl_99_bss_2A4;
extern Byte lbl_99_bss_2A8[], lbl_99_bss_250[], lbl_99_bss_2BC[], lbl_27_bss_6E8[];
void fn_27_197BF8(void*);
void fn_27_82C14(void*, short);
void fn_27_A34D4(void*, void*, unsigned char, void*, void*, void*, void*, void*, int);
void fn_27_A78C0(void*);
void fn_27_1993F8(void*, int);
void fn_27_198D94(void*, int);

void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_CBD88(void*, int, int);
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
void fn_27_1A2FF8(void*, int);
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
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
void fn_99_60A0(void*, int);
void fn_99_6760(void*, void*);
void fn_99_1033C(void*, Word);
void fn_99_10394(void*, short);
void fn_99_C610(void*, float, float, float);
void fn_99_7288(void*, void*, int, void*, int, void*, int);
void fn_99_7C08(void*, void*, void*, void*);
void fn_99_7C24(void*, short, void*, int, int, float, Byte*);
}

struct LuigiMotionEventStorage {
    Word storage[59];
    inline LuigiMotionEventStorage(Word id) {
        fn_27_1A9430(this, static_cast<short>(id), 4);
    }
};

struct LuigiStatusEventStorage {
    Word storage[107];
    inline LuigiStatusEventStorage(Word id) {
        fn_27_1AA1F4(this, static_cast<short>(id), 5);
    }
};

struct LuigiUnknownEventStorage {
    Word storage[17];
    inline LuigiUnknownEventStorage(Word id) {
        fn_27_D5878(this, static_cast<short>(id), 7);
    }
};

struct LuigiUnknownEventStorage11 {
    Word storage[17];
    inline LuigiUnknownEventStorage11(Word id) {
        fn_27_1AA878(this, static_cast<short>(id), 11);
    }
};

struct LuigiEventStorage {
    soInstanceManagerSimpleEntity<
        soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    LuigiMotionEventStorage motion;
    LuigiStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    LuigiUnknownEventStorage unknown;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    LuigiUnknownEventStorage11 unknown11;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;

    inline Word id() {
        return reinterpret_cast<LuigiVirtualInterface*>(&events)->slot54();
    }

    inline LuigiEventStorage()
        : manager(), events(this), motion(id()), status(id()), damage(id(), 6),
          unknown(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
          model(id(), 9), unknown11(id()), capture(id(), 13), shield(id(), 14),
          reflector(id(), 15), absorber(id(), 16), search(id(), 17),
          item(id(), 12), motion1(id(), 10) {}
};

struct LuigiFollowingVector {
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

#define DESCRIPTOR reinterpret_cast<LuigiVirtualInterface*>(descriptor)

static inline Byte* negativeZoneName() {
    return lbl_99_data_6580;
}

static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}

static inline void buildDescriptor(Byte* descriptor, Byte* article, void* resource, Byte* parameters) {
    Byte* resourceIds = pointer(resource, 4);
    Word resourceC = reinterpret_cast<LuigiVirtualInterface*>(resourceIds)->slot1C();
    Word resourceA = reinterpret_cast<LuigiVirtualInterface*>(resourceIds)->slot10();
    fn_27_1DC5E8(descriptor, 0x74, parameters, resourceA, 31, resourceC,
        static_cast<unsigned char>(word(parameters, 0)), -1,
        article + 0x2054, 0, 0, 0, 0, 0, 0, 0);
}

class LuigiArticleStorage {
public:
    inline LuigiArticleStorage(int owner, void* resource, Byte* parameters) {
        Byte* article = reinterpret_cast<Byte*>(this);
        Byte* commands;
        Byte* following;
        const LuigiConstants* const constants = &lbl_99_rodata_58;
        Byte descriptor[64];
        buildDescriptor(descriptor, article, resource, parameters);
        Byte* const& articleName = negativeZoneName();
        fn_27_1D7EF0(article, articleName, word(descriptor, 4), word(descriptor, 8),
            owner, resource, article + 0x8C4, 1);
        INSTALL_ARTICLE_TABLE(lbl_99_data_6808);

        Byte* modules = article + 0xCC;
        new (modules) LuigiEventStorage;
        new (modules + 0x7F8) soModuleAccesser(
            reinterpret_cast<StageObject*>(article),
            reinterpret_cast<soResourceModule*>(modules + 0x918),
            reinterpret_cast<soModelModule*>(modules + 0xA44),
            reinterpret_cast<soMotionModule*>(modules + 0xBAC),
            reinterpret_cast<soPostureModule*>(modules + 0xD58),
            reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
            reinterpret_cast<soSituationModule*>(modules + 0xDD4),
            modules + 0xE30,
            reinterpret_cast<soCollisionAttackModule*>(modules + 0xF98),
            reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
            lbl_27_bss_3BC,
            reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
            reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
            lbl_27_bss_3F4, lbl_27_bss_404,
            reinterpret_cast<soStopModule*>(modules + 0x1044),
            lbl_27_bss_424, modules + 0x1070,
            reinterpret_cast<soSoundModule*>(modules + 0x1084),
            reinterpret_cast<soLinkModule*>(modules + 0x11F0),
            reinterpret_cast<soVisibilityModule*>(modules + 0x1244),
            reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
            reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
            reinterpret_cast<soWorkManageModule*>(modules + 0x125C),
            lbl_27_bss_4BC,
            reinterpret_cast<soAnimCmdModule*>(modules + 0x1290),
            reinterpret_cast<soStatusModule*>(modules + 0x1448),
            lbl_27_bss_170, lbl_27_bss_188,
            reinterpret_cast<soKineticModule*>(modules + 0x14F8),
            reinterpret_cast<soEventManageModule*>(modules + 0xB8),
            lbl_27_bss_55C,
            reinterpret_cast<soEffectModule*>(modules + 0x1664),
            lbl_27_bss_584,
            reinterpret_cast<soAreaModule*>(modules + 0x17A4),
            lbl_27_bss_5B0, lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604,
            reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
            reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
            reinterpret_cast<soColorBlendModule*>(lbl_27_bss_640),
            lbl_27_bss_654, lbl_27_bss_66C,
            reinterpret_cast<soSlowModule*>(modules + 0x18FC),
            modules + 0x1914, modules + 0x8D8,
            reinterpret_cast<soParamCustomizeModule*>(modules + 0x8F0),
            lbl_27_bss_6E8);

        Heaps::HeapType heapA, heapB, heapC;
        Word heapSize;
        heapSize = DESCRIPTOR->slot80();
        heapC = static_cast<Heaps::HeapType>(DESCRIPTOR->slot7C());
        heapB = static_cast<Heaps::HeapType>(DESCRIPTOR->slot78());
        heapA = static_cast<Heaps::HeapType>(DESCRIPTOR->slot74());
        new (modules + 0x8D8) soHeapModuleImpl(heapA, heapB, heapC, heapSize);

        Byte* customization = modules + 0x8F0;
        fn_99_60A0(customization, 0);
        word(customization, 0) = reinterpret_cast<Word>(lbl_99_data_6B30);
        scalar(customization, 8) = constants->one;
        scalar(customization, 12) = constants->one;
        Word resourceFlag = DESCRIPTOR->slot10();
        Word resourceSet = DESCRIPTOR->slot0C();
        Word resourceKind = DESCRIPTOR->slot08();
        Byte* ids = modules + 0x900;
        fn_99_60A0(ids, 0);
        word(ids, 0) = reinterpret_cast<Word>(lbl_99_data_6D08);
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
        model = modules + 0x930;
        fn_27_CBD88(model, 5, 0);
        INITIALIZE_GLOBAL(lbl_99_bss_274, lbl_99_bss_278,
            fn_27_197C78, fn_27_82A94, lbl_99_bss_208);
        new (model + 0x114) soModelModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale,
            reinterpret_cast<void*>(modelData),
            reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_99_bss_278),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

        Word motionEntry[5], statusEntry[5];
        Word motionResource = DESCRIPTOR->slot18();
        Byte* motion = modules + 0xB10;
        fn_27_CD8C8(motion, 0);
        fn_27_D2A38(motion + 0x20, 0);
        fn_99_6760(motion + 0x6C, motion);
        for (int i = 0; i < 1; ++i) {
            fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
            reinterpret_cast<Object_vptr_0*>(motion)->slot10(motionEntry);
            fn_27_AB18C(motionEntry, -1);
        }
        fn_27_C7470(motion + 0x88, motionResource, 2);
        INITIALIZE_GLOBAL(lbl_99_bss_28C, lbl_99_bss_290,
            fn_27_197C28, fn_27_82794, lbl_99_bss_22C);
        Byte* motionA = lbl_99_bss_290;
        INITIALIZE_GLOBAL(lbl_99_bss_284, lbl_99_bss_288,
            fn_27_197C08, fn_27_82754, lbl_99_bss_220);
        Byte* motionInstances;
        Byte* motionB = lbl_99_bss_288;
        INITIALIZE_GLOBAL(lbl_99_bss_27C, lbl_99_bss_280,
            fn_27_C94E0, fn_27_82A14, lbl_99_bss_214);
        motionInstances = getMotionInstances(motion);
        fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88,
            motionInstances, motionA, motionB, lbl_27_bss_9BC, lbl_99_bss_280,
            eventId(modules), 0, lbl_27_bss_DBC);
        reinterpret_cast<LuigiVirtualInterface*>(
            pointer(pointer(modules, 0x8D0), 4))->slot08();

        Byte* posture = modules + 0xD1C;
        fn_27_19FF5C(posture, 1, 0);
        new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
        reinterpret_cast<LuigiVirtualInterface*>(posture + 0x3C)->slot38();
        DESCRIPTOR->slot28();
        fn_27_3513C(modules + 0xDD4, eventId(modules),
            articleAccesser(modules), lbl_27_bss_A48);

        Byte* transition;
        Word transitionData = DESCRIPTOR->slot14();
        transition = modules + 0xE10;
        fn_99_1033C(transition, transitionData);
        fn_99_1033C(transition + 0x10, transitionData);
        fn_27_B5048(transition + 0x20, transition, transition + 0x10,
            transition, articleAccesser(modules), lbl_27_bss_A48);

        int taskId;
        Byte* attack;
        unsigned char taskCategory = static_cast<unsigned char>(word(article, 0x2C) >> 7);
        taskId = word(article, 0x28);
        attack = modules + 0xE74;
        Byte attackPart[144];
        new (attackPart) soCollisionAttackPart(static_cast<soCollision::Category>(0), false);
        fn_27_19C940(attack, 1, attackPart, 0);
        reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
        fn_27_CB6E0(attack + 0x9C, 1, 0);
        LuigiAbsoluteAttackRecord absolute;
        absolute.initialize(constants->one);
        fn_27_C94AC(attack + 0x120, 0, &absolute);
        fn_99_10394(&absolute, -1);
        new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules),
            taskId, static_cast<gfTask::Category>(taskCategory),
            reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
            reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
            reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
        new (modules + 0x1044) soStopModuleImpl(articleAccesser(modules));

        Word hitData = DESCRIPTOR->slot1C();
        INITIALIZE_GLOBAL(lbl_99_bss_294, lbl_99_bss_298,
            fn_27_197C18, fn_27_82B14, lbl_99_bss_238);
        fn_27_687F8(modules + 0x1070, articleAccesser(modules), lbl_99_bss_298, hitData);
        Byte* sound;
        Word soundData = DESCRIPTOR->slot84();
        sound = modules + 0x1078;
        fn_27_57FC8(sound);
        fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData, 1, 0, lbl_27_bss_A48);
        Byte* link = modules + 0x10E0;
        fn_27_CBAA0(link, 5, 0);
        fn_27_6A244(link + 0x110, articleAccesser(modules), link);
        Word visibilityData = DESCRIPTOR->slot20();
        fn_27_5AD88(modules + 0x1244, articleAccesser(modules), visibilityData, 1);

        eventId(modules);
        DESCRIPTOR->slot60();
        DESCRIPTOR->slot5C();
        Word workData = DESCRIPTOR->slot54();
        fn_27_A1DA4(modules + 0x125C, articleAccesser(modules), workData);
        Word animEvent = eventId(modules);
        Byte* animCommand = modules + 0x1290;
        fn_27_711E4(animCommand, animEvent, animCommand + 0x24);
        fn_27_1AC390(animCommand + 0x24, 0);

        Byte* status;
        Word statusData = DESCRIPTOR->slot70();
        Word statusResource = DESCRIPTOR->slot24();
        status = modules + 0x1334;
        fn_27_C74BC(status, statusResource, 2);
        Byte* statusWork = status + 0x10;
        fn_99_7288(statusWork + 0x14, statusWork, 2, statusWork + 8, 2,
            statusWork + 0x10, 1);
        reinterpret_cast<LuigiWorkInterface*>(statusWork + 0x14)->initialize();
        int i;
        Byte* statusArray = status + 0x48;
        fn_27_CD8C8(statusArray, 0);
        fn_27_1A1E04(statusArray + 0x20, 0);
        fn_99_6760(statusArray + 0x8C, statusArray);
        for (i = 0; i < 1; ++i) {
            fn_27_AB15C(statusEntry, i == 0 ? statusArray + 0x20 : 0);
            reinterpret_cast<Object_vptr_0*>(statusArray)->slot10(statusEntry);
            fn_27_AB18C(statusEntry, -1);
        }
        fn_27_1A2FF8(status + 0xEC, 0);
        word(status, 0x100) = reinterpret_cast<Word>(status + 0x104);
        fn_27_1A29F0(status + 0x104, 1, lbl_99_data_6594, 0);
        reinterpret_cast<LuigiVirtualInterface*>(status + 0x104)->slot3C();
        fn_27_73930(status + 0x114, articleAccesser(modules), status,
            status + 0xEC, status + 0x24, status + 0xD4, status + 0x100, statusData, 2, 1);

        Byte* kinetic = modules + 0x14F8;
        fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0xB0);
        fn_27_1AEB6C(kinetic + 0x30, 0);
        word(kinetic, 0xB0) = reinterpret_cast<Word>(lbl_99_data_6C5C);
        Byte* kineticWork = modules + 0x15AC;
        fn_99_7288(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6,
            kineticWork + 0x34, 1);
        reinterpret_cast<LuigiWorkInterface*>(kineticWork + 0x38)->initialize();

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
        effect = modules + 0x160C;
        fn_27_CBEC8(effect, 1, 0);
        fn_27_C9FE4(effect + 0x3C, 1, 0);
        fn_27_D37BC(effect + 0x48, 1, lbl_99_data_6598, 0);
        INITIALIZE_GLOBAL(lbl_99_bss_29C, lbl_99_bss_2A0,
            fn_27_C948C, fn_27_82C54, lbl_99_bss_244);
        fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA,
            effect + 0x48, lbl_99_bss_2A0, effectB, lbl_27_bss_A48,
            effectC, -1, effectD, effect + 0x3C);

        Word areaData = DESCRIPTOR->slot58();
        INITIALIZE_GLOBAL(lbl_99_bss_2A4, lbl_99_bss_2A8,
            fn_27_197BF8, fn_27_82C14, lbl_99_bss_250);
        fn_27_A34D4(modules + 0x17A4, articleAccesser(modules),
            static_cast<unsigned char>(areaData), modules + 0x18C0,
            modules + 0x180C, modules + 0x17F0, lbl_99_bss_2A8, lbl_27_bss_A48, -1);
        fn_27_A78C0(modules + 0x17F0);
        fn_27_1993F8(modules + 0x180C, 0);
        fn_27_198D94(modules + 0x18C0, 0);
        DESCRIPTOR->slot40();
        DESCRIPTOR->slot3C();
        DESCRIPTOR->slot44();
        DESCRIPTOR->slot48();
        DESCRIPTOR->slot88();
        DESCRIPTOR->slot64();
        DESCRIPTOR->slot6C();
        fn_27_5C600(modules + 0x18FC, articleAccesser(modules));
        fn_27_63B94(modules + 0x1914, articleAccesser(modules), 0);
        if (reinterpret_cast<LuigiVirtualInterface*>(modules + 0x15E4)->slot08() == 0) {
            Byte* work = pointer(pointer(modules, 0x8D0), 0x64);
            reinterpret_cast<LuigiArrayRegistry*>(work)->add(1, modules + 0x15E4);
        }

        Byte commandFlag0, commandFlag1, commandFlag2, commandFlag3, commandFlag4;
        short listenerId0, listenerId1;
        short commandId0, commandId1, commandId2, commandId3, commandId4;
        void* commandPair0[2];
        void* commandPair1[2];
        void* commandPair2[2];
        void* commandPair3[2];
        void* commandPair4[2];
        commands = modules + 0x1958;

        DESCRIPTOR->slot90(0, 2);
        DESCRIPTOR->slot90(0, 1);
        Word commandData0 = DESCRIPTOR->slot90(0, 0);
        fn_27_C7744(commands, commandData0, 2);
        fn_27_D22D0(commands + 0x14, 0);
        fn_99_7C08(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
        commandFlag0 = 0;
        fn_99_7C24(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
            constants->one, &commandFlag0);
        commandId0 = 1;
        commandPair0[0] = commands + 0xDC;
        commandPair0[1] = commands + 0xC0;
        Byte* commandRegistry0 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LuigiPairRegistry*>(commandRegistry0)->add(commandPair0, &commandId0);

#define INITIALIZE_COMMAND(index, offset)                                              \
        DESCRIPTOR->slot90(index, 2);                                                   \
        DESCRIPTOR->slot90(index, 1);                                                   \
        Word commandData##index = DESCRIPTOR->slot90(index, 0);                         \
        command##index = commands + offset;                                       \
        fn_27_C7744(command##index, commandData##index, 2);                             \
        fn_27_D22D0(command##index + 0x14, 0);                                          \
        fn_99_7C08(command##index + 0xC0, command##index, lbl_27_bss_D8C, lbl_27_bss_D8C); \
        commandFlag##index = 0;                                                         \
        fn_99_7C24(command##index + 0xDC, eventId(modules), command##index + 0x14,     \
            index, 1, constants->one, &commandFlag##index);                             \
        commandId##index = 2;                                                           \
        commandPair##index[0] = command##index + 0xDC;                                  \
        commandPair##index[1] = command##index + 0xC0;                                  \
        Byte* commandRegistry##index = pointer(pointer(modules, 0x8D0), 0x6C);           \
        reinterpret_cast<LuigiPairRegistry*>(commandRegistry##index)->add(              \
            commandPair##index, &commandId##index)

        INITIALIZE_COMMAND(1, 0x12C);
        INITIALIZE_COMMAND(2, 0x258);
        INITIALIZE_COMMAND(3, 0x384);
#undef INITIALIZE_COMMAND

        command4 = commands + 0x4B0;
        commandFlag4 = 1;
        fn_99_7C24(command4, eventId(modules), command4 + 0x50, 4, 1,
            constants->one, &commandFlag4);
        fn_27_D22D0(command4 + 0x50, 0);
        commandId4 = 4;
        commandPair4[0] = command4;
        commandPair4[1] = lbl_27_bss_8C4;
        Byte* commandRegistry4 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LuigiPairRegistry*>(commandRegistry4)->add(commandPair4, &commandId4);
        DESCRIPTOR->slot90(5, 2);
        DESCRIPTOR->slot90(5, 1);
        DESCRIPTOR->slot90(5, 0);

        fn_27_1DBA64(article + 0x1FD4);
        LuigiFollowingVector vector0, vector1, vector2, vector3, vector4;
        fn_99_C610(&vector4, constants->negativeOne, constants->negativeOne, constants->negativeOne);
        fn_99_C610(&vector3, constants->zero, constants->zero, constants->zero);
        fn_99_C610(&vector2, constants->negativeOne, constants->negativeOne, constants->negativeOne);
        fn_99_C610(&vector1, constants->zero, constants->zero, constants->zero);
        fn_99_C610(&vector0, constants->zero, constants->zero, constants->zero);
        following = article + 0x200C;
        fn_99_60A0(following, 0);
        following[5] |= 0x80;
        following[6] = 0;
        word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
        *reinterpret_cast<LuigiFollowingVector*>(following + 8) = vector0;
        *reinterpret_cast<LuigiFollowingVector*>(following + 20) = vector1;
        *reinterpret_cast<LuigiFollowingVector*>(following + 32) = vector2;
        *reinterpret_cast<LuigiFollowingVector*>(following + 44) = vector3;
        *reinterpret_cast<LuigiFollowingVector*>(following + 56) = vector4;
        fn_27_1D90FC(article);

        listenerId0 = 1;
        Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<LuigiListenerRegistry*>(listeners0)->add(
            article + 0x1FD4, 0, &listenerId0, -1);
        listenerId1 = 1;
        Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<LuigiListenerRegistry*>(listeners1)->add(
            following, 1, &listenerId1, -1);

        INSTALL_ARTICLE_TABLE(lbl_99_data_659C);
        Byte* const& parameterData = pointer(parameters, 0x34);
        word(article, 0x2050) = reinterpret_cast<Word>(parameterData);
        parameterAccesser = article + 0x2054;
        fn_99_60A0(parameterAccesser, 0);
        word(parameterAccesser, 12) = 0x74;
        word(parameterAccesser, 16) = 3999;
        word(parameterAccesser, 20) = 23999;
        word(parameterAccesser, 24) = 43999;
        word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_99_data_6A74);
        word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_99_data_6A74 + 8);
        word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
        word(parameterAccesser, 0x24) = reinterpret_cast<Word>(parameterData + 0x50);
        word(parameterAccesser, 0x28) = reinterpret_cast<Word>(parameterData + 0x54);
        word(parameterAccesser, 0x30) = reinterpret_cast<Word>(parameterData + 4);
        word(parameterAccesser, 0x34) = reinterpret_cast<Word>(parameterData + 0x18);
        void* customizedParams[2];
        customizedParams[0] = 0;
        customizedParams[1] = lbl_99_bss_2BC;
        Byte* customizationRegistry = pointer(pointer(pointer(article, 0x60), 0xD8), 0x70);
        reinterpret_cast<LuigiParamRegistry*>(customizationRegistry)->add(customizedParams, 2);
        fn_27_1D8FC8(article, 0);
    }
};

#undef DESCRIPTOR
#undef INITIALIZE_GLOBAL
#undef INSTALL_ARTICLE_TABLE

extern "C" void* fn_99_D428(Byte* article, int owner, void* resource, Byte* parameters) {
    new (article) LuigiArticleStorage(owner, resource, parameters);
    return article;
}