#include <gf/gf_task_scheduler.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

extern "C" {
extern const char lbl_113_data_2950[], lbl_113_data_2A50[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_113_2589C(void*, soModuleAccesser* self) {
    soModuleEnumeration* modules = *(soModuleEnumeration**)((char*)self + 0xd8);
    u32 id = modules->m_workManageModule->getInt(0x10000000);
    gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)10, id);
    StageObject* obj = (StageObject*)__dynamic_cast(task, 0x3c, lbl_113_data_2950, lbl_113_data_2A50, 0);
    if (obj) {
        Vec3f pos = soExternalValueAccesser::getPos(obj);
        Vec2f safe;
        safe.m_x = pos.m_x;
        safe.m_y = pos.m_y;
        modules = *(soModuleEnumeration**)((char*)self + 0xd8);
        modules->m_groundModule->setShapeSafePos(&safe, 0);
        modules = *(soModuleEnumeration**)((char*)self + 0xd8);
        modules->m_kineticModule->changeKinetic(0, self);
    }
}