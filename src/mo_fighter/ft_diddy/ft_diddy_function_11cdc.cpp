#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
void fn_115_12E60(void*, soModuleAccesser* accesser);
}

extern "C" void fn_115_11CDC(void* process, soModuleAccesser* accesser) {
    accesser->getAreaModule().setWhole(0);
    if (accesser->getWorkManageModule().isFlag(0x22000014)) {
        fn_115_12E60(process, accesser);
    }
}
