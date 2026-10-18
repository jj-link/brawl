#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" {
void fn_123_17F74(soKineticEnergy* energy, soModuleAccesser* accesser);
}

extern "C" void fn_123_17ED8(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() == 0x20 ||
        accesser->getKineticModule().getKineticType() == 0x21) {
        fn_123_17F74(energy, accesser);
    } else {
        energy->updateEnergy(accesser);
    }
}
