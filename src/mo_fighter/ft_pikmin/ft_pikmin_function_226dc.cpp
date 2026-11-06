#pragma force_active on
#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <so/work/so_work_manage_module_impl.h>

extern "C" float fn_113_226DC(soModuleAccesser* accesser) {
    float result;
    if (accesser->getWorkManageModule().isFlag(0x12000003) == 1) {
        result = soValueAccesser::getConstantFloat(accesser, 0xfca, 0);
    } else {
        result = soValueAccesser::getConstantFloat(accesser, 0xfc6, 0);
    }
    if (accesser->getWorkManageModule().getInt(0x10000008) == 1) {
        result *= soValueAccesser::getConstantFloat(accesser, 0xfa8, 0);
    } else if (accesser->getWorkManageModule().getInt(0x10000008) == 2) {
        result *= soValueAccesser::getConstantFloat(accesser, 0xfa9, 0);
    }
    return result;
}
