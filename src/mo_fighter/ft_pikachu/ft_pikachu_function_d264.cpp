// Preserve the original REL's four-byte-aligned dispatch table.
#pragma section data_type ".data$pikachuD264" ".bss"

#include <so/so_module_accesser.h>
#include <so/so_enable.h>

// These mediator entries use a full suspension byte, rather than the
// bitfield in soKineticEnergy's generic suspension base.
struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

namespace {
// The per-type update argument is a one-byte default-initialized state.
struct PikachuEnergyUpdateArgument {
    bool state;
    PikachuEnergyUpdateArgument() : state(false) {}
    ~PikachuEnergyUpdateArgument() {}
};
struct PikachuSpecialEnergyUpdateArgument {
    bool state;
    PikachuSpecialEnergyUpdateArgument() : state(false) {}
};
#pragma always_inline on
inline void updateDefaultEnergy(PikachuMediatorEnergy* energy,
                                const PikachuEnergyUpdateArgument&,
                                soModuleAccesser* accesser) {
    reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
}
#pragma always_inline reset
}

extern "C" void fn_98_E704(PikachuMediatorEnergy*, PikachuSpecialEnergyUpdateArgument,
                            soModuleAccesser*);

extern "C" void fn_98_D264(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: {
            fn_98_E704(energy, PikachuSpecialEnergyUpdateArgument(), accesser);
            break;
        }
        case 101: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 102: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 103: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 104: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 105: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 106: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        case 107: {
            updateDefaultEnergy(energy, PikachuEnergyUpdateArgument(), accesser);
            break;
        }
        }
    }
}
