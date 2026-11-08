#include <so/so_array.h>
#include <so/so_module_accesser.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

namespace {
struct MetaKnightEnergyFlag {
    unsigned char initialized;
    MetaKnightEnergyFlag() {
        __memclr(&initialized, sizeof(initialized));
    }
};
}

extern "C" void fn_111_AC2C(void*,
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
                case 100: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 101: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 102: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 103: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 104: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 105: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 106: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                case 107: { MetaKnightEnergyFlag flag; energy->updateEnergy(accesser); break; }
                }
            }
        }
    }
}
