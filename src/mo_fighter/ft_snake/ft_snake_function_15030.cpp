#include <so/so_module_accesser.h>
#pragma force_active on

// Guarded cooldown decrement: only count the shared work timer down while it
// is still positive.
extern "C" void fn_122_15030(void*, soModuleAccesser* accesser) {
    if (accesser->getWorkManageModule().getInt(0x20000002) > 0) {
        soWorkManageModule& work = accesser->getWorkManageModule();
        work.decInt(0x20000002);
    }
}
