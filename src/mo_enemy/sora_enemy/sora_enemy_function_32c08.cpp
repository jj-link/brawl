#include <gf/gf_task_scheduler.h>
#include <so/so_module_accesser.h>
#include <so/collision/so_collision_log.h>
#include <em/wnem/wn_em_report.h>
#pragma force_active on

extern const char lbl_41_data_4B5E[];
extern const char lbl_41_data_4BE3[];

extern "C" void fn_41_32C08(char* self, float value, soCollisionLog* log) {
    if (log) {
        gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)*((unsigned char*)log + 0x22), log->m_taskId);
        switch (*(int*)(self + 0x21dc)) {
        case 0:
        case 1:
            break;
        case 2:
            if (value > *(float*)(self + 0x21e0))
                *(float*)(self + 0x21e0) = value;
            if (*(float*)(self + 0x21e4) < value) {
                soModuleAccesser* accesser = *(soModuleAccesser**)(self + 0x6c);
                wnemReport(lbl_41_data_4B5E, ((*(u32*)((char*)accesser->getCollisionAttackModule().getData(log->m_damageIndex, false) + 0x38) >> 7) & 1));
                accesser = *(soModuleAccesser**)(self + 0x6c);
                if (!((*(u32*)((char*)accesser->getCollisionAttackModule().getData(log->m_damageIndex, false) + 0x38) >> 7) & 1)) {
                    wnemReport(lbl_41_data_4BE3, *(float*)(self + 0x21e4));
                    *(float*)(self + 0x21e4) = value;
                }
            }
            break;
        }
    }
}
