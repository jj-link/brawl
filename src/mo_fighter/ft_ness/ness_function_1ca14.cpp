#include <new>
#pragma use_simple_stdpnew on

// ABI views of the out-of-line constructors used by this article builder.
// Their storage belongs to the containing object, not these declaration-only views.
class StageObject; class soModuleAccesser; class soEventUnit;
template<class T> class soInstanceUnit;
template<class T, int N> class soArrayVector;
template<class T> class soArray;
template<class T> class soInterpolation;
class Vec3f; class soModelNodeSetUp; class soModelVirtualNode;
class soEventObserverRegistrationDesc;
template<class T, class A> class soInstanceManagerSimpleEntity {
public: soInstanceManagerSimpleEntity();
private: unsigned long storage[46];
};
class soEventManageModuleImpl {
public: soEventManageModuleImpl(void*);
private: unsigned long storage[5];
};
template<class T, int N> class soEventUnitWithWorkArea {
public: soEventUnitWithWorkArea(short, short);
private: unsigned long storage[23];
};
class soDamageEventObserver;
class soSituationEventObserver;
class soCollisionHitEventObserver;
class soCollisionAttackEventObserver;
class soModelEventObserver;
template<> class soEventUnitWithWorkArea<soModelEventObserver, 4> {
public: soEventUnitWithWorkArea(short, short);
private: unsigned long storage[23];
};
class soCaptureEventObserver;
class soCollisionShieldEventObserver;
class soCollisionReflectorEventObserver;
class soCollisionAbsorberEventObserver;
class soCollisionSearchEventObserver;
class soItemManageEventObserver;
class soMotionEventObserver;
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public: soEventUnitWithWorkArea(short, short);
private: unsigned long storage[14];
};
template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public: soEventUnitWithWorkArea(short, short);
private: unsigned long storage[15];
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
class soModuleAccesser { public: soModuleAccesser(
    StageObject*, soResourceModule*, soModelModule*, soMotionModule*, soPostureModule*, soGroundModule*, soSituationModule*, void*, soCollisionAttackModule*, soCollisionHitModule*, soCollisionShieldModule*, soCollisionShieldModule*, soCollisionShieldModule*, void*, soCollisionSearchModule*, soDamageModule*, void*, void*, soStopModule*, void*, void*, soSoundModule*, soLinkModule*, soVisibilityModule*, soControllerModule*, soCameraModule*, soWorkManageModule*, void*, soAnimCmdModule*, soStatusModule*, void*, void*, soKineticModule*, soEventManageModule*, void*, soEffectModule*, void*, soAreaModule*, void*, void*, void*, void*, soShadowModule*, soItemManageModule*, soColorBlendModule*, void*, void*, soSlowModule*, void*, void*, soParamCustomizeModule*, void*); };
class Heaps { public: enum HeapType { HeapDefault }; };
class soHeapModuleImpl { public: soHeapModuleImpl(Heaps::HeapType, Heaps::HeapType, Heaps::HeapType, long); };
class soResourceIdAccesser;
class soResourceModuleImpl { public: soResourceModuleImpl(unsigned long, soResourceIdAccesser*, unsigned char); };
class soModelModuleImpl { public: soModelModuleImpl(soModuleAccesser*, soArray<soModelNodeSetUp>*, float, void*, soArray<soModelVirtualNode>*, soEventObserverRegistrationDesc*); };
class soPostureModuleImpl { public: soPostureModuleImpl(soModuleAccesser*, soArray<soInterpolation<Vec3f> >*, soEventObserverRegistrationDesc*); };
class soCollision { public: enum Category { CategoryDefault }; };
class soCollisionAttackPart {
    unsigned long storage[36];
public: soCollisionAttackPart(soCollision::Category, bool); ~soCollisionAttackPart();
};
class soCollisionGroup; class soCollisionAttackAbsolute;
class gfTask { public: enum Category { CategoryDefault }; };
class soCollisionAttackModuleImpl { public: soCollisionAttackModuleImpl(soModuleAccesser*, int, gfTask::Category, soArray<soCollisionAttackPart>*, soArray<soCollisionGroup>*, soArray<soCollisionAttackAbsolute>*, soEventObserverRegistrationDesc*, bool); };
class soStopModuleImpl { public: soStopModuleImpl(soModuleAccesser*); };

typedef unsigned char Byte;
typedef unsigned long Word;
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
class NessAppendInterface {
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
struct NessAbsoluteAttackRecord {
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
class NessStatusStorageInterface {
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
    virtual Word slot50() = 0;
    virtual Word slot54() = 0;
    virtual Word slot58() = 0;
    virtual Word slot5C() = 0;
    virtual Word slot60() = 0;
    virtual Word slot64() = 0;
    virtual Word slot68() = 0;
    virtual Word slot6C() = 0;
    virtual Word slot70() = 0;
    virtual Word slot74() = 0;
    virtual void add(void*, int) = 0;
};
#pragma always_inline on
#pragma inline_depth(8)
static inline Word& word(void* p, int offset) { return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset); }
static inline Byte* pointer(void* p, int offset) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset); }
static inline float& scalar(void* p, int offset) { return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset); }
template<class F> static inline F method(void* p, int offset) { return *reinterpret_cast<F*>(*reinterpret_cast<Byte**>(p) + offset); }
static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x5BC);
}
typedef Word (*Getter)(void*);
static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x694), 0x80) + 8;
    return reinterpret_cast<NessVirtualInterface*>(events)->slot24();
}
extern "C" {
extern Byte lbl_27_bss_6E8[];
void fn_27_1AA024(void*, short, short);
void fn_27_D7CB8(void*, short, short);
void fn_27_1A8A0C(void*, short, short);
extern const float lbl_101_rodata_130[];
extern Byte lbl_101_data_B028[];
extern Byte lbl_101_data_B2AC[];
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
extern Byte lbl_27_bss_640[];
extern Byte lbl_27_bss_654[];
extern Byte lbl_27_bss_66C[];
extern Byte lbl_101_data_93C8[];
extern Byte lbl_101_data_974C[];
extern signed char lbl_101_bss_2F8;
extern Byte lbl_101_bss_2FC[];
extern Byte lbl_101_bss_44C[];
extern Byte lbl_27_bss_A48[];
extern signed char lbl_101_bss_310;
extern Byte lbl_101_bss_314[];
extern Byte lbl_101_bss_470[];
extern signed char lbl_101_bss_308;
extern Byte lbl_101_bss_30C[];
extern Byte lbl_101_bss_464[];
extern signed char lbl_101_bss_300;
extern Byte lbl_101_bss_304[];
extern Byte lbl_101_bss_458[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern Byte lbl_27_bss_298[];
extern signed char lbl_101_bss_328;
extern Byte lbl_101_bss_32C[];
extern Byte lbl_101_bss_47C[];
extern signed char lbl_101_bss_3C0;
extern Byte lbl_101_bss_3C4[];
extern Byte lbl_101_bss_3A0[];
extern signed char lbl_101_bss_3B8;
extern Byte lbl_101_bss_3BC[];
extern Byte lbl_101_bss_394[];
extern Byte __vt__25soControllerModuleLinkRef[];
extern Byte lbl_101_data_B038[];
extern Byte lbl_101_data_94F4[];
extern Byte lbl_101_data_9F08[];
extern Byte lbl_101_data_A17C[];
extern Byte lbl_101_data_A22C[];
extern Byte lbl_101_data_A2BC[];
extern Byte lbl_101_data_A34C[];
extern Byte lbl_101_data_A3DC[];
extern Byte lbl_101_data_A46C[];
extern Byte lbl_101_data_A4FC[];
extern Byte lbl_101_data_A090[];
extern Byte lbl_101_data_B03C[];
extern signed char lbl_101_bss_330;
extern Byte lbl_101_bss_334[];
extern Byte lbl_101_bss_488[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_101_data_B040[];
extern Byte lbl_101_data_B518[];
extern Byte lbl_101_bss_43C[];
extern Byte lbl_27_bss_47C[];
extern Byte lbl_27_bss_344[];
extern Byte lbl_27_bss_55C[];
void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_1A8F7C(void*, short, short);
void fn_101_9210(void*, int);
void fn_27_19A55C(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_101_98D0(void*, void*);
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
void fn_27_CC060(void*, int, int);
void fn_27_2556C(void*, void*, void*, Word, void*);
void fn_27_3513C(void*, short, void*, void*);
void fn_101_156C4(void*, Word);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19C940(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_101_1571C(void*, short);
void fn_27_197C18(void*);
void fn_27_82B14(void*, short);
void fn_27_687F8(void*, void*, void*, Word);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, Word, int, int, void*);
void fn_27_CBAA0(void*, int, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_6A244(void*, void*, void*);
void fn_27_5AD88(void*, void*, Word, int);
void fn_27_197C48(void*);
void fn_27_82854(void*, short);
void fn_27_197C8C(void*);
void fn_27_82814(void*, short);
void fn_27_58264(void*, short, void*, void*);
void fn_27_A1DA4(void*, void*, Word);
void fn_27_711E4(void*, short, void*);
void fn_27_1AC390(void*, int);
void fn_27_C74BC(void*, Word, int);
void fn_101_A4CC(void*, void*, int, void*, int, void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A2CEC(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
void fn_27_1DBE08(void*, void*, void*, void*);
void fn_27_1AD79C(void*, int);
void fn_27_1A5690(void*, int);
void fn_27_19F5CC(void*, int, int);
void fn_101_18E28(void*, void*);
void fn_27_92F10(void*, void*, void*, void*, void*);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_C948C(void*);
void fn_27_82C54(void*, short);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_C319C(void*, void*);
void fn_27_C7744(void*, Word, int);
void fn_27_D22D0(void*, int);
void fn_101_B2BC(void*, void*, void*, void*);
void fn_101_B2D8(void*, short, void*, int, int, float, Byte*);
void fn_27_1DBA64(void*);
void fn_101_1303C(void*, float, float, float);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}
struct NessMotionEventStorage {
    Byte storage[236];
    inline NessMotionEventStorage(Word id) { fn_27_1A9430(this, static_cast<short>(id), 4); }
};
struct NessStatusEventStorage {
    Byte storage[332];
    inline NessStatusEventStorage(Word id) { fn_27_1AA024(this, static_cast<short>(id), 5); }
};
struct NessUnknownEventStorage {
    Byte storage[68];
    inline NessUnknownEventStorage(Word id) { fn_27_D5878(this, static_cast<short>(id), 7); }
};
struct NessSituationEventStorage {
    Byte storage[96];
    inline NessSituationEventStorage(Word id) {
        new (this) soEventUnitWithWorkArea<soSituationEventObserver, 4>(id, 8);
    }
};
struct NessUnknownEventStorage11 {
    Byte storage[72];
    inline NessUnknownEventStorage11(Word id) { fn_27_1AA878(this, static_cast<short>(id), 11); }
};
struct NessShieldEventStorage {
    Byte storage[64];
    inline NessShieldEventStorage(Word id) { fn_27_D7CB8(this, static_cast<short>(id), 14); }
};
struct NessEffectEventStorage {
    Byte storage[120];
    inline NessEffectEventStorage(Word id) { fn_27_1A8A0C(this, static_cast<short>(id), 18); }
};
struct NessArticleEventStorage {
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
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
    inline Word id() { return reinterpret_cast<NessVirtualInterface*>(&events)->slot54(); }
    inline NessArticleEventStorage() :
        manager(), events(this), motion(id()), status(id()), damage(id(), 6),
        unknown(id()), situation(id()), attack(id(), 1), model(id(), 9),
        unknown11(id()), shield(id()), effect(id()) { }
};
struct NessFollowingVector { Word components[3]; };
struct NessConstructorRegistrations {
    Byte commandFlags[5];
    short listenerId0;
    short listenerId1;
    short commandIds[5];
    void* commandPairs[5][2];
};

class NessFireArticle {
    Byte storage[0x1C08];
public:
    NessFireArticle(int, void*, Byte*);
};

static inline void initializeFireDescriptor(void* descriptor, Byte* article, void* resource, Byte* parameters) {
    Byte* resourceIds = pointer(resource, 4);
    Word resourceC = reinterpret_cast<NessVirtualInterface*>(resourceIds)->slot1C();
    Word resourceA = reinterpret_cast<NessVirtualInterface*>(resourceIds)->slot10();
    fn_27_1DC5E8(descriptor, 106, parameters, resourceA, 31, resourceC,
        static_cast<unsigned char>(word(parameters, 0)), -1,
        article + 0x1BDC, 0, 0, 0, 0, 0, 0, 0);
}

NessFireArticle::NessFireArticle(int owner, void* resource, Byte* parameters) {
    Byte* article = reinterpret_cast<Byte*>(this);
    const float* constants = lbl_101_rodata_130;
    Word descriptor[16];
    initializeFireDescriptor(descriptor, article, resource, parameters);
    fn_27_1D7EF0(article, lbl_101_data_B028, word(descriptor, 4), word(descriptor, 8),
        owner, resource, article + 0x688, 1);
    word(article, 0x3C) = reinterpret_cast<Word>(lbl_101_data_B2AC);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_101_data_B2AC + 0x124);

    Byte* modules = article + 0xCC;
    new (modules) NessArticleEventStorage;
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
    Word heapSize = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot80();
    Heaps::HeapType heapC = static_cast<Heaps::HeapType>(reinterpret_cast<NessVirtualInterface*>(descriptor)->slot7C());
    Heaps::HeapType heapB = static_cast<Heaps::HeapType>(reinterpret_cast<NessVirtualInterface*>(descriptor)->slot78());
    Heaps::HeapType heapA = static_cast<Heaps::HeapType>(reinterpret_cast<NessVirtualInterface*>(descriptor)->slot74());
    new (modules + 0x69C) soHeapModuleImpl(heapA, heapB, heapC, heapSize);
    Byte* customization = modules + 0x6B4;
    fn_101_9210(customization, 0);
    word(customization, 0) = reinterpret_cast<Word>(lbl_101_data_93C8);
    scalar(customization, 8) = constants[0];
    scalar(customization, 12) = constants[0];
    Word resourceFlag = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot10();
    Word resourceSet = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot0C();
    Word resourceKind = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot08();
    Byte* ids = modules + 0x6C4;
    fn_101_9210(ids, 0);
    word(ids, 0) = reinterpret_cast<Word>(lbl_101_data_974C);
    word(ids, 8) = resourceKind;
    word(ids, 12) = resourceKind;
    word(ids, 16) = resourceSet;
    *reinterpret_cast<short*>(ids + 20) = 0;
    *reinterpret_cast<short*>(ids + 22) = 0;
    new (ids + 24) soResourceModuleImpl(0, reinterpret_cast<soResourceIdAccesser*>(ids),
        static_cast<unsigned char>(resourceFlag));

    Word modelData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot68();
    float modelScale = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot50();
    Byte* model = modules + 0x6F4;
    fn_27_19A55C(model, 2, 0);
    if (lbl_101_bss_2F8 == 0) {
        fn_27_197C78(lbl_101_bss_2FC);
        __register_global_object(lbl_101_bss_2FC, reinterpret_cast<void*>(fn_27_82A94), lbl_101_bss_44C);
        lbl_101_bss_2F8 = 1;
    }
    new (model + 0x78) soModelModuleImpl(articleAccesser(modules), reinterpret_cast<soArray<soModelNodeSetUp>*>(model),
        modelScale, reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_101_bss_2FC),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    Word motionResource = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot18();
    Byte* motion = modules + 0x838;
    fn_27_CD8C8(motion, 0);
    fn_27_D2A38(motion + 0x20, 0);
    fn_101_98D0(motion + 0x6C, motion);
    for (int i = 0; i < 1; ++i) {
        Word entry[5];
        fn_27_AB15C(entry, i == 0 ? motion + 0x20 : 0);
        reinterpret_cast<NessAppendInterface*>(motion)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_C7470(motion + 0x88, motionResource, 1);
    if (lbl_101_bss_310 == 0) {
        fn_27_197C28(lbl_101_bss_314);
        __register_global_object(lbl_101_bss_314, reinterpret_cast<void*>(fn_27_82794), lbl_101_bss_470);
        lbl_101_bss_310 = 1;
    }
    Byte* motionA = lbl_101_bss_314;
    if (lbl_101_bss_308 == 0) {
        fn_27_197C08(lbl_101_bss_30C);
        __register_global_object(lbl_101_bss_30C, reinterpret_cast<void*>(fn_27_82754), lbl_101_bss_464);
        lbl_101_bss_308 = 1;
    }
    Byte* motionB = lbl_101_bss_30C;
    if (lbl_101_bss_300 == 0) {
        fn_27_C94E0(lbl_101_bss_304);
        __register_global_object(lbl_101_bss_304, reinterpret_cast<void*>(fn_27_82A14), lbl_101_bss_458);
        lbl_101_bss_300 = 1;
    }
    short motionEvent = eventId(modules);
    Byte* motionList = motion + 0x6C;
    fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88, motionList,
        motionA, motionB, lbl_27_bss_9BC, lbl_101_bss_304, motionEvent, 0, lbl_27_bss_DBC);
    reinterpret_cast<NessVirtualInterface*>(pointer(pointer(modules, 0x694), 4))->slot08();
    Byte* posture = modules + 0xA44;
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<NessVirtualInterface*>(posture + 0x3C)->slot38();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot28();
    fn_27_3513C(modules + 0xAFC, eventId(modules), articleAccesser(modules), lbl_27_bss_A48);
    Word transitionData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot14();
    Byte* transition = modules + 0xB38;
    fn_101_156C4(transition, transitionData);
    fn_101_156C4(transition + 0x10, transitionData);
    fn_27_B5048(transition + 0x20, transition, transition + 0x10,
        transition, articleAccesser(modules), lbl_27_bss_A48);

    unsigned char taskCategory = static_cast<unsigned char>(word(article, 0x2C) >> 7);
    int taskId = word(article, 0x28);
    Byte* attack = modules + 0xB9C;
    {
        soCollisionAttackPart attackPart(soCollision::CategoryDefault, false);
        fn_27_19C940(attack, 1, &attackPart, 0);
    }
    fn_27_CB6E0(attack + 0x9C, 1, 0);
    NessAbsoluteAttackRecord absolute;
    absolute.initialize(constants[0]);
    fn_27_C94AC(attack + 0x120, 0, &absolute);
    fn_101_1571C(&absolute, -1);
    new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules), taskId,
        static_cast<gfTask::Category>(taskCategory), reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
        reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
    new (modules + 0xD6C) soStopModuleImpl(articleAccesser(modules));
    Word hitData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot1C();
    if (lbl_101_bss_328 == 0) {
        fn_27_197C18(lbl_101_bss_32C);
        __register_global_object(lbl_101_bss_32C, reinterpret_cast<void*>(fn_27_82B14), lbl_101_bss_47C);
        lbl_101_bss_328 = 1;
    }
    fn_27_687F8(modules + 0xD98, articleAccesser(modules), lbl_101_bss_32C, hitData);
    Word soundData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot84();
    Byte* sound = modules + 0xDA0;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData, 1, 0, lbl_27_bss_A48);
    Byte* link = modules + 0xE08;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, articleAccesser(modules), link);
    Word visibilityData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot20();
    fn_27_5AD88(modules + 0xF6C, articleAccesser(modules), visibilityData, 1);
    eventId(modules);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot60();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot5C();
    Word workData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot54();
    fn_27_A1DA4(modules + 0xF84, articleAccesser(modules), workData);
    short animEventId = eventId(modules);
    Byte* animCommand = modules + 0xFB8;
    fn_27_711E4(animCommand, animEventId, animCommand + 0x24);
    fn_27_1AC390(animCommand + 0x24, 0);
    Word statusData = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot70();
    Word statusResource = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot24();
    Byte* status = modules + 0x105C;
    fn_27_C74BC(status, statusResource, 1);
    Byte* statusWork = status + 0x10;
    fn_101_A4CC(statusWork + 0x14, statusWork, 2, statusWork + 0x8, 2, statusWork + 0x10, 1);
    reinterpret_cast<NessVirtualInterface*>(statusWork + 0x14)->slot6C();
    Byte* statusArray = status + 0x48;
    fn_27_CD8C8(statusArray, 0);
    fn_27_1A1E04(statusArray + 0x20, 0);
    fn_101_98D0(statusArray + 0x8C, statusArray);
    for (int i = 0; i < 1; ++i) {
        Byte entry[20];
        fn_27_AB15C(entry, i == 0 ? statusArray + 0x20 : 0);
        reinterpret_cast<NessAppendInterface*>(statusArray)->append(entry);
        fn_27_AB18C(entry, -1);
    }
    fn_27_1A2CEC(status + 0xEC, 0);
    word(status, 0xFC) = reinterpret_cast<Word>(status + 0x100);
    fn_27_1A29F0(status + 0x100, 1, lbl_101_data_B038, 0);
    reinterpret_cast<NessVirtualInterface*>(status + 0x100)->slot3C();
    fn_27_73930(status + 0x110, articleAccesser(modules), status, status + 0xEC,
        status + 0x24, status + 0xD4, status + 0xFC, statusData, 1, 1);
    Byte* kinetic = modules + 0x121C;
    fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0x68);
    fn_27_1AD79C(kinetic + 0x30, 0);
    word(kinetic, 0x68) = reinterpret_cast<Word>(lbl_101_data_94F4);
    Byte* kineticWork = modules + 0x1288;
    fn_101_A4CC(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6, kineticWork + 0x34, 1);
    reinterpret_cast<NessVirtualInterface*>(kineticWork + 0x38)->slot6C();
    Word effectD = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot38();
    Word effectC = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot34();
    Word effectB = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot30();
    Word effectA = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot2C();
    Byte* effect = modules + 0x12E8;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3C, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_101_data_B03C, 0);
    if (lbl_101_bss_330 == 0) {
        fn_27_C948C(lbl_101_bss_334);
        __register_global_object(lbl_101_bss_334, reinterpret_cast<void*>(fn_27_82C54), lbl_101_bss_488);
        lbl_101_bss_330 = 1;
    }
    fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA, effect + 0x48,
        lbl_101_bss_334, effectB, lbl_27_bss_A48, effectC, -1, effectD, effect + 0x3C);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot58();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot40();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot3C();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot44();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot48();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot88();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot64();
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot6C();
    fn_27_5C600(modules + 0x1484, articleAccesser(modules));
    fn_27_63B94(modules + 0x149C, articleAccesser(modules), 0);
    if (reinterpret_cast<NessVirtualInterface*>(modules + 0x12C0)->slot08() == 0) {
        Byte* work = pointer(pointer(modules, 0x694), 0x64);
        reinterpret_cast<NessArrayRegistry*>(work)->add(1, modules + 0x12C0);
    }
    NessFollowingVector vector4, vector3, vector2, vector1, vector0;
    NessConstructorRegistrations registrations;
    Byte* commands = modules + 0x14E0;
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(0, 2);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(0, 1);
    Word commandData0 = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(0, 0);
    fn_27_C7744(commands, commandData0, 1);
    fn_27_D22D0(commands + 0x14, 0);
    fn_101_B2BC(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
    registrations.commandFlags[0] = 0;
    fn_101_B2D8(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
        constants[0], &registrations.commandFlags[0]);
    registrations.commandIds[0] = 1;
    registrations.commandPairs[0][0] = commands + 0xDC;
    registrations.commandPairs[0][1] = commands + 0xC0;
    Byte* commandRegistry0 = pointer(pointer(modules, 0x694), 0x6C);
    reinterpret_cast<NessPairRegistry*>(commandRegistry0)->add(registrations.commandPairs[0], &registrations.commandIds[0]);

    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(1, 2);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(1, 1);
    Word commandData1 = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(1, 0);
    Byte* command1 = commands + 0x12C;
    fn_27_C7744(command1, commandData1, 1);
    fn_27_D22D0(command1 + 0x14, 0);
    fn_101_B2BC(command1 + 0xC0, command1, lbl_27_bss_D8C, lbl_27_bss_D8C);
    registrations.commandFlags[1] = 0;
    fn_101_B2D8(command1 + 0xDC, eventId(modules), command1 + 0x14, 1, 1,
        constants[0], &registrations.commandFlags[1]);
    registrations.commandIds[1] = 2;
    registrations.commandPairs[1][0] = command1 + 0xDC;
    registrations.commandPairs[1][1] = command1 + 0xC0;
    Byte* commandRegistry1 = pointer(pointer(modules, 0x694), 0x6C);
    reinterpret_cast<NessPairRegistry*>(commandRegistry1)->add(registrations.commandPairs[1], &registrations.commandIds[1]);

    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(2, 2);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(2, 1);
    Word commandData2 = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(2, 0);
    Byte* command2 = commands + 0x258;
    fn_27_C7744(command2, commandData2, 1);
    fn_27_D22D0(command2 + 0x14, 0);
    fn_101_B2BC(command2 + 0xC0, command2, lbl_27_bss_D8C, lbl_27_bss_D8C);
    registrations.commandFlags[2] = 0;
    fn_101_B2D8(command2 + 0xDC, eventId(modules), command2 + 0x14, 2, 1,
        constants[0], &registrations.commandFlags[2]);
    registrations.commandIds[2] = 2;
    registrations.commandPairs[2][0] = command2 + 0xDC;
    registrations.commandPairs[2][1] = command2 + 0xC0;
    Byte* commandRegistry2 = pointer(pointer(modules, 0x694), 0x6C);
    reinterpret_cast<NessPairRegistry*>(commandRegistry2)->add(registrations.commandPairs[2], &registrations.commandIds[2]);

    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(3, 2);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(3, 1);
    Word commandData3 = reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(3, 0);
    Byte* command3 = commands + 0x384;
    fn_27_C7744(command3, commandData3, 1);
    fn_27_D22D0(command3 + 0x14, 0);
    fn_101_B2BC(command3 + 0xC0, command3, lbl_27_bss_D8C, lbl_27_bss_D8C);
    registrations.commandFlags[3] = 0;
    fn_101_B2D8(command3 + 0xDC, eventId(modules), command3 + 0x14, 3, 1,
        constants[0], &registrations.commandFlags[3]);
    registrations.commandIds[3] = 2;
    registrations.commandPairs[3][0] = command3 + 0xDC;
    registrations.commandPairs[3][1] = command3 + 0xC0;
    Byte* commandRegistry3 = pointer(pointer(modules, 0x694), 0x6C);
    reinterpret_cast<NessPairRegistry*>(commandRegistry3)->add(registrations.commandPairs[3], &registrations.commandIds[3]);

    Byte* command4 = commands + 0x4B0;
    registrations.commandFlags[4] = 1;
    fn_101_B2D8(command4, eventId(modules), command4 + 0x50, 4, 1,
        constants[0], &registrations.commandFlags[4]);
    fn_27_D22D0(command4 + 0x50, 0);
    registrations.commandIds[4] = 4;
    registrations.commandPairs[4][0] = command4;
    registrations.commandPairs[4][1] = lbl_27_bss_8C4;
    Byte* commandRegistry4 = pointer(pointer(modules, 0x694), 0x6C);
    reinterpret_cast<NessPairRegistry*>(commandRegistry4)->add(registrations.commandPairs[4], &registrations.commandIds[4]);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(5, 2);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(5, 1);
    reinterpret_cast<NessVirtualInterface*>(descriptor)->slot90(5, 0);

    fn_27_1DBA64(article + 0x1B5C);
    fn_101_1303C(&vector4, constants[1], constants[1], constants[1]);
    fn_101_1303C(&vector3, constants[2], constants[2], constants[2]);
    fn_101_1303C(&vector2, constants[1], constants[1], constants[1]);
    fn_101_1303C(&vector1, constants[2], constants[2], constants[2]);
    fn_101_1303C(&vector0, constants[2], constants[2], constants[2]);
    Byte* following = article + 0x1B94;
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
    registrations.listenerId0 = 1;
    Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<NessListenerRegistry*>(listeners0)->add(article + 0x1B5C, 0, &registrations.listenerId0, -1);
    registrations.listenerId1 = 1;
    Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
    reinterpret_cast<NessListenerRegistry*>(listeners1)->add(following, 1, &registrations.listenerId1, -1);
    word(article, 0x3C) = reinterpret_cast<Word>(lbl_101_data_B040);
    word(article, 0x40) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x64);
    word(article, 0x48) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x70);
    word(article, 0x54) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x84);
    word(article, 0x64) = reinterpret_cast<Word>(lbl_101_data_B040 + 0xDC);
    word(article, 0x70) = reinterpret_cast<Word>(lbl_101_data_B040 + 0xEC);
    word(article, 0x7C) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x100);
    word(article, 0x88) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x118);
    word(article, 0x90) = reinterpret_cast<Word>(lbl_101_data_B040 + 0x124);
    Byte* parameterData = pointer(parameters, 0x34);
    word(article, 0x1BD8) = reinterpret_cast<Word>(parameterData);
    Byte* parameterAccesser = article + 0x1BDC;
    fn_101_9210(parameterAccesser, 0);
    word(parameterAccesser, 12) = 106;
    word(parameterAccesser, 16) = 3999;
    word(parameterAccesser, 20) = 23999;
    word(parameterAccesser, 24) = 0;
    word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_101_data_B518);
    word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_101_data_B518 + 8);
    word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
    word(parameterAccesser, 32) = reinterpret_cast<Word>(parameterData + 4);
    word(parameterAccesser, 40) = reinterpret_cast<Word>(parameterData + 8);
    fn_27_1D8FC8(article, 0);
}
