#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_94_F418(void*, soModuleAccesser* accesser) {
    float a = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa9, 0);
    accesser->getWorkManageModule().setFloat(a, 0x11000000);
    float b = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xfa7, 0);
    accesser->getWorkManageModule().setFloat(b, 0x11000001);
}
