#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on
extern "C" void fn_27_165B84(void* unused, soModuleAccesser* accesser) {
    int value = accesser->getWorkManageModule().getInt(0x20000000);
    accesser->getWorkManageModule().setInt(value + 1, 0x20000000);
    if (!accesser->getWorkManageModule().isFlag(0x22000010) &&
        (float)(value + 1) > soValueAccesser::getConstantFloat(accesser, 0xc33, 0)) {
        accesser->getWorkManageModule().onFlag(0x22000010);
    }
    if (!accesser->getWorkManageModule().isFlag(0x22000011) &&
        (float)(value + 1) > soValueAccesser::getConstantFloat(accesser, 0xc34, 0)) {
        accesser->getWorkManageModule().onFlag(0x22000011);
    }
    if (!accesser->getWorkManageModule().isFlag(0x22000013)) {
        accesser->getWorkManageModule().onFlag(0x22000013);
    }
}
