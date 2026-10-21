#include <so/so_module_accesser.h>
#include <so/link/so_link_module_impl.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" void fn_101_1127C(void*, soModuleAccesser* accesser) {
    if (accesser->getLinkModule().getParentSituationKind(7) == 0) {
        accesser->getWorkManageModule().onFlag(0x22000010);
    } else {
        accesser->getWorkManageModule().offFlag(0x22000010);
    }
}
