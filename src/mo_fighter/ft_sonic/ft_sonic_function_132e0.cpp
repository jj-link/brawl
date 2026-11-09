#include <so/event/so_gimmick_event_presenter.h>
#include <so/event/so_event_system.h>
#include <so/event/so_event_presenter.h>
#include <types.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern u8 lbl_123_data_6894[];
extern u8 lbl_123_data_685C[];
extern u8 lbl_123_data_6E00[];
extern u8 lbl_123_data_21F8[];
}

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
};

class soGimmickEventPresenter : public soEventPresenter<soGimmickEventObserver> {
public:
    s32 m_p2;
};

extern "C" soGimmickEventPresenter* fn_123_132E0(
    soGimmickEventPresenter* self, s32 manageId, s32 p2)
{
    soInstanceManagerFullProperty<soGimmickEventObserver*>* list;
    s16 id;

    *(void**)self = lbl_123_data_6894;
    self->m_manageID = manageId;
    self->m_unitID = 3;
    list = NULL;
    self->m_obsrvrList = list;

    if (manageId > 0 && (s16)manageId > -1) {
        id = self->m_manageID;
        if (soEventSystem::getInstance()->getInstanceManager().isContain(id)) {
            if (soEventSystem::getInstance()->getManager(self->m_manageID)
                    ->getObserverCapacity(self->m_unitID) == 0) {
                self->m_obsrvrList = list;
            } else {
                soEventManager* mgr;
                s16 unitID = self->m_unitID;
                mgr = soEventSystem::getInstance()->getManager(self->m_manageID);
                if (mgr->getObserverCapacity(unitID) == 0) {
                    list = NULL;
                } else {
                    soEventUnitWrapper<soGimmickEventObserver>* w =
                        reinterpret_cast<soEventUnitWrapper<soGimmickEventObserver>*>(
                            __dynamic_cast(mgr->getEventUnit(unitID), 0,
                                           lbl_123_data_6E00, lbl_123_data_21F8, 0));
                    if (w == NULL) {
                        list = NULL;
                    } else {
                        list = w->getObserverListSub();
                    }
                }
                self->m_obsrvrList = list;
            }
        }
    }

    *(void**)self = lbl_123_data_685C;
    self->m_p2 = p2;
    return self;
}
