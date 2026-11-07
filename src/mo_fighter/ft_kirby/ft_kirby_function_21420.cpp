#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on
extern "C" void fn_96_217B8(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_27_3326C4(soKineticEnergy*, soModuleAccesser*);
extern "C" void fn_27_3BD5B8(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BD698(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BD914(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BDE6C(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BE364(soKineticEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_96_21420(soKineticEnergy* energy, soModuleAccesser* accesser) {
    signed char state[23];
    if (accesser->getKineticModule().getKineticType() <= 99) {
        fn_96_217B8(energy, accesser);
        return;
    }
    switch (accesser->getWorkManageModule().getInt(0x10000048)) {
    case 47:
        if (accesser->getKineticModule().getKineticType() <= 99) {
            fn_96_217B8(energy, accesser);
            return;
        }
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: state[1]=0; state[0]=0; fn_27_3BD5B8(energy, &state[0], accesser); break;
        case 101: state[3]=0; state[2]=0; fn_27_3BD698(energy, &state[2], accesser); break;
        case 102: state[4]=0; energy->updateEnergy(accesser); break;
        case 103: state[5]=0; energy->updateEnergy(accesser); break;
        case 104: state[7]=0; state[6]=0; fn_27_3BD914(energy, &state[6], accesser); break;
        case 105: state[8]=0; energy->updateEnergy(accesser); break;
        case 106: state[9]=0; energy->updateEnergy(accesser); break;
        case 107: state[11]=0; state[10]=0; fn_27_3BDE6C(energy, &state[10], accesser); break;
        case 108: state[12]=0; energy->updateEnergy(accesser); break;
        case 109: state[13]=0; energy->updateEnergy(accesser); break;
        case 110: state[14]=0; energy->updateEnergy(accesser); break;
        case 111: state[15]=0; energy->updateEnergy(accesser); break;
        case 112: state[16]=0; energy->updateEnergy(accesser); break;
        case 113: state[17]=0; energy->updateEnergy(accesser); break;
        case 114: state[18]=0; energy->updateEnergy(accesser); break;
        case 115: state[20]=0; state[19]=0; fn_27_3BE364(energy, &state[19], accesser); break;
        case 116: state[21]=0; energy->updateEnergy(accesser); break;
        case 117: state[22]=0; energy->updateEnergy(accesser); break;
        }
        break;
    case 12: fn_27_3326C4(energy, accesser); break;
    default: fn_96_217B8(energy, accesser); break;
    }
}