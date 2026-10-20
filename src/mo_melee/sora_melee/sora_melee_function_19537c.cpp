#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" float fn_27_19537C(soModuleAccesser* accesser) {
    return getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(accesser, 0xdaf, 0);
}
