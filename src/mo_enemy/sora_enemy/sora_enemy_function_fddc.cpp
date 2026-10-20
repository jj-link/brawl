#include <em/em_create.h>
#include <em/em_extend_param_accesser.h>
#pragma force_active on

extern "C" int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void* acc, unsigned int id, unsigned int arg);

struct UnkOwner {
    char pad[0x3C];
    void* acc;
};

extern "C" bool fn_41_FDDC(UnkOwner* acc, int param) {
    if (param != 0x169) {
        if (param >= getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(acc->acc, 0x59D9, 0)) {
            if (param <= getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(acc->acc, 0x59DA, 0)) {
                return true;
            }
        }
    }
    return false;
}
