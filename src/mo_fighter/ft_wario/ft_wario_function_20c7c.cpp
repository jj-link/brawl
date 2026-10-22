#pragma opt_propagation off

#include <so/kinetic/so_kinetic_energy.h>
#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_110_20C7C(void*, soArrayFixed<soKineticEnergy**>* energies,
                             soModuleAccesser* accesser) {
    for (int i = 0; i < energies->size(); ++i) {
        soKineticEnergy* energy = *energies->at(i);
        u32 disabled =
            ((static_cast<u32>(reinterpret_cast<const u8*>(energy)[5]) & 0x80) >> 7) == 0;
        u32 enabled = disabled == 0;
        u32 suspension;

        if (enabled && (suspension = reinterpret_cast<const u8*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}
