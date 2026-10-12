// Preserve the REL's four-byte-aligned special-kinetic dispatch table.
#pragma section data_type ".data$pikachuD4FC" ".bss"

#include <so/so_module_accesser.h>

// This prefix matches the mediator's instantiated energy, whose suspension
// field is a full byte rather than soSuspendable's shared bitfield view.
struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

namespace {
// The special kinetic kinds use an initially unsuspended update policy.
// This is a local reconstruction of the per-case policy, not a shared ABI.
struct SpecialEnergyUpdatePolicy {
    bool suspended;
    SpecialEnergyUpdatePolicy() : suspended(false) {}
    ~SpecialEnergyUpdatePolicy() {}
    void update(soKineticEnergy* energy, soModuleAccesser* accesser) {
        if (!suspended)
            energy->updateEnergy(accesser);
    }
};
}

extern "C" void fn_98_D4FC(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
    soKineticEnergy* kineticEnergy = reinterpret_cast<soKineticEnergy*>(energy);
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            kineticEnergy->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 101: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 102: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 103: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 104: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 105: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 106: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        case 107: { SpecialEnergyUpdatePolicy policy; policy.update(kineticEnergy, accesser); break; }
        }
    }
}
