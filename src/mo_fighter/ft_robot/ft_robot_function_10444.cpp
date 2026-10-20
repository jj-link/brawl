#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(soModuleAccesser*, unsigned long, unsigned long);

extern "C" void fn_120_10444(void* self, soModuleAccesser* accesser) {
    accesser->getWorkManageModule().onFlag(0x12000042);
    soWorkManageModule& work = accesser->getWorkManageModule();
    int value = getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0x5dcc, 0);
    work.setInt(value, 0x10000043);
}
