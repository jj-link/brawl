#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

struct SonicMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

extern "C" void fn_27_3BD860(SonicMediatorEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_3BE2B0(SonicMediatorEnergy*, signed char*, soModuleAccesser*);

extern "C" void fn_123_D13C(SonicMediatorEnergy* energy, soModuleAccesser* accesser) {
    signed char state[20];
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100:
            state[19] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 101:
            state[18] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 102:
            state[17] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 103:
            state[15] = 0;
            state[16] = 0;
            fn_27_3BD860(energy, &state[16], accesser);
            break;
        case 104:
            state[14] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 105:
            state[13] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 106:
            state[12] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 107:
            state[11] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 108:
            state[10] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 109:
            state[9] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 110:
            state[8] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 111:
            state[7] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 112:
            state[6] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 113:
            state[5] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 114:
            state[3] = 0;
            state[4] = 0;
            fn_27_3BE2B0(energy, &state[4], accesser);
            break;
        case 115:
            state[2] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 116:
            state[1] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 117:
            state[0] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
    }
}
