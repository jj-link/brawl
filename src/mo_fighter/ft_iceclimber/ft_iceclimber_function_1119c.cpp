#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

namespace {
struct KineticEnergyStatePolicy {
    unsigned char initialized;
    KineticEnergyStatePolicy() { __memclr(&initialized, sizeof(initialized)); }
    void update(soKineticEnergy* energy, soModuleAccesser* accesser) {
        energy->updateEnergy(accesser);
    }
};
}

extern "C" void fn_27_347C5C(soKineticEnergy* energy, soModuleAccesser* accesser);

extern "C" void fn_105_1119C(soKineticEnergy* energy, soModuleAccesser* accesser) {
    int kineticType = accesser->getKineticModule().getKineticType();
    if (kineticType <= 99) {
        if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0)
            energy->updateEnergy(accesser);
    } else {
        if (!energy->isEnable() || reinterpret_cast<u8*>(energy)[6] == 1)
            return;
        if ((unsigned int)(kineticType - 101) <= 3U) {
            fn_27_347C5C(energy, accesser);
        } else {
            switch (accesser->getKineticModule().getKineticType()) {
            case 100: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 101: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 102: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 103: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 104: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 105: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 106: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 107: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 108: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 109: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 110: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 111: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 112: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 113: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            case 114: { KineticEnergyStatePolicy state; state.update(energy, accesser); break; }
            }
        }
    }
}
