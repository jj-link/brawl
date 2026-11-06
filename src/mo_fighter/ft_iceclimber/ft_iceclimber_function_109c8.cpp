#include <so/so_array.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

namespace {
// Each special kinetic kind gets a one-byte default-initialized state.
struct KineticEnergyStatePolicy {
    unsigned char initialized;
    KineticEnergyStatePolicy() {
        __memclr(&initialized, sizeof(initialized));
    }
    void update(soKineticEnergy* energy, soModuleAccesser* accesser) {
        energy->updateEnergy(accesser);
    }
};
}

extern "C" void fn_105_109C8(void*,
    soArrayFixed<soInstanceUnitFullProperty<soKineticEnergy*>*>* energies,
    soModuleAccesser* accesser) {
    for (int index = 0; index < energies->size(); ++index) {
        soKineticEnergy* energy = energies->at(index)->m_element;
        if (energy->isEnable() == false)
            continue;
        unsigned int suspended = reinterpret_cast<u8*>(energy)[6];
        if (suspended == 1)
            continue;
        if (energy->isEnable() == true && suspended == 0) {
            int kineticType = accesser->getKineticModule().getKineticType();
            if (kineticType <= 99) {
                if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0)
                    energy->updateEnergy(accesser);
            } else {
                if (energy->isEnable() && reinterpret_cast<u8*>(energy)[6] != 1) {
                    if ((unsigned int)(kineticType - 101) <= 3U) {
                        energy->updateEnergy(accesser);
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
        }
    }
}
