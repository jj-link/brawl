#include <so/so_module_accesser.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on

extern "C" void fn_103_106E4(void*, soModuleAccesser* accesser) {
    int id = accesser->getWorkManageModule().getInt(0x10000041);
    if (id != 0) {
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category_Info, id);
        if (task != 0) {
            task->exit();
            accesser->getEffectModule().killAll(0, true, true);
        }
        accesser->getWorkManageModule().setInt(0, 0x10000041);
    }
    accesser->getWorkManageModule().setInt(0, 0x10000042);
}