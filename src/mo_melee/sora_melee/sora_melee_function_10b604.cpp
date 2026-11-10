#include <ft/ft_manager.h>
#include <types.h>
#pragma force_active on

struct Pack {
    void* vt;
    short a, b;
    int c, d;
};

struct FtSub {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11();
    virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15();
    virtual void d16(); virtual void d17(); virtual void d18();
    virtual short f21();
};

struct SysView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5();
    virtual int f8(int);
};

struct MgrView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void* f6(int);
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void* f10(int);
};

struct UnitView {
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6();
    virtual int f9();
};

extern "C" {
extern char lbl_27_data_261F0[];
extern char lbl_27_data_261B0[];
extern char lbl_27_data_26440[];
extern char __RTTI__11soEventUnit[];

void fn_27_1119E0(void*, u32);
u32 fn_27_111A08(void*);
void fn_27_111B14(void*, int);
void fn_27_115FAC(void*, int);
void fn_27_117000(void*, int);
void fn_27_11A418(void*, int);
void fn_27_157680(void*, u32, u32, int, int);
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* getInstance__13soEventSystemFv();
void* getManager__13soEventSystemFl(void*, long);
}

static int getUnit(MgrView* manager, short id) {
    UnitView* unit = (UnitView*)__dynamic_cast(
        manager->f10(id), 0, lbl_27_data_26440, __RTTI__11soEventUnit, 0);
    if (unit == 0)
        return 0;
    return unit->f9();
}

void ftManager::setDead(int entryId, int unk1, int unk2) {
    char* ent1;
    u32 entityId;
    ftOwner* owner;
    char* ent0;
    u32 adjustedEntry;
    u32 eventFlag;
    int eventResult;
    short eventId;
    short observerId;
    Pack pack;
    int finalArg;

    ent0 = (char*)m_entryManager->getEntity(entryId);
    adjustedEntry = entryId;
    entityId = entryId;
    eventFlag = 0;

    if (*(int*)(ent0 + 0x50) != -1)
        entityId = *(int*)(ent0 + 0x50);

    ent1 = (char*)m_entryManager->getEntity(entityId);
    owner = *(ftOwner**)(ent1 + 0x28);
    fn_27_1119E0(owner, fn_27_111A08(owner) + 1);

    u32 deadFlag = *(u8*)((char*)this + 0x6d) != 0;
    if (deadFlag == 1 || *(u8*)((char*)this + 0x6a) == 1) {
        if (deadFlag == 1) {
            fn_27_115FAC(ent0, 0);
            bool entryFlag = (*(u8*)(ent1 + 0x11) & 2) >> 1;
            if (entryFlag == 1)
                adjustedEntry = entityId;
            eventFlag = 1;
        } else {
            int stock = owner->getStockCount();
            int stockIndex;
            if (stock < 0)
                stockIndex = -1;
            else {
                stockIndex = stock - 1;
                if (stockIndex < 0)
                    stockIndex = 0;
            }
            fn_27_111B14(owner, stockIndex);
            if (stockIndex == 0 && *(u8*)((char*)this + 0x6a) == 1) {
                fn_27_115FAC(ent0, 0);
                if (*(int*)(ent0 + 0x50) != -1)
                    eventFlag = 1;
            }
        }

        if (*(int*)(ent0 + 0x50) != -1) {
            bool entryFlag = (*(u8*)(ent1 + 0x11) & 2) >> 1;
            if (entryFlag == 1) {
                fn_27_11A418(m_entryManager, 0);
                adjustedEntry = entityId;
            }
        }
    }

    eventResult = 0;
    eventId = (short)((FtSub*)((char*)this + 0xb4))->f21();
    pack.vt = lbl_27_data_261F0;
    pack.a = eventId;
    pack.b = 0;
    pack.c = 0;

    if (eventId > 0 && eventId > -1) {
        if (((SysView*)getInstance__13soEventSystemFv())->f8(eventId) != 0) {
            MgrView* manager = (MgrView*)getManager__13soEventSystemFl(
                getInstance__13soEventSystemFv(), pack.a);
            if (manager->f6(pack.b) == 0) {
                pack.c = eventResult;
            } else {
                observerId = pack.b;
                manager = (MgrView*)getManager__13soEventSystemFl(
                    getInstance__13soEventSystemFv(), pack.a);
                if (manager->f6(observerId) == 0)
                    eventResult = 0;
                else
                    eventResult = getUnit(manager, observerId);
                pack.c = eventResult;
            }
        }
    }

    pack.d = entryId;
    pack.vt = lbl_27_data_261B0;
    finalArg = -1;
    if (eventFlag != 1)
        finalArg = unk2;

    fn_27_157680(&pack, adjustedEntry, fn_27_111A08(owner), unk1, finalArg);
    fn_27_117000(ent0, unk1);
}
