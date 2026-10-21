#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>
#pragma force_active on

extern "C" void fn_112_E148(void*, soModuleAccesser* accesser) {
    float val = accesser->getWorkManageModule().getFloat(0x11000013);
    float c = soValueAccesser::getConstantFloat(accesser, 0xfb6, 0);
    float product = val * c;
    accesser->getWorkManageModule().setFloat(product, 0x11000013);
}
