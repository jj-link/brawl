#pragma force_active on
#include <gf/gf_task.h>
#include <so/so_external_value_accesser.h>
#include <so/so_value_accesser.h>

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char __RTTI__6gfTask[];
}
extern const char lbl_27_data_248[];

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
    virtual void fn_27_248088();
    virtual int slot40();
};

struct HitData {
    char pad0[4];
    float amount;
    char pad8[0x14];
    u32 taskId;
    char pad20[0x12];
    u8 category;
};

extern "C" int fn_27_1888D0(void*, soModuleAccesser* accesser, HitData* __restrict hit) {
    if (hit->taskId != 0xFFFFFFFF && hit->category == 10) {
        gfTask* task = gfTask::getTask(hit->taskId);
        if (task != 0) {
            TaskView* object = (TaskView*)__dynamic_cast(task, 0x3C, lbl_27_data_248, __RTTI__6gfTask, 1);
            if (object->slot40() == 9 &&
                soExternalValueAccesser::getStatusKind((StageObject*)object) == 0x116)
                return 0;
        }
    }
    float value = soValueAccesser::getConstantFloat(accesser, 0xD71, 0);
    accesser->m_enumerationStart->m_controllerModule->addClatterTime(-(hit->amount * value), 0);
    return 1;
}
