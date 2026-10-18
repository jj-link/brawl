#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_98_1523C(void* owner, soModuleAccesser* accesser) {
    accesser->getWorkManageModule().offFlag(0x12000004);
}
