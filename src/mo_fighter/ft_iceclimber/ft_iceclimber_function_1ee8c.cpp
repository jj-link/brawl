#include <new>
#pragma force_active on
#pragma use_simple_stdpnew on

class StageObject;
class soModuleAccesser;
class soEventUnit;
template<class T> class soInstanceUnit;
template<class T, int N> class soArrayVector;
template<class T> class soArray;
template<class T> class soInterpolation;
class Vec3f;
class soModelNodeSetUp;
class soModelVirtualNode;
class soEventObserverRegistrationDesc;

template<class T, class A>
class soInstanceManagerSimpleEntity {
public:
    soInstanceManagerSimpleEntity();
private:
    unsigned long storage[46];
};

class soEventManageModuleImpl {
public:
    soEventManageModuleImpl(void*);
private:
    unsigned long storage[5];
};

template<class T, int N>
class soEventUnitWithWorkArea {
public:
    soEventUnitWithWorkArea(short, short);
private:
    unsigned long storage[23];
};

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

template<>
class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short, short);
private:
    unsigned long storage[14];
};

template<>
class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(short, short);
private:
    unsigned long storage[15];
};

class soResourceModule;
class soModelModule;
class soMotionModule;
class soPostureModule;
class soGroundModule;
class soSituationModule;
class soCollisionAttackModule;
class soCollisionHitModule;
class soCollisionShieldModule;
class soCollisionSearchModule;
class soDamageModule;
class soStopModule;
class soSoundModule;
class soLinkModule;
class soVisibilityModule;
class soControllerModule;
class soCameraModule;
class soWorkManageModule;
class soAnimCmdModule;
class soStatusModule;
class soKineticModule;
class soEventManageModule;
class soEffectModule;
class soAreaModule;
class soShadowModule;
class soItemManageModule;
class soColorBlendModule;
class soSlowModule;
class soParamCustomizeModule;

class Heaps {
public:
    enum HeapType { HeapDefault };
};

class soHeapModuleImpl {
public:
    soHeapModuleImpl(Heaps::HeapType, Heaps::HeapType, Heaps::HeapType, long);
};

class soModelModuleImpl {
public:
    soModelModuleImpl(soModuleAccesser*, soArray<soModelNodeSetUp>*, float,
                      void*, soArray<soModelVirtualNode>*,
                      soEventObserverRegistrationDesc*);
};

class soPostureModuleImpl {
public:
    soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*,
                        soEventObserverRegistrationDesc*);
};

class soCollision {
public:
    enum Category { CategoryDefault };
};

class soCollisionAttackPart {
public:
    soCollisionAttackPart(soCollision::Category, bool);
    ~soCollisionAttackPart();
};

class soCollisionGroup;
class soCollisionAttackAbsolute;

class gfTask {
public:
    enum Category { CategoryDefault };
};

class soCollisionAttackModuleImpl {
public:
    soCollisionAttackModuleImpl(
        soModuleAccesser*, int, gfTask::Category,
        soArray<soCollisionAttackPart>*, soArray<soCollisionGroup>*,
        soArray<soCollisionAttackAbsolute>*,
        soEventObserverRegistrationDesc*, bool);
};

typedef unsigned char Byte;
typedef unsigned long Word;

class Object_vptr_0 {
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
};

class IceVirtualInterface {
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

class IcePairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};

class IceListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};

class IceArrayRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(int, void*) = 0;
};

class IceAppendInterface {
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
    virtual void append(void*) = 0;
};

struct IceAbsoluteAttackRecord {
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

template<class F>
static inline F method(void* p, int offset) {
    return *reinterpret_cast<F*>(*reinterpret_cast<Byte**>(p) + offset);
}

static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x7F8);
}

typedef Word (*Getter)(void*);

static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x8D0), 0x80) + 8;
    return reinterpret_cast<IceVirtualInterface*>(events)->slot24();
}

struct IceConstants {
    float one, followingFirst, followingSecond;
};

extern "C" {
extern const IceConstants lbl_105_rodata_128;
extern Byte lbl_105_data_9FF0[];
extern Byte lbl_105_data_A274[];
extern Byte lbl_27_bss_2EC[];
extern Byte lbl_27_bss_344[];
extern Byte lbl_27_bss_398[];
extern Byte lbl_27_bss_3AC[];
extern Byte lbl_27_bss_3BC[];
extern Byte lbl_27_bss_3CC[];
extern Byte lbl_27_bss_3DC[];
extern Byte lbl_27_bss_3F4[];
extern Byte lbl_27_bss_404[];
extern Byte lbl_27_bss_424[];
extern Byte lbl_27_bss_47C[];
extern Byte lbl_27_bss_48C[];
extern Byte lbl_27_bss_4BC[];
extern Byte lbl_27_bss_170[];
extern Byte lbl_27_bss_188[];
extern Byte lbl_27_bss_55C[];
extern Byte lbl_27_bss_584[];
extern Byte lbl_27_bss_598[];
extern Byte lbl_27_bss_5B0[];
extern Byte lbl_27_bss_5D8[];
extern Byte lbl_27_bss_5EC[];
extern Byte lbl_27_bss_604[];
extern Byte lbl_27_bss_614[];
extern Byte lbl_27_bss_628[];
extern Byte lbl_27_bss_640[];
extern Byte lbl_27_bss_654[];
extern Byte lbl_27_bss_66C[];
extern Byte lbl_27_bss_6E8[];
extern Byte lbl_105_data_8AC8[];
extern signed char lbl_105_bss_398;
extern Byte lbl_105_bss_39C[];
extern Byte lbl_105_bss_4C4[];
extern Byte lbl_27_bss_A48[];
extern signed char lbl_105_bss_3B0;
extern Byte lbl_105_bss_3B4[];
extern Byte lbl_105_bss_4E8[];
extern signed char lbl_105_bss_3A8;
extern Byte lbl_105_bss_3AC[];
extern Byte lbl_105_bss_4DC[];
extern signed char lbl_105_bss_3A0;
extern Byte lbl_105_bss_3A4[];
extern Byte lbl_105_bss_4D0[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern signed char lbl_105_bss_3B8;
extern Byte lbl_105_bss_3BC[];
extern Byte lbl_105_bss_4F4[];
extern Byte lbl_105_data_A000[];
extern Byte lbl_105_data_8BF4[];
extern Byte lbl_105_data_A004[];
extern signed char lbl_105_bss_3C0;
extern Byte lbl_105_bss_3C4[];
extern Byte lbl_105_bss_500[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_105_data_A008[];
extern Byte lbl_105_data_A4E0[];

void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                   void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_105_8058(void*, int);
void fn_27_CBD88(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_105_8720(void*, void*);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C7470(void*, Word, int);
void fn_27_197C28(void*);
void fn_27_82794(void*, short);
void fn_27_197C08(void*);
void fn_27_82754(void*, short);
void fn_27_C94E0(void*);
void fn_27_82A14(void*, short);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*,
                 short, int, void*);
void fn_27_19FF5C(void*, int, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_105_17DB8(void*, Word);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_CCE34(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_105_17E10(void*, short);
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
void fn_105_9248(void*, void*, int, void*, int, void*, int);
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
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*,
                 Word, int, Word, void*);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_C7744(void*, Word, int);
void fn_27_D22D0(void*, int);
void fn_105_9E0C(void*, void*, void*, void*);
void fn_105_9E28(void*, short, void*, int, int, float, Byte*);
void fn_27_1DBA64(void*);
void fn_105_C1C0(void*, float, float, float);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);

void __ct__21soCollisionAttackPartFQ211soCollision8Categoryb(
    void*, soCollision::Category, bool);
void __ct__16soStopModuleImplFP16soModuleAccesser(void*, soModuleAccesser*);

void __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
    void*, StageObject*, soResourceModule*, soModelModule*, soMotionModule*,
    soPostureModule*, soGroundModule*, soSituationModule*, void*,
    soCollisionAttackModule*, soCollisionHitModule*, soCollisionShieldModule*,
    soCollisionShieldModule*, soCollisionShieldModule*, void*,
    soCollisionSearchModule*, soDamageModule*, void*, void*, soStopModule*,
    void*, void*, soSoundModule*, soLinkModule*, soVisibilityModule*,
    soControllerModule*, soCameraModule*, soWorkManageModule*, void*,
    soAnimCmdModule*, soStatusModule*, void*, void*, soKineticModule*,
    soEventManageModule*, void*, soEffectModule*, void*, soAreaModule*,
    void*, void*, void*, void*, soShadowModule*, soItemManageModule*,
    soColorBlendModule*, void*, void*, soSlowModule*, void*, void*,
    soParamCustomizeModule*, void*);
}

struct IceMotionEventStorage {
    Word storage[59];
    inline IceMotionEventStorage(Word id) {
        fn_27_1A9430(this, static_cast<short>(id), 4);
    }
};

struct IceStatusEventStorage {
    Word storage[107];
    inline IceStatusEventStorage(Word id) {
        fn_27_1AA1F4(this, static_cast<short>(id), 5);
    }
};

struct IceUnknownEventStorage {
    Word storage[17];
    inline IceUnknownEventStorage(Word id) {
        fn_27_D5878(this, static_cast<short>(id), 7);
    }
};

struct IceUnknownEventStorage11 {
    Word storage[17];
    inline IceUnknownEventStorage11(Word id) {
        fn_27_1AA878(this, static_cast<short>(id), 11);
    }
};

struct IceArticleEventStorage {
    soInstanceManagerSimpleEntity<
        soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    IceMotionEventStorage motion;
    IceStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    IceUnknownEventStorage unknown;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    IceUnknownEventStorage11 unknown11;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;

    inline Word id() {
        return reinterpret_cast<IceVirtualInterface*>(&events)->slot54();
    }

    inline IceArticleEventStorage()
        : manager(), events(this), motion(id()), status(id()), damage(id(), 6),
          unknown(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
          model(id(), 9), unknown11(id()), capture(id(), 13), shield(id(), 14),
          reflector(id(), 15), absorber(id(), 16), search(id(), 17),
          item(id(), 12), motion1(id(), 10) {}
};

struct IceFollowingVector {
    Word components[3];
};

static inline void initializeDescriptor(Byte* descriptor, void* resource,
                                        Byte* parameters, Byte* article) {
    Byte* resourceIds = pointer(resource, 4);
    fn_27_1DC5E8(
        descriptor, 0x99, parameters,
        reinterpret_cast<IceVirtualInterface*>(resourceIds)->slot10(),
        reinterpret_cast<IceVirtualInterface*>(resourceIds)->slot18(),
        reinterpret_cast<IceVirtualInterface*>(resourceIds)->slot1C(),
        static_cast<unsigned char>(word(parameters, 0)),
        -1, article + 0x1FF0, 0, 0, 0, 0, 0, 0, 0);
}

static inline Byte* iceName() {
    return lbl_105_data_9FF0;
}

static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}

class IceWorkInterface {
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

class IceBergWindArticle {
    Byte storage[0x2010];
public:
    inline IceBergWindArticle(int owner, void* resource, Byte* parameters);
};

inline IceBergWindArticle::IceBergWindArticle(
    int owner, void* resource, Byte* parameters) {
    Byte* article = reinterpret_cast<Byte*>(this);
    Byte* commands;
    Byte* following;
    const IceConstants* const constants = &lbl_105_rodata_128;
    Byte descriptor[64];
    initializeDescriptor(descriptor, resource, parameters, article);
    Byte* const& articleName = iceName();
    fn_27_1D7EF0(article, articleName, word(descriptor, 4),
                  word(descriptor, 8), owner, resource, article + 0x8C4, 1);

    word(article, 0x3C) = reinterpret_cast<Word>(lbl_105_data_A274);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_105_data_A274 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_105_data_A274 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_105_data_A274 + 0x124);

    Byte* modules = article + 0xCC;
    new (modules) IceArticleEventStorage;
    __ct__16soModuleAccesserFP11StageObjectP16soResourceModuleP13soModelModuleP14soMotionModuleP15soPostureModuleP14soGroundModuleP17soSituationModulePvP23soCollisionAttackModuleP20soCollisionHitModuleP23soCollisionShieldModuleP23soCollisionShieldModuleP23soCollisionShieldModulePvP23soCollisionSearchModuleP14soDamageModulePvPvP12soStopModulePvPvP13soSoundModuleP12soLinkModuleP18soVisibilityModuleP18soControllerModuleP14soCameraModuleP18soWorkManageModulePvP15soAnimCmdModuleP14soStatusModulePvPvP15soKineticModuleP19soEventManageModulePvP14soEffectModulePvP12soAreaModulePvPvPvPvP14soShadowModuleP18soItemManageModuleP18soColorBlendModulePvPvP12soSlowModulePvPvP22soParamCustomizeModulePv(
        modules + 0x7F8,
        reinterpret_cast<StageObject*>(article),
        reinterpret_cast<soResourceModule*>(lbl_27_bss_2EC),
        reinterpret_cast<soModelModule*>(modules + 0xA18),
        reinterpret_cast<soMotionModule*>(modules + 0xB80),
        reinterpret_cast<soPostureModule*>(modules + 0xD2C),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(modules + 0xDA8),
        modules + 0xE04,
        reinterpret_cast<soCollisionAttackModule*>(modules + 0x108C),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4, lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(modules + 0x1138),
        lbl_27_bss_424, modules + 0x1164,
        reinterpret_cast<soSoundModule*>(modules + 0x1178),
        reinterpret_cast<soLinkModule*>(modules + 0x12E4),
        reinterpret_cast<soVisibilityModule*>(modules + 0x1338),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(modules + 0x1350),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(modules + 0x1384),
        reinterpret_cast<soStatusModule*>(modules + 0x1538),
        lbl_27_bss_170, lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(modules + 0x15E8),
        reinterpret_cast<soEventManageModule*>(modules + 0xB8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(modules + 0x1754),
        lbl_27_bss_584,
        reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0, lbl_27_bss_5D8, lbl_27_bss_5EC, lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(lbl_27_bss_640),
        lbl_27_bss_654, lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(modules + 0x1898),
        modules + 0x18B0, modules + 0x8D8,
        reinterpret_cast<soParamCustomizeModule*>(modules + 0x8F0),
        lbl_27_bss_6E8);

    Heaps::HeapType heapB;
    Heaps::HeapType heapC;
    long heapSize;
    heapSize = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot80();
    heapC = static_cast<Heaps::HeapType>(
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot7C());
    heapB = static_cast<Heaps::HeapType>(
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot78());
    new (modules + 0x8D8) soHeapModuleImpl(
        static_cast<Heaps::HeapType>(
            reinterpret_cast<IceVirtualInterface*>(descriptor)->slot74()),
        heapB, heapC, heapSize);

    Byte* customization = modules + 0x8F0;
    fn_105_8058(customization, 0);
    word(customization, 0) = reinterpret_cast<Word>(lbl_105_data_8AC8);
    scalar(customization, 8) = constants->one;
    scalar(customization, 12) = constants->one;
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot10();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot0C();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot08();

    Byte* model;
    float modelScale;
    Word modelData;
    modelData = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot68();
    modelScale = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot50();
    model = modules + 0x904;
    fn_27_CBD88(model, 5, 0);
    if (lbl_105_bss_398 == 0) {
        fn_27_197C78(lbl_105_bss_39C);
        __register_global_object(lbl_105_bss_39C,
            reinterpret_cast<void*>(fn_27_82A94), lbl_105_bss_4C4);
        lbl_105_bss_398 = 1;
    }
    new (model + 0x114) soModelModuleImpl(
        articleAccesser(modules),
        reinterpret_cast<soArray<soModelNodeSetUp>*>(model),
        modelScale, reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_105_bss_39C),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

    Word motionEntry[5], statusEntry[5];
    Word motionResource =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot18();
    Byte* motion = modules + 0xAE4;
    fn_27_CD8C8(motion, 0);
    fn_27_D2A38(motion + 0x20, 0);
    fn_105_8720(motion + 0x6C, motion);
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
        reinterpret_cast<IceAppendInterface*>(motion)->append(motionEntry);
        fn_27_AB18C(motionEntry, -1);
    }
    fn_27_C7470(motion + 0x88, motionResource, 1);
    if (lbl_105_bss_3B0 == 0) {
        fn_27_197C28(lbl_105_bss_3B4);
        __register_global_object(lbl_105_bss_3B4,
            reinterpret_cast<void*>(fn_27_82794), lbl_105_bss_4E8);
        lbl_105_bss_3B0 = 1;
    }
    Byte* motionA = lbl_105_bss_3B4;
    if (lbl_105_bss_3A8 == 0) {
        fn_27_197C08(lbl_105_bss_3AC);
        __register_global_object(lbl_105_bss_3AC,
            reinterpret_cast<void*>(fn_27_82754), lbl_105_bss_4DC);
        lbl_105_bss_3A8 = 1;
    }
    Byte* motionInstances;
    Byte* motionB = lbl_105_bss_3AC;
    if (lbl_105_bss_3A0 == 0) {
        fn_27_C94E0(lbl_105_bss_3A4);
        __register_global_object(lbl_105_bss_3A4,
            reinterpret_cast<void*>(fn_27_82A14), lbl_105_bss_4D0);
        lbl_105_bss_3A0 = 1;
    }
    motionInstances = getMotionInstances(motion);
    fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88,
        motionInstances, motionA, motionB, lbl_27_bss_9BC, lbl_105_bss_3A4,
        eventId(modules), 0, lbl_27_bss_DBC);
    reinterpret_cast<IceVirtualInterface*>(
        pointer(pointer(modules, 0x8D0), 4))->slot08();

    Byte* posture = modules + 0xCF0;
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3C) soPostureModuleImpl(
        articleAccesser(modules),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<IceVirtualInterface*>(posture + 0x3C)->slot38();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot28();
    fn_27_3513C(modules + 0xDA8, eventId(modules),
                articleAccesser(modules), lbl_27_bss_A48);

    Byte* transition;
    Word transitionData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot14();
    transition = modules + 0xDE4;
    fn_105_17DB8(transition, transitionData);
    fn_105_17DB8(transition + 0x10, transitionData);
    fn_27_B5048(transition + 0x20, transition, transition + 0x10,
                transition, articleAccesser(modules), lbl_27_bss_A48);

    int taskId;
    Byte* attack;
    unsigned char taskCategory =
        static_cast<unsigned char>(word(article, 0x2C) >> 7);
    taskId = word(article, 0x28);
    attack = modules + 0xE48;
    Byte attackPart[144];
    __ct__21soCollisionAttackPartFQ211soCollision8Categoryb(
        attackPart, soCollision::CategoryDefault, false);
    fn_27_CCE34(attack, 3, attackPart, 0);
    reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
    fn_27_CB6E0(attack + 0x1BC, 1, 0);
    IceAbsoluteAttackRecord absolute;
    absolute.initialize(constants->one);
    fn_27_C94AC(attack + 0x240, 0, &absolute);
    fn_105_17E10(&absolute, -1);
    new (attack + 0x244) soCollisionAttackModuleImpl(
        articleAccesser(modules), taskId,
        static_cast<gfTask::Category>(taskCategory),
        reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
        reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x1BC),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x240),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48),
        true);
    __ct__16soStopModuleImplFP16soModuleAccesser(
        modules + 0x1138, articleAccesser(modules));

    Word hitData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot1C();
    if (lbl_105_bss_3B8 == 0) {
        fn_27_197C18(lbl_105_bss_3BC);
        __register_global_object(lbl_105_bss_3BC,
            reinterpret_cast<void*>(fn_27_82B14), lbl_105_bss_4F4);
        lbl_105_bss_3B8 = 1;
    }
    fn_27_687F8(modules + 0x1164, articleAccesser(modules),
                lbl_105_bss_3BC, hitData);

    Byte* sound;
    Word soundData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot84();
    sound = modules + 0x116C;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData,
                1, 0, lbl_27_bss_A48);
    Byte* link = modules + 0x11D4;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, articleAccesser(modules), link);

    Word visibilityData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot20();
    fn_27_5AD88(modules + 0x1338, articleAccesser(modules), visibilityData, 1);
    eventId(modules);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot60();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot5C();
    Word workData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot54();
    fn_27_A1DA4(modules + 0x1350, articleAccesser(modules), workData);

    Word animEvent = eventId(modules);
    Byte* animCommand = modules + 0x1384;
    fn_27_711E4(animCommand, animEvent, animCommand + 0x24);
    fn_27_1AC390(animCommand + 0x24, 0);
    Byte* status;
    Word statusData =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot70();
    Word statusResource =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot24();
    status = modules + 0x1428;
    fn_27_C74BC(status, statusResource, 1);
    Byte* statusWork = status + 0x10;
    fn_105_9248(statusWork + 0x14, statusWork, 2, statusWork + 0x8,
                2, statusWork + 0x10, 1);
    reinterpret_cast<IceWorkInterface*>(statusWork + 0x14)->initialize();
    int i;
    Byte* statusArray = status + 0x48;
    fn_27_CD8C8(statusArray, 0);
    fn_27_1A1E04(statusArray + 0x20, 0);
    fn_105_8720(statusArray + 0x8C, statusArray);
    for (i = 0; i < 1; ++i) {
        fn_27_AB15C(statusEntry, i == 0 ? statusArray + 0x20 : 0);
        reinterpret_cast<IceAppendInterface*>(statusArray)->append(statusEntry);
        fn_27_AB18C(statusEntry, -1);
    }
    fn_27_1A2CEC(status + 0xEC, 0);
    word(status, 0xFC) = reinterpret_cast<Word>(status + 0x100);
    fn_27_1A29F0(status + 0x100, 1, lbl_105_data_A000, 0);
    reinterpret_cast<IceVirtualInterface*>(status + 0x100)->slot3C();
    fn_27_73930(status + 0x110, articleAccesser(modules), status,
        status + 0xEC, status + 0x24, status + 0xD4, status + 0xFC,
        statusData, 1, 1);

    Byte* kinetic = modules + 0x15E8;
    fn_27_1DBE08(kinetic, articleAccesser(modules),
                 kinetic + 0x30, kinetic + 0xB0);
    fn_27_1AEB6C(kinetic + 0x30, 0);
    word(kinetic, 0xB0) = reinterpret_cast<Word>(lbl_105_data_8BF4);
    Byte* kineticWork = modules + 0x169C;
    fn_105_9248(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C,
                6, kineticWork + 0x34, 1);
    reinterpret_cast<IceWorkInterface*>(kineticWork + 0x38)->initialize();

    Word effectD = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot38();
    Word effectC = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot34();
    Byte* parameterAccesser;
    Byte* command1;
    Byte* command2;
    Byte* command3;
    Byte* command4;
    Byte* effect;
    Word effectA;
    Word effectB = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot30();
    effectA = reinterpret_cast<IceVirtualInterface*>(descriptor)->slot2C();
    effect = modules + 0x16FC;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3C, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_105_data_A004, 0);
    if (lbl_105_bss_3C0 == 0) {
        fn_27_C948C(lbl_105_bss_3C4);
        __register_global_object(lbl_105_bss_3C4,
            reinterpret_cast<void*>(fn_27_82C54), lbl_105_bss_500);
        lbl_105_bss_3C0 = 1;
    }
    fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA,
        effect + 0x48, lbl_105_bss_3C4, effectB, lbl_27_bss_A48,
        effectC, -1, effectD, effect + 0x3C);

    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot58();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot40();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot3C();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot44();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot48();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot88();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot64();
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot6C();
    fn_27_5C600(modules + 0x1898, articleAccesser(modules));
    fn_27_63B94(modules + 0x18B0, articleAccesser(modules), 0);
    if (reinterpret_cast<IceVirtualInterface*>(modules + 0x16D4)->slot08() == 0) {
        Byte* work = pointer(pointer(modules, 0x8D0), 0x64);
        reinterpret_cast<IceArrayRegistry*>(work)->add(1, modules + 0x16D4);
    }

    Byte commandFlag0, commandFlag1, commandFlag2, commandFlag3, commandFlag4;
    short listenerId0, listenerId1;
    short commandId0, commandId1, commandId2, commandId3, commandId4;
    void* commandPair0[2];
    void* commandPair1[2];
    void* commandPair2[2];
    void* commandPair3[2];
    void* commandPair4[2];

    commands = modules + 0x18F4;
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(0, 2);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(0, 1);
    Word commandData0 =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(0, 0);
    fn_27_C7744(commands, commandData0, 1);
    fn_27_D22D0(commands + 0x14, 0);
    fn_105_9E0C(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag0 = 0;
    fn_105_9E28(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
                 constants->one, &commandFlag0);
    commandId0 = 1;
    commandPair0[0] = commands + 0xDC;
    commandPair0[1] = commands + 0xC0;
    Byte* commandRegistry0 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<IcePairRegistry*>(commandRegistry0)->add(
        commandPair0, &commandId0);

    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(1, 2);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(1, 1);
    Word commandData1 =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(1, 0);
    command1 = commands + 0x12C;
    fn_27_C7744(command1, commandData1, 1);
    fn_27_D22D0(command1 + 0x14, 0);
    fn_105_9E0C(command1 + 0xC0, command1, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag1 = 0;
    fn_105_9E28(command1 + 0xDC, eventId(modules), command1 + 0x14, 1, 1,
                 constants->one, &commandFlag1);
    commandId1 = 2;
    commandPair1[0] = command1 + 0xDC;
    commandPair1[1] = command1 + 0xC0;
    Byte* commandRegistry1 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<IcePairRegistry*>(commandRegistry1)->add(
        commandPair1, &commandId1);

    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(2, 2);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(2, 1);
    Word commandData2 =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(2, 0);
    command2 = commands + 0x258;
    fn_27_C7744(command2, commandData2, 1);
    fn_27_D22D0(command2 + 0x14, 0);
    fn_105_9E0C(command2 + 0xC0, command2, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag2 = 0;
    fn_105_9E28(command2 + 0xDC, eventId(modules), command2 + 0x14, 2, 1,
                 constants->one, &commandFlag2);
    commandId2 = 2;
    commandPair2[0] = command2 + 0xDC;
    commandPair2[1] = command2 + 0xC0;
    Byte* commandRegistry2 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<IcePairRegistry*>(commandRegistry2)->add(
        commandPair2, &commandId2);

    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(3, 2);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(3, 1);
    Word commandData3 =
        reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(3, 0);
    command3 = commands + 0x384;
    fn_27_C7744(command3, commandData3, 1);
    fn_27_D22D0(command3 + 0x14, 0);
    fn_105_9E0C(command3 + 0xC0, command3, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag3 = 0;
    fn_105_9E28(command3 + 0xDC, eventId(modules), command3 + 0x14, 3, 1,
                 constants->one, &commandFlag3);
    commandId3 = 2;
    commandPair3[0] = command3 + 0xDC;
    commandPair3[1] = command3 + 0xC0;
    Byte* commandRegistry3 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<IcePairRegistry*>(commandRegistry3)->add(
        commandPair3, &commandId3);

    command4 = commands + 0x4B0;
    commandFlag4 = 1;
    fn_105_9E28(command4, eventId(modules), command4 + 0x50, 4, 1,
                 constants->one, &commandFlag4);
    fn_27_D22D0(command4 + 0x50, 0);
    commandId4 = 4;
    commandPair4[0] = command4;
    commandPair4[1] = lbl_27_bss_8C4;
    Byte* commandRegistry4 = pointer(pointer(modules, 0x8D0), 0x6C);
    reinterpret_cast<IcePairRegistry*>(commandRegistry4)->add(
        commandPair4, &commandId4);

    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(5, 2);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(5, 1);
    reinterpret_cast<IceVirtualInterface*>(descriptor)->slot90(5, 0);

    fn_27_1DBA64(article + 0x1F70);
    IceFollowingVector vector0, vector1, vector2, vector3, vector4;
    fn_105_C1C0(&vector4, constants->followingFirst, constants->followingFirst, constants->followingFirst);
    fn_105_C1C0(&vector3, constants->followingSecond, constants->followingSecond, constants->followingSecond);
    fn_105_C1C0(&vector2, constants->followingFirst, constants->followingFirst, constants->followingFirst);
    fn_105_C1C0(&vector1, constants->followingSecond, constants->followingSecond, constants->followingSecond);
    fn_105_C1C0(&vector0, constants->followingSecond, constants->followingSecond, constants->followingSecond);

    following = article + 0x1FA8;
    fn_105_8058(following, 0);
    following[5] |= 0x80;
    following[6] = 0;
    word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
    *reinterpret_cast<IceFollowingVector*>(following + 8) = vector0;
    *reinterpret_cast<IceFollowingVector*>(following + 20) = vector1;
    *reinterpret_cast<IceFollowingVector*>(following + 32) = vector2;
    *reinterpret_cast<IceFollowingVector*>(following + 44) = vector3;
    *reinterpret_cast<IceFollowingVector*>(following + 56) = vector4;

    fn_27_1D90FC(article);
    listenerId0 = 1;
    Byte* listeners0 =
        pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<IceListenerRegistry*>(listeners0)->add(
        article + 0x1F70, 0, &listenerId0, -1);
    listenerId1 = 1;
    Byte* listeners1 =
        pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<IceListenerRegistry*>(listeners1)->add(
        following, 1, &listenerId1, -1);

    word(article, 0x3C) = reinterpret_cast<Word>(lbl_105_data_A008);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_105_data_A008 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_105_data_A008 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_105_data_A008 + 0x124);

    Byte* const& parameterData = pointer(parameters, 0x34);
    word(article, 0x1FEC) = reinterpret_cast<Word>(parameterData);
    parameterAccesser = article + 0x1FF0;
    fn_105_8058(parameterAccesser, 0);
    word(parameterAccesser, 12) = 0x99;
    word(parameterAccesser, 16) = 3999;
    word(parameterAccesser, 20) = 23999;
    word(parameterAccesser, 24) = 0;
    word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_105_data_A4E0);
    word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_105_data_A4E0 + 8);
    word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
    fn_27_1D8FC8(article, word(parameterAccesser, 24));
}

extern "C" void* fn_105_1EE8C(
    void* self, int owner, void* resource, Byte* parameters) {
    return new (self) IceBergWindArticle(owner, resource, parameters);
}
