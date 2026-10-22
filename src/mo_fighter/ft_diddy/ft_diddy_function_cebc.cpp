#include <so/kinetic/so_kinetic_energy.h>
#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_115_CEBC(
    void*,
    soArrayFixed<soKineticEnergy**>* energies,
    soModuleAccesser* accesser
) {
    for (int i = 0; i < energies->size(); ++i) {
        soKineticEnergy* energy = *energies->at(i);
        u32 suspension;
        if (energy->isEnable() && (suspension = reinterpret_cast<const u8*>(energy)[6]) != 1) {
            if (energy->isEnable() == true && suspension == 0) {
                if (energy->isEnable() == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}
