#include <gf/gf_slow_manager.h>
#include <gf/gf_task_scheduler.h>
#pragma force_active on
extern "C" {
void* fn_103_10E9C();
void fn_103_10D10(void*, float);
unsigned int fn_27_5BEA8(void*);
float fn_27_8CC94(void*);
unsigned int fn_800B61C0(void*);
void fn_103_9708(void*);
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern char lbl_103_data_22A0[], lbl_103_data_23A0[], lbl_103_data_654[];
}
extern "C" void fn_103_10D80(gfTask* self) {
    float rate = *(float*)((char*)fn_103_10E9C() + 0x44);
    rate *= gfSlowManager::getQuickRate();
    float factor = 1.0f;
    void* task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category_Fighter, *(unsigned long*)((char*)self + 0x54));
    void* obj = __dynamic_cast(task, 0x3c, lbl_103_data_22A0, lbl_103_data_23A0, 0);
    if (obj) factor = fn_27_8CC94(obj);
    fn_103_10D10(self, rate * factor);
    if (fn_27_5BEA8(fn_103_10E9C()) == 1 && *(unsigned char*)((char*)self + 0x58) == 1 && fn_800B61C0(*(void**)((char*)self + 0x4c)) == 1) {
        task = gfTaskScheduler::getInstance()->getTaskById(gfTask::Category_Fighter, *(unsigned long*)((char*)self + 0x54));
        obj = __dynamic_cast(task, 0x3c, lbl_103_data_654, lbl_103_data_23A0, 0);
        if (obj) fn_103_9708(obj);
        self->exit();
    }
}