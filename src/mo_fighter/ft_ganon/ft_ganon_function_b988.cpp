#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

class EnergyDispatch {
public:
    virtual void slot0();
    virtual void updateEnergy(soModuleAccesser*);
};

extern "C" void fn_109_B988(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) {
        reinterpret_cast<EnergyDispatch*>(energy)->updateEnergy(accesser);
    }
}
