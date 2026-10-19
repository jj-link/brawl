#include <so/so_module_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#include <so/collision/so_collision_shield_module_impl.h>
#pragma force_active on

extern "C" void fn_114_10894(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    if (work.isFlag(0x22000010)) {
        accesser->getCollisionReflectorModule().setStatus(0, 1, 2);
        work.offFlag(0x22000010);
    }
    if (work.isFlag(0x22000011)) {
        accesser->getCollisionReflectorModule().setStatus(0, 0, 2);
        work.offFlag(0x22000011);
    }
}
