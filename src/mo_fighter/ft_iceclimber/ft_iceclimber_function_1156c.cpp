#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_energy.h>

#pragma force_active on
#pragma optimization_level 4

struct Energy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    unsigned char suspended;
};

extern "C" void fn_27_3478AC(Energy*, soModuleAccesser*);
extern "C" void fn_27_347F90(Energy*, signed char*, soModuleAccesser*);

extern "C" void fn_105_1156C(Energy* energy, soModuleAccesser* accesser) {
    signed char state[16];
    int type = accesser->getKineticModule().getKineticType();

    if (type <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        if (!energy->enabled.isEnable() || energy->suspended == true)
            return;

        do {
            if ((unsigned int)(type - 101) <= 3) {
                fn_27_3478AC(energy, accesser);
                break;
            }

            switch (accesser->getKineticModule().getKineticType()) {
            case 100:
                state[15] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 101:
                state[14] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 102:
                state[13] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 103:
                state[12] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 104:
                state[11] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 105:
                state[10] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 106:
                state[9] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 107:
                state[8] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 108:
                state[7] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 109:
                state[6] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 110:
                state[4] = 0;
                state[5] = 0;
                fn_27_347F90(energy, &state[5], accesser);
                break;
            case 111:
                state[3] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 112:
                state[2] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 113:
                state[1] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            case 114:
                state[0] = 0;
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
                break;
            default:
                break;
            }
        } while (false);
    }
}