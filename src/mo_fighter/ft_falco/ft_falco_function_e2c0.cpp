#pragma force_active on
#include <so/kinetic/so_kinetic_energy.h>

extern "C" void fn_108_E2C0(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() != true)
        return;
    if (reinterpret_cast<u8*>(energy)[6] != 0)
        return;
    energy->updateEnergy(accesser);
}