#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_108_E008(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() != true) return;
    if (reinterpret_cast<u8*>(energy)[6] != 0) return;
    return energy->updateEnergy(accesser);
}
