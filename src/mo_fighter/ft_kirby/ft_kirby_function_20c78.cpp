#include <types.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_96_21194(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_27_359750(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BD860(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BE2B0(soKineticEnergy*, signed char*, soModuleAccesser*);

extern "C" void fn_96_20C78(soKineticEnergy* energy, soModuleAccesser* accesser) {
    signed char state[29];
    if (accesser->getKineticModule().getKineticType() <= 99) {
        fn_96_21194(energy, accesser);
        return;
    }
    switch (accesser->getWorkManageModule().getInt(0x10000048)) {
    case 22:
        if (accesser->getKineticModule().getKineticType() <= 99) {
            fn_96_21194(energy, accesser);
            return;
        }
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: state[20] = 0; energy->updateEnergy(accesser); break;
        case 101: state[22] = 0; state[21] = 0; fn_27_359750(energy, &state[21], accesser); break;
        case 102: state[23] = 0; energy->updateEnergy(accesser); break;
        case 103: state[24] = 0; energy->updateEnergy(accesser); break;
        case 104: state[25] = 0; energy->updateEnergy(accesser); break;
        case 105: state[26] = 0; energy->updateEnergy(accesser); break;
        case 106: state[27] = 0; energy->updateEnergy(accesser); break;
        case 107: state[28] = 0; energy->updateEnergy(accesser); break;
        }
        break;
    case 47:
        if (accesser->getKineticModule().getKineticType() <= 99) {
            fn_96_21194(energy, accesser);
            return;
        }
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: state[0] = 0; energy->updateEnergy(accesser); break;
        case 101: state[1] = 0; energy->updateEnergy(accesser); break;
        case 102: state[2] = 0; energy->updateEnergy(accesser); break;
        case 103: state[4] = 0; state[3] = 0; fn_27_3BD860(energy, &state[3], accesser); break;
        case 104: state[5] = 0; energy->updateEnergy(accesser); break;
        case 105: state[6] = 0; energy->updateEnergy(accesser); break;
        case 106: state[7] = 0; energy->updateEnergy(accesser); break;
        case 107: state[8] = 0; energy->updateEnergy(accesser); break;
        case 108: state[9] = 0; energy->updateEnergy(accesser); break;
        case 109: state[10] = 0; energy->updateEnergy(accesser); break;
        case 110: state[11] = 0; energy->updateEnergy(accesser); break;
        case 111: state[12] = 0; energy->updateEnergy(accesser); break;
        case 112: state[13] = 0; energy->updateEnergy(accesser); break;
        case 113: state[14] = 0; energy->updateEnergy(accesser); break;
        case 114: state[16] = 0; state[15] = 0; fn_27_3BE2B0(energy, &state[15], accesser); break;
        case 115: state[17] = 0; energy->updateEnergy(accesser); break;
        case 116: state[18] = 0; energy->updateEnergy(accesser); break;
        case 117: state[19] = 0; energy->updateEnergy(accesser); break;
        }
        break;
    default:
        fn_96_21194(energy, accesser);
        break;
    }
}
