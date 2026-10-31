#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
#pragma force_tail_call on

extern "C" void fn_107_FC7C(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        energy->updateEnergy(accesser);
    }
}