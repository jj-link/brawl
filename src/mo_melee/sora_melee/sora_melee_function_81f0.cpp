#pragma force_active on
#include <types.h>
#include <so/model/so_model_module_impl.h>
#include <so/event/so_event_system.h>
#include <gf/gf_heap_manager.h>
#include <nw4r/g3d/g3d_obj.h>

struct ElemView {
    virtual void v0();
    virtual void v1();
    virtual void invoke(void*);
};
struct ListView {
    virtual void v0();
    virtual void v1();
    virtual ElemView** get(int);
    virtual void v3();
    virtual int size();
};
struct EvUnitView {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual ListView* getObserverListSub();
};
class TaskView : public gfTask {
public:
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual u8 fn_27_248088();
    virtual u8 slot40();
};
struct AccessView {
    char pad[8];
    TaskView* task;
};
struct ModelFlags {
    u8 upper : 3;
    u8 immediate : 1;
    u8 lower : 4;
};
struct ModelFields {
    char pad0[0xC];
    nw4r::g3d::ScnMdl* mdl;
    char pad10[0x14];
    short managerId;
    short unitId;
    ListView* list;
    char pad2c[0x6C];
    char callback[0x10];
    void* bufA;
    void* bufB;
    int fieldB0;
    int fieldB4;
    u8 fieldB8;
    char padB9[10];
    u8 state;
    u8 id;
    ModelFlags flags;
    char padC6[2];
    AccessView* access;
};
struct DisposeRecord {
    nw4r::g3d::ScnMdl* mdl;
    u32 taskId;
    u8 a;
    u8 b;
};
extern "C" {
extern char lbl_27_bss_CE0[];
extern char lbl_27_data_548[];
extern char __RTTI__11soEventUnit[];
extern u8 lbl_27_data_4A4;
extern void* g_soDisposeInstanceManager;
void* __dynamic_cast(void*, long, const void*, const void*, long);
void fn_800257FC(u32, nw4r::g3d::ScnMdl*);
void fn_27_AF08C(void*, DisposeRecord*);
void fn_8000D074(gfSceneRoot*, void*);
}
static inline bool checkManageId(const ModelFields* self, s32& mId) {
    mId = self->managerId;
    return soEventSystem::getInstance()->getInstanceManager().isContain(mId);
}
extern "C" void destructInstance__17soModelModuleImplFv(soModelModuleImpl* obj) {
    ModelFields* self = (ModelFields*)obj;
    s32 i;
    ListView* sel;
    short evId;
    soEventManager* mgr;
    EvUnitView* unit;
    ListView* cur;
    int flag;
    s32 mId;
    if (self->mdl != 0) {
        if (self->managerId <= -1) {
            sel = (ListView*)lbl_27_bss_CE0;
            goto LOOP;
        }
        if (self->list != 0) goto CHECK_CACHE;
        if (self->managerId <= -1 || !checkManageId(self, i)) {
            flag = 0;
            goto CHECK_VALID;
        }
        if (soEventSystem::getInstance()->getManager(self->managerId)->getObserverCapacity(self->unitId) == 0) {
            self->list = 0;
            flag = 0;
            goto CHECK_VALID;
        }
        evId = self->unitId;
        mgr = soEventSystem::getInstance()->getManager(self->managerId);
        if (mgr->getObserverCapacity(evId) == 0) {
            cur = 0;
        } else {
            unit = (EvUnitView*)__dynamic_cast(mgr->getEventUnit(evId), 0, lbl_27_data_548, __RTTI__11soEventUnit, 0);
            if (unit == 0) cur = 0;
            else cur = unit->getObserverListSub();
        }
        self->list = cur;
        flag = (cur != 0);
CHECK_VALID:
        if (flag != 0) goto CHECK_CACHE;
        sel = (ListView*)lbl_27_bss_CE0;
        goto LOOP;
CHECK_CACHE:
        mgr = soEventSystem::getInstance()->getManager(self->managerId);
        if (mgr->getObserverCapacity(self->unitId) == 0) {
            self->list = 0;
            sel = (ListView*)lbl_27_bss_CE0;
        } else sel = self->list;
LOOP:
        for (i = 0; i < sel->size(); i++) {
            (*sel->get(i))->invoke(self->access);
        }
        if (self->state != 3) {
            if (self->id != lbl_27_data_4A4) {
                fn_800257FC(self->id, self->mdl);
                self->id = lbl_27_data_4A4;
            }
            if (!self->flags.immediate) {
                DisposeRecord rec;
                rec.a = self->access->task->fn_27_248088();
                rec.b = self->access->task->slot40();
                rec.mdl = self->mdl;
                rec.taskId = self->access->task->m_taskId;
                fn_27_AF08C(g_soDisposeInstanceManager, &rec);
            } else {
                ((nw4r::g3d::G3dObj*)self->mdl)->Destroy();
            }
            g_gfSceneRoot->remove(self->mdl);
            *(u32*)((char*)self->mdl + 0x11c) = 0;
            *(u32*)((char*)self->mdl + 0xd4) = 0;
            gfHeapManager::free(self->bufA);
            gfHeapManager::free(self->bufB);
            self->bufA = 0;
            self->bufB = 0;
            if (obj->isAddEnvMapMat() == 1) {
                obj->switchEnvMap(false);
                self->fieldB8 = 0;
            }
        }
        self->mdl = 0;
        self->state = 0;
        if (obj->getScnMdl(true) != 0) {
            if (!self->flags.immediate) {
                DisposeRecord rec;
                rec.a = self->access->task->fn_27_248088();
                rec.b = self->access->task->slot40();
                rec.mdl = obj->getScnMdl(true);
                rec.taskId = self->access->task->m_taskId;
                fn_27_AF08C(g_soDisposeInstanceManager, &rec);
            } else {
                ((nw4r::g3d::G3dObj*)self->mdl)->Destroy();
            }
            nw4r::g3d::ScnMdl* mdl = obj->getScnMdl(true);
            *(u32*)((char*)mdl + 0xd4) = 0;
            self->fieldB4 = 0;
            fn_8000D074(g_gfSceneRoot, self->callback);
        }
    }
}
