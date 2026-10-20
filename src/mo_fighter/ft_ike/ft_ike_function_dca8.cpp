#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_119_DCA8(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().isFlag(0x22000012)) {
        accesser->getCollisionShieldModule().setStatus(0, 0, 1);
    }
}
