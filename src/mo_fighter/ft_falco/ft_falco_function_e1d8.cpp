#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

struct EnergyView {
    virtual void v0();
    virtual soKineticEnergy* updateEnergy(soModuleAccesser* accesser);
};

extern "C" soKineticEnergy* fn_108_E1D8(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() != true)
        return energy;
    if (reinterpret_cast<u8*>(energy)[6] != 0)
        return energy;
    return reinterpret_cast<EnergyView*>(energy)->updateEnergy(accesser);
}