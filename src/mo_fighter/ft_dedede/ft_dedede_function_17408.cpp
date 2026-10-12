#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

namespace {
struct DededeStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
struct DededeGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
// Stateless selectors identify the embedded energies without a runtime lookup.
template <class T, int Offset> struct DededeEnergySlot {};
template <class T, int Offset>
inline T* energy(unsigned char* storage, const DededeEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}
} // namespace

extern "C" const float lbl_117_rodata_C8;

extern "C" void fn_117_17408(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    DededeStopEnergy* stop = energy(energies, DededeEnergySlot<DededeStopEnergy, 0x10>());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->speed), speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->brake), speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->limit), speedWords(Vec2f(params->getParamFloat(accesser, 0xfaf, 0), lbl_117_rodata_C8)));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
    DededeGravityEnergy* gravity = energy(energies, DededeEnergySlot<DededeGravityEnergy, 0x50>());
    gravity->speed = lbl_117_rodata_C8;
    gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
    gravity->terminalSpeed = -params->getParamFloat(accesser, 0xfb2, 0);
    reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
}
