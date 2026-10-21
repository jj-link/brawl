#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_98_14298(soModuleAccesser* accesser, int handleIndex) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    int handle = work.getInt(handleIndex);
    if (handle != 0) accesser->getEffectModule().remove(handle);
    work.setInt(0, handleIndex);
}
