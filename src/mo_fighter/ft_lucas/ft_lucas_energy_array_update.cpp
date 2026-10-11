#include <so/kinetic/so_kinetic_energy.h>
#include <so/so_array.h>

extern "C" void fn_114_FCC0(void*, soArrayFixed<soKineticEnergy**>* energies, soModuleAccesser* accesser) {
    for (int i = 0; i < energies->size(); ++i) {
        soKineticEnergy* energy = *energies->at(i);
        // The original normalizes the leading enable bit through disable/enable queries.
        u32 disabled = ((static_cast<u32>(reinterpret_cast<const u8*>(energy)[5]) & 0x80) >> 7) == 0;
        u32 enabled = disabled == 0;
        u32 suspension;
        // Retain the original nested guards and complete suspension-byte tests.
        if (enabled && (suspension = reinterpret_cast<const u8*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}

#pragma force_active on
extern "C" void fn_114_FD90(void*) { }
