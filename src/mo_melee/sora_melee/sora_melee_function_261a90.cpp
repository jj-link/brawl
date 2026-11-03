#include <gr/ground.h>
#include <gr/collision/gr_collision_status.h>
#include <gf/gf_task.h>
#pragma force_active on

extern "C" bool isCollisionStatusOwnerTask__6GroundFP12grCollStatusPi(Ground* ths, grCollStatus* collStatus, int* arg) {
    gfTask* task = gfTask::getTask(collStatus->m_taskId);
    if (task != 0) {
        int mask = *arg;
        if ((mask & 1) && task->m_taskCategory == gfTask::Category_Fighter) return 1;
        if ((mask & 2) && task->m_taskCategory == gfTask::Category_Enemy) return 1;
        if ((mask & 4) && task->m_taskCategory == gfTask::Category_Item) return 1;
    }
    return 0;
}
