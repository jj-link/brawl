#include <so/so_array.h>
#include <so/kinetic/so_kinetic_energy.h>

extern "C" void fn_99_B084(void*,
    soArrayFixed<soInstanceUnitFullProperty<soKineticEnergy*>*>* energies,
    soModuleAccesser* accesser) {
    for (int index = 0; index < energies->size(); ++index) {
        soKineticEnergy* energy = energies->at(index)->m_element;
        if (energy->isEnable() == false)
            continue;
        unsigned int suspended = reinterpret_cast<u8*>(energy)[6];
        if (suspended == 1)
            continue;
        // Preserve the filtered-array and per-energy dispatch guards separately.
        if (energy->isEnable() == true && suspended == 0) {
            if (energy->isEnable() == true && suspended == 0)
                energy->updateEnergy(accesser);
        }
    }
}
