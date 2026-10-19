#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" void fn_124_C1D8(void*, soModuleAccesser* accesser) {
    float scale = accesser->getWorkManageModule().getFloat(0x21000005);
    accesser->getPostureModule().setOwnerScale(scale);
}
