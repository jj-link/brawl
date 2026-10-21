#include <so/so_value_accesser.h>
#include <so/so_module_accesser.h>
#include <types.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" int fn_27_634CC(soModuleAccesser* accesser, int kind) {
    unsigned int var;
    if (kind != 0x169) {
        if (kind != 0x169 &&
            kind >= getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                        accesser, 0x55f1, 0) &&
            kind <= getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
                        accesser, 0x55f2, 0)) {
            var = 1;
        } else {
            var = 0;
        }
        if (var == 1) {
            return 1;
        }
    }
    return 0;
}
