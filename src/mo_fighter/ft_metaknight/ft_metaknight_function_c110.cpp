#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

// These mediator entries use a full suspension byte, rather than the
// bitfield in soKineticEnergy's generic suspension base.
struct MetaKnightMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

namespace {
// The per-type update argument is a one-byte default-initialized state.
struct MetaKnightStatusEnergyState {
    unsigned char initialized;
    MetaKnightStatusEnergyState() {
        __memclr(&initialized, sizeof(initialized));
    }
    void update(MetaKnightMediatorEnergy* energy, soModuleAccesser* accesser) {
        reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    }
};
}

extern "C" void fn_111_C110(MetaKnightMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 101: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 102: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 103: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 104: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 105: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 106: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        case 107: { MetaKnightStatusEnergyState state; state.update(energy, accesser); break; }
        }
    }
}
