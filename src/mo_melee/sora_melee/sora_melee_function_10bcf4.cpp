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

struct Owner {
    char pad[0xc];
    virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3();
    virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8();
    virtual void f9(unsigned short);
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

unsigned short fn_27_111AEC(void*);
void fn_27_157CD0(void*, u32);
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

extern "C" void setSUlcide__9ftManagerFi(ftManager* self, int entryId) {
    short eventId;
    int eventResult;
    u32 entityId;
    Owner* owner;
    char* ent1;
    char* ent0;
    short observerId;
    Pack pack;
    int checked;

    ent0 = (char*)self->m_entryManager->getEntity(entryId);
    entityId = entryId;
    if (*(int*)(ent0 + 0x50) != -1)
        entityId = *(int*)(ent0 + 0x50);

    if (self->m_finalStatus == 1 && entryId != self->m_finalEntryId) {
        self->setBeat(entryId, self->m_finalEntryId);
        checked = 1;
    } else {
        checked = 0;
    }

    if (checked == 0) {
        ent1 = (char*)self->m_entryManager->getEntity(entityId);
        owner = *(Owner**)(ent1 + 0x28);
        owner->f9((unsigned short)(fn_27_111AEC(owner) + 1));

        eventResult = 0;
        eventId = (short)((FtSub*)&self->m_eventManageModule)->f21();
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
        fn_27_157CD0(&pack, entityId);
    }
}
