#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>
#include <math.h>

struct DededeLaunchStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
struct DededeLaunchGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
// Compile-time selectors address the embedded energies without a lookup.
template <class T, int Offset> struct DededeLaunchEnergySlot {};
template <class T, int Offset>
inline T* launchEnergy(unsigned char* storage, const DededeLaunchEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}

extern "C" {
extern const float lbl_117_rodata_C8, lbl_117_rodata_CC;
}

extern "C" void fn_117_15DF0(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    float angle = lbl_117_rodata_CC * accesser->getWorkManageModule().getFloat(0x21000005);
    float magnitude = accesser->getWorkManageModule().getFloat(0x21000006);
    float facing = accesser->getPostureModule().getLr();
    DededeLaunchStopEnergy* stop = launchEnergy(energies, DededeLaunchEnergySlot<DededeLaunchStopEnergy, 0x10>());
    float cosine = cos(angle);
    Vec2f speed(facing * (magnitude * cosine), lbl_117_rodata_C8);
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->speed), reinterpret_cast<const DededeSpeed*>(&speed));
    Vec2f brake(params->getParamFloat(accesser, 0xfb0, 0), lbl_117_rodata_C8);
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->brake), reinterpret_cast<const DededeSpeed*>(&brake));
    Vec2f limit(params->getParamFloat(accesser, 0xfaf, 0), lbl_117_rodata_C8);
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->limit), reinterpret_cast<const DededeSpeed*>(&limit));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
    DededeLaunchGravityEnergy* gravity = launchEnergy(energies, DededeLaunchEnergySlot<DededeLaunchGravityEnergy, 0x50>());
    float sine = sin(angle);
    gravity->speed = magnitude * sine;
    gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
    gravity->terminalSpeed = params->getParamFloat(accesser, 0xfb2, 0);
    reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
}
