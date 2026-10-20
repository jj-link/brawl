#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" {
extern unsigned int lbl_27_bss_7B0C;
soModuleAccesser* fn_27_30FA2C(
    unsigned int*, int, void*, soModuleAccesser*, int);
int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);
}

extern "C" int fn_27_1922CC(soModuleAccesser* accesser, unsigned long value) {
    soModuleAccesser* module =
        fn_27_30FA2C(&lbl_27_bss_7B0C, 1, reinterpret_cast<void*>(value), accesser, 0);
    return getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
        accesser, reinterpret_cast<unsigned long>(module), 0);
}
