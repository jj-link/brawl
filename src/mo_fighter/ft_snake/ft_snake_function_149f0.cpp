#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on
extern "C" void fn_122_14650(soModuleAccesser*, float);
extern "C" void fn_122_149F0(void*, soModuleAccesser* accesser) {
    soWorkManageModule& work = accesser->getWorkManageModule();
    int maximum = soValueAccesser::getConstantInt(accesser, 0x5dc0, 0);
    if (work.getInt(0x20000002) <= maximum) {
        soWorkManageModule& chargeWork = accesser->getWorkManageModule();
        float limit = static_cast<float>(soValueAccesser::getConstantInt(accesser, 0x5dc0, 0));
        float charge = static_cast<float>(chargeWork.getInt(0x20000002));
        float proportion = charge / limit;
        fn_122_14650(accesser, proportion);
    }
}
