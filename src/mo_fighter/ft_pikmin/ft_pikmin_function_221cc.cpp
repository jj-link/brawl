#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#include <types.h>

#pragma force_active on

extern "C" void fn_113_222B8(char*, soKineticEnergy*, soModuleAccesser*);

extern "C" void fn_113_221CC(soKineticEnergy* energy, soModuleAccesser* accesser) {
    char values[5];

    if (!energy->isEnable() || *(u8*)((char*)energy + 6) == 1) {
        return;
    }
    if (accesser->getKineticModule().getKineticType() == 0x34) {
        values[3] = 0;
        values[4] = 0;
        fn_113_222B8(&values[4], energy, accesser);
    } else if (accesser->getKineticModule().getKineticType() == 0x35) {
        values[2] = 0;
        values[1] = 0;
        values[0] = 0;
        fn_113_222B8(values, energy, accesser);
    } else {
        energy->updateEnergy(accesser);
    }
}
