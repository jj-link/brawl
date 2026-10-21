#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#pragma force_active on

extern "C" {
extern const float lbl_113_rodata_90;
}

struct Gravity {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};

template <class T, int Offset>
struct EnergySlot {};

template <class T, int Offset>
inline T* energy(unsigned char* storage, const EnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}

extern "C" void fn_113_1EF84(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();

    soParamAccesser* params = static_cast<soParamAccesser*>(
        accesser->getWorkManageModule().getParamAccesser());
    Gravity* gravity = energy(energies, EnergySlot<Gravity, 0x50>());

    gravity->speed = lbl_113_rodata_90;
    gravity->acceleration = -params->getParamFloat(accesser, 0xfd4, 0);
    gravity->terminalSpeed = params->getParamFloat(accesser, 0xfd5, 0);
    energies[0x55] |= 0x80;
}
