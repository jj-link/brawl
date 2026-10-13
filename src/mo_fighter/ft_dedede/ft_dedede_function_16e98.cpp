#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>

struct DededeSpecialGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
template <class T, int Offset> struct DededeSpecialEnergySlot {};
template <class T, int Offset>
inline T* specialEnergy(unsigned char* storage, const DededeSpecialEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}
extern "C" {
extern const float lbl_117_rodata_C8;
}

extern "C" void fn_117_16E98(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    DededeSpecialGravityEnergy* gravity = specialEnergy(energies, DededeSpecialEnergySlot<DededeSpecialGravityEnergy, 0x50>());
    gravity->speed = lbl_117_rodata_C8;
    gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
    gravity->terminalSpeed = -params->getParamFloat(accesser, 0xfb2, 0);
    reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
}
