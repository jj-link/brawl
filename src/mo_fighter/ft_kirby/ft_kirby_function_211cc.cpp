#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>

#pragma force_active on

extern "C" void fn_96_213E8(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_27_3598EC(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_359AE8(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_359DF8(soKineticEnergy*, signed char*, soModuleAccesser*);

extern "C" void fn_96_211CC(soKineticEnergy* energy, soModuleAccesser* accesser) {
    signed char state[11];

    if (accesser->getKineticModule().getKineticType() <= 99) {
        fn_96_213E8(energy, accesser);
        return;
    }

    switch (accesser->getWorkManageModule().getInt(0x10000048)) {
    case 22:
        if (accesser->getKineticModule().getKineticType() <= 99) {
            fn_96_213E8(energy, accesser);
            return;
        }

        switch (accesser->getKineticModule().getKineticType()) {
        case 100:
            state[1] = 0;
            state[0] = 0;
            fn_27_3598EC(energy, &state[0], accesser);
            break;
        case 101:
            state[3] = 0;
            state[2] = 0;
            fn_27_359AE8(energy, &state[2], accesser);
            break;
        case 102:
            state[4] = 0;
            energy->updateEnergy(accesser);
            break;
        case 103:
            state[5] = 0;
            energy->updateEnergy(accesser);
            break;
        case 104:
            state[6] = 0;
            energy->updateEnergy(accesser);
            break;
        case 105:
            state[7] = 0;
            energy->updateEnergy(accesser);
            break;
        case 106:
            state[9] = 0;
            state[8] = 0;
            fn_27_359DF8(energy, &state[8], accesser);
            break;
        case 107:
            state[10] = 0;
            energy->updateEnergy(accesser);
            break;
        }
        break;
    default:
        fn_96_213E8(energy, accesser);
        break;
    }
}
