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
    SonicStatusEnergyState() {
        __memclr(&initialized, sizeof(initialized));
    }
    void update(SonicMediatorEnergy* energy, soModuleAccesser* accesser) {
        reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    }
};
}

extern "C" void fn_123_E52C(SonicMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 0x63) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 0x64: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x65: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x66: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x67: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x68: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x69: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6A: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6B: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6C: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6D: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6E: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x6F: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x70: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x71: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x72: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x73: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x74: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        case 0x75: { SonicStatusEnergyState state; state.update(energy, accesser); break; }
        }
    }
}