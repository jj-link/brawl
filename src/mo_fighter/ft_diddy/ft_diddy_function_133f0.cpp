#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mt/mt_vector.h>
#pragma force_active on

struct DiddyStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
struct DiddyGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
template <class T, int Offset> struct DiddyEnergySlot {};
template <class T, int Offset>
inline T* energy(unsigned char* storage, const DiddyEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}

extern "C" {
extern const float lbl_115_rodata_E8;
void fn_115_C8BC(float* dst, const float* src);
}

extern "C" void fn_115_133F0(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    DiddyStopEnergy* stop = energy(energies, DiddyEnergySlot<DiddyStopEnergy, 0x10>());
    Vec2f speed;
    speed.m_x = accesser->getWorkManageModule().getFloat(0x21000004);
    speed.m_y = lbl_115_rodata_E8;
    fn_115_C8BC(reinterpret_cast<float*>(&stop->speed), reinterpret_cast<const float*>(&speed));
    stop->base[5] |= 0x80;
    DiddyGravityEnergy* gravity = energy(energies, DiddyEnergySlot<DiddyGravityEnergy, 0x50>());
    gravity->speed = accesser->getWorkManageModule().getFloat(0x21000005);
    gravity->acceleration = -params->getParamFloat(accesser, 0xfa4, 0);
    gravity->terminalSpeed = params->getParamFloat(accesser, 0xfa5, 0);
    gravity->base[5] |= 0x80;
}
