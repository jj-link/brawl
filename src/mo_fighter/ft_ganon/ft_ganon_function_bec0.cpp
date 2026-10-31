#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

#pragma peephole on

extern "C" void fn_109_BEC0(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}
