// Preserve the original REL's four-byte-aligned dispatch table.
#pragma section data_type ".data$pikachuDA34" ".bss"

#include <so/so_module_accesser.h>
#include <so/so_enable.h>

// Mediator entries carry a full suspension byte, not the generic energy
// base's suspension bitfield.
struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

namespace {
// Each special kinetic kind constructs its own default update state.
// Unlike the generic path, these wrappers forward without an enable gate.
template <int KineticType> class PikachuSpecialEnergyState {
    bool enabled;
public:
    PikachuSpecialEnergyState() : enabled(false) {}
    ~PikachuSpecialEnergyState() {}
    void update(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
        reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    }
};
}

extern "C" void fn_98_DA34(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: { PikachuSpecialEnergyState<100> state; state.update(energy, accesser); break; }
        case 101: { PikachuSpecialEnergyState<101> state; state.update(energy, accesser); break; }
        case 102: { PikachuSpecialEnergyState<102> state; state.update(energy, accesser); break; }
        case 103: { PikachuSpecialEnergyState<103> state; state.update(energy, accesser); break; }
        case 104: { PikachuSpecialEnergyState<104> state; state.update(energy, accesser); break; }
        case 105: { PikachuSpecialEnergyState<105> state; state.update(energy, accesser); break; }
        case 106: { PikachuSpecialEnergyState<106> state; state.update(energy, accesser); break; }
        case 107: { PikachuSpecialEnergyState<107> state; state.update(energy, accesser); break; }
        }
    }
}
