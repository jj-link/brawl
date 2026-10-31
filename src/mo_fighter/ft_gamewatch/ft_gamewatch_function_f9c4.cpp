#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_107_F9C4(soKineticEnergy* energy, soModuleAccesser* accesser) {
    u8* p = reinterpret_cast<u8*>(energy);
    if (energy->isEnable() == true && p[6] == 0) {
        energy->updateEnergy(accesser);
    }
}
