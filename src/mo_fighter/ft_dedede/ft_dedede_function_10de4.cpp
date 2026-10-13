#include <gf/gf_task_scheduler.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>

namespace {
// Partial interfaces for the opaque team module and its team object.
class DededeTeam {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual int getTeam();
};
class DededeTeamModule {
public:
    virtual void reserved08();
    virtual void reserved0C();
    virtual DededeTeam* getTeam();
};
}

extern "C" {
extern const char lbl_117_data_3254[], lbl_117_data_4248[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_117_209C8(void*, int, int, int);
}

extern "C" void fn_117_10DE4(void*, soModuleAccesser* accesser) {
    int owner;
    int kind = accesser->getWorkManageModule().getInt(0x10000043);
    int taskId = accesser->getWorkManageModule().getInt(0x10000044);
    gfTask* task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category(0xc), taskId);
    if (task == 0) return;
    if (kind == 0x33) {
        void* object = __dynamic_cast(task, 0x3c, lbl_117_data_3254, lbl_117_data_4248, 0);
        owner = accesser->m_stageObject->m_taskId;
        fn_117_209C8(object, owner, 0x36,
            static_cast<DededeTeamModule*>(accesser->m_enumerationStart->m_teamModule)->getTeam()->getTeam());
        accesser->getWorkManageModule().onFlag(0x22000017);
    }
}
