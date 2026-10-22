#include <so/kinetic/so_kinetic_energy.h>
#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_119_BCCC(void*, soArrayFixed<soKineticEnergy**>* energies,
                            soModuleAccesser* accesser) {
    for (int i = 0; i < energies->size(); ++i) {
        soKineticEnergy* energy = *energies->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(energy)[5]) &
              0x80) >>
             7) == 0);
        bool enabled = disabled == false;
        unsigned int suspension;

        if (enabled &&
            (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}
