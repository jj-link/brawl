#include <so/so_array.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

namespace {
struct SonicEnergyFlag {
    unsigned char initialized;
    SonicEnergyFlag() {
        __memclr(&initialized, sizeof(initialized));
    }
    void update(soKineticEnergy* energy, soModuleAccesser* accesser) {
        energy->updateEnergy(accesser);
    }
};
}

extern "C" void fn_123_C914(void*,
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
                case 100: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 101: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 102: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 103: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 104: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 105: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 106: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 107: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 108: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 109: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 110: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 111: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 112: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 113: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 114: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 115: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 116: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                case 117: { SonicEnergyFlag flag; flag.update(energy, accesser); break; }
                }
            }
        }
    }
}