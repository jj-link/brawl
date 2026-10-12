// Preserve the original REL's four-byte-aligned dispatch table.
#pragma section data_type ".data$pikachuCFC8" ".bss"

#include <so/so_module_accesser.h>
#include <so/so_enable.h>

struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

// Status-specific mediator wrappers construct a fresh disabled state before
// forwarding the energy update; each status has its own template instance.
template <int Status> class PikachuStatusEnergyState {
    bool enabled;
public:
    PikachuStatusEnergyState() : enabled(false) {}
    ~PikachuStatusEnergyState() {}
    void update(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
        reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    }
};

extern "C" void fn_98_CFC8(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: { PikachuStatusEnergyState<100> state; state.update(energy, accesser); break; }
        case 101: { PikachuStatusEnergyState<101> state; state.update(energy, accesser); break; }
        case 102: { PikachuStatusEnergyState<102> state; state.update(energy, accesser); break; }
        case 103: { PikachuStatusEnergyState<103> state; state.update(energy, accesser); break; }
        case 104: { PikachuStatusEnergyState<104> state; state.update(energy, accesser); break; }
        case 105: { PikachuStatusEnergyState<105> state; state.update(energy, accesser); break; }
        case 106: { PikachuStatusEnergyState<106> state; state.update(energy, accesser); break; }
        case 107: { PikachuStatusEnergyState<107> state; state.update(energy, accesser); break; }
        }
    }
}
