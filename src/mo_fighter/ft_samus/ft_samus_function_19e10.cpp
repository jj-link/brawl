#include <gf/gf_task.h>
#include <so/so_module_accesser.h>
#include <so/area/so_area_module_impl.h>
#include <so/status/so_status_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#include <types.h>
#pragma force_active on

extern "C" void fn_94_19E10(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work = &accesser->getWorkManageModule();
    soAreaModule* area = &accesser->getAreaModule();
    if (work->isFlag(0x2200001A) == true) {
        if (work->isFlag(0x22000019) == false) {
            if (work->isFlag(0x22000014) == true) {
                int count = (int)area->getAreaContactCount(9);
                for (int i = 0; i < count; i++) {
                    u8* log = (u8*)area->getAreaContactLog(9, i);
                    if (*(u32*)(log + 8) != 0xFFFFFFFF && gfTask::getTask(*(int*)(log + 8)) != 0) {
                        work->setInt(*(int*)(log + 8), 0x20000003);
                        accesser->getStatusModule().changeStatusRequest(0x11C, accesser);
                    }
                }
            }
        }
    }
}
