#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" void fn_27_151D90(void* self, soModuleAccesser* accesser) {
    int val = soValueAccesser::getConstantInt(accesser, 0x5A43, 0);
    accesser->getWorkManageModule().setInt(val, 0x10000010);
}
