#include <types.h>
#include <new>
#include <so/so_module_accesser.h>
#include <so/so_heap_module_impl.h>
#include <so/stop/so_stop_module_impl.h>
#include <so/event/so_event_system.h>
#include <ac/ac_cmd_interpreter.h>
#pragma force_active on

#pragma use_simple_stdpnew on

class ResourceIds {
public:
    virtual u32 slot08();
    virtual u32 slot0C();
    virtual u32 slot10();
    virtual u32 slot14();
    virtual u32 slot18();
    virtual u32 slot1C();
};

class Descriptor {
public:
    virtual u32 slot08();
    virtual u32 slot0C();
    virtual u8 slot10();
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
    virtual u32 slot90(int, int);
};

class EventId {
public:
    virtual u32 slot08();
    virtual u32 slot0C();
    virtual u32 slot10();
    virtual u32 slot14();
    virtual u32 slot18();
    virtual u32 slot1C();
    virtual u32 slot20();
    virtual u32 slot24();
};

class Observer {
public:
    virtual int slot08();
};

class ObserverManager {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14(int, void*);
};

struct Registration {
    void* interpreter;
    void* addresses;
};

class Registrar {
public:
    virtual void slot08();
    virtual void slot0C(Registration*, s16*);
};

class UnitView {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual s32 get();
};

struct Presenter {
    void* vt;
    s16 id;
    s16 unit;
    s32 value;
};

extern "C" {
extern char g_soParamAccesserNull[];
extern char lbl_27_data_9E0F0[], lbl_27_data_9E0FC[], lbl_27_data_9E408[], lbl_27_data_2BEE8[];
extern char lbl_27_data_20878[], lbl_27_data_15218[], lbl_27_data_46658[], lbl_27_data_466B8[];
extern char lbl_27_data_81A0[], lbl_27_data_128[], __RTTI__11soEventUnit[];
extern const f32 lbl_27_rodata_7F60, lbl_27_rodata_7F64;
extern char lbl_27_bss_170[], lbl_27_bss_188[], lbl_27_bss_344[], lbl_27_bss_35C[];
extern char lbl_27_bss_384[], lbl_27_bss_398[], lbl_27_bss_3AC[], lbl_27_bss_3BC[], lbl_27_bss_3CC[];
extern char lbl_27_bss_3DC[], lbl_27_bss_3F4[], lbl_27_bss_404[], lbl_27_bss_424[];
extern char lbl_27_bss_47C[], lbl_27_bss_48C[], lbl_27_bss_4BC[], lbl_27_bss_4E8[];
extern char lbl_27_bss_530[], lbl_27_bss_55C[], lbl_27_bss_584[], lbl_27_bss_598[];
extern char lbl_27_bss_5B0[], lbl_27_bss_5D8[], lbl_27_bss_5EC[], lbl_27_bss_604[];
extern char lbl_27_bss_614[], lbl_27_bss_628[], lbl_27_bss_640[], lbl_27_bss_654[];
extern char lbl_27_bss_66C[], lbl_27_bss_6E8[], lbl_27_bss_8C4[], lbl_27_bss_A48[], lbl_27_bss_D8C[];

void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_27_1DC5E8(void*, int, const void*, int, int, int, u8, int, void*, int, int, int, int, int, int, int);
void fn_27_1D7EF0(void*, void*, u32, u32, int, void*, void*, int);
void fn_27_2DA3CC(void*);
void fn_27_1E107C(void*, u32, u32, u8, void*);
void fn_27_1E10E0(void*, void*, u32, void*, f32);
void fn_27_2E1E54(void*, void*, u32);
void fn_27_2DAC38(void*, void*, void*);
void fn_27_1E1524(void*, u32, void*);
void fn_27_1E15A4(void*, void*, u32);
void fn_27_57FC8(void*);
void fn_27_561E0(void*, void*, void*, u32, int, int, void*);
void fn_27_1E1648(void*, void*);
void fn_27_5B248(void*, void*, u32, int);
void fn_27_A1DA4(void*, void*, u32);
void fn_27_1E16CC(void*, s16);
void fn_27_1E1774(void*);
void fn_27_2DB778(void*, void*, u32, u32, u32, u32, void*);
void fn_27_5C600(void*, void*);
void fn_27_63B94(void*, void*, int);
void fn_27_1D90FC(void*);
void fn_27_1D8FC8(void*, int);
}

inline s32 getUnitResult(soEventManager* mgr, s16 uid, s32 result) {
    if (mgr->getObserverCapacity(uid) == 0) {
        result = 0;
    } else {
        UnitView* unit = (UnitView*)__dynamic_cast(
            mgr->getEventUnit(uid), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
        if (unit == 0) {
            result = 0;
        } else {
            result = unit->get();
        }
    }
    return result;
}

inline void initPresenter(Presenter* p, s32 n) {
    s32 result = 0;
    s32 eid = (s16)n;
    p->vt = lbl_27_data_466B8;
    p->id = eid;
    p->unit = 5;
    p->value = result;
    if (eid > 0 && eid > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(eid)) {
            if (soEventSystem::getInstance()->getManager(p->id)->getObserverCapacity(p->unit) == 0) {
                p->value = 0;
            } else {
                p->value = getUnitResult(
                    soEventSystem::getInstance()->getManager(p->id), p->unit, result);
            }
        }
    }
}

struct StackEntryInit : acCmdInterpreterStackData {
    StackEntryInit()
        : acCmdInterpreterStackData(Invalid, 0, false, 0, lbl_27_rodata_7F64) {}
};

struct StackInit {
    void* vt;
    void* vt2;
    s32 top : 5;
    s32 last : 5;
    s32 size : 5;
    u32 full : 1;
    u32 preservedBits : 16;
    StackEntryInit entries[8];

    StackInit()
        : vt(lbl_27_data_15218),
          vt2(lbl_27_data_15218 + 0x48),
          top(0),
          last(0),
          size(0),
          full(0) {}
};

inline void initStack(u8* p) {
    new (p) StackInit;
}

inline u32 eventId(u8* modules) {
    u8* owner = *(u8**)(modules + 0x8D0);
    u8* object = *(u8**)(owner + 0x80);
    return ((EventId*)(object + 8))->slot24();
}

inline Registrar* registrar(u8* modules) {
    return *(Registrar**)(*(u8**)(modules + 0x8D0) + 0x6C);
}

#define D ((Descriptor*)(storage + 32))
#define W(p, o) (*(u32*)((p) + (o)))
#define P(p, o) (*(void**)((p) + (o)))
#define F(p, o) (*(f32*)((p) + (o)))

inline void initSecondInterpreter(u8* modules, u8* storage) {
    storage[4] = 1;
    u8* interp2 = modules + 0x14E0;
    u32 id2 = eventId(modules);
    new (interp2) acCmdInterpreter(
        (soArrayVector<acCmdInterpreterStackData, 8>*)(interp2 + 0x50),
        1, 0, storage + 4, lbl_27_rodata_7F60);

    initPresenter((Presenter*)(interp2 + 0x34), id2);
    P(interp2, 0) = lbl_27_data_81A0;
    P(interp2, 0x34) = lbl_27_data_81A0 + 0x20;
    W(interp2, 0x40) = 4;
    W(interp2, 0x44) = 0;
    W(interp2, 0x48) = 0;
    W(interp2, 0x4C) = 0;
    initStack(interp2 + 0x50);

    *(s16*)(storage + 12) = 4;
    P(storage, 24) = interp2;
    P(storage, 28) = lbl_27_bss_8C4;
    registrar(modules)->slot0C((Registration*)(storage + 24), (s16*)(storage + 12));
}

extern "C" void* fn_27_3AA6D8(
    void* self, int owner, void* resource, const int* parameters) {
    u8 storage[96];
    u8* article = (u8*)self;
    int resourceB, resourceC;
    ResourceIds* ids = *(ResourceIds**)((u8*)resource + 4);
    resourceC = ids->slot1C();
    resourceB = ids->slot18();
    int resourceA = ids->slot10();

    fn_27_1DC5E8(
        storage + 32, 0x15, parameters, resourceA, resourceB, resourceC,
        *parameters & 0xff, -1, g_soParamAccesserNull, 0, 0, 0, 0, 0, 0, 0);

    fn_27_1D7EF0(
        article, lbl_27_data_9E0F0, W(storage, 36), W(storage, 40),
        owner, resource, article + 0x8C4, 1);

    P(article, 0x3C) = lbl_27_data_9E408;
    P(article, 0x40) = lbl_27_data_9E408 + 0x64;
    P(article, 0x48) = lbl_27_data_9E408 + 0x70;
    P(article, 0x54) = lbl_27_data_9E408 + 0x84;
    P(article, 0x64) = lbl_27_data_9E408 + 0xDC;
    P(article, 0x70) = lbl_27_data_9E408 + 0xEC;
    P(article, 0x7C) = lbl_27_data_9E408 + 0x100;
    P(article, 0x88) = lbl_27_data_9E408 + 0x118;
    P(article, 0x90) = lbl_27_data_9E408 + 0x124;

    u8* modules = article + 0xCC;

    fn_27_2DA3CC(modules);
    new (modules + 0x7F8) soModuleAccesser(
        (StageObject*)article,
        (soResourceModule*)(modules + 0x918),
        (soModelModule*)(modules + 0xA44),
        (soMotionModule*)(modules + 0xBAC),
        (soPostureModule*)(modules + 0xD58),
        (soGroundModule*)lbl_27_bss_344,
        (soSituationModule*)lbl_27_bss_35C,
        modules + 0xDF4,
        (soCollisionAttackModule*)lbl_27_bss_384,
        (soCollisionHitModule*)lbl_27_bss_398,
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        (soCollisionShieldModule*)lbl_27_bss_3AC,
        lbl_27_bss_3BC,
        (soCollisionSearchModule*)lbl_27_bss_3CC,
        (soDamageModule*)lbl_27_bss_3DC,
        lbl_27_bss_3F4,
        lbl_27_bss_404,
        (soStopModule*)(modules + 0xE44),
        lbl_27_bss_424,
        modules + 0xE70,
        (soSoundModule*)(modules + 0xE84),
        (soLinkModule*)(modules + 0xFF0),
        (soVisibilityModule*)(modules + 0x1044),
        (soControllerModule*)lbl_27_bss_47C,
        (soCameraModule*)lbl_27_bss_48C,
        (soWorkManageModule*)(modules + 0x1078),
        lbl_27_bss_4BC,
        (soAnimCmdModule*)(modules + 0x10AC),
        (soStatusModule*)lbl_27_bss_4E8,
        lbl_27_bss_170,
        lbl_27_bss_188,
        (soKineticModule*)lbl_27_bss_530,
        (soEventManageModule*)(modules + 0xB8),
        lbl_27_bss_55C,
        (soEffectModule*)(modules + 0x120C),
        lbl_27_bss_584,
        (soAreaModule*)lbl_27_bss_598,
        lbl_27_bss_5B0,
        lbl_27_bss_5D8,
        lbl_27_bss_5EC,
        lbl_27_bss_604,
        (soShadowModule*)lbl_27_bss_614,
        (soItemManageModule*)lbl_27_bss_628,
        (soColorBlendModule*)lbl_27_bss_640,
        lbl_27_bss_654,
        lbl_27_bss_66C,
        (soSlowModule*)(modules + 0x1350),
        modules + 0x1368,
        modules + 0x8D8,
        (soParamCustomizeModule*)(modules + 0x8F0),
        lbl_27_bss_6E8);

    new (modules + 0x8D8) soHeapModuleImpl(
        (Heaps::HeapType)D->slot74(),
        (Heaps::HeapType)D->slot78(),
        (Heaps::HeapType)D->slot7C(),
        D->slot80());

    modules[0x8F4] = 0;
    P(modules, 0x8F0) = lbl_27_data_2BEE8;
    F(modules, 0x8F8) = lbl_27_rodata_7F60;
    F(modules, 0x8FC) = lbl_27_rodata_7F60;

    fn_27_1E107C(
        modules + 0x900, D->slot08(), D->slot0C(), D->slot10(),
        modules + 0x7F8);

    u32 modelData = D->slot68();
    f32 modelScale = D->slot50();
    fn_27_1E10E0(
        modules + 0x930, modules + 0x7F8, modelData, lbl_27_bss_A48, modelScale);

    u32 motionData = D->slot18();
    fn_27_2E1E54(modules + 0xB10, modules + 0x7F8, motionData);
    fn_27_2DAC38(modules + 0xD1C, modules + 0x7F8, lbl_27_bss_A48);

    D->slot28();
    eventId(modules);
    u32 situationData = D->slot14();
    fn_27_1E1524(modules + 0xDD4, situationData, modules + 0x7F8);

    new (modules + 0xE44) soStopModuleImpl((soModuleAccesser*)(modules + 0x7F8));

    u32 hitData = D->slot1C();
    fn_27_1E15A4(modules + 0xE6C, modules + 0x7F8, hitData);

    u8* sound;
    u32 soundData = D->slot84();
    sound = modules + 0xE78;
    fn_27_57FC8(sound);
    fn_27_561E0(
        sound + 0xC, modules + 0x7F8, sound, soundData, 1, 0, lbl_27_bss_A48);

    fn_27_1E1648(modules + 0xEE0, modules + 0x7F8);

    u32 visibilityData = D->slot20();
    fn_27_5B248(modules + 0x1044, modules + 0x7F8, visibilityData, 1);

    eventId(modules);
    D->slot60();
    D->slot5C();
    u32 workData = D->slot54();
    fn_27_A1DA4(modules + 0x1078, modules + 0x7F8, workData);

    s16 eid = (s16)eventId(modules);
    fn_27_1E16CC(modules + 0x10AC, eid);

    D->slot70();
    D->slot24();
    fn_27_1E1774(modules + 0x1154);
    fn_27_2DB778(
        modules + 0x11B4, modules + 0x7F8,
        D->slot2C(), D->slot30(), D->slot34(), D->slot38(), lbl_27_bss_A48);

    D->slot58();
    D->slot40();
    D->slot3C();
    D->slot44();
    D->slot48();
    D->slot88();
    D->slot64();
    D->slot6C();

    fn_27_5C600(modules + 0x1350, modules + 0x7F8);
    fn_27_63B94(modules + 0x1368, modules + 0x7F8, 0);

    if (!((Observer*)(modules + 0x118C))->slot08()) {
        ObserverManager* manager =
            *(ObserverManager**)(*(u8**)(modules + 0x8D0) + 0x64);
        manager->slot14(1, modules + 0x118C);
    }

    D->slot90(0, 2);
    D->slot90(0, 1);
    D->slot90(0, 0);
    D->slot90(1, 2);
    D->slot90(1, 1);
    u32 commands = D->slot90(1, 0);

    {
    u8* obj = modules + 0x13B0;
    W(obj, 4) = 0;
    P(obj, 0) = lbl_27_data_20878;
    W(obj, 8) = commands;
    W(obj, 12) = 3;
    if (!commands)
        W(obj, 12) = 0;

    initStack(obj + 0x14);
    P(obj, 0xD0) = obj;
    P(obj, 0xC0) = lbl_27_data_46658;

    u8* interp;
    s32 result = 0;
    u8* stack = obj + 0x14;
    P(stack, 0xC0) = lbl_27_bss_D8C;
    P(stack, 0xC4) = lbl_27_bss_D8C;
    storage[0] = result;

    s32 id = eventId(modules);
    interp = obj + 0xDC;

    new (interp) acCmdInterpreter(
        (soArrayVector<acCmdInterpreterStackData, 8>*)stack,
        1, 0, storage, lbl_27_rodata_7F60);

    Presenter* presenter = (Presenter*)(interp + 0x34);
    presenter->vt = lbl_27_data_466B8;
    presenter->id = id;
    presenter->unit = 5;
    presenter->value = result;
    s32 peid = (s16)id;

    if (peid > 0 && peid > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(peid)) {
            if (soEventSystem::getInstance()
                    ->getManager(presenter->id)
                    ->getObserverCapacity(presenter->unit) == 0) {
                presenter->value = result;
            } else {
                soEventManager* mgr;
                s16 uid;
                uid = presenter->unit;
                mgr = soEventSystem::getInstance()->getManager(presenter->id);
                if (mgr->getObserverCapacity(uid) == 0) {
                    result = 0;
                } else {
                    UnitView* unit = (UnitView*)__dynamic_cast(
                        mgr->getEventUnit(uid), 0, lbl_27_data_128, __RTTI__11soEventUnit, 0);
                    if (unit == 0) {
                        result = 0;
                    } else {
                        result = unit->get();
                    }
                }
                presenter->value = result;
            }
        }
    }

    P(interp, 0) = lbl_27_data_81A0;
    P(interp, 0x34) = lbl_27_data_81A0 + 0x20;
    W(interp, 0x40) = 1;
    W(interp, 0x44) = 0;
    W(interp, 0x48) = 0;
    W(interp, 0x4C) = 0;

    *(s16*)(storage + 8) = 2;
    P(storage, 16) = obj + 0xDC;
    P(storage, 20) = obj + 0xC0;
    registrar(modules)->slot0C((Registration*)(storage + 16), (s16*)(storage + 8));
    }

    D->slot90(2, 2);
    D->slot90(2, 1);
    D->slot90(2, 0);
    D->slot90(3, 2);
    D->slot90(3, 1);
    D->slot90(3, 0);

    initSecondInterpreter(modules, storage);

    D->slot90(5, 2);
    D->slot90(5, 1);
    D->slot90(5, 0);

    fn_27_1D90FC(article);
    P(article, 0x3C) = lbl_27_data_9E0FC;
    P(article, 0x40) = lbl_27_data_9E0FC + 0x64;
    P(article, 0x48) = lbl_27_data_9E0FC + 0x70;
    P(article, 0x54) = lbl_27_data_9E0FC + 0x84;
    P(article, 0x64) = lbl_27_data_9E0FC + 0xDC;
    P(article, 0x70) = lbl_27_data_9E0FC + 0xEC;
    P(article, 0x7C) = lbl_27_data_9E0FC + 0x100;
    P(article, 0x88) = lbl_27_data_9E0FC + 0x118;
    P(article, 0x90) = lbl_27_data_9E0FC + 0x124;
    fn_27_1D8FC8(article, 0);
    return self;
}
