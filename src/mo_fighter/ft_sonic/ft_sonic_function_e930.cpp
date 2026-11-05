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
namespace {
struct SonicStatusEnergyState {
    unsigned char initialized;
    SonicStatusEnergyState() { __memclr(&initialized, sizeof(initialized)); }
    void update(SonicMediatorEnergy* energy, soModuleAccesser* accesser) {
        reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    }
};
}
extern "C" void fn_123_E930(SonicMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 101: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 102: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 103: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 104: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 105: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 106: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 107: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 108: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 109: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 110: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 111: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 112: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 113: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 114: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 115: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 116: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 117: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        }
    }
}