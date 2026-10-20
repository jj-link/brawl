#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" int getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" bool fn_27_6405C(void* self, soModuleAccesser* accesser) {
    unsigned int constant =
        getConstantInt__15soValueAccesserFP16soModuleAccesserUlUl(
            accesser, 0x55f5, 0);
    unsigned int value =
        *reinterpret_cast<unsigned int*>(
            static_cast<unsigned char*>(self) + 0x38);
    return value >= constant;
}
