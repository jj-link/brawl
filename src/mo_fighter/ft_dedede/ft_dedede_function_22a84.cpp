#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_117_22B20(void* self, soModuleAccesser* accesser);
extern "C" void fn_117_22CF0(void* self, soModuleAccesser* accesser);

extern "C" void fn_117_22A84(void* self, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000004) == 0) {
        fn_117_22B20(self, accesser);
    } else if (accesser->getWorkManageModule().getInt(0x20000004) == 1) {
        fn_117_22CF0(self, accesser);
    }
}
