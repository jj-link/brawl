#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" void fn_117_23880(void*, soModuleAccesser* accesser) {
    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    accesser->getWorkManageModule().subInt(1, 0x20000005);
    if (accesser->getWorkManageModule().getInt(0x20000005) <= 0) {
        accesser->getWorkManageModule().onFlag(0x22000006);
        accesser->getWorkManageModule().setInt(
            params->getParamInt(accesser, 0x5DCD, 0), 0x20000005);
        if (accesser->getWorkManageModule().getInt(0x20000003) == 4)
            accesser->getWorkManageModule().setInt(0, 0x20000003);
    }
}
