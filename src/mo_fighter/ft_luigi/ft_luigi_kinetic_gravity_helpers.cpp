#include <so/kinetic/so_kinetic_energy.h>

extern "C" void fn_99_B1A4(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}
