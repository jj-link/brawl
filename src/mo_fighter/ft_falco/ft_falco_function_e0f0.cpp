#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_108_E0F0(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}
