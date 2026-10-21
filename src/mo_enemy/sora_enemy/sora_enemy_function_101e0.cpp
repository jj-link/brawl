#include <so/so_module_accesser.h>
#pragma force_active on

extern "C" float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
    soModuleAccesser*, unsigned long, unsigned long);

extern "C" int fn_41_101E0(void* self, int p2, unsigned int p3, float p4) {
    unsigned int result = -1;

    if (p2 == 3 && p3 == 1) {
        float first = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
            *(soModuleAccesser**)((char*)self + 0x3C), 0xBE3, 0);

        if (p4 >= first) {
            result = 2;
        } else {
            float second = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(
                *(soModuleAccesser**)((char*)self + 0x3C), 0xBE4, 0);
            result = p4 >= second;
        }
    }

    return result;
}
