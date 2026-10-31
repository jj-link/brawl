#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

struct MetaKnightEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

extern "C" void fn_27_3598EC(MetaKnightEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_359AE8(MetaKnightEnergy*, signed char*, soModuleAccesser*);
extern "C" void fn_27_359DF8(MetaKnightEnergy*, signed char*, soModuleAccesser*);

extern "C" void fn_111_B410(MetaKnightEnergy* energy, soModuleAccesser* accesser) {
    signed char state[11];
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100:
            state[9] = 0;
            state[10] = 0;
            fn_27_3598EC(energy, &state[10], accesser);
            break;
        case 101:
            state[7] = 0;
            state[8] = 0;
            fn_27_359AE8(energy, &state[8], accesser);
            break;
        case 102:
            state[6] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 103:
            state[5] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 104:
            state[4] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 105:
            state[3] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        case 106:
            state[1] = 0;
            state[2] = 0;
            fn_27_359DF8(energy, &state[2], accesser);
            break;
        case 107:
            state[0] = 0;
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
    }
}
