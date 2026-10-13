#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

extern "C" void fn_117_22988(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) == 2)
        return;

    switch (accesser->getStatusModule().getStatusKind()) {
    case 6: {
        soParamAccesser* params = static_cast<soParamAccesser*>(
            accesser->getWorkManageModule().getParamAccesser());
        soWorkManageModule& work = accesser->getWorkManageModule();
        int threshold = params->getParamInt(accesser, 0x5dca, 0);
        if (work.getInt(0x20000002) >= threshold)
            accesser->getWorkManageModule().onFlag(0x22000004);
        break;
    }
    }
}
