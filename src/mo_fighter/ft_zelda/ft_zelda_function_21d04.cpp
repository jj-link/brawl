#include <new>
#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/work/so_general_work.h>

#pragma use_simple_stdpnew on
#pragma force_active on

typedef u8 Byte;
typedef u32 Word;

extern "C" {
void fn_27_1A9430(void*, short, short);
void fn_27_1AA1F4(void*, short, short);
void fn_27_D5878(void*, short, short);
void fn_27_1AA878(void*, short, short);
void fn_27_1A8F7C(void*, short, short);
void fn_27_CBD88(void*, int, int);
void fn_27_197C78(void*);
void fn_27_82A94(void*, short);
void fn_27_197C28(void*);
void fn_27_82794(void*, short);
void fn_27_197C08(void*);
void fn_27_82754(void*, short);
void fn_27_C94E0(void*);
void fn_27_82A14(void*, short);
void fn_27_197C18(void*);
void fn_27_82B14(void*, short);
void fn_27_C948C(void*);
void fn_27_82C54(void*, short);
void fn_27_197C68(void*);
void fn_27_82B94(void*, short);
void __register_global_object(void*, void*, void*);
void fn_27_1DC5E8(void*, int, void*, Word, Word, Word, unsigned char, int,
                 void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, Word, Word, int, void*, void*, int);
void fn_27_CD8C8(void*, int);
void fn_27_D2A38(void*, int);
void fn_27_AB15C(void*, void*);
void fn_27_AB18C(void*, short);
void fn_27_C7470(void*, Word, int);
void fn_27_13844(void*, void*, void*, void*, void*, void*, void*, void*, short, int, void*);
void fn_27_19FF5C(void*, int, int);
void fn_27_3513C(void*, short, void*, void*);
void fn_27_B5048(void*, void*, void*, void*, void*, void*);
void fn_27_19C940(void*, int, void*, int);
void fn_27_CB6E0(void*, int, int);
void fn_27_C94AC(void*, int, void*);
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
void fn_27_1A4D6C(void*, int);
void fn_27_1A29F0(void*, int, void*, int);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, Word, int, int);
void fn_27_1DBE08(void*, void*, void*, void*);
void fn_27_1AEB6C(void*, int);
void fn_27_CBEC8(void*, int, int);
void fn_27_C9FE4(void*, int, int);
void fn_27_D37BC(void*, int, void*, int);
void fn_27_9747C(void*, void*, void*, Word, void*, void*, Word, void*, Word, int, Word, void*);
void fn_27_10158(void*, void*, Word, void*, int);
void fn_27_BEBB4(void*, void*, int, int);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_C319C(void*, void*);
void fn_27_C7744(void*, Word, int);
void fn_27_D22D0(void*, int);
void fn_27_1DBA64(void*);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
void fn_104_7858(void*, int);
void fn_104_7F18(void*, void*);
void fn_104_121F8(void*, void*);
void fn_104_121E8(void*, float, float, float);
void fn_104_12250(void*, short);
void fn_104_8ADC(void*, void*, int, void*, int, void*, int);
void fn_104_95F0(void*, void*, void*, void*);
void fn_104_960C(void*, short, void*, int, int, float, void*);
}

typedef soArrayVector<soInstanceUnit<soEventUnit*>, 19> ZeldaEventUnits;
template<> class soInstanceManagerSimpleEntity<soEventUnit*, ZeldaEventUnits> {
public:
    soInstanceManagerSimpleEntity();
private:
    Word storage[46];
};
template<> class soEventUnitWithWorkArea<soDamageEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soSituationEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCaptureEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[23];
};
template<> class soEventUnitWithWorkArea<soItemManageEventObserver, 1> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[14];
};
template<> class soEventUnitWithWorkArea<soMotionEventObserver, 1> {
public:
    soEventUnitWithWorkArea(s16, s16);
private:
    Word storage[15];
};

class ZeldaVirtualInterface {
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
class ZeldaPairRegistry {
public:
    virtual Word slot08() = 0;
    virtual void add(void*, short*) = 0;
};
class ZeldaListenerRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(void*, int, short*, short) = 0;
};
class ZeldaArrayRegistry {
public:
    virtual Word slot08() = 0;
    virtual Word slot0C() = 0;
    virtual Word slot10() = 0;
    virtual void add(int, void*) = 0;
};
class ZeldaAppendInterface {
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

struct ZeldaWorkPrefix {
    Word state[2];
};

class ZeldaGeneralWorkSimple : private ZeldaWorkPrefix {
public:
    virtual void slot08() = 0;
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual void slot28() = 0;
    virtual void slot2C() = 0;
    virtual void slot30() = 0;
    virtual void slot34() = 0;
    virtual void slot38() = 0;
    virtual void slot3C() = 0;
    virtual void slot40() = 0;
    virtual void slot44() = 0;
    virtual void slot48() = 0;
    virtual void slot4C() = 0;
    virtual void slot50() = 0;
    virtual void slot54() = 0;
    virtual void slot58() = 0;
    virtual void slot5C() = 0;
    virtual void slot60() = 0;
    virtual void slot64() = 0;
    virtual void slot68() = 0;
    virtual void clearWorkAll() = 0;
};

class ZeldaStatusStorageInterface {
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
struct ZeldaVec { Word components[3]; };
struct ZeldaConstants { float one, negOne, zero; };

class ZeldaMotionEventStorage {
public:
    Word storage[59];
    inline ZeldaMotionEventStorage(Word id) { fn_27_1A9430(this, static_cast<short>(id), 4); }
};
class ZeldaStatusEventStorage {
public:
    Word storage[107];
    inline ZeldaStatusEventStorage(Word id) { fn_27_1AA1F4(this, static_cast<short>(id), 5); }
};
class ZeldaUnknownEventStorage {
public:
    Word storage[17];
    inline ZeldaUnknownEventStorage(Word id) { fn_27_D5878(this, static_cast<short>(id), 7); }
};
class ZeldaUnknownEventStorage11 {
public:
    Word storage[17];
    inline ZeldaUnknownEventStorage11(Word id) { fn_27_1AA878(this, static_cast<short>(id), 11); }
};
class ZeldaModelEventStorage {
public:
    Word storage[26];
    inline ZeldaModelEventStorage(Word id) { fn_27_1A8F7C(this, static_cast<short>(id), 9); }
};
class ZeldaArticleEventStorage {
public:
    soInstanceManagerSimpleEntity<soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    ZeldaMotionEventStorage motion;
    ZeldaStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    ZeldaUnknownEventStorage unknown;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    ZeldaModelEventStorage model;
    ZeldaUnknownEventStorage11 unknown11;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;
    inline Word id() { return reinterpret_cast<ZeldaVirtualInterface*>(&events)->slot54(); }
    inline ZeldaArticleEventStorage() : manager(), events(this), motion(id()), status(id()),
        damage(id(), 6), unknown(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
        model(id()), unknown11(id()), capture(id(), 13), shield(id(), 14), reflector(id(), 15),
        absorber(id(), 16), search(id(), 17), item(id(), 12), motion1(id(), 10) { }
};

extern "C" {
extern const Byte lbl_104_rodata_1A0[];
extern Byte lbl_104_data_CB64[];
extern Byte lbl_104_data_CDE8[];
extern Byte lbl_104_data_CB74[];
extern Byte lbl_104_data_CB78[];
extern Byte lbl_104_data_CB7C[];
extern Byte lbl_104_data_7E60[];
extern Byte lbl_104_data_7FC0[];
extern Byte lbl_104_data_7F14[];
extern Byte lbl_104_data_D054[];
extern Byte lbl_27_data_13730[];
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
extern Byte lbl_27_bss_604[];
extern Byte lbl_27_bss_614[];
extern Byte lbl_27_bss_628[];
extern Byte lbl_27_bss_654[];
extern Byte lbl_27_bss_66C[];
extern Byte lbl_27_bss_510C[];
extern Byte lbl_27_bss_511C[];
extern Byte lbl_27_bss_513C[];
extern Byte lbl_27_bss_516C[];
extern Byte lbl_27_bss_A48[];
extern Byte lbl_27_bss_D8C[];
extern Byte lbl_27_bss_DBC[];
extern Byte lbl_27_bss_9BC[];
extern Byte lbl_27_bss_8C4[];
extern signed char lbl_104_bss_270;
extern Byte lbl_104_bss_274[];
extern signed char lbl_104_bss_278;
extern Byte lbl_104_bss_27C[];
extern signed char lbl_104_bss_280;
extern Byte lbl_104_bss_284[];
extern signed char lbl_104_bss_288;
extern Byte lbl_104_bss_28C[];
extern signed char lbl_104_bss_290;
extern Byte lbl_104_bss_294[];
extern signed char lbl_104_bss_2A8;
extern Byte lbl_104_bss_2AC[];
extern Byte lbl_104_bss_5AC[];
extern Byte lbl_104_bss_5B8[];
extern Byte lbl_104_bss_5C4[];
extern Byte lbl_104_bss_5D0[];
extern Byte lbl_104_bss_5DC[];
extern Byte lbl_104_bss_5E8[];
extern Byte lbl_104_bss_5F4[];
extern signed char lbl_104_bss_600;
extern Byte lbl_104_bss_604[];
extern Byte lbl_104_bss_614[];
extern Byte lbl_104_bss_624[];
extern Byte lbl_104_bss_634[];
extern Byte lbl_104_bss_644[];
extern Byte lbl_104_bss_654[];
}

#pragma always_inline on
#pragma inline_depth(8)
static inline Word& word(void* p, int offset) { return *reinterpret_cast<Word*>(static_cast<Byte*>(p) + offset); }
static inline Byte* pointer(void* p, int offset) { return *reinterpret_cast<Byte**>(static_cast<Byte*>(p) + offset); }
static inline float& scalar(void* p, int offset) { return *reinterpret_cast<float*>(static_cast<Byte*>(p) + offset); }

static inline soModuleAccesser* articleAccesser(Byte* modules) {
    return reinterpret_cast<soModuleAccesser*>(modules + 0x804);
}
static inline Word eventId(Byte* modules) {
    Byte* events = pointer(pointer(modules, 0x8DC), 0x80) + 8;
    return reinterpret_cast<ZeldaVirtualInterface*>(events)->slot24();
}

static inline Byte* getMotionInstances(Byte* motion) {
    return motion + 0x6C;
}

static inline Byte* sheikIronWireName() {
    return lbl_104_data_CB64;
}

extern "C" Byte* fn_104_21D04(Byte* self, void* a2, Byte* a3, Byte* a4) {
    const ZeldaConstants* constants = reinterpret_cast<const ZeldaConstants*>(lbl_104_rodata_1A0);
    Byte* following;
    Byte* commands;
    struct ArticleLocals {
        Byte flags[6];
        short listener[2];
        short ids[5];
        void* pairs[5][2];
        ZeldaVec vectors[5];
        Word motion[5];
        Word status[5];
        Word data[16];
        void* listeners[9];
        Word attack[sizeof(soCollisionAttackAbsolute) / sizeof(Word)];
        Word attackPartStorage[36];
    } locals;
#define descriptor locals.data
#define motionEntry locals.motion
#define statusEntry locals.status
#define attackPart locals.attackPartStorage
#define absolute (*reinterpret_cast<soCollisionAttackAbsolute*>(locals.attack))
#define commandFlag0 locals.flags[0]
#define commandFlag1 locals.flags[1]
#define commandFlag2 locals.flags[2]
#define commandFlag3 locals.flags[3]
#define commandFlag4 locals.flags[4]
#define commandId0 locals.ids[0]
#define commandId1 locals.ids[1]
#define commandId2 locals.ids[2]
#define commandId3 locals.ids[3]
#define commandId4 locals.ids[4]
#define commandPair0 locals.pairs[0]
#define commandPair1 locals.pairs[1]
#define commandPair2 locals.pairs[2]
#define commandPair3 locals.pairs[3]
#define commandPair4 locals.pairs[4]
#define vector0 locals.vectors[0]
#define vector1 locals.vectors[1]
#define vector2 locals.vectors[2]
#define vector3 locals.vectors[3]
#define vector4 locals.vectors[4]
#define listenerId0 locals.listener[0]
#define listenerId1 locals.listener[1]
#define listenerList locals.listeners
    {
    ZeldaVirtualInterface* resourceIds = reinterpret_cast<ZeldaVirtualInterface*>(pointer(a3, 4));
    fn_27_1DC5E8(descriptor, 0x46, a4,
        resourceIds->slot10(), resourceIds->slot18(), resourceIds->slot1C(),
        static_cast<unsigned char>(word(a4, 0)), -1, self + 0x20E8, 0, 0, 0, 0, 0, 0, 0);
    }
    Byte* const& articleName = sheikIronWireName();
    fn_27_1D7EF0(self, articleName, word(descriptor, 4), word(descriptor, 8),
        reinterpret_cast<int>(a2), a3, self + 0x8D0, 1);
    word(self, 0x3C) = reinterpret_cast<Word>(lbl_104_data_CDE8);
    word(self, 0x40) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x64);
    word(self, 0x48) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x70);
    word(self, 0x54) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x84);
    word(self, 0x64) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0xDC);
    word(self, 0x70) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0xEC);
    word(self, 0x7C) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x100);
    word(self, 0x88) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x118);
    word(self, 0x90) = reinterpret_cast<Word>(lbl_104_data_CDE8 + 0x124);

    Byte* modules = self + 0xCC;
    struct ModuleStorage {
        static inline void initialize(Byte* modules, Byte* self, ArticleLocals& locals,
                                      const ZeldaConstants* constants) {
    new (modules) ZeldaArticleEventStorage;
    new (modules + 0x804) soModuleAccesser(
        reinterpret_cast<StageObject*>(self),
        reinterpret_cast<soResourceModule*>(modules + 0x924),
        reinterpret_cast<soModelModule*>(modules + 0xA50),
        reinterpret_cast<soMotionModule*>(modules + 0xBB8),
        reinterpret_cast<soPostureModule*>(modules + 0xD64),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(modules + 0xDE0),
        modules + 0xE3C,
        reinterpret_cast<soCollisionAttackModule*>(modules + 0xFA4),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4, lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(modules + 0x1050),
        lbl_27_bss_424, modules + 0x107C,
        reinterpret_cast<soSoundModule*>(modules + 0x1090),
        reinterpret_cast<soLinkModule*>(modules + 0x11FC),
        reinterpret_cast<soVisibilityModule*>(modules + 0x1250),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(modules + 0x1268),
        lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(modules + 0x129C),
        reinterpret_cast<soStatusModule*>(modules + 0x1478),
        lbl_27_bss_170, lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(modules + 0x1528),
        reinterpret_cast<soEventManageModule*>(modules + 0xB8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(modules + 0x1694),
        lbl_27_bss_584,
        reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0, lbl_27_bss_5D8, modules + 0x17D4, lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(modules + 0x1820),
        lbl_27_bss_654, lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(modules + 0x1978),
        modules + 0x1990, modules + 0x8E4,
        reinterpret_cast<soParamCustomizeModule*>(modules + 0x8FC),
        modules + 0x19D0);
    Heaps::HeapType heapA, heapB, heapC;
    Word heapSize;
    heapSize = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot80();
    heapC = static_cast<Heaps::HeapType>(reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot7C());
    heapB = static_cast<Heaps::HeapType>(reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot78());
    heapA = static_cast<Heaps::HeapType>(reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot74());
    new (modules + 0x8E4) soHeapModuleImpl(heapA, heapB, heapC, heapSize);
    Byte* customization = modules + 0x8FC;
    fn_104_7858(customization, 0);
    word(customization, 0) = reinterpret_cast<Word>(lbl_104_data_7E60);
    scalar(customization, 8) = constants->one;
    scalar(customization, 12) = constants->one;
    Word resourceFlag = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot10();
    Word resourceSet = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot0C();
    Word resourceKind = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot08();
    Byte* ids = modules + 0x90C;
    fn_104_7858(ids, 0);
    word(ids, 0) = reinterpret_cast<Word>(lbl_104_data_7FC0);
    word(ids, 8) = resourceKind;
    word(ids, 12) = resourceKind;
    word(ids, 16) = resourceSet;
    *reinterpret_cast<short*>(ids + 20) = 0;
    *reinterpret_cast<short*>(ids + 22) = 0;
    new (ids + 24) soResourceModuleImpl(0, reinterpret_cast<soResourceIdAccesser*>(ids),
        static_cast<unsigned char>(resourceFlag));

    Byte* model;
    Word modelData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot68();
    float modelScale = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot50();
    model = modules + 0x93C;
    fn_27_CBD88(model, 5, 0);
    if (lbl_104_bss_270 == 0) {
        fn_27_197C78(lbl_104_bss_274);
        __register_global_object(lbl_104_bss_274, reinterpret_cast<void*>(fn_27_82A94), lbl_104_bss_5AC);
        lbl_104_bss_270 = 1;
    }
    new (model + 0x114) soModelModuleImpl(articleAccesser(modules),
        reinterpret_cast<soArray<soModelNodeSetUp>*>(model), modelScale,
        reinterpret_cast<void*>(modelData),
        reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_104_bss_274),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    Word motionResource = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot18();
    Byte* motion = modules + 0xB1C;
    fn_27_CD8C8(motion, 0);
    fn_27_D2A38(motion + 0x20, 0);
    fn_104_7F18(motion + 0x6C, motion);
    for (int i = 0; i < 1; ++i) {
        fn_27_AB15C(motionEntry, i == 0 ? motion + 0x20 : 0);
        reinterpret_cast<ZeldaAppendInterface*>(motion)->append(motionEntry);
        fn_27_AB18C(motionEntry, -1);
    }
    fn_27_C7470(motion + 0x88, motionResource, 3);
    if (lbl_104_bss_288 == 0) {
        fn_27_197C28(lbl_104_bss_28C);
        __register_global_object(lbl_104_bss_28C, reinterpret_cast<void*>(fn_27_82794), lbl_104_bss_5D0);
        lbl_104_bss_288 = 1;
    }
    Byte* motionA = lbl_104_bss_28C;
    if (lbl_104_bss_280 == 0) {
        fn_27_197C08(lbl_104_bss_284);
        __register_global_object(lbl_104_bss_284, reinterpret_cast<void*>(fn_27_82754), lbl_104_bss_5C4);
        lbl_104_bss_280 = 1;
    }
    Byte* motionSequence;
    Byte* motionB = lbl_104_bss_284;
    if (lbl_104_bss_278 == 0) {
        fn_27_C94E0(lbl_104_bss_27C);
        __register_global_object(lbl_104_bss_27C, reinterpret_cast<void*>(fn_27_82A14), lbl_104_bss_5B8);
        lbl_104_bss_278 = 1;
    }
    motionSequence = getMotionInstances(motion);
    fn_27_13844(motion + 0x9C, articleAccesser(modules), motion + 0x88, motionSequence,
        motionA, motionB, lbl_27_bss_9BC, lbl_104_bss_27C, static_cast<short>(eventId(modules)), 0, lbl_27_bss_DBC);
    reinterpret_cast<ZeldaVirtualInterface*>(pointer(pointer(modules, 0x8DC), 4))->slot08();
    Byte* posture = modules + 0xD28;
    fn_27_19FF5C(posture, 1, 0);
    new (posture + 0x3C) soPostureModuleImpl(articleAccesser(modules),
        reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<ZeldaVirtualInterface*>(posture + 0x3C)->slot38();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot28();
    fn_27_3513C(modules + 0xDE0, static_cast<short>(eventId(modules)), articleAccesser(modules), lbl_27_bss_A48);
    Byte* transition;
    Word transitionData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot14();
    transition = modules + 0xE1C;
    fn_104_121F8(transition, reinterpret_cast<void*>(transitionData));
    fn_104_121F8(transition + 0x10, reinterpret_cast<void*>(transitionData));
    fn_27_B5048(transition + 0x20, transition, transition + 0x10,
        transition, articleAccesser(modules), lbl_27_bss_A48);

    int taskId;
    Byte* attack;
    unsigned char taskCategory = static_cast<unsigned char>(word(self, 0x2C) >> 7);
    taskId = word(self, 0x28);
    attack = modules + 0xE80;
    new (attackPart) soCollisionAttackPart(static_cast<soCollision::Category>(0), false);
    fn_27_19C940(attack, 1, attackPart, 0);
    reinterpret_cast<soCollisionAttackPart*>(attackPart)->~soCollisionAttackPart();
    fn_27_CB6E0(attack + 0x9C, 1, 0);
    absolute.m_attackData.m_slipChance = constants->one;
    absolute.m_attackData.m_hitStopFrame = constants->one;
    absolute.m_attackData.m_hitStopDelay = constants->one;
    absolute.m_attackData.m_region = soCollisionAttackData::Region_None;
    fn_27_C94AC(attack + 0x120, 0, &absolute);
    fn_104_12250(&absolute, -1);
    new (attack + 0x124) soCollisionAttackModuleImpl(articleAccesser(modules), taskId,
        static_cast<gfTask::Category>(taskCategory), reinterpret_cast<soArray<soCollisionAttackPart>*>(attack),
        reinterpret_cast<soArray<soCollisionGroup>*>(attack + 0x9C),
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(attack + 0x120),
        reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48), true);
    new (modules + 0x1050) soStopModuleImpl(articleAccesser(modules));
    Word hitData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot1C();
    if (lbl_104_bss_290 == 0) {
        fn_27_197C18(lbl_104_bss_294);
        __register_global_object(lbl_104_bss_294, reinterpret_cast<void*>(fn_27_82B14), lbl_104_bss_5DC);
        lbl_104_bss_290 = 1;
    }
    fn_27_687F8(modules + 0x107C, articleAccesser(modules), lbl_104_bss_294, hitData);
    Byte* sound;
    Word soundData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot84();
    sound = modules + 0x1084;
    fn_27_57FC8(sound);
    fn_27_561E0(sound + 12, articleAccesser(modules), sound, soundData, 1, 0, lbl_27_bss_A48);
    Byte* link = modules + 0x10EC;
    fn_27_CBAA0(link, 5, 0);
    fn_27_6A244(link + 0x110, articleAccesser(modules), link);
    Word visibilityData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot20();
    fn_27_5AD88(modules + 0x1250, articleAccesser(modules), visibilityData, 1);
    eventId(modules);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot60();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot5C();
    Word workData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot54();
    fn_27_A1DA4(modules + 0x1268, articleAccesser(modules), workData);
    Word animEvent = eventId(modules);
    Byte* animCommand = modules + 0x129C;
    fn_27_711E4(animCommand, static_cast<short>(animEvent), animCommand + 0x24);
    fn_27_1AC390(animCommand + 0x24, 0);
    Byte* status;
    Word statusData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot70();
    Word statusResource = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot24();
    status = modules + 0x1340;
    fn_27_C74BC(status, statusResource, 9);
    Byte* statusWork = status + 0x10;
    fn_104_8ADC(statusWork + 0x1C, statusWork, 3, statusWork + 0xC, 3, statusWork + 0x18, 1);
    reinterpret_cast<ZeldaGeneralWorkSimple*>(statusWork + 0x1C)->clearWorkAll();
    int i;
    Byte* statusArray = status + 0x50;
    fn_27_CD8C8(statusArray, 0);
    fn_27_1A1E04(statusArray + 0x20, 0);
    fn_104_7F18(statusArray + 0x8C, statusArray);
    for (i = 0; i < 1; ++i) {
        fn_27_AB15C(statusEntry, i == 0 ? statusArray + 0x20 : 0);
        reinterpret_cast<ZeldaAppendInterface*>(statusArray)->append(statusEntry);
        fn_27_AB18C(statusEntry, -1);
    }
    fn_27_1A4D6C(status + 0xF4, 0);
    word(status, 0x124) = reinterpret_cast<Word>(status + 0x128);
    fn_27_1A29F0(status + 0x128, 1, lbl_104_data_CB74, 0);
    reinterpret_cast<ZeldaVirtualInterface*>(status + 0x128)->slot3C();
    fn_27_73930(status + 0x138, articleAccesser(modules), status, status + 0xF4,
        status + 0x2C, status + 0xDC, status + 0x124, statusData, 9, 1);
    Byte* kinetic = modules + 0x1528;
    fn_27_1DBE08(kinetic, articleAccesser(modules), kinetic + 0x30, kinetic + 0xB0);
    fn_27_1AEB6C(kinetic + 0x30, 0);
    word(kinetic, 0xB0) = reinterpret_cast<Word>(lbl_104_data_7F14);
    Byte* kineticWork = modules + 0x15DC;
    fn_104_8ADC(kineticWork + 0x38, kineticWork, 7, kineticWork + 0x1C, 6, kineticWork + 0x34, 1);
    reinterpret_cast<ZeldaGeneralWorkSimple*>(kineticWork + 0x38)->clearWorkAll();
    Word effectD = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot38();
    Word effectC = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot34();
    Byte* effect;
    Word effectA;
    Word effectB = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot30();
    effectA = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot2C();
    effect = modules + 0x163C;
    fn_27_CBEC8(effect, 1, 0);
    fn_27_C9FE4(effect + 0x3C, 1, 0);
    fn_27_D37BC(effect + 0x48, 1, lbl_104_data_CB78, 0);
    if (lbl_104_bss_2A8 == 0) {
        fn_27_C948C(lbl_104_bss_2AC);
        __register_global_object(lbl_104_bss_2AC, reinterpret_cast<void*>(fn_27_82C54), lbl_104_bss_5E8);
        lbl_104_bss_2A8 = 1;
    }
    fn_27_9747C(effect + 0x58, articleAccesser(modules), effect, effectA, effect + 0x48,
        lbl_104_bss_2AC, effectB, lbl_27_bss_A48, effectC, -1, effectD, effect + 0x3C);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot58();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot40();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot3C();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot44();
    Word shadowData = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot48();
    if (lbl_104_bss_600 == 0) {
        fn_27_197C68(lbl_104_bss_604);
        __register_global_object(lbl_104_bss_604, reinterpret_cast<void*>(fn_27_82B94), lbl_104_bss_5F4);
        lbl_104_bss_600 = 1;
    }
    fn_27_10158(modules + 0x17D4, articleAccesser(modules), shadowData, lbl_104_bss_604, 1);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot88();
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot64();
    fn_27_BEBB4(modules + 0x1820, articleAccesser(modules), -1, 0);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot6C();
    fn_27_5C600(modules + 0x1978, articleAccesser(modules));
    fn_27_63B94(modules + 0x1990, articleAccesser(modules), 0);
    fn_27_C319C(modules + 0x19D0, articleAccesser(modules));
    if (reinterpret_cast<ZeldaVirtualInterface*>(modules + 0x1614)->slot08() == 0) {
        Byte* registry = pointer(pointer(modules, 0x8DC), 0x64);
        reinterpret_cast<ZeldaArrayRegistry*>(registry)->add(1, modules + 0x1614);
    }

        }
    };
    ModuleStorage::initialize(modules, self, locals, constants);
    commands = modules + 0x19EC;
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(0, 2);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(0, 1);
    Word commandData0 = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(0, 0);
    fn_27_C7744(commands, commandData0, 9);
    fn_27_D22D0(commands + 0x14, 0);
    fn_104_95F0(commands + 0xC0, commands, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag0 = 0;
    fn_104_960C(commands + 0xDC, static_cast<short>(eventId(modules)), commands + 0x14, 0, 0,
        constants->one, &commandFlag0);
    commandId0 = 1;
    commandPair0[0] = commands + 0xDC;
    commandPair0[1] = commands + 0xC0;
    reinterpret_cast<ZeldaPairRegistry*>(pointer(pointer(modules, 0x8DC), 0x6C))->add(commandPair0, &commandId0);

    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(1, 2);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(1, 1);
    Word commandData1 = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(1, 0);
    Byte* command1 = commands + 0x12C;
    fn_27_C7744(command1, commandData1, 3);
    fn_27_D22D0(command1 + 0x14, 0);
    fn_104_95F0(command1 + 0xC0, command1, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag1 = 0;
    fn_104_960C(command1 + 0xDC, static_cast<short>(eventId(modules)), command1 + 0x14, 1, 1,
        constants->one, &commandFlag1);
    commandId1 = 2;
    commandPair1[0] = command1 + 0xDC;
    commandPair1[1] = command1 + 0xC0;
    reinterpret_cast<ZeldaPairRegistry*>(pointer(pointer(modules, 0x8DC), 0x6C))->add(commandPair1, &commandId1);

    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(2, 2);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(2, 1);
    Word commandData2 = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(2, 0);
    Byte* command2 = commands + 0x258;
    fn_27_C7744(command2, commandData2, 3);
    fn_27_D22D0(command2 + 0x14, 0);
    fn_104_95F0(command2 + 0xC0, command2, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag2 = 0;
    fn_104_960C(command2 + 0xDC, static_cast<short>(eventId(modules)), command2 + 0x14, 2, 1,
        constants->one, &commandFlag2);
    commandId2 = 2;
    commandPair2[0] = command2 + 0xDC;
    commandPair2[1] = command2 + 0xC0;
    reinterpret_cast<ZeldaPairRegistry*>(pointer(pointer(modules, 0x8DC), 0x6C))->add(commandPair2, &commandId2);

    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(3, 2);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(3, 1);
    Word commandData3 = reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(3, 0);
    Byte* command3 = commands + 0x384;
    fn_27_C7744(command3, commandData3, 3);
    fn_27_D22D0(command3 + 0x14, 0);
    fn_104_95F0(command3 + 0xC0, command3, lbl_27_bss_D8C, lbl_27_bss_D8C);
    commandFlag3 = 0;
    fn_104_960C(command3 + 0xDC, static_cast<short>(eventId(modules)), command3 + 0x14, 3, 1,
        constants->one, &commandFlag3);
    commandId3 = 2;
    commandPair3[0] = command3 + 0xDC;
    commandPair3[1] = command3 + 0xC0;
    reinterpret_cast<ZeldaPairRegistry*>(pointer(pointer(modules, 0x8DC), 0x6C))->add(commandPair3, &commandId3);

    Byte* command4 = commands + 0x4B0;
    commandFlag4 = 1;
    fn_104_960C(command4, static_cast<short>(eventId(modules)), command4 + 0x50, 4, 1,
        constants->one, &commandFlag4);
    fn_27_D22D0(command4 + 0x50, 0);
    commandId4 = 4;
    commandPair4[0] = command4;
    commandPair4[1] = lbl_27_bss_8C4;
    reinterpret_cast<ZeldaPairRegistry*>(pointer(pointer(modules, 0x8DC), 0x6C))->add(commandPair4, &commandId4);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(5, 2);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(5, 1);
    reinterpret_cast<ZeldaVirtualInterface*>(descriptor)->slot90(5, 0);

    fn_27_1DBA64(self + 0x2068);
    fn_104_121E8(&vector4, constants->negOne, constants->negOne, constants->negOne);
    fn_104_121E8(&vector3, constants->zero, constants->zero, constants->zero);
    fn_104_121E8(&vector2, constants->negOne, constants->negOne, constants->negOne);
    fn_104_121E8(&vector1, constants->zero, constants->zero, constants->zero);
    fn_104_121E8(&vector0, constants->zero, constants->zero, constants->zero);
    following = self + 0x20A0;
    fn_104_7858(following, 0);
    following[5] |= 0x80;
    following[6] = 0;
    word(following, 0) = reinterpret_cast<Word>(lbl_27_data_13730);
    *reinterpret_cast<ZeldaVec*>(following + 8) = vector0;
    *reinterpret_cast<ZeldaVec*>(following + 20) = vector1;
    *reinterpret_cast<ZeldaVec*>(following + 32) = vector2;
    *reinterpret_cast<ZeldaVec*>(following + 44) = vector3;
    *reinterpret_cast<ZeldaVec*>(following + 56) = vector4;
    fn_27_1D90FC(self);
    listenerId0 = 1;
    reinterpret_cast<ZeldaListenerRegistry*>(pointer(pointer(pointer(self, 0x60), 0xD8), 0x7C))->add(
        self + 0x2068, 0, &listenerId0, -1);
    listenerId1 = 1;
    reinterpret_cast<ZeldaListenerRegistry*>(pointer(pointer(pointer(self, 0x60), 0xD8), 0x7C))->add(
        following, 1, &listenerId1, -1);
    word(self, 0x3C) = reinterpret_cast<Word>(lbl_104_data_CB7C);
    word(self, 0x40) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x64);
    word(self, 0x48) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x70);
    word(self, 0x54) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x84);
    word(self, 0x64) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0xDC);
    word(self, 0x70) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0xEC);
    word(self, 0x7C) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x100);
    word(self, 0x88) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x118);
    word(self, 0x90) = reinterpret_cast<Word>(lbl_104_data_CB7C + 0x124);
    Byte* const& parameterData = pointer(a4, 0x34);
    word(self, 0x20E4) = reinterpret_cast<Word>(parameterData);
    Byte* parameterAccesser = self + 0x20E8;
    fn_104_7858(parameterAccesser, 0);
    word(parameterAccesser, 12) = 0x46;
    word(parameterAccesser, 16) = 0xF9F;
    word(parameterAccesser, 20) = 0x5DBF;
    word(parameterAccesser, 24) = 0;
    word(parameterAccesser, 8) = reinterpret_cast<Word>(lbl_104_data_D054);
    word(parameterAccesser, 0) = reinterpret_cast<Word>(lbl_104_data_D054 + 8);
    word(parameterAccesser, 28) = reinterpret_cast<Word>(parameterData);
    word(parameterAccesser, 32) = reinterpret_cast<Word>(parameterData + 4);
    word(parameterAccesser, 36) = reinterpret_cast<Word>(parameterData + 8);
    word(parameterAccesser, 40) = reinterpret_cast<Word>(parameterData + 0xC);
    word(parameterAccesser, 44) = reinterpret_cast<Word>(parameterData + 0x10);
    word(parameterAccesser, 48) = reinterpret_cast<Word>(parameterData + 0x14);
    listenerList[0] = lbl_104_bss_614;
    listenerList[1] = lbl_104_bss_624;
    listenerList[2] = lbl_104_bss_634;
    listenerList[3] = lbl_104_bss_644;
    listenerList[4] = lbl_104_bss_654;
    listenerList[5] = lbl_27_bss_510C;
    listenerList[6] = lbl_27_bss_511C;
    listenerList[7] = lbl_27_bss_513C;
    listenerList[8] = lbl_27_bss_516C;
    reinterpret_cast<ZeldaStatusStorageInterface*>(pointer(pointer(pointer(self, 0x60), 0xD8), 0x70))->add(
        listenerList, 9);
    fn_27_1D8FC8(self, 0);
    return self;
}
