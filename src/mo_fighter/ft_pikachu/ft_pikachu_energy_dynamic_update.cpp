#pragma section data_type ".data$pikachuCA70" ".bss"

#include <so/so_array.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>

namespace {
// Each special kinetic kind starts with an unsuspended update policy.
struct SpecialEnergyUpdatePolicy {
    bool suspended;
    SpecialEnergyUpdatePolicy() : suspended(false) {}
    ~SpecialEnergyUpdatePolicy() {}
    void update(soKineticEnergy* energy, soModuleAccesser* accesser) {
        if (!suspended)
            energy->updateEnergy(accesser);
    }
};
}

extern "C" void fn_98_CA70(void*,
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
            if (accesser->getKineticModule().getKineticType() <= 99) {
                if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0)
                    energy->updateEnergy(accesser);
            } else {
                switch (accesser->getKineticModule().getKineticType()) {
                case 100: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 101: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 102: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 103: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 104: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 105: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 106: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                case 107: { SpecialEnergyUpdatePolicy policy; policy.update(energy, accesser); break; }
                }
            }
        }
    }
}
