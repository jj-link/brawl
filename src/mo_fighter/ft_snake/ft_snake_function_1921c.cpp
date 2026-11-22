#include <new>
#pragma use_simple_stdpnew on

#include <types.h>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/resource/so_resource_module_impl.h>
#include <so/model/so_model_module_impl.h>
#include <so/posture/so_posture_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
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

class ZeldaWorkInterface {
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

struct ZeldaAbsoluteAttackRecord {
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
    return reinterpret_cast<ZeldaVirtualInterface*>(events)->slot24();
}


extern "C" {
extern Byte g_soParamAccesserNull[];
extern Byte lbl_122_data_E2D8[], lbl_122_data_E55C[], lbl_122_data_E2F0[], lbl_122_data_DF10[], lbl_122_data_E0FC[], lbl_122_data_E2E8[], lbl_122_data_E2EC[], lbl_27_data_8E80[];
extern float lbl_122_rodata_B8;
extern signed char lbl_122_bss_250, lbl_122_bss_270, lbl_122_bss_280;
extern Byte lbl_122_bss_254[], lbl_122_bss_29C[], lbl_122_bss_274[], lbl_122_bss_2A8[], lbl_122_bss_284[], lbl_122_bss_2B4[];
extern Byte lbl_27_bss_31C[], lbl_27_bss_344[], lbl_27_bss_35C[], lbl_27_bss_384[], lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[], lbl_27_bss_3CC[], lbl_27_bss_3DC[], lbl_27_bss_3F4[], lbl_27_bss_404[], lbl_27_bss_424[], lbl_27_bss_46C[], lbl_27_bss_47C[], lbl_27_bss_48C[], lbl_27_bss_4BC[], lbl_27_bss_4D0[], lbl_27_bss_170[], lbl_27_bss_188[], lbl_27_bss_530[], lbl_27_bss_55C[], lbl_27_bss_584[], lbl_27_bss_598[], lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_5EC[], lbl_27_bss_604[], lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[], lbl_27_bss_654[], lbl_27_bss_66C[], lbl_27_bss_6E8[], lbl_27_bss_A48[];
void fn_27_1DC5E8(void*,int,void*,Word,Word,Word,unsigned char,int,void*,int,int,int,int,int,int,int);
void fn_27_1D7EF0(void*,void*,Word,Word,int,void*,void*,int);
void fn_27_1A9430(void*,short,short);
void fn_27_1AA1F4(void*,short,short);
void fn_27_D5878(void*,short,short);
void fn_27_1AA878(void*,short,short);
void fn_122_AADC(void*,int);
void fn_122_17808(void*,Word);
void fn_122_BD60(void*,void*,int,void*,int,void*,int);
void fn_27_CBD88(void*,int,int);
void fn_27_197C78(void*);
void fn_27_82A94(void*,short);
void fn_27_197C18(void*);
void fn_27_82B14(void*,short);
void fn_27_C948C(void*);
void fn_27_82C54(void*,short);
void __register_global_object(void*,void*,void*);
void fn_27_19FF5C(void*,int,int);
void fn_27_B5048(void*,void*,void*,void*,void*,void*);
void fn_27_687F8(void*,void*,void*,Word);
void fn_27_57FC8(void*);
void fn_27_561E0(void*,void*,void*,Word,int,int,void*);
void fn_27_CBAA0(void*,int,int);
void fn_27_6A244(void*,void*,void*);
void fn_27_A1DA4(void*,void*,Word);
void fn_27_C74BC(void*,Word,int);
void fn_27_CD8C8(void*,int);
void fn_27_1A1E04(void*,int);
void fn_27_AB15C(void*,void*);
void fn_27_AB18C(void*,short);
void fn_27_1A2CEC(void*,int);
void fn_27_1A29F0(void*,int,void*,int);
void fn_27_73930(void*,void*,void*,void*,void*,void*,void*,Word,int,int);
void fn_27_CBEC8(void*,int,int);
void fn_27_C9FE4(void*,int,int);
void fn_27_D37BC(void*,int,void*,int);
void fn_27_9747C(void*,void*,void*,Word,void*,void*,Word,void*,Word,int,Word,void*);
void fn_27_5C600(void*,void*);
void fn_27_63B94(void*,void*,int);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*,int);
}
struct ZeldaMotionEventStorage {
    Word storage[59];
    inline ZeldaMotionEventStorage(Word id) {
        fn_27_1A9430(this, static_cast<short>(id), 4);
    }
};

struct ZeldaStatusEventStorage {
    Word storage[107];
    inline ZeldaStatusEventStorage(Word id) {
        fn_27_1AA1F4(this, static_cast<short>(id), 5);
    }
};

struct ZeldaUnknownEventStorage {
    Word storage[17];
    inline ZeldaUnknownEventStorage(Word id) {
        fn_27_D5878(this, static_cast<short>(id), 7);
    }
};

struct ZeldaUnknownEventStorage11 {
    Word storage[17];
    inline ZeldaUnknownEventStorage11(Word id) {
        fn_27_1AA878(this, static_cast<short>(id), 11);
    }
};

struct ZeldaEventStorage {
    soInstanceManagerSimpleEntity<
        soEventUnit*, soArrayVector<soInstanceUnit<soEventUnit*>, 19> > manager;
    soEventManageModuleImpl events;
    ZeldaMotionEventStorage motion;
    ZeldaStatusEventStorage status;
    soEventUnitWithWorkArea<soDamageEventObserver, 4> damage;
    ZeldaUnknownEventStorage unknown;
    soEventUnitWithWorkArea<soSituationEventObserver, 4> situation;
    soEventUnitWithWorkArea<soCollisionHitEventObserver, 4> hit;
    soEventUnitWithWorkArea<soCollisionAttackEventObserver, 4> attack;
    soEventUnitWithWorkArea<soModelEventObserver, 4> model;
    ZeldaUnknownEventStorage11 unknown11;
    soEventUnitWithWorkArea<soCaptureEventObserver, 4> capture;
    soEventUnitWithWorkArea<soCollisionShieldEventObserver, 4> shield;
    soEventUnitWithWorkArea<soCollisionReflectorEventObserver, 4> reflector;
    soEventUnitWithWorkArea<soCollisionAbsorberEventObserver, 4> absorber;
    soEventUnitWithWorkArea<soCollisionSearchEventObserver, 4> search;
    soEventUnitWithWorkArea<soItemManageEventObserver, 1> item;
    soEventUnitWithWorkArea<soMotionEventObserver, 1> motion1;

    inline Word id() {
        return reinterpret_cast<ZeldaVirtualInterface*>(&events)->slot54();
    }

    inline ZeldaEventStorage()
        : manager(), events(this), motion(id()), status(id()), damage(id(), 6),
          unknown(id()), situation(id(), 8), hit(id(), 0), attack(id(), 1),
          model(id(), 9), unknown11(id()), capture(id(), 13), shield(id(), 14),
          reflector(id(), 15), absorber(id(), 16), search(id(), 17),
          item(id(), 12), motion1(id(), 10) {}
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

#define DESCRIPTOR reinterpret_cast<ZeldaVirtualInterface*>(descriptor)


static inline Byte* snakeName() { return lbl_122_data_E2D8; }
class SnakeArticle {
public:
 inline SnakeArticle(int owner, void* resource, Byte* parameters) {
    Byte* article = reinterpret_cast<Byte*>(this);
    Byte descriptor[64];
    Byte* ids0 = pointer(resource,4);
    fn_27_1DC5E8(descriptor,25,parameters,
        reinterpret_cast<ZeldaVirtualInterface*>(ids0)->slot10(),
        reinterpret_cast<ZeldaVirtualInterface*>(ids0)->slot18(),
        reinterpret_cast<ZeldaVirtualInterface*>(ids0)->slot1C(),
        (unsigned char)word(parameters,0),-1,g_soParamAccesserNull,0,0,0,0,0,0,0);
    Byte* const& name = snakeName();
    fn_27_1D7EF0(article,name,word(descriptor,4),word(descriptor,8),owner,resource,article+0x8c4,1);
    INSTALL_ARTICLE_TABLE(lbl_122_data_E55C);
    Byte* modules = article+0xcc;
    new (modules) ZeldaEventStorage;
    new (modules+0x7f8) soModuleAccesser(
        reinterpret_cast<StageObject*>(article),
        reinterpret_cast<soResourceModule*>(modules+0x918),
        reinterpret_cast<soModelModule*>(modules+0xa44),
        reinterpret_cast<soMotionModule*>(lbl_27_bss_31C),
        reinterpret_cast<soPostureModule*>(modules+0xb50),
        reinterpret_cast<soGroundModule*>(lbl_27_bss_344),
        reinterpret_cast<soSituationModule*>(lbl_27_bss_35C),
        modules+0xbec,
        reinterpret_cast<soCollisionAttackModule*>(lbl_27_bss_384),
        reinterpret_cast<soCollisionHitModule*>(lbl_27_bss_398),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        reinterpret_cast<soCollisionShieldModule*>(lbl_27_bss_3AC),
        lbl_27_bss_3BC,
        reinterpret_cast<soCollisionSearchModule*>(lbl_27_bss_3CC),
        reinterpret_cast<soDamageModule*>(lbl_27_bss_3DC),
        lbl_27_bss_3F4,lbl_27_bss_404,
        reinterpret_cast<soStopModule*>(modules+0xc3c),lbl_27_bss_424,modules+0xc68,
        reinterpret_cast<soSoundModule*>(modules+0xc7c),
        reinterpret_cast<soLinkModule*>(modules+0xde8),
        reinterpret_cast<soVisibilityModule*>(lbl_27_bss_46C),
        reinterpret_cast<soControllerModule*>(lbl_27_bss_47C),
        reinterpret_cast<soCameraModule*>(lbl_27_bss_48C),
        reinterpret_cast<soWorkManageModule*>(modules+0xe40),lbl_27_bss_4BC,
        reinterpret_cast<soAnimCmdModule*>(lbl_27_bss_4D0),
        reinterpret_cast<soStatusModule*>(modules+0xf88),
        lbl_27_bss_170,lbl_27_bss_188,
        reinterpret_cast<soKineticModule*>(lbl_27_bss_530),
        reinterpret_cast<soEventManageModule*>(modules+0xb8),
        lbl_27_bss_55C,
        reinterpret_cast<soEffectModule*>(modules+0x10f0),
        lbl_27_bss_584,reinterpret_cast<soAreaModule*>(lbl_27_bss_598),
        lbl_27_bss_5B0,lbl_27_bss_5D8,lbl_27_bss_5EC,lbl_27_bss_604,
        reinterpret_cast<soShadowModule*>(lbl_27_bss_614),
        reinterpret_cast<soItemManageModule*>(lbl_27_bss_628),
        reinterpret_cast<soColorBlendModule*>(lbl_27_bss_640),
        lbl_27_bss_654,lbl_27_bss_66C,
        reinterpret_cast<soSlowModule*>(modules+0x1234),
        modules+0x124c,modules+0x8d8,
        reinterpret_cast<soParamCustomizeModule*>(modules+0x8f0),lbl_27_bss_6E8);
    Heaps::HeapType ha, hb, hc;
    Word heapSize;
    heapSize=DESCRIPTOR->slot80();
    hc=static_cast<Heaps::HeapType>(DESCRIPTOR->slot7C());
    hb=static_cast<Heaps::HeapType>(DESCRIPTOR->slot78());
    ha=static_cast<Heaps::HeapType>(DESCRIPTOR->slot74());
    new (modules+0x8d8) soHeapModuleImpl(ha,hb,hc,heapSize);
    Byte* customize=modules+0x8f0;
    fn_122_AADC(customize,0);
    word(customize,0)=reinterpret_cast<Word>(lbl_122_data_DF10);
    float defaultValue=lbl_122_rodata_B8;
    scalar(customize,8)=defaultValue;
    scalar(customize,12)=defaultValue;
    Word rf=DESCRIPTOR->slot10();
    Word rs=DESCRIPTOR->slot0C();
    Word rk=DESCRIPTOR->slot08();
    Byte* ids=modules+0x900;
    fn_122_AADC(ids,0);
    word(ids,0)=reinterpret_cast<Word>(lbl_122_data_E0FC);
    word(ids,8)=rk; word(ids,12)=rk; word(ids,16)=rs;
    *reinterpret_cast<short*>(ids+20)=0;
    *reinterpret_cast<short*>(ids+22)=0;
    new (ids+24) soResourceModuleImpl(0,reinterpret_cast<soResourceIdAccesser*>(ids),(unsigned char)rf);
    Byte* model;
    Word modelData=DESCRIPTOR->slot68();
    float scale=DESCRIPTOR->slot50();
    model=modules+0x930;
    fn_27_CBD88(model,5,0);
    INITIALIZE_GLOBAL(lbl_122_bss_250,lbl_122_bss_254,fn_27_197C78,fn_27_82A94,lbl_122_bss_29C);
    new (model+0x114) soModelModuleImpl(articleAccesser(modules),reinterpret_cast<soArray<soModelNodeSetUp>*>(model),scale,reinterpret_cast<void*>(modelData),reinterpret_cast<soArray<soModelVirtualNode>*>(lbl_122_bss_254),reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    DESCRIPTOR->slot18();
    Byte* posture=modules+0xb14;
    fn_27_19FF5C(posture,1,0);
    new (posture+0x3c) soPostureModuleImpl(articleAccesser(modules),reinterpret_cast<soArray<soInterpolation<Vec3f> >*>(posture),reinterpret_cast<soEventObserverRegistrationDesc*>(lbl_27_bss_A48));
    reinterpret_cast<ZeldaVirtualInterface*>(posture+0x3c)->slot38();
    DESCRIPTOR->slot28();
    eventId(modules);
    Byte* transition;
    Word t=DESCRIPTOR->slot14();
    transition=modules+0xbcc;
    fn_122_17808(transition,t);
    fn_122_17808(transition+0x10,t);
    fn_27_B5048(transition+0x20,transition,transition+0x10,transition,articleAccesser(modules),lbl_27_bss_A48);
    new (modules+0xc3c) soStopModuleImpl(articleAccesser(modules));
    Word hit=DESCRIPTOR->slot1C();
    INITIALIZE_GLOBAL(lbl_122_bss_270,lbl_122_bss_274,fn_27_197C18,fn_27_82B14,lbl_122_bss_2A8);
    fn_27_687F8(modules+0xc68,articleAccesser(modules),lbl_122_bss_274,hit);
    Byte* sound;
    Word soundData=DESCRIPTOR->slot84();
    sound=modules+0xc70;
    fn_27_57FC8(sound);
    fn_27_561E0(sound+12,articleAccesser(modules),sound,soundData,1,0,lbl_27_bss_A48);
    Byte* link=modules+0xcd8;
    fn_27_CBAA0(link,5,0);
    fn_27_6A244(link+0x110,articleAccesser(modules),link);
    DESCRIPTOR->slot20();
    eventId(modules);
    DESCRIPTOR->slot60();
    DESCRIPTOR->slot5C();
    Word wd=DESCRIPTOR->slot54();
    fn_27_A1DA4(modules+0xe40,articleAccesser(modules),wd);
    eventId(modules);
    Byte* status;
    Word statusData=DESCRIPTOR->slot70();
    Word statusResource=DESCRIPTOR->slot24();
    status=modules+0xe78;
    fn_27_C74BC(status,statusResource,1);
    Byte* sw=status+0x10;
    fn_122_BD60(sw+0x14,sw,2,sw+8,2,sw+0x10,1);
    reinterpret_cast<ZeldaWorkInterface*>(sw+0x14)->initialize();
    int i;
    Byte* sa=status+0x48;
    fn_27_CD8C8(sa,0);
    fn_27_1A1E04(sa+0x20,0);
    word(sa,0x8c)=reinterpret_cast<Word>(lbl_27_data_8E80);
    word(sa,0x90)=reinterpret_cast<Word>(sa);
    word(sa,0x94)=0;
    Word statusEntry[6];
    statusEntry[0]=0;
    word(sa,0x98)=-1; word(sa,0x9c)=-1; word(sa,0xa0)=0;
    for(i=0;i<1;++i) {
        fn_27_AB15C(statusEntry+1,i==0?sa+0x20:0);
        reinterpret_cast<Object_vptr_0*>(sa)->slot10(statusEntry+1);
        fn_27_AB18C(statusEntry+1,-1);
    }
    fn_27_1A2CEC(status+0xec,0);
    word(status,0xfc)=reinterpret_cast<Word>(status+0x100);
    fn_27_1A29F0(status+0x100,1,lbl_122_data_E2E8,0);
    reinterpret_cast<ZeldaVirtualInterface*>(status+0x100)->slot3C();
    fn_27_73930(status+0x110,articleAccesser(modules),status,status+0xec,status+0x24,status+0xd4,status+0xfc,statusData,1,1);
    Byte* kw=modules+0x1038;
    fn_122_BD60(kw+0x38,kw,7,kw+0x1c,6,kw+0x34,1);
    reinterpret_cast<ZeldaWorkInterface*>(kw+0x38)->initialize();
    Word ed=DESCRIPTOR->slot38();
    Word ec=DESCRIPTOR->slot34();
    Byte* effect;
    Word ea;
    Word eb=DESCRIPTOR->slot30();
    ea=DESCRIPTOR->slot2C();
    effect=modules+0x1098;
    fn_27_CBEC8(effect,1,0);
    fn_27_C9FE4(effect+0x3c,1,0);
    fn_27_D37BC(effect+0x48,1,lbl_122_data_E2EC,0);
    INITIALIZE_GLOBAL(lbl_122_bss_280,lbl_122_bss_284,fn_27_C948C,fn_27_82C54,lbl_122_bss_2B4);
    fn_27_9747C(effect+0x58,articleAccesser(modules),effect,ea,effect+0x48,lbl_122_bss_284,eb,lbl_27_bss_A48,ec,-1,ed,effect+0x3c);
    DESCRIPTOR->slot58(); DESCRIPTOR->slot40(); DESCRIPTOR->slot3C();
    DESCRIPTOR->slot44(); DESCRIPTOR->slot48(); DESCRIPTOR->slot88();
    DESCRIPTOR->slot64(); DESCRIPTOR->slot6C();
    fn_27_5C600(modules+0x1234,articleAccesser(modules));
    fn_27_63B94(modules+0x124c,articleAccesser(modules),0);
    if (reinterpret_cast<ZeldaVirtualInterface*>(modules+0x1070)->slot08()==0) {
      Byte* work=pointer(pointer(modules,0x8d0),0x64);
      reinterpret_cast<ZeldaArrayRegistry*>(work)->add(1,modules+0x1070);
    }
    DESCRIPTOR->slot90(0,2); DESCRIPTOR->slot90(0,1); DESCRIPTOR->slot90(0,0);
    DESCRIPTOR->slot90(1,2); DESCRIPTOR->slot90(1,1); DESCRIPTOR->slot90(1,0);
    DESCRIPTOR->slot90(2,2); DESCRIPTOR->slot90(2,1); DESCRIPTOR->slot90(2,0);
    DESCRIPTOR->slot90(3,2); DESCRIPTOR->slot90(3,1); DESCRIPTOR->slot90(3,0);
    DESCRIPTOR->slot90(5,2); DESCRIPTOR->slot90(5,1); DESCRIPTOR->slot90(5,0);
    fn_27_1D90FC(article);
    INSTALL_ARTICLE_TABLE(lbl_122_data_E2F0);
    fn_27_1D8FC8(article,0);
 }
};
extern "C" void* fn_122_1921C(Byte* article,int owner,void* resource,Byte* parameters) {
 new (article) SnakeArticle(owner,resource,parameters);
 return article;
}
