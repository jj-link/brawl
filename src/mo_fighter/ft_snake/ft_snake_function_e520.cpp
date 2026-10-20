#include <so/so_module_accesser.h>
#include <ft/fighter.h>
#pragma force_active on

extern "C" {
extern const char lbl_122_data_8B84[], lbl_122_data_8BB0[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_14DB04(void*);
void fn_27_3B8DC8(void*, int, int);
}

extern "C" bool fn_122_E520(void* owner, soModuleAccesser* accesser) {
    unsigned int taskId = accesser->m_stageObject->m_taskId;
    int resource = fn_27_14DB04(__dynamic_cast(
        accesser->getResourceModule().getResourceIdAccesser(), 0,
        lbl_122_data_8B84, lbl_122_data_8BB0, short(1)));
    fn_27_3B8DC8(owner, taskId, resource);
    return true;
}
