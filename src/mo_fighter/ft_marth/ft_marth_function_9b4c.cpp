#include <so/kinetic/so_kinetic_energy.h>
#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_106_9B4C(void*, soArrayFixed<soKineticEnergy**>* energies, soModuleAccesser* accesser) {
    for (int i = 0; i < energies->size(); ++i) {
        soKineticEnergy* energy = *energies->at(i);
        if (!energy->isEnable() || reinterpret_cast<const bool*>(energy)[6] == true) {
            continue;
        }
        bool suspension = reinterpret_cast<const bool*>(energy)[6];
        if (energy->isEnable() == true && suspension == false) {
            if (energy->isEnable() == true && suspension == false) {
                energy->updateEnergy(accesser);
            }
        }
    }
}
