#include <gf/gf_task_scheduler.h>
#include <so/so_external_value_accesser.h>
#pragma force_active on
class Class_1B64 {
public:
    virtual void fn_113_80F4();
    virtual void fn_113_958();
    virtual void fn_113_CAD0();
    virtual void fn_113_CAC8();
    virtual Vec3f fn_113_CAC0();
};
extern "C" {
extern const char lbl_113_data_2950[], lbl_113_data_2A50[];
extern const float lbl_113_rodata_E8;
void* __dynamic_cast(void*, long, const void*, const void*, short);
void* fn_113_B7F0(Vec2f*, const Vec3f*);
float fn_113_23E44(Vec2f*, void*, int);
}
extern "C" float fn_113_23D5C(soModuleAccesser* self, int mode) {
    u32 id = (*(soModuleEnumeration**)((char*)self + 0xd8))->m_workManageModule->getInt(0x10000000);
    gfTask* task = gfTaskScheduler::getInstance()->getTaskById((gfTask::Category)10, id);
    StageObject* obj = (StageObject*)__dynamic_cast(task, 0x3c, lbl_113_data_2950, lbl_113_data_2A50, 0);
    if (!obj) return lbl_113_rodata_E8;
    Vec3f pos = soExternalValueAccesser::getPos(obj);
    Vec2f first;
    fn_113_B7F0(&first, &pos);
    soModuleEnumeration* modules = *(soModuleEnumeration**)((char*)self + 0xd8);
    Vec3f own = ((Class_1B64*)modules->m_postureModule)->fn_113_CAC0();
    Vec2f second;
    return fn_113_23E44(&first, fn_113_B7F0(&second, &own), mode);
}