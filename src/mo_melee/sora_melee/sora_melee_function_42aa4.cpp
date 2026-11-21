#include <types.h>
#include <gf/gf_task.h>
#include <so/event/so_event_presenter.h>
#include <so/event/so_event_system.h>

#pragma force_active on

extern "C" {
extern char lbl_27_data_3E80[];
extern char lbl_27_data_3E38[];
extern char lbl_27_data_3CC0[];
extern char lbl_27_data_3CB8[];
extern char __RTTI__11soEventUnit[];
extern char __vt__21soStatusEventObserver[];
extern char __vt__22soAnimCmdEventObserver[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_27_35C3C(void*, u32, u32, u32, u32, u32, u8);
}

class soCollisionHitPart;
class soCollisionGroup;
class soCollisionHitGroup;
class soCollisionHitEventObserver;

struct Obs {
    virtual void attach(short, signed char);
    short a, b, c;
};

struct I9 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual int get();
};

struct I2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual u32 get();
};

struct Self {
    void* vt;
    u8 flag;
    char pad5[3];
    Obs status;
    Obs anim;
    void* pv;
    short manageId;
    short unitId;
    void* obsList;
    void* access;
    void* parts;
    void* zero;
    char collision[0x20];
    void* hitGroups;
    char pad5c[8];
    short reaction;
    unsigned short bit0 : 1;
    unsigned short bit1 : 1;
    unsigned short bit2 : 1;
    unsigned short otherBits : 13;
};

inline int getResult(Self* s) {
    short id = s->unitId;
    soEventManager* mgr = soEventSystem::getInstance()->getManager(s->manageId);
    if (!mgr->getObserverCapacity(id))
        return 0;
    soEventUnitWrapper<soCollisionHitEventObserver>* unit =
        (soEventUnitWrapper<soCollisionHitEventObserver>*)__dynamic_cast(
            mgr->getEventUnit(id), 0, lbl_27_data_3CB8, __RTTI__11soEventUnit, 0);
    if (!unit)
        return 0;
    return (int)unit->getObserverListSub();
}

class soCollisionHitModuleImpl {
public:
    soCollisionHitModuleImpl(soModuleAccesser*, int, gfTask::Category,
        soArray<soCollisionHitPart>*, soArray<soCollisionGroup>*,
        soArray<soCollisionHitGroup>*, soEventObserverRegistrationDesc*, bool);
};

soCollisionHitModuleImpl::soCollisionHitModuleImpl(
    soModuleAccesser* access, int task, gfTask::Category category,
    soArray<soCollisionHitPart>* parts, soArray<soCollisionGroup>* groups,
    soArray<soCollisionHitGroup>* hitGroups,
    soEventObserverRegistrationDesc* registration, bool flag) {
    short hid;
    Self* s = (Self*)this;
    char* ctx;
    char* p;

    s->flag = 0;
    s->vt = lbl_27_data_3E80;

    int id;
    if (registration->checkStatus() == 1) {
        ctx = *(char**)((char*)access + 0xd8);
        p = *(char**)(ctx + 0x80);
        id = ((I9*)(p + 8))->get();
    } else {
        id = -1;
    }

    int animId = -1;
    Obs* status = (Obs*)((char*)s + 8);
    status->a = animId;
    status->b = 4;
    status->c = animId;
    *(void**)status = __vt__21soStatusEventObserver;
    status->attach(id, -1);

    if (registration->checkAnimCmd() == 1) {
        ctx = *(char**)((char*)access + 0xd8);
        p = *(char**)(ctx + 0x80);
        animId = ((I9*)(p + 8))->get();
    }

    int invalid2 = -1;
    Obs* anim = (Obs*)((char*)s + 0x14);
    anim->a = invalid2;
    anim->b = 5;
    anim->c = invalid2;
    *(void**)anim = __vt__22soAnimCmdEventObserver;
    anim->attach(animId, -1);

    int hitId;
    if (registration->checkCollisionHit() == 1) {
        ctx = *(char**)((char*)access + 0xd8);
        p = *(char**)(ctx + 0x80);
        hitId = ((I9*)(p + 8))->get();
    } else {
        hitId = invalid2;
    }
    hid = hitId;
    void* result = 0;
    s->pv = lbl_27_data_3E38;
    s->manageId = hid;
    s->unitId = 0;
    s->obsList = result;

    if (hid > 0 && hid > -1) {
        if (soEventSystem::getInstance()->getInstanceManager().isContain(hid)) {
            if (!soEventSystem::getInstance()->getManager(s->manageId)->getObserverCapacity(s->unitId)) {
                s->obsList = 0;
            } else {
                soEventManager* mgr;
                short uid = s->unitId;
                mgr = soEventSystem::getInstance()->getManager(s->manageId);
                if (mgr->getObserverCapacity(uid) == 0) {
                    result = 0;
                } else {
                    void* unit = __dynamic_cast(mgr->getEventUnit(uid), 0, lbl_27_data_3CB8, __RTTI__11soEventUnit, 0);
                    if (unit == 0) {
                        result = 0;
                    } else {
                        result = ((soEventUnitWrapper<soCollisionHitEventObserver>*)unit)->getObserverListSub();
                    }
                }
                s->obsList = result;
            }
        }
    }

    s->access = access;
    s->vt = lbl_27_data_3CC0;
    *(void**)&s->status = lbl_27_data_3CC0 + 0xdc;
    *(void**)&s->anim = lbl_27_data_3CC0 + 0xec;
    s->pv = lbl_27_data_3CC0 + 0x100;
    s->parts = parts;
    s->zero = 0;

    ctx = *(char**)((char*)access + 0xd8);
    u32 val = ((I2*)*(void**)(ctx + 0x18))->get();
    fn_27_35C3C(s->collision, task, category, val, 1, (u32)groups, 0);

    s->hitGroups = hitGroups;
    s->reaction = -1;
    s->bit1 = 0;
    s->bit2 = flag;
}
