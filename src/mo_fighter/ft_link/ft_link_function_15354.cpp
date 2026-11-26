#include <types.h>
#include <new>
#pragma use_simple_stdpnew on
class soEventUnit;
template<class T> class soInstanceUnit;
template<class T,s32 N> class soArrayVector;
template<class T,class A> class soInstanceManagerSimpleEntity;
template<class T,s32 C> class soEventUnitWithWorkArea;
template<> class soInstanceManagerSimpleEntity<soEventUnit*,soArrayVector<soInstanceUnit<soEventUnit*>,19> > { public: soInstanceManagerSimpleEntity(); private: u32 storage[46]; };
class soDamageEventObserver; template<> class soEventUnitWithWorkArea<soDamageEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soSituationEventObserver; template<> class soEventUnitWithWorkArea<soSituationEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionHitEventObserver; template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionAttackEventObserver; template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soModelEventObserver; template<> class soEventUnitWithWorkArea<soModelEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCaptureEventObserver; template<> class soEventUnitWithWorkArea<soCaptureEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionShieldEventObserver; template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionReflectorEventObserver; template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionAbsorberEventObserver; template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soCollisionSearchEventObserver; template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver,4> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[23]; };
class soItemManageEventObserver; template<> class soEventUnitWithWorkArea<soItemManageEventObserver,1> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[14]; };
class soMotionEventObserver; template<> class soEventUnitWithWorkArea<soMotionEventObserver,1> { public: soEventUnitWithWorkArea(s16,s16); private: u32 storage[15]; };
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#pragma force_active on
typedef unsigned char Byte;
typedef unsigned long Word;
class LinkVirtualInterface {
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
    virtual Heaps::HeapType slot74() = 0;
    virtual Heaps::HeapType slot78() = 0;
    virtual Heaps::HeapType slot7C() = 0;
    virtual s32 slot80() = 0;
    virtual Word slot84() = 0;
    virtual Word slot88() = 0;
    virtual Word slot8C() = 0;
    virtual Word slot90(int, int) = 0;
};
class LinkPairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};
class LinkListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};
class LinkArrayRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(int, void*) = 0;
};
class LinkAppendInterface {
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
struct LinkAbsoluteAttackRecord {
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
class LinkStatusStorageInterface {
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
static inline Byte* loadResourceIds(void* resource) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(resource) + 4); }
static inline Word& word(void* p, int offset) { return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset); }
static inline Byte* pointer(void* p, int offset) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset); }
static inline float& scalar(void* p, int offset) { return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset); }
static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x7F8);
}
static inline s16 eventId(Byte* modules) {
    soEventManageModule& events = *articleAccesser(modules)->m_enumerationStart->m_eventManageModule;
    return static_cast<soEventManager&>(events).getManageId();
}
struct LinkThunderConstants {
    float zero, followingFirst, followingSecond;
};
extern "C" {
extern const LinkThunderConstants lbl_93_rodata_B8;
extern Byte lbl_93_data_8FEC[];
extern Byte lbl_93_data_9270[];
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
extern Byte lbl_27_bss_604[];
extern Byte lbl_27_bss_614[];
extern Byte lbl_27_bss_628[];
extern Byte lbl_27_bss_654[];
extern Byte lbl_27_bss_66C[];
extern Byte lbl_93_data_8B74[];
extern Byte lbl_93_data_8CF8[];
extern signed char lbl_93_bss_238;
extern Byte lbl_93_bss_23C[];
extern Byte lbl_93_bss_288[];
extern Byte lbl_27_bss_A48[];
extern signed char lbl_93_bss_250;
extern Byte lbl_93_bss_254[];
extern Byte lbl_93_bss_2AC[];
extern signed char lbl_93_bss_248;
extern Byte lbl_93_bss_24C[];
extern Byte lbl_93_bss_2A0[];
extern signed char lbl_93_bss_240;
extern Byte lbl_93_bss_244[];
extern Byte lbl_93_bss_294[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern signed char lbl_93_bss_258;
extern Byte lbl_93_bss_25C[];
extern Byte lbl_93_bss_2B8[];
extern Byte lbl_93_data_8FFC[];
extern Byte lbl_93_data_8CA0[];
extern Byte lbl_93_data_9000[];
extern signed char lbl_93_bss_260;
extern Byte lbl_93_bss_264[];
extern Byte lbl_93_bss_2C4[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_8C4[];
extern Byte lbl_27_data_13730[];
extern Byte lbl_93_data_9004[];
extern Byte lbl_93_data_98BC[];
extern Byte lbl_27_bss_47C[];
extern Byte lbl_27_bss_344[];
void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_1A8F7C(void*, short, short);
void fn_93_1AC4(void*, int);
void fn_27_CBD88(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_93_2C68(void*, void*);
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
void fn_93_12C58(void*, Word);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19C940(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
void fn_93_12D0C(void*, short);
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
void fn_93_47AC(void*, void*, int, void*, int, void*, int);
void fn_27_1A1E04(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
void fn_27_1DBE08(void*, void*, void*, void*);
void fn_27_1AEB6C(void*, int);
void fn_27_92F10(void*, void*, void*, void*, void*);
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
void fn_93_8870(void*, void*, void*, void*);
void fn_93_888C(void*, short, void*, int, int, float, Byte*);
void fn_27_1DBA64(void*);
void fn_93_AC0C(void*, float, float, float);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}
extern "C" {
extern Byte lbl_27_bss_6E8[], lbl_27_bss_50DC[], lbl_27_bss_50EC[], lbl_27_bss_50FC[], lbl_27_bss_510C[], lbl_27_bss_511C[], lbl_27_bss_513C[];
void fn_27_CBAA0(void*,int,int); void fn_27_1A4D6C(void*,int);
void fn_27_1A4E70(void*,int); void fn_27_19EAA4(void*,int,int);
void* __dynamic_cast(void*,int,void*,void*,short);
void* fn_27_149B58(void*,Word,Byte*);
void fn_27_1DF5F8(void*,int,void*,void*,bool);
extern Byte lbl_93_data_94DC[],lbl_93_data_9738[],lbl_93_data_97DC[],lbl_93_data_9860[],lbl_93_data_9658[],lbl_93_data_30A4[],lbl_93_data_3BF8[],g_ftCommonDataAccesser[];
extern signed char lbl_93_bss_2DC;
extern Byte lbl_93_bss_2E0[],lbl_93_bss_2D0[];
void fn_27_197C68(void*); void fn_27_82B94(void*,short);
void fn_27_10158(void*,void*,Word,void*,int);
}
struct LinkMotionEventStorage {
    Word storage[59];
    inline LinkMotionEventStorage(Word id) { fn_27_1A9430(this, static_cast<short>(id), 4); }
};
struct LinkStatusEventStorage {
    Word storage[107];
    inline LinkStatusEventStorage(Word id) { fn_27_1AA1F4(this, static_cast<short>(id), 5); }
};
struct LinkUnknownEventStorage {
    Word storage[17];
    inline LinkUnknownEventStorage(Word id) { fn_27_D5878(this, static_cast<short>(id), 7); }
};
struct LinkUnknownEventStorage11 {
    Word storage[17];
    inline LinkUnknownEventStorage11(Word id) { fn_27_1AA878(this, static_cast<short>(id), 11); }
};
struct LinkArticleEventStorage {
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    LinkMotionEventStorage motion;
    LinkStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    LinkUnknownEventStorage unknown;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    LinkUnknownEventStorage11 unknown11;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;
    inline s16 id() { return events.getManageId(); }
    inline LinkArticleEventStorage() :
        manager(), events(this), motion(id()), status(id()), damage(id(), 6),
        unknown(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
        model(id(), 9), unknown11(id()), capture(id(), 13), shield(id(), 14),
        reflector(id(), 15), absorber(id(), 16), search(id(), 17), item(id(), 12),
        motion1(id(), 10) { }
};
struct LinkFollowingVector { Word components[3]; };
struct LinkProcessTable { void* entries[9]; };
class WorkView : public soGeneralWorkAbstract { public: virtual void clearWorkAll(); };
static inline Byte* linkHookshotName() {
    return lbl_93_data_8FEC;
}
static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}
#define DESCRIPTOR reinterpret_cast<LinkVirtualInterface*>(descriptor)
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
class LinkArticleStorage {
public:
    inline LinkArticleStorage(int owner, void* resource, Byte* parameters, Byte*& resourceIds) {
        Byte* article = reinterpret_cast<Byte*>(this);
        Byte* commands;
        Byte* following;
        Byte* control;
        const LinkThunderConstants* const constants = &lbl_93_rodata_B8;
        Byte flag0, flag1, flag2, flag3, flag4;
        Byte flagPair[2];
        short listenerId0, listenerId1;
        short commandId0, commandId1, commandId2, commandId3, commandId4;
        void* commandPair0[2];
        void* commandPair1[2];
        void* commandPair2[2];
        void* commandPair3[2];
        void* commandPair4[2];
        void* controllerArgs[2];
        LinkFollowingVector vector0, vector1, vector2, vector3, vector4;
        Word motionEntry[5], statusEntry[5];
        Byte descriptor[32];
        Byte descriptorTail[32];
        LinkAbsoluteAttackRecord absolute;
        Byte attackPart[144];
        resourceIds = *reinterpret_cast<Byte**>(static_cast<Byte*>(resource) + 4);
        fn_27_1DC5E8(descriptorTail - 32, 110, parameters,
            reinterpret_cast<LinkVirtualInterface*>(resourceIds)->slot10(),
            reinterpret_cast<LinkVirtualInterface*>(resourceIds)->slot18(),
            reinterpret_cast<LinkVirtualInterface*>(resourceIds)->slot1C(),
            static_cast<unsigned char>(word(parameters, 0)), -1,
            article + 0x380C, 0, 0, 0, 0, 0, 0, 0);
        Byte* const& articleName = linkHookshotName();
        fn_27_1D7EF0(article, articleName, word(descriptor, 4), word(descriptor, 8),
            owner, resource, article + 0x8C4, 1);
        INSTALL_ARTICLE_TABLE(lbl_93_data_9270);

        Byte* modules = article + 0xCC;
        new (modules) LinkArticleEventStorage;
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
            reinterpret_cast<soStatusModule*>(modules + 0x146C),
            lbl_27_bss_170, lbl_27_bss_188,
            reinterpret_cast<soKineticModule*>(modules + 0x151C),
            reinterpret_cast<soEventManageModule*>(modules + 0xB8),
            modules + 0x2D3C,
            reinterpret_cast<soEffectModule*>(modules + 0x2DD0),
            lbl_27_bss_584,
            reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
            lbl_27_bss_5B0, lbl_27_bss_5D8, modules + 0x2F10, lbl_27_bss_604,
            reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
            reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
            reinterpret_cast<soColorBlendModule*>(modules + 0x2F5C),
            lbl_27_bss_654, lbl_27_bss_66C,
            reinterpret_cast<soSlowModule*>(modules + 0x30B4),
            modules + 0x30CC, modules + 0x8D8,
            reinterpret_cast<soParamCustomizeModule*>(modules + 0x8F0),
            lbl_27_bss_6E8);

        Heaps::HeapType heapA, heapB, heapC;
        s32 heapSize;
        heapSize = DESCRIPTOR->slot80();
        heapC = static_cast<Heaps::HeapType>(DESCRIPTOR->slot7C());
        heapB = static_cast<Heaps::HeapType>(DESCRIPTOR->slot78());
        heapA = static_cast<Heaps::HeapType>(DESCRIPTOR->slot74());
        new (modules + 0x8D8) soHeapModuleImpl(heapA, heapB, heapC, heapSize);

        Byte* customization = modules + 0x8F0;
        fn_93_1AC4(customization, 0);
        word(customization, 0) = reinterpret_cast<Word>(lbl_93_data_8B74);
        scalar(customization, 8) = constants->zero;
        scalar(customization, 12) = constants->zero;
        Word resourceFlag = DESCRIPTOR->slot10();
        Word resourceSet = DESCRIPTOR->slot0C();
        Word resourceKind = DESCRIPTOR->slot08();
        Byte* ids = modules + 0x900;
        fn_93_1AC4(ids, 0);
        word(ids, 0) = reinterpret_cast<Word>(lbl_93_data_8CF8);
        word(ids, 8) = resourceKind;
        word(ids, 12) = resourceKind;
        word(ids, 16) = resourceSet;
        *reinterpret_cast<short*>(ids + 20) = 0;
        *reinterpret_cast<short*>(ids + 22) = 0;
        new (ids + 24) soResourceModuleImpl(0, reinterpret_cast<soResourceIdAccesser*>(ids),
            static_cast<unsigned char>(resourceFlag));

        Byte* model;
        Word modelData = DESCRIPTOR->slot68();
        float modelScale = DESCRIPTOR->slot50();
        model = modules + 0x930;
        fn_27_CBD88(model, 5, 0);
        INITIALIZE_GLOBAL(lbl_93_bss_238, lbl_93_bss_23C, fn_27_197C78, fn_27_82A94, lbl_93_bss_288);
        new (model + 0x114) soModelModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale,
            reinterpret_cast<void*>(modelData),
            reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_93_bss_23C),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));

        Word motionResource = DESCRIPTOR->slot18();
        Byte* motion = modules + 0xB10;
        fn_27_CD8C8(motion, 0);
        fn_27_D2A38(motion + 0x20, 0);
        fn_93_2C68(motion + 0x6C, motion);
        for (int i = 0; i < 1; ++i) {
            fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
            reinterpret_cast<LinkAppendInterface*>(motion)->append(motionEntry);
            fn_27_AB18C(motionEntry, -1);
        }
        fn_27_C7470(motion + 0x88, motionResource, 1);
        INITIALIZE_GLOBAL(lbl_93_bss_250, lbl_93_bss_254, fn_27_197C28, fn_27_82794, lbl_93_bss_2AC);
        Byte* motionA = lbl_93_bss_254;
        INITIALIZE_GLOBAL(lbl_93_bss_248, lbl_93_bss_24C, fn_27_197C08, fn_27_82754, lbl_93_bss_2A0);
        Byte* motionInstances;
        Byte* motionB = lbl_93_bss_24C;
        INITIALIZE_GLOBAL(lbl_93_bss_240, lbl_93_bss_244, fn_27_C94E0, fn_27_82A14, lbl_93_bss_294);
        motionInstances = getMotionInstances(motion);
        fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88,
            motionInstances, motionA, motionB, lbl_27_bss_9BC, lbl_93_bss_244,
            eventId(modules), 0, lbl_27_bss_DBC);
        reinterpret_cast<LinkVirtualInterface*>(pointer(pointer(modules, 0x8D0), 4))->slot08();

        Byte* posture = modules + 0xD1C;
        fn_27_19FF5C(posture, 1, 0);
        new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
            reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
        reinterpret_cast<LinkVirtualInterface*>(posture + 0x3C)->slot38();
        DESCRIPTOR->slot28();
        fn_27_3513C(modules + 0xDD4, eventId(modules), articleAccesser(modules), lbl_27_bss_A48);

        Byte* transition;
        Word transitionData = DESCRIPTOR->slot14();
        transition = modules + 0xE10;
        fn_93_12C58(transition, transitionData);
        fn_93_12C58(transition + 0x10, transitionData);
        fn_27_B5048(transition + 0x20, transition, transition + 0x10,
            transition, articleAccesser(modules), lbl_27_bss_A48);

        int taskId;
        Byte* attack;
        unsigned char taskCategory = static_cast<unsigned char>(word(article, 0x2C) >> 7);
        taskId = word(article, 0x28);
        attack = modules + 0xE74;
        new (attackPart) soCollisionAttackPart(static_cast<soCollision::Category>(0), false);
        fn_27_19C940(attack, 1, attackPart, 0);
        reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
        fn_27_CB6E0(attack + 0x9C, 1, 0);
        absolute.initialize(constants->zero);
        fn_27_C94AC(attack + 0x120, 0, &absolute);
        fn_93_12D0C(&absolute, -1);
        new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules), taskId,
            static_cast<gfTask::Category>(taskCategory),
            reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
            reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
            reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
            reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
        new (modules + 0x1044) soStopModuleImpl(articleAccesser(modules));

        Word hitData = DESCRIPTOR->slot1C();
        INITIALIZE_GLOBAL(lbl_93_bss_258, lbl_93_bss_25C, fn_27_197C18, fn_27_82B14, lbl_93_bss_2B8);
        fn_27_687F8(modules + 0x1070, articleAccesser(modules), lbl_93_bss_25C, hitData);
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
        fn_27_C74BC(status, statusResource, 9);
        Byte* statusWork = status + 0x10;
        fn_93_47AC(statusWork + 0x1C, statusWork, 3, statusWork + 0xC, 3, statusWork + 0x18, 1);
        reinterpret_cast<WorkView*>(statusWork + 0x1C)->clearWorkAll();
        int i;
        Byte* statusArray = status + 0x50;
        fn_27_CD8C8(statusArray, 0);
        fn_27_1A1E04(statusArray + 0x20, 0);
        fn_93_2C68(statusArray + 0x8C, statusArray);
        for (i = 0; i < 1; ++i) {
            fn_27_AB15C(statusEntry, i == 0 ? statusArray + 0x20 : 0);
            reinterpret_cast<LinkAppendInterface*>(statusArray)->append(statusEntry);
            fn_27_AB18C(statusEntry, -1);
        }
        fn_27_1A4D6C(status + 0xF4, 0);
        word(status, 0x124) = reinterpret_cast<Word>(status + 0x128);
        fn_27_1A29F0(status + 0x128, 1, lbl_93_data_8FFC, 0);
        reinterpret_cast<LinkVirtualInterface*>(status + 0x128)->slot3C();
        fn_27_73930(status + 0x138, articleAccesser(modules), status, status + 0xF4,
            status + 0x2C, status + 0xDC, status + 0x124, statusData, 9, 1);

        Byte* kinetic = modules + 0x151C;
        fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0xB0);
        fn_27_1AEB6C(kinetic + 0x30, 0);
        word(kinetic, 0xB0) = reinterpret_cast<Word>(lbl_93_data_8CA0);
        Byte* kineticWork = modules + 0x15D0;
        fn_93_47AC(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6, kineticWork + 0x34, 1);
        reinterpret_cast<WorkView*>(kineticWork + 0x38)->clearWorkAll();

        control = modules + 0x162C;
        fn_27_1A4E70(control, 0);
        fn_27_19EAA4(control + 0x10, 1, 0);
        Word fighterKind;
        Byte* input;
        Byte* outer = control + 0x2C;
        word(outer, 0) = reinterpret_cast<Word>(lbl_93_data_94DC);
        word(outer, 4) = reinterpret_cast<Word>(lbl_93_data_94DC + 0x10);
        Byte* controller = outer + 8;
        word(controller, 0) = reinterpret_cast<Word>(lbl_93_data_9738);
        Byte* second = controller + 4;
        word(second, 0) = reinterpret_cast<Word>(lbl_93_data_97DC);
        input = second + 8;
        word(input, 0) = reinterpret_cast<Word>(lbl_93_data_9860);
        flagPair[0] = 0;
        flagPair[1] = 0;
        fighterKind = word(__dynamic_cast(pointer(modules, 0x800), 0x3C, lbl_93_data_30A4, lbl_93_data_3BF8, 1), 0xC8);
        Byte* controllerSource = pointer(pointer(modules, 0x8D0), 0xC0);
        Byte* fighter = static_cast<Byte*>(__dynamic_cast(pointer(modules, 0x800), 0x3C, lbl_93_data_30A4, lbl_93_data_3BF8, 1));
        controllerArgs[0] = fighter + 0xC4;
        controllerArgs[1] = controllerSource;
        void* common = fn_27_149B58(g_ftCommonDataAccesser, fighterKind, &flagPair[1]);
        fn_27_1DF5F8(input + 4, 0, controllerArgs, common, false);
        word(controller, 0) = reinterpret_cast<Word>(lbl_93_data_9658);
        control[0x170C] = 0;
        fn_27_92F10(control + 0x1710, articleAccesser(modules), control, control + 0x2C, control + 0x10);

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
        effect = modules + 0x2D78;
        fn_27_CBEC8(effect, 1, 0);
        fn_27_C9FE4(effect + 0x3C, 1, 0);
        fn_27_D37BC(effect + 0x48, 1, lbl_93_data_9000, 0);
        INITIALIZE_GLOBAL(lbl_93_bss_260, lbl_93_bss_264, fn_27_C948C, fn_27_82C54, lbl_93_bss_2C4);
        fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA, effect + 0x48,
            lbl_93_bss_264, effectB, lbl_27_bss_A48, effectC, -1, effectD, effect + 0x3C);

        DESCRIPTOR->slot58();
        DESCRIPTOR->slot40();
        DESCRIPTOR->slot3C();
        DESCRIPTOR->slot44();
        Word colorData = DESCRIPTOR->slot48();
        INITIALIZE_GLOBAL(lbl_93_bss_2DC, lbl_93_bss_2E0, fn_27_197C68, fn_27_82B94, lbl_93_bss_2D0);
        fn_27_10158(modules + 0x2F10, articleAccesser(modules), colorData, lbl_93_bss_2E0, 1);
        DESCRIPTOR->slot88();
        DESCRIPTOR->slot64();
        fn_27_BEBB4(modules + 0x2F5C, articleAccesser(modules), -1, 0);
        DESCRIPTOR->slot6C();
        fn_27_5C600(modules + 0x30B4, articleAccesser(modules));
        fn_27_63B94(modules + 0x30CC, articleAccesser(modules), 0);
        if (reinterpret_cast<LinkVirtualInterface*>(modules + 0x1608)->slot08() == 0) {
            Byte* work = pointer(pointer(modules, 0x8D0), 0x64);
            reinterpret_cast<LinkArrayRegistry*>(work)->add(1, modules + 0x1608);
        }

        commands = modules + 0x3110;
        DESCRIPTOR->slot90(0, 2);
        DESCRIPTOR->slot90(0, 1);
        Word commandData0 = DESCRIPTOR->slot90(0, 0);
        fn_27_C7744(commands, commandData0, 9);
        fn_27_D22D0(commands + 0x14, 0);
        fn_93_8870(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flag0 = 0;
        fn_93_888C(commands + 0xDC, eventId(modules), commands + 0x14, 0, 0,
            constants->zero, &flag0);
        commandId0 = 1;
        commandPair0[0] = commands + 0xDC;
        commandPair0[1] = commands + 0xC0;
        Byte* commandRegistry0 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LinkPairRegistry*>(commandRegistry0)->add(commandPair0, &commandId0);

        DESCRIPTOR->slot90(1, 2);
        DESCRIPTOR->slot90(1, 1);
        Word commandData1 = DESCRIPTOR->slot90(1, 0);
        command1 = commands + 0x12C;
        fn_27_C7744(command1, commandData1, 1);
        fn_27_D22D0(command1 + 0x14, 0);
        fn_93_8870(command1 + 0xC0, command1, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flag1 = 0;
        fn_93_888C(command1 + 0xDC, eventId(modules), command1 + 0x14, 1, 1,
            constants->zero, &flag1);
        commandId1 = 2;
        commandPair1[0] = command1 + 0xDC;
        commandPair1[1] = command1 + 0xC0;
        Byte* commandRegistry1 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LinkPairRegistry*>(commandRegistry1)->add(commandPair1, &commandId1);

        DESCRIPTOR->slot90(2, 2);
        DESCRIPTOR->slot90(2, 1);
        Word commandData2 = DESCRIPTOR->slot90(2, 0);
        command2 = commands + 0x258;
        fn_27_C7744(command2, commandData2, 1);
        fn_27_D22D0(command2 + 0x14, 0);
        fn_93_8870(command2 + 0xC0, command2, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flag2 = 0;
        fn_93_888C(command2 + 0xDC, eventId(modules), command2 + 0x14, 2, 1,
            constants->zero, &flag2);
        commandId2 = 2;
        commandPair2[0] = command2 + 0xDC;
        commandPair2[1] = command2 + 0xC0;
        Byte* commandRegistry2 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LinkPairRegistry*>(commandRegistry2)->add(commandPair2, &commandId2);

        DESCRIPTOR->slot90(3, 2);
        DESCRIPTOR->slot90(3, 1);
        Word commandData3 = DESCRIPTOR->slot90(3, 0);
        command3 = commands + 0x384;
        fn_27_C7744(command3, commandData3, 1);
        fn_27_D22D0(command3 + 0x14, 0);
        fn_93_8870(command3 + 0xC0, command3, lbl_27_bss_D8C, lbl_27_bss_D8C);
        flag3 = 0;
        fn_93_888C(command3 + 0xDC, eventId(modules), command3 + 0x14, 3, 1,
            constants->zero, &flag3);
        commandId3 = 2;
        commandPair3[0] = command3 + 0xDC;
        commandPair3[1] = command3 + 0xC0;
        Byte* commandRegistry3 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LinkPairRegistry*>(commandRegistry3)->add(commandPair3, &commandId3);

        command4 = commands + 0x4B0;
        flag4 = 1;
        fn_93_888C(command4, eventId(modules), command4 + 0x50, 4, 1,
            constants->zero, &flag4);
        fn_27_D22D0(command4 + 0x50, 0);
        commandId4 = 4;
        commandPair4[0] = command4;
        commandPair4[1] = lbl_27_bss_8C4;
        Byte* commandRegistry4 = pointer(pointer(modules, 0x8D0), 0x6C);
        reinterpret_cast<LinkPairRegistry*>(commandRegistry4)->add(commandPair4, &commandId4);
        DESCRIPTOR->slot90(5, 2);
        DESCRIPTOR->slot90(5, 1);
        DESCRIPTOR->slot90(5, 0);

        fn_27_1DBA64(article + 0x378C);
        fn_93_AC0C(&vector4, constants->followingFirst, constants->followingFirst, constants->followingFirst);
        fn_93_AC0C(&vector3, constants->followingSecond, constants->followingSecond, constants->followingSecond);
        fn_93_AC0C(&vector2, constants->followingFirst, constants->followingFirst, constants->followingFirst);
        fn_93_AC0C(&vector1, constants->followingSecond, constants->followingSecond, constants->followingSecond);
        fn_93_AC0C(&vector0, constants->followingSecond, constants->followingSecond, constants->followingSecond);
        following = article + 0x37C4;
        fn_93_1AC4(following, 0);
        following[5] |= 0x80;
        following[6] = 0;
        word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
        *reinterpret_cast<LinkFollowingVector*>(following + 8) = vector0;
        *reinterpret_cast<LinkFollowingVector*>(following + 20) = vector1;
        *reinterpret_cast<LinkFollowingVector*>(following + 32) = vector2;
        *reinterpret_cast<LinkFollowingVector*>(following + 44) = vector3;
        *reinterpret_cast<LinkFollowingVector*>(following + 56) = vector4;
        fn_27_1D90FC(article);

        listenerId0 = 1;
        Byte* listeners0 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<LinkListenerRegistry*>(listeners0)->add(article + 0x378C, 0, &listenerId0, -1);
        listenerId1 = 1;
        Byte* listeners1 = pointer(pointer(pointer(article, 0x60), 0xD8), 0x7C);
        reinterpret_cast<LinkListenerRegistry*>(listeners1)->add(following, 1, &listenerId1, -1);

        INSTALL_ARTICLE_TABLE(lbl_93_data_9004);
        Byte* const& parameterData = pointer(parameters, 0x34);
        word(article, 0x3808) = reinterpret_cast<Word>(parameterData);
        parameterAccesser = article + 0x380C;
        fn_93_1AC4(parameterAccesser, 0);
        word(parameterAccesser, 12) = 110;
        word(parameterAccesser, 16) = 3999;
        word(parameterAccesser, 20) = 23999;
        word(parameterAccesser, 24) = 0;
        word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_93_data_98BC);
        word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_93_data_98BC + 8);
        word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
        word(parameterAccesser, 32) = reinterpret_cast<Word>(parameterData + 12);
        word(parameterAccesser, 36) = reinterpret_cast<Word>(parameterData + 16);
        word(parameterAccesser, 44) = reinterpret_cast<Word>(parameterData + 4);
        word(parameterAccesser, 48) = reinterpret_cast<Word>(parameterData + 8);
        const LinkProcessTable& table = LinkProcessTable();
        const_cast<LinkProcessTable&>(table).entries[1] = lbl_27_bss_50DC;
        const_cast<LinkProcessTable&>(table).entries[3] = lbl_27_bss_50EC;
        const_cast<LinkProcessTable&>(table).entries[4] = lbl_27_bss_50FC;
        const_cast<LinkProcessTable&>(table).entries[5] = lbl_27_bss_510C;
        const_cast<LinkProcessTable&>(table).entries[6] = lbl_27_bss_511C;
        const_cast<LinkProcessTable&>(table).entries[7] = lbl_27_bss_513C;
        Byte* statusModule = pointer(pointer(pointer(article, 0x60), 0xD8), 0x70);
        reinterpret_cast<LinkStatusStorageInterface*>(statusModule)->add(reinterpret_cast<void**>(descriptorTail + 32), 9);
        fn_27_1D8FC8(article, 0);
    }
};
#undef DESCRIPTOR
#undef INITIALIZE_GLOBAL
#undef INSTALL_ARTICLE_TABLE
extern "C" void* fn_93_15354(Byte* article, int owner, void* resource, Byte* parameters) {
    Byte* resourceIds;
    new (article) LinkArticleStorage(owner, resource, parameters, resourceIds);
    return article;
}
