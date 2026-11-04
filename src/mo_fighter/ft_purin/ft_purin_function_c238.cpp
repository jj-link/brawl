#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" void fn_124_C238(void*, soModuleAccesser* accesser) {
    switch (accesser->getStatusModule().getStatusKind()) {
    case 0x116: {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float value = soValueAccesser::getConstantFloat(accesser, 0xfce, 0);
        if (work->getFloat(0x21000004) >= value)
            accesser->getStatusModule().changeStatusRequest(0x11e, accesser);
        break;
    }
    case 0x11e: {
        soWorkManageModule* work = &accesser->getWorkManageModule();
        float value = soValueAccesser::getConstantFloat(accesser, 0xfcf, 0);
        if (work->getFloat(0x21000004) >= value)
            accesser->getStatusModule().changeStatusRequest(0x11f, accesser);
        break;
    }
    }
}