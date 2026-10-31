#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_109_B8A0(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0)
        energy->updateEnergy(accesser);
}
