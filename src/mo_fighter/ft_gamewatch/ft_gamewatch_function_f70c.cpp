#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
extern "C" void fn_107_F70C(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0)
        return energy->updateEnergy(accesser);
}