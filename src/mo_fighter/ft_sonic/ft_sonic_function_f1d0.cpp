#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_123_F928(void* p1, soModuleAccesser* accesser);
}

extern "C" void fn_123_F1D0(void* arg1, soModuleAccesser* accesser) {
    if (!accesser->getWorkManageModule().isFlag(0x22000012)) {
        fn_123_F928(arg1, accesser);
    }
    accesser->getWorkManageModule().onFlag(0x22000013);
}
