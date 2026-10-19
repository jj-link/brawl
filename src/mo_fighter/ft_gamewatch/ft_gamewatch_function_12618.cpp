#include <so/so_module_accesser.h>
#include <so/collision/so_collision_shield_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" void fn_107_12618(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000013)) {
        accesser->getCollisionAbsorberModule().setStatus(0, 1, 0);
    }
}
