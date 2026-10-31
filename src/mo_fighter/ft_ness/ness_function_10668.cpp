#pragma scheduling off
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
#pragma scheduling on

extern "C" void fn_101_10668(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}