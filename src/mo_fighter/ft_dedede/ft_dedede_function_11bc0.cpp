#include <gf/gf_task_scheduler.h>
#include <so/stageobject.h>
#include <so/so_module_accesser.h>

// Field view of an area-contact log; the shared declaration is still opaque.
struct DededeSearchTarget {
    u8 prefix[8];
    u32 taskId;
    u8 kind;
    u8 subKind;
    u8 padding[2];
    float x;
    float y;
};
struct DededeSearchDecision {
    int reserved;
    int status;
};
extern "C" {
extern const float lbl_117_rodata_A0[];
extern const char lbl_117_data_3650[], lbl_117_data_4248[], lbl_117_data_3254[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_117_208E8(void*);

bool fn_117_11BC0(void*, DededeSearchDecision* decision, soModuleAccesser* accesser) {
    int count = accesser->getAreaModule().getAreaContactCount(-1);
    accesser->getWorkManageModule().setInt(-1, 0x10000043);
    accesser->getWorkManageModule().setInt(-1, 0x10000044);
    if (count > 0) {
        float nearestDistance = lbl_117_rodata_A0[0];
        DededeSearchTarget* nearest = 0;
        int nearestKind = -1;
        for (int index = 0; index < count; ++index) {
            DededeSearchTarget* target = reinterpret_cast<DededeSearchTarget*>(accesser->getAreaModule().getAreaContactLog(-1, index));
            if (target->kind == 4 && target->subKind == 0x1d) {
                float distance = target->x * target->x + target->y * target->y;
                if (distance < nearestDistance) {
                    gfTask* task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category(0xc), target->taskId);
                    if (task != 0) {
                        StageObject* object = static_cast<StageObject*>(__dynamic_cast(task, 0x3c, lbl_117_data_3650, lbl_117_data_4248, 0));
                        int kind = object->soGetSubKind();
                        bool eligible = false;
                        if (kind == 0x33) {
                            void* waddle = __dynamic_cast(task, 0x3c, lbl_117_data_3254, lbl_117_data_4248, 0);
                            if (fn_117_208E8(waddle)) eligible = true;
                        }
                        if (eligible) {
                            nearest = target;
                            nearestDistance = distance;
                            nearestKind = kind;
                        }
                    }
                }
            }
        }
        if (nearest != 0) {
            decision->status = 0;
            accesser->getWorkManageModule().setInt(nearestKind, 0x10000043);
            accesser->getWorkManageModule().setInt(nearest->taskId, 0x10000044);
            return true;
        }
    }
    return false;
}
}
