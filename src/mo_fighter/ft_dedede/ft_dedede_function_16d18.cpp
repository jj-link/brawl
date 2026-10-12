#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

struct DededeSpecialStopEnergy {
    unsigned char base[8];
    Vec2f speed, acceleration, brake, limit;
};
struct DededeSpecialGravityEnergy {
    unsigned char base[8];
    float speed, acceleration, terminalSpeed;
};
template <class T, int Offset> struct DededeSpecialEnergySlot {};
template <class T, int Offset>
inline T* specialEnergy(unsigned char* storage, const DededeSpecialEnergySlot<T, Offset>&) {
    return reinterpret_cast<T*>(storage + Offset);
}
inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}
extern "C" {
extern const float lbl_117_rodata_C8;
}

extern "C" void fn_117_16D18(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    Vec2f speed;
    speed.m_x = accesser->getWorkManageModule().getFloat(0x21000002);
    speed.m_y = accesser->getWorkManageModule().getFloat(0x21000003);
    DededeSpecialStopEnergy* stop = specialEnergy(energies, DededeSpecialEnergySlot<DededeSpecialStopEnergy, 0x70>());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->speed), speedWords(Vec2f(speed.m_x, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(&stop->limit), speedWords(Vec2f(params->getParamFloat(accesser, 0xfaf, 0), lbl_117_rodata_C8)));
    reinterpret_cast<unsigned char*>(stop)[5] |= 0x80;
    DededeSpecialGravityEnergy* gravity = specialEnergy(energies, DededeSpecialEnergySlot<DededeSpecialGravityEnergy, 0x50>());
    gravity->speed = speed.m_y;
    gravity->acceleration = -params->getParamFloat(accesser, 0xfb1, 0);
    gravity->terminalSpeed = -params->getParamFloat(accesser, 0xfb2, 0);
    reinterpret_cast<unsigned char*>(gravity)[5] |= 0x80;
}
