#include <so/so_module_accesser.h>
#include <so/so_enable.h>
#include <so/kinetic/so_kinetic_energy.h>
#pragma force_active on

extern "C" void fn_103_F308(soKineticEnergy* energy, soModuleAccesser* accesser);

struct PeachStatusEnergyState {
    unsigned char initialized;
    PeachStatusEnergyState() {
        __memclr(&initialized, sizeof(initialized));
    }
};

extern "C" void fn_103_EE90(soKineticEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        fn_103_F308(energy, accesser);
        return;
    }
    if (!energy->isEnable() || reinterpret_cast<u8*>(energy)[6] == 1u) {
        return;
    }
    switch (accesser->getKineticModule().getKineticType()) {
        case 100: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 101: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 102: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 103: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 104: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 105: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 106: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 107: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 108: { PeachStatusEnergyState state; fn_103_F308(energy, accesser); break; }
        case 109: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 110: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 111: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 112: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
        case 113: { PeachStatusEnergyState state; if (energy->isEnable() == true && reinterpret_cast<u8*>(energy)[6] == 0) energy->updateEnergy(accesser); break; }
    }
}
