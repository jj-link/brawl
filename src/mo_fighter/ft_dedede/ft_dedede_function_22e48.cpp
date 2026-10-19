#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_117_22E48(void* self, soModuleAccesser* accesser, int duration) {
    accesser->getWorkManageModule().setInt(duration, 0x20000001);
    accesser->getWorkManageModule().setInt(0, 0x20000000);
}
