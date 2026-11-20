#include <so/model/so_model_module_impl.h>
#include <so/model/so_model_event_presenter.h>
#include <so/event/so_event_presenter.h>
#include <so/event/so_event_system.h>
#include <so/so_instance_manager.h>
#include <gf/gf_3d_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {
extern soInstanceManagerFullPropertyNull<soModelEventObserver*> lbl_27_bss_CE0;
extern u8 lbl_27_data_4A4;
extern char lbl_27_data_548[];
extern char __RTTI__11soEventUnit[];
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_8000D074(gfSceneRoot*, void*);
void fn_800257FC(s32, u32);
}

struct ElemView {
    virtual void v0();
    virtual void v1();
    virtual void invoke(soModuleAccesser*);
};
struct ListView {
    virtual void v0();
    virtual void v1();
    virtual ElemView** get(int);
    virtual void v3();
    virtual int size();
};

static inline bool checkIdHelper(const s16* id, s32& temp) {
    temp = *id;
    return soEventSystem::getInstance()->getInstanceManager().isContain(temp);
}

nw4r::g3d::ScnMdl* soModelModuleImpl::detachScnMdl(void* arg0) {
    soInstanceManagerFullProperty<soModelEventObserver*>* obs;
    s32 i;
    soEventManager* mgr;
    s32 j;
    s16 unitId;
    soInstanceManagerFullProperty<soModelEventObserver*>* list;
    soEventUnitWrapper<soModelEventObserver>* w;
    s32 r0;
    u8* self = reinterpret_cast<u8*>(this);

    switchEnvMap(false);
    obs = NULL;
    self[0xC3] = 0;

    if (soEventPresenter<soModelEventObserver>::m_manageID <= -1) {
        list = &lbl_27_bss_CE0;
        goto L8FCC;
    }
    if (m_obsrvrList != NULL) {
        goto L8F8C;
    }
    if (soEventPresenter<soModelEventObserver>::m_manageID <= -1 ||
        !checkIdHelper(reinterpret_cast<s16*>(self + 0x24), i)) {
        r0 = 0;
        goto L8F78;
    }
    if (soEventSystem::getInstance()->getManager(soEventPresenter<soModelEventObserver>::m_manageID)
            ->getObserverCapacity(soEventPresenter<soModelEventObserver>::m_unitID) == 0) {
        m_obsrvrList = NULL;
        r0 = 0;
        goto L8F78;
    }
    unitId = soEventPresenter<soModelEventObserver>::m_unitID;
    mgr = soEventSystem::getInstance()->getManager(soEventPresenter<soModelEventObserver>::m_manageID);
    if (mgr->getObserverCapacity(unitId) == 0) {
        obs = NULL;
    } else {
        w = (soEventUnitWrapper<soModelEventObserver>*)__dynamic_cast(
            mgr->getEventUnit(unitId), 0, lbl_27_data_548, __RTTI__11soEventUnit, 0);
        if (w == NULL) {
            obs = NULL;
        } else {
            obs = w->getObserverListSub();
        }
    }
    m_obsrvrList = obs;
    r0 = (obs != NULL);

L8F78:
    if (r0 != 0) {
        goto L8F8C;
    }
    list = &lbl_27_bss_CE0;
    goto L8FCC;

L8F8C:
    if (soEventSystem::getInstance()->getManager(soEventPresenter<soModelEventObserver>::m_manageID)
            ->getObserverCapacity(soEventPresenter<soModelEventObserver>::m_unitID) == 0) {
        m_obsrvrList = NULL;
        list = &lbl_27_bss_CE0;
    } else {
        list = m_obsrvrList;
    }

L8FCC:
    for (j = 0; j < ((ListView*)list)->size(); j++) {
        (*((ListView*)list)->get(j))->invoke(m_moduleAccesser);
    }

    if (getScnMdl(true) != NULL) {
        fn_8000D074(g_gfSceneRoot, self + 0x98);
    }

    u32* out = reinterpret_cast<u32*>(arg0);
    out[0] = *reinterpret_cast<u32*>(self + 0xA8);
    out[1] = *reinterpret_cast<u32*>(self + 0xAC);
    out[2] = *reinterpret_cast<u32*>(self + 0xB0);
    out[3] = *reinterpret_cast<u32*>(self + 0xB4);
    reinterpret_cast<u8*>(arg0)[0x10] = self[0xB8];

    *reinterpret_cast<u32*>(self + 0xA8) = 0;
    u8 c4 = self[0xC4];
    *reinterpret_cast<u32*>(self + 0xAC) = 0;
    *reinterpret_cast<u32*>(self + 0xB0) = 0;
    *reinterpret_cast<u32*>(self + 0xB4) = 0;
    self[0xB8] = 0;

    if (c4 != lbl_27_data_4A4) {
        fn_800257FC(c4, *reinterpret_cast<u32*>(self + 0xC));
    }

    return soModelModuleSimple::detachScnMdl(arg0);
}