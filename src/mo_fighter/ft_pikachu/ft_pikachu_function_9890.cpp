#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void* fn_98_9890(soModuleAccesser* accesser) {
    return reinterpret_cast<void*>(accesser->getWorkManageModule().getInt(0x10000043));
}
