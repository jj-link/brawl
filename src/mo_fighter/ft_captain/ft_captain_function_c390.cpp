#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_100_C390(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<unsigned char*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}
