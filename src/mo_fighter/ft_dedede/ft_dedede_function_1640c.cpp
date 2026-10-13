#include <so/so_module_accesser.h>
#include <so/so_value_accesser.h>
#include <mo_fighter/ft_dedede/ft_dedede_speed.h>

extern "C" const float lbl_117_rodata_C8;
struct DededeStopEnergySlot {};
inline unsigned char* stopEnergy(unsigned char* energies, const DededeStopEnergySlot&) {
    return energies + 0x10;
}

inline const DededeSpeed* speedWords(const Vec2f& speed) {
    return reinterpret_cast<const DededeSpeed*>(&speed);
}

// Mode 35 clears stop speed and braking, then applies its horizontal limit.
extern "C" void fn_117_1640C(void*, unsigned char* energies, soModuleAccesser* accesser) {
    accesser->getKineticModule().unableEnergyAll();
    soParamAccesser* params = static_cast<soParamAccesser*>(accesser->getWorkManageModule().getParamAccesser());
    unsigned char* stop = stopEnergy(energies, DededeStopEnergySlot());
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 0x08), speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 0x18), speedWords(Vec2f(lbl_117_rodata_C8, lbl_117_rodata_C8)));
    fn_117_D134(reinterpret_cast<DededeSpeed*>(stop + 0x20), speedWords(Vec2f(params->getParamFloat(accesser, 0xfae, 0), lbl_117_rodata_C8)));
    stop[5] |= 0x80;
}
