#include <gf/gf_task_scheduler.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7(int);
};
struct SavedTasks { int count; unsigned long ids[1]; };
extern "C" {
extern SavedTasks* lbl_100_bss_2D0;
extern char lbl_100_data_167C[], lbl_100_data_22AC[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_100_1046C() {
    for (int i = 0; i < lbl_100_bss_2D0->count; ++i) {
        gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)12, lbl_100_bss_2D0->ids[i]);
        if (task) {
            StageObject* obj = (StageObject*)__dynamic_cast(task, 0x3c, lbl_100_data_167C, lbl_100_data_22AC, 0);
            char* acc = (char*)soExternalValueAccesser::getModuleAccesser(obj);
            char* modules = *(char**)(acc + 0xd8);
            (*(Object_vptr_0**)(modules + 0x58))->slot7(1);
        }
    }
}
}