#pragma force_active on
#include <so/situation/so_situation_module_impl.h>
#include <so/event/so_event_system.h>
#include <so/event/so_event_presenter.h>
class soModuleAccesser;
class IdGetter {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual int get();
};
extern "C" {
extern char lbl_27_data_33B0[];
extern char lbl_27_data_32B0[];
extern char lbl_27_data_32A8[];
extern char lbl_27_data_3370[];
extern void* __vt__21soStatusEventObserver[];
extern void* __vt__22soAnimCmdEventObserver[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}
struct SituationFlags { unsigned char a : 2; unsigned char b : 6; };
extern "C" soSituationModuleImpl* fn_27_3513C(
    soSituationModuleImpl* self, s16 manageId, soModuleAccesser* accesser,
    soEventObserverRegistrationDesc* desc
) {
    char* base = (char*)self;
    int id;
    int id2;
    void* r28;
    *(void**)base = lbl_27_data_33B0;
    if (desc->checkStatus() == true) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        id = ((IdGetter*)(p + 8))->get();
    } else {
        id = -1;
    }
    id2 = -1;
    soStatusEventObserver* status = (soStatusEventObserver*)(base + 4);
    status->m_manageID = -1;
    status->m_unitID = 4;
    status->m_sendID = -1;
    *(void**)status = __vt__21soStatusEventObserver;
    status->addObserver((short)id, -1);
    if (desc->checkAnimCmd() == true) {
        char* p = *(char**)((char*)accesser + 0xd8);
        p = *(char**)(p + 0x80);
        id2 = ((IdGetter*)(p + 8))->get();
    }
    soAnimCmdEventObserver* anim = (soAnimCmdEventObserver*)(base + 0x10);
    anim->m_manageID = -1;
    anim->m_unitID = 5;
    anim->m_sendID = -1;
    *(void**)anim = __vt__22soAnimCmdEventObserver;
    anim->addObserver((short)id2, -1);
    r28 = 0;
    *(void**)(base + 0x1C) = lbl_27_data_3370;
    *(s16*)(base + 0x20) = manageId;
    *(s16*)(base + 0x22) = 8;
    *(void**)(base + 0x24) = r28;
    if (manageId > 0 && manageId > -1 &&
        soEventSystem::getInstance()->getInstanceManager().isContain(manageId)) {
        if (soEventSystem::getInstance()
                ->getManager(*(s16*)(base + 0x20))
                ->getObserverCapacity(*(s16*)(base + 0x22)) == 0) {
            *(void**)(base + 0x24) = 0;
        } else {
            soEventManager* mgr;
            s16 uid = *(s16*)(base + 0x22);
            mgr = soEventSystem::getInstance()->getManager(*(s16*)(base + 0x20));
            if (mgr->getObserverCapacity(uid) == 0) {
                r28 = 0;
            } else {
                void* unit = __dynamic_cast(mgr->getEventUnit(uid), 0, lbl_27_data_32A8, __RTTI__11soEventUnit, 0);
                if (unit == 0) {
                    r28 = 0;
                } else {
                    r28 = ((soEventUnitWrapper<soSituationEventObserver>*)unit)->getObserverListSub();
                }
            }
            *(void**)(base + 0x24) = r28;
        }
    }
    *(void**)base = lbl_27_data_32B0;
    *(void**)(base + 4) = lbl_27_data_32B0 + 0x2C;
    *(void**)(base + 0x10) = lbl_27_data_32B0 + 0x3C;
    *(void**)(base + 0x1C) = lbl_27_data_32B0 + 0x50;
    *(soModuleAccesser**)(base + 0x28) = accesser;
    *(int*)(base + 0x2C) = 5;
    *(int*)(base + 0x30) = 5;
    *(int*)(base + 0x34) = 5;
    ((SituationFlags*)(base + 0x38))->a = 0;
    return self;
}
